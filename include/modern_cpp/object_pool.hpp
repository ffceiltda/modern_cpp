#ifndef _MODERN_CPP_OBJECT_POOL_HPP_
#define _MODERN_CPP_OBJECT_POOL_HPP_

#include <modern_cpp/prolog.hpp>

#include <memory>
#include <functional>
#include <forward_list>
#include <vector>
#include <mutex>
#include <cstdint>
#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
#include <set>
#include <cassert>
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */ 

namespace modern_cpp
{
	template <typename ObjectType>
	class object_pool
	{
	public:
		using object_type = ObjectType;
		using shared_ptr = std::shared_ptr<object_type>;
		using unique_ptr = std::unique_ptr<object_type, std::function<void(object_type*)>>;
		using object_recycle_function = std::function<void(object_type*)>;

	private:
		using arena_pointer_list_type = std::forward_list<object_type*>;
		using arena_type = std::vector<object_type>;
		using arena_list_type = std::forward_list<arena_type>;
#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
		using arena_allocation_track_set_type = std::set<object_type*>;
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */ 

		std::mutex mutex;
		size_t arena_count;
		size_t const arena_growing_factor;
		size_t const maximum_arenas;
		arena_list_type arenas;
		arena_pointer_list_type free_list;
		object_recycle_function m_object_recycle_function;
#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
		arena_allocation_track_set_type tracked_allocations;
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */ 

	private:
		template <typename ResultType>
		auto do_allocate()
		{
			object_type* allocated_memory;

			{
				std::unique_lock<std::mutex> lock(mutex);

				if (free_list.empty())
				{
					if (arena_count < maximum_arenas)
					{
						try
						{
							arenas.emplace_front(arena_growing_factor);

							arena_type& arena = arenas.front();

							arena.resize(arena_growing_factor);

							std::for_each(std::begin(arena), std::end(arena), [this](object_type& ubt) mutable
								{
									free_list.push_front(std::addressof(ubt));
								});
						}
						catch (std::bad_alloc&)
						{
						}
					}
				}

				if (free_list.empty())
				{
					allocated_memory = nullptr;
				}
				else
				{
					allocated_memory = free_list.front();

					free_list.pop_front();

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
					tracked_allocations.insert(allocated_memory);
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */
				}
			}

			bool const pool_allocated = (allocated_memory != nullptr);

			if (!pool_allocated)
			{
				allocated_memory = reinterpret_cast<object_type*>(::malloc(sizeof(object_type)));
			}

			if (!allocated_memory)
			{
				throw std::bad_alloc();
			}

			try
			{
				if (!pool_allocated)
				{
					new (allocated_memory) object_type();
				}
			}
			catch (...)
			{
				if (pool_allocated)
				{
					std::unique_lock<std::mutex> lock(mutex);

					free_list.push_front(allocated_memory);

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
					auto iterator = tracked_allocations.find(allocated_memory);

					if (iterator != tracked_allocations.end())
					{
						tracked_allocations.erase(iterator);
					}
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */
				}
				else
				{
					::free(allocated_memory);
				}

				throw;
			}

			return ResultType(allocated_memory, [this, pool_allocated](object_type* allocated_memory) mutable
				{
					if (pool_allocated)
					{
						if (m_object_recycle_function)
						{
							m_object_recycle_function(allocated_memory);
						}

						std::unique_lock<std::mutex> lock(mutex);

						free_list.push_front(allocated_memory);

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
						auto iterator = tracked_allocations.find(allocated_memory);

						if (iterator != tracked_allocations.end())
						{
							tracked_allocations.erase(iterator);
						}
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */ 
					}
					else
					{
						allocated_memory->~object_type();

						::free(allocated_memory);
					}
				});
		}

	public:
		object_pool(size_t const growing_factor = 256, size_t const maximum_growths = 64)
			: arena_count(0), arena_growing_factor(growing_factor), maximum_arenas(maximum_growths)
		{
		}

		object_pool(object_pool const&) = delete;
		object_pool(object_pool&&) = delete;

		object_pool& operator = (object_pool const&) = delete;
		object_pool& operator = (object_pool&&) = delete;

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
		virtual ~object_pool()
		{
			if (!tracked_allocations.empty())
			{
				assert(false);

				std::abort();
			}
		}
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */ 

		void set_object_recycle_function(object_recycle_function value)
		{
			m_object_recycle_function = value;
		}

		auto allocate_unique()
		{
			return do_allocate<unique_ptr>();
		}

		auto allocate_unique(size_t const requested_size)
		{
			auto result = allocate_unique();

			result->resize(requested_size);

			return result;
		}

		auto allocate_shared()
		{
			return do_allocate<shared_ptr>();
		}

		auto allocate_shared(size_t const requested_size)
		{
			auto result = allocate_shared();

			result->resize(requested_size);

			return result;
		}
	};
}

#endif // _MODERN_CPP_OBJECT_POOL_HPP_
