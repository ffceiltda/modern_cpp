#ifndef _MODERN_CPP_OBJECT_POOL_HPP_
#define _MODERN_CPP_OBJECT_POOL_HPP_

#include <modern_cpp/prolog.hpp>

#include <memory>
#include <functional>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <mutex>
#include <cstdint>
#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
#include <set>
#include <cassert>
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */ 
#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
#include <atomic>
#include <sstream>
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

namespace modern_cpp
{
#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
	template <typename ObjectType>
	struct object_pool_statistics
	{
		using object_type = ObjectType;

		constexpr static size_t const object_size = (sizeof(object_type[2]) / 2);

		std::atomic_size_t pooled_objects = {};
		std::atomic_size_t allocated_objects = {};
		std::atomic_size_t allocated_objects_outside_pool = {};

		size_t const pooled_objects_estimated_memory_usage() const noexcept
		{
			return sizeof(std::vector<object_type>) + (object_size * pooled_objects.load());
		}

		size_t const allocated_objects_estimated_memory_usage() const noexcept
		{
			return (object_size * allocated_objects.load());
		}

		size_t const allocated_objects_outside_pool_estimated_memory_usage() const noexcept
		{
			return (object_size * allocated_objects_outside_pool.load());
		}

		std::string to_string() const noexcept
		{
			std::stringstream ss;
			
			ss << "\"statistics\": { \"pooled\": \"" << pooled_objects.load() << " objects\", \"pooled_memory\": \"" << pooled_objects_estimated_memory_usage() << " bytes\""; 
			ss << ", \"allocated\": \"" << allocated_objects.load() << " objects\", \"allocated_memory\": \"" << allocated_objects_estimated_memory_usage() << " bytes\"";
			ss << ", \"allocated_outside_pool\": \"" << allocated_objects_outside_pool.load() << " objects\", \"allocated_outside_pool_estimated_memory\": \"" << allocated_objects_outside_pool_estimated_memory_usage() << " bytes\" }";

			return ss.str();
		}
	};
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

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
#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
		using statistics_type = object_pool_statistics<ObjectType>;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

		std::mutex mutex;
		size_t arena_count;
		size_t const arena_growing_factor;
		size_t const maximum_arenas;
		arena_list_type arenas;
		arena_pointer_list_type free_list;
		object_recycle_function m_object_recycle_function;
#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
		arena_allocation_track_set_type tracked_allocations;
		std::mutex tracked_external_allocations_mutex;
		arena_allocation_track_set_type tracked_external_allocations;
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */ 
#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
		statistics_type m_statistics;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

	private:
		template <typename ResultType>
		auto do_allocate()
		{
			object_type* allocated_memory = nullptr;

			{
				std::unique_lock<std::mutex> lock(mutex);

				if (free_list.empty())
				{
					if (arena_count < maximum_arenas)
					{
						try
						{
							arenas.emplace_front();
							
							++arena_count;

							arena_type& arena = arenas.front();

							arena.resize(arena_growing_factor);

							auto iterator = std::begin(arena);							
							auto end_iterator = std::end(arena);

							if (iterator != end_iterator)
							{
								object_type& ubt = *iterator;
								object_type* ubt_address = std::addressof(ubt);

								allocated_memory = ubt_address;								

#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
								++m_statistics.allocated_objects;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
								tracked_allocations.insert(allocated_memory);
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */
								
								++iterator;
							}

							while (iterator != end_iterator)
							{
								object_type& ubt = *iterator;
								object_type* ubt_address = std::addressof(ubt);

								free_list.push_front(ubt_address);
				
#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
								++m_statistics.pooled_objects;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */
								
								++iterator;
							};
						}
						catch (std::bad_alloc&)
						{
						}
					}
				}
				else
				{
					allocated_memory = free_list.front();

					free_list.pop_front();

#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
					++m_statistics.allocated_objects;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
					tracked_allocations.insert(allocated_memory);
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */
				}
			}

			bool const pool_allocated = (allocated_memory != nullptr);

			if (!pool_allocated)
			{
				allocated_memory = reinterpret_cast<object_type*>(::malloc(sizeof(object_type)));

				if (!allocated_memory)
				{
					throw std::bad_alloc();
				}
			}

			try
			{
				if (!pool_allocated)
				{
					new (allocated_memory) object_type();

#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
					++m_statistics.allocated_objects_outside_pool;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
					{
						std::unique_lock<std::mutex> track_lock(tracked_external_allocations_mutex);

						tracked_external_allocations.insert(allocated_memory);
					}
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */
				}
			}
			catch (...)
			{
				::free(allocated_memory);

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

#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
						--m_statistics.allocated_objects;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

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
						try
						{
							allocated_memory->~object_type();
						}
						catch (std::exception const& e)
						{
							std::cerr << typeid(this).name() << " exception on object destruction: " << e.what() << std::endl;
						}

#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
						--m_statistics.allocated_objects_outside_pool;
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

#ifdef MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS
						{
							std::unique_lock<std::mutex> track_lock(tracked_external_allocations_mutex);
						
							auto iterator = tracked_external_allocations.find(allocated_memory);

							if (iterator != tracked_external_allocations.end())
							{
								tracked_external_allocations.erase(iterator);
							}
						}
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */

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
			
			if (!tracked_external_allocations.empty())
			{
				assert(false);

				std::abort();
			}
		}
#endif /* MODERN_CPP_OBJECT_POOL_DEBUG_CHECKS */

#ifdef MODERN_CPP_OBJECT_POOL_STATISTICS
		auto const& statistics() const noexcept
		{
			return m_statistics;
		}
#endif /* MODERN_CPP_OBJECT_POOL_STATISTICS */

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
	
	template <typename ObjectType>
	class resetable_object_pool
		: public object_pool<ObjectType>
	{
	public:
		using base_type = object_pool<ObjectType>;
		using object_type = typename base_type::object_type;
		using shared_ptr = typename base_type::shared_ptr;
		using unique_ptr = typename base_type::unique_ptr;
		
	private:
		static void recycle_buffer(object_type* object)
		{
			object->reset();
		}

	public:
		resetable_object_pool(size_t const growing_factor = 512, size_t const maximum_growths = 128)
			: base_type(growing_factor, maximum_growths)
		{
			this->set_object_recycle_function(resetable_object_pool<ObjectType>::recycle_buffer);
		}

		resetable_object_pool(resetable_object_pool const&) = delete;
		resetable_object_pool(resetable_object_pool&&) = delete;

		resetable_object_pool& operator = (resetable_object_pool const&) = delete;
		resetable_object_pool& operator = (resetable_object_pool&&) = delete;
	};
}

#endif // _MODERN_CPP_OBJECT_POOL_HPP_
