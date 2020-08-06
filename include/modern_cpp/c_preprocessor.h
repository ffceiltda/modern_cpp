#ifndef _MODERN_CPP_C_PREPROCESSOR_H_
#define _MODERN_CPP_C_PREPROCESSOR_H_

#include <modern_cpp/prolog.h>

#if defined(_MSVC_TRADITIONAL) && (_MSVC_TRADITIONAL == 0)

#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_
#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_PRAGMA_

#elif (_MODERN_CPP_LANGUAGE_C_STANDARD_ >= _MODERN_CPP_LANGUAGE_C_STANDARD_99_)

#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_
#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_PRAGMA_

#elif defined(__cplusplus) && (_MODERN_CPP_LANGUAGE_CXX_STANDARD_ >= _MODERN_CPP_LANGUAGE_CXX_STANDARD_0X_)

#   define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_VA_ARGS_

#   if (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_)
#       define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_PRAGMA__
#   endif /* (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_) */

#   if ((_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_LLVM_CLANG_) || (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_GNU_GCC_))
#       define _MODERN_CPP_C_PREPROCESSOR_SUPPORT_PRAGMA_
#   endif /* ((_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_LLVM_CLANG_) || (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_GNU_GCC_)) */

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

#define modern_cpp_c_preprocessor_defer_compile()
#define modern_cpp_c_preprocessor_defer_compile()

#define modern_cpp_c_preprocessor_stringify_implementation(identifier)                          #identifier

#define modern_cpp_c_preprocessor_stringify(identifier)                                         modern_cpp_c_preprocessor_stringify_implementation(identifier)

#define modern_cpp_c_preprocessor_concatenate_implementation(left_identifier, right_identifier) left_identifier##right_identifier

#define modern_cpp_c_preprocessor_concatenate(left_identifier, right_identifier)                modern_cpp_c_preprocessor_recompile( \
                                                                                                modern_cpp_c_preprocessor_concatenate_implementation( \
                                                                                                left_identifier, right_identifier ) )


#define modern_cpp_c_preprocessor_concatenate_many_implementation(left_identifier, middle_identifier, right_identifier) \
																								left_identifier##middle_identifier##right_identifier

#define modern_cpp_c_preprocessor_concatenate_many(left_identifier, middle_identifier, right_identifier) \
																								modern_cpp_c_preprocessor_recompile( \
																								modern_cpp_c_preprocessor_concatenate_many_implementation( \
                                                                                                left_identifier, middle_identifier, right_identifier ) )

#if defined(_MODERN_CPP_C_PREPROCESSOR_SUPPORT_PRAGMA_)

#   define modern_cpp_c_preprocessor_pragma(expression)                                         _Pragma( modern_cpp_c_preprocessor_stringify(expression) )

#elif defined(_MODERN_CPP_C_PREPROCESSOR_SUPPORT_PRAGMA__)

#   define modern_cpp_c_preprocessor_pragma(expression)                                         __pragma(expression)

#endif /* defined(_MODERN_CPP_C_PREPROCESSOR_SUPPORT_PRAGMA?_) */

#if (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_LLVM_CLANG_)

#   define modern_cpp_c_preprocessor_warning_push()                                             modern_cpp_c_preprocessor_pragma(clang diagnostic push)
#   define modern_cpp_c_preprocessor_warning_pop()                                              modern_cpp_c_preprocessor_pragma(clang diagnostic pop)

#   define modern_cpp_c_preprocessor_warning_enable_clang(warning_id)                           modern_cpp_c_preprocessor_pragma(clang diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 
#   define modern_cpp_c_preprocessor_warning_disable_clang(warning_id)                          modern_cpp_c_preprocessor_pragma(clang diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 

#   define modern_cpp_c_preprocessor_warning_enable_clang_or_gcc(warning_id)                    modern_cpp_c_preprocessor_pragma(GCC diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 
#   define modern_cpp_c_preprocessor_warning_disable_clang_or_gcc(warning_id)                   modern_cpp_c_preprocessor_pragma(GCC diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 

#elif (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_GNU_GCC_)

#   define modern_cpp_c_preprocessor_warning_push()                                             modern_cpp_c_preprocessor_pragma(GCC diagnostic push)
#   define modern_cpp_c_preprocessor_warning_pop()                                              modern_cpp_c_preprocessor_pragma(GCC diagnostic pop)

#   define modern_cpp_c_preprocessor_warning_enable_gcc(warning_id)                             modern_cpp_c_preprocessor_pragma(GCC diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 
#   define modern_cpp_c_preprocessor_warning_disable_gcc(warning_id)                            modern_cpp_c_preprocessor_pragma(GCC diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 

#   define modern_cpp_c_preprocessor_warning_enable_clang_or_gcc(warning_id)                    modern_cpp_c_preprocessor_pragma(GCC diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 
#   define modern_cpp_c_preprocessor_warning_disable_clang_or_gcc(warning_id)                   modern_cpp_c_preprocessor_pragma(GCC diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate(-W, warning_id))) 

#elif (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_)

#   define modern_cpp_c_preprocessor_warning_push()                                             modern_cpp_c_preprocessor_pragma(warning(push)) \
                                                                                                modern_cpp_c_preprocessor_pragma(warning(disable:5103))

#   define modern_cpp_c_preprocessor_warning_pop()                                              modern_cpp_c_preprocessor_pragma(warning(pop))

#   define modern_cpp_c_preprocessor_warning_enable_msvc(warning_id)                            modern_cpp_c_preprocessor_pragma(warning(enable:##warning_id))
#   define modern_cpp_c_preprocessor_warning_disable_msvc(warning_id)                           modern_cpp_c_preprocessor_pragma(warning(disable:##warning_id))

#endif /* (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_?_) */

#ifndef modern_cpp_c_preprocessor_warning_push
#   define modern_cpp_c_preprocessor_warning_push(expression)
#endif /* modern_cpp_c_preprocessor_warning_push */

#ifndef modern_cpp_c_preprocessor_warning_pop
#   define modern_cpp_c_preprocessor_warning_pop(expression)
#endif /* modern_cpp_c_preprocessor_warning_pop */

#ifndef modern_cpp_c_preprocessor_warning_enable_clang
#   define modern_cpp_c_preprocessor_warning_enable_clang(expression)
#endif /* modern_cpp_c_preprocessor_warning_enable_clang */

#ifndef modern_cpp_c_preprocessor_warning_disable_clang
#   define modern_cpp_c_preprocessor_warning_disable_clang(expression)
#endif /* modern_cpp_c_preprocessor_warning_disable_clang */

#ifndef modern_cpp_c_preprocessor_warning_enable_clang_or_gcc
#   define modern_cpp_c_preprocessor_warning_enable_clang_or_gcc(expression)
#endif /* modern_cpp_c_preprocessor_warning_enable_clang_or_gcc */

#ifndef modern_cpp_c_preprocessor_warning_disable_clang_or_gcc
#   define modern_cpp_c_preprocessor_warning_disable_clang_or_gcc(expression)
#endif /* modern_cpp_c_preprocessor_warning_disable_clang_or_gcc */

#ifndef modern_cpp_c_preprocessor_warning_enable_gcc
#   define modern_cpp_c_preprocessor_warning_enable_gcc(expression)
#endif /* modern_cpp_c_preprocessor_warning_enable_gcc */

#ifndef modern_cpp_c_preprocessor_warning_disable_gcc
#   define modern_cpp_c_preprocessor_warning_disable_gcc(expression)
#endif /* modern_cpp_c_preprocessor_warning_disable_gcc */

#ifndef modern_cpp_c_preprocessor_warning_enable_msvc
#   define modern_cpp_c_preprocessor_warning_enable_msvc(expression)
#endif /* modern_cpp_c_preprocessor_warning_enable_msvc */

#ifndef modern_cpp_c_preprocessor_warning_disable_msvc
#   define modern_cpp_c_preprocessor_warning_disable_msvc(expression)
#endif /* modern_cpp_c_preprocessor_warning_disable_msvc */

#endif /* _MODERN_CPP_C_PREPROCESSOR_H_ */
