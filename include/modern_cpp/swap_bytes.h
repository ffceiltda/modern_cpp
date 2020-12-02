#ifndef _MODERN_CPP_SWAP_BYTES_H_
#define _MODERN_CPP_SWAP_BYTES_H_

#include <modern_cpp/c_compatibility.h>
#include <modern_cpp/endianness.h>

#ifdef __cplusplus

#include <type_traits>

namespace modern_cpp
{

#endif /* __cplusplus */

#if _MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_

#   include <intrin.h>

#   define _MODERN_CPP_SWAP_BYTES_16_INTRINSIC_                                                 _byteswap_ushort
#   define _MODERN_CPP_SWAP_BYTES_32_INTRINSIC_                                                 _byteswap_ulong
#   define _MODERN_CPP_SWAP_BYTES_64_INTRINSIC_                                                 _byteswap_uint64

#endif /* _MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_ */

#ifdef __has_builtin

#   if !defined(_MODERN_CPP_SWAP_BYTES_16_INTRINSIC_) && __has_builtin(__builtin_bswap16)
#      define _MODERN_CPP_SWAP_BYTES_16_INTRINSIC_                                              __builtin_bswap16
#   endif /* !defined(_MODERN_CPP_SWAP_BYTES_16_INTRINSIC_) && __has_builtin(__builtin_bswap16) */

#   if !defined(_MODERN_CPP_SWAP_BYTES_32_INTRINSIC_) && __has_builtin(__builtin_bswap16)
#      define _MODERN_CPP_SWAP_BYTES_32_INTRINSIC_                                              __builtin_bswap32
#   endif /* !defined(_MODERN_CPP_SWAP_BYTES_32_INTRINSIC_) && __has_builtin(__builtin_bswap16) */

#   if !defined(_MODERN_CPP_SWAP_BYTES_64_INTRINSIC_) && __has_builtin(__builtin_bswap16)
#      define _MODERN_CPP_SWAP_BYTES_64_INTRINSIC_                                              __builtin_bswap64
#   endif /* !defined(_MODERN_CPP_SWAP_BYTES_64_INTRINSIC_) && __has_builtin(__builtin_bswap16) */

#endif /* __has_builtin */

#if defined(__cpp_lib_is_constant_evaluated) && (__cpp_lib_is_constant_evaluated >= 201811)
#   define MODERN_CPP_SWAP_BYTES_CONSTEXPR                                                      modern_cpp_constexpr
#else /* defined(__cpp_lib_is_constant_evaluated) && (__cpp_lib_is_constant_evaluated >= 201811) */
#   define MODERN_CPP_SWAP_BYTES_CONSTEXPR
#endif /* defined(__cpp_lib_is_constant_evaluated) && (__cpp_lib_is_constant_evaluated >= 201811) */

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint16_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, swap_bytes_u16)(uint16_t const value) modern_cpp_noexcept
    {
#  ifdef _MODERN_CPP_SWAP_BYTES_16_INTRINSIC_

        if (!modern_cpp_is_constant_evaluated(value))
        {
            return _MODERN_CPP_SWAP_BYTES_16_INTRINSIC_(value);
        }

#   endif /* _MODERN_CPP_SWAP_BYTES_16_INTRINSIC_ */

        return ((value & 0xFF00) >> 8) | ((value & 0x00FF) << 8);
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int16_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, swap_bytes_i16)(int16_t const value) modern_cpp_noexcept
    {
        return (int16_t)(modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u16)((uint16_t)(value)));
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint32_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, swap_bytes_u32)(uint32_t const value) modern_cpp_noexcept
    {
#  ifdef _MODERN_CPP_SWAP_BYTES_32_INTRINSIC_

        if (!modern_cpp_is_constant_evaluated(value))
        {
            return _MODERN_CPP_SWAP_BYTES_32_INTRINSIC_(value);
        }

#   endif /* _MODERN_CPP_SWAP_BYTES_32_INTRINSIC_ */

        return ((value & 0xFF000000) >> 24) | ((value & 0x00FF0000) >> 8) | ((value & 0x0000FF00) << 8) | ((value & 0x000000FF) << 24);
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int32_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, swap_bytes_i32)(int32_t const value) modern_cpp_noexcept
    {
        return (int32_t)(modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u32)((uint32_t)(value)));
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint64_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, swap_bytes_u64)(uint64_t const value) modern_cpp_noexcept
    {
#  ifdef _MODERN_CPP_SWAP_BYTES_64_INTRINSIC_

        if (!modern_cpp_is_constant_evaluated(value))
        {
            return _MODERN_CPP_SWAP_BYTES_64_INTRINSIC_(value);
        }

#   endif /* _MODERN_CPP_SWAP_BYTES_64_INTRINSIC_ */

        return ((value & 0xFF00000000000000) >> 56) | ((value & 0x00FF000000000000) >> 40) | ((value & 0x0000FF0000000000) >> 24) | ((value & 0x000000FF00000000) >> 8) |
            ((value & 0x00000000FF000000) << 8) | ((value & 0x0000000000FF0000) << 24) | ((value & 0x000000000000FF00) << 40) | ((value & 0x00000000000000FF) << 56);
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int64_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, swap_bytes_i64)(int64_t const value) modern_cpp_noexcept
    {
        return (int64_t)(modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u64)((uint64_t)(value)));
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int16_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, host_to_network_i16)(int16_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_i16)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int16_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, network_to_host_i16)(int16_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_i16)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint16_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, host_to_network_u16)(uint16_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u16)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint16_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, network_to_host_u16)(uint16_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u16)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int32_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, host_to_network_i32)(int32_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_i32)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int32_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, network_to_host_i32)(int32_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_i32)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint32_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, host_to_network_u32)(uint32_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u32)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint32_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, network_to_host_u32)(uint32_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u32)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int64_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, host_to_network_i64)(int64_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_i64)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline int64_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, network_to_host_i64)(int64_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_i64)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint64_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, host_to_network_u64)(uint64_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u64)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

    MODERN_CPP_SWAP_BYTES_CONSTEXPR static inline uint64_t modern_cpp_identifier_declare_scope_prefixed(modern_cpp, network_to_host_u64)(uint64_t const value) modern_cpp_noexcept
    {
#if (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return modern_cpp_identifier_use_scope_prefixed(modern_cpp, swap_bytes_u64)(value);
#else // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
        return value;
#endif // (_MODERN_CPP_ENDIANNESS_ == _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_)
    }

#ifdef __cplusplus

}

#endif /* __cplusplus */

#endif /* _MODERN_CPP_SWAP_BYTES_H_ */
