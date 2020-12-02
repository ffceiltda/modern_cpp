#ifndef _MODERN_CPP_C_PREPROCESSOR_H_
#define _MODERN_CPP_C_PREPROCESSOR_H_

#include <modern_cpp/prolog.h>

#if defined(_MSVC_TRADITIONAL) && (_MSVC_TRADITIONAL == 0)

#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_

#elif (_MODERN_CPP_LANGUAGE_C_STANDARD_ >= _MODERN_CPP_LANGUAGE_C_STANDARD_99_)

#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_

#elif defined(__cplusplus) && (_MODERN_CPP_LANGUAGE_CXX_STANDARD_ >= _MODERN_CPP_LANGUAGE_CXX_STANDARD_0X_)

#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_

#endif /* MODERN_CPP_LANGUAGE_??_STANDARD_ >= _MODERN_CPP_LANGUAGE_?_STANDARD_??_ */

#ifdef _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_(...)                                         __VA_ARGS__

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_(...)                                         _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_(__VA_ARGS__)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_(...)                                         _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_(__VA_ARGS__)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_(...)                                         _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_(__VA_ARGS__)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_(...)                                         _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_(__VA_ARGS__)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_(...)                                           _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_(__VA_ARGS__)))

#   define modern_cpp_c_preprocessor_recompile(...)                                             _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_(__VA_ARGS__)

#else /* _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_ */

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_(expression)                                  expression

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_(expression)                                  _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_5_(expression)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_(expression)                                  _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_4_(expression)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_(expression)                                  _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_3_(expression)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_(expression)                                  _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_2_(expression)))

#   define _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_(expression)                                    _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_( \
                                                                                                _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_1_(expression)))

#   define modern_cpp_c_preprocessor_recompile(expression)                                      _MODERN_CPP_C_PREPROCESSOR_RECOMPILE_(expression)

#endif /* _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_ */

#define modern_cpp_c_preprocessor_stringify_implementation(identifier)                          #identifier

#define modern_cpp_c_preprocessor_stringify(identifier)                                         modern_cpp_c_preprocessor_recompile( \
                                                                                                modern_cpp_c_preprocessor_stringify_implementation( \
                                                                                                identifier ) )

#define modern_cpp_c_preprocessor_concatenate_implementation(left_identifier, right_identifier) left_identifier ## right_identifier

#define modern_cpp_c_preprocessor_concatenate(left_identifier, right_identifier)                modern_cpp_c_preprocessor_recompile( \
                                                                                                modern_cpp_c_preprocessor_concatenate_implementation( \
                                                                                                left_identifier, right_identifier) )


#define modern_cpp_c_preprocessor_concatenate_many_implementation(left_identifier, middle_identifier, right_identifier) \
																								left_identifier ## middle_identifier ## right_identifier

#define modern_cpp_c_preprocessor_concatenate_many(left_identifier, middle_identifier, right_identifier) \
																								modern_cpp_c_preprocessor_recompile( \
                                                                                                modern_cpp_c_preprocessor_concatenate_many_implementation( \
                                                                                                left_identifier, middle_identifier, right_identifier) )


#endif /* _MODERN_CPP_C_PREPROCESSOR_H_ */
