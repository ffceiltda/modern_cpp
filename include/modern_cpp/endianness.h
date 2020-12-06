#ifndef _MODERN_CPP_ENDIANNESS_H_
#define _MODERN_CPP_ENDIANNESS_H_

#include <modern_cpp/prolog.h>

#undef _MODERN_CPP_ENDIANNESS_

#define _MODERN_CPP_ENDIANNESS_BIG_ENDIAN_                                                      1
#define _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_                                                   2

#if ((defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_BIG__)) || (defined(_BYTE_ORDER) && (_BYTE_ORDER == _BIG_ENDIAN)))
#   define _MODERN_CPP_ENDIANNESS_                                                              _MODERN_CPP_ENDIANNESS_BIG_ENDIAN_
#else /* ((defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_BIG__)) || (defined(_BYTE_ORDER) && (_BYTE_ORDER == _BIG_ENDIAN))) */
#   define _MODERN_CPP_ENDIANNESS_                                                              _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_
#endif /* ((defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_BIG__)) || (defined(_BYTE_ORDER) && (_BYTE_ORDER == _BIG_ENDIAN))) */

#ifndef _MODERN_CPP_ENDIANNESS_
#   error modern_cpp/endianness.h: _MODERN_CPP_ENDIANNESS_ not defined
#endif /* _MODERN_CPP_ENDIANNESS_ */

#ifdef __cplusplus
namespace modern_cpp
{
#endif /* __cplusplus*/

    modern_cpp_enum_class_declare
        modern_cpp_identifier_declare_scope_prefixed(modern_cpp, endianness)
    {
        modern_cpp_identifier_member_declare_scope_prefixed(modern_cpp, endianness, unspecified),
            modern_cpp_identifier_member_declare_scope_prefixed(modern_cpp, endianness, big_endian) = _MODERN_CPP_ENDIANNESS_BIG_ENDIAN_,
            modern_cpp_identifier_member_declare_scope_prefixed(modern_cpp, endianness, little_endian) = _MODERN_CPP_ENDIANNESS_LITTLE_ENDIAN_
    };

    modern_cpp_constexpr static modern_cpp_enum_class_use modern_cpp_identifier_use_scope_prefixed(modern_cpp, endianness) const compiled_endianness =
        ((modern_cpp_enum_class_use modern_cpp_identifier_use_scope_prefixed(modern_cpp, endianness)) _MODERN_CPP_ENDIANNESS_);

#ifdef __cplusplus
    template <typename char_type, typename traits_type>
    std::basic_ostream<char_type, traits_type>& operator << (std::basic_ostream<char_type, traits_type>& ostream, endianness const value)
    {
        switch (value)
        {
        case endianness::unspecified:
            {
                ostream << "unspecified";
                
                break;
            }
        case endianness::unspecified:
            {
                ostream << "unspecified";
                
                break;
            }
        case endianness::unspecified:
            {
                ostream << "unspecified";
                
                break;
            }
        default:
            {
                ostream << "invalid-endianness=" << static_cast<int>(value);
                
                break;
            }
        }

        return ostream;
    }
}
#endif /* __cplusplus*/

#endif /* _MODERN_CPP_ENDIANNESS_H_ */
