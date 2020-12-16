#ifndef _MODERN_CPP_C_COMPATIBILITY_KEYWORDS_H_
#define _MODERN_CPP_C_COMPATIBILITY_KEYWORDS_H_

#ifndef _MODERN_CPP_C_COMPATIBILITY_H_
#   error modern_cpp/c_compatibility/keywords.h: you must include <modern_cpp/c_compatibility.h> before including this header
#endif /* _MODERN_CPP_C_COMPATIBILITY_H_ */

#include <modern_cpp/c_preprocessor.h>

#if defined(_MSVC_TRADITIONAL) && (_MSVC_TRADITIONAL == 0)

#   define _MODERN_CPP_SUPPORT_PRAGMA_

#elif (_MODERN_CPP_LANGUAGE_C_STANDARD_ >= _MODERN_CPP_LANGUAGE_C_STANDARD_99_)

#   define _MODERN_CPP_SUPPORT_PRAGMA_

#elif (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_)

#   define _MODERN_CPP_SUPPORT_PRAGMA__

#elif ((_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_LLVM_CLANG_) || (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_GNU_GCC_))

#   define _MODERN_CPP_SUPPORT_PRAGMA_

#endif /* ((_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_LLVM_CLANG_) || (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_GNU_GCC_)) */

#if defined(_MODERN_CPP_SUPPORT_PRAGMA_)

#   define modern_cpp_pragma(expression)                                                        _Pragma( modern_cpp_c_preprocessor_stringify( expression ) )

#elif defined(_MODERN_CPP_SUPPORT_PRAGMA__)

#   define modern_cpp_pragma(expression)                                                        __pragma( expression )

#else  /* defined(_MODERN_CPP_SUPPORT_PRAGMA?_) */

#   define modern_cpp_pragma(expression)

#endif /* defined(_MODERN_CPP_SUPPORT_PRAGMA?_) */

#if (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_LLVM_CLANG_)

#   define modern_cpp_pragma_warning_push()                                                     modern_cpp_pragma( clang diagnostic push )
#   define modern_cpp_pragma_warning_pop()                                                      modern_cpp_pragma( clang diagnostic pop )

#   define modern_cpp_pragma_warning_enable_clang(warning_id)                                   modern_cpp_pragma( clang diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 
#   define modern_cpp_pragma_warning_disable_clang(warning_id)                                  modern_cpp_pragma( clang diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 

#   define modern_cpp_pragma_warning_enable_clang_or_gcc(warning_id)                            modern_cpp_pragma( GCC diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 
#   define modern_cpp_pragma_warning_disable_clang_or_gcc(warning_id)                           modern_cpp_pragma( GCC diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 

#   define modern_cpp_maybe_unused                                                              __attribute__((unused))

#elif (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_GNU_GCC_)

#   define modern_cpp_pragma_warning_push()                                                     modern_cpp_pragma( GCC diagnostic push )
#   define modern_cpp_pragma_warning_pop()                                                      modern_cpp_pragma( GCC diagnostic pop )

#   define modern_cpp_pragma_warning_enable_gcc(warning_id)                                     modern_cpp_pragma( GCC diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 
#   define modern_cpp_pragma_warning_disable_gcc(warning_id)                                    modern_cpp_pragma( GCC diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 

#   define modern_cpp_pragma_warning_enable_clang_or_gcc(warning_id)                            modern_cpp_pragma( GCC diagnostic warning modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 
#   define modern_cpp_pragma_warning_disable_clang_or_gcc(warning_id)                           modern_cpp_pragma( GCC diagnostic ignored modern_cpp_c_preprocessor_stringify( modern_cpp_c_preprocessor_concatenate( -W, warning_id ) ) ) 

#   define modern_cpp_maybe_unused                                                              __attribute__((unused))

#elif (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_)

#   define modern_cpp_pragma_warning_push()                                                     modern_cpp_pragma( warning( push ) ) \
                                                                                                modern_cpp_pragma( warning( disable:5103 ) )

#   define modern_cpp_pragma_warning_pop()                                                      modern_cpp_pragma( warning( pop ) )

#   define modern_cpp_pragma_warning_enable_msvc(warning_id)                                    modern_cpp_pragma( warning( enable:##warning_id ) )
#   define modern_cpp_pragma_warning_disable_msvc(warning_id)                                   modern_cpp_pragma( warning( disable:##warning_id ) )

#   define modern_cpp_maybe_unused

#endif /* (_MODERN_CPP_COMPILER_ == _MODERN_CPP_COMPILER_?_) */

#ifndef modern_cpp_pragma_warning_push
#   define modern_cpp_pragma_warning_push(expression)
#endif /* modern_cpp_pragma_warning_push */

#ifndef modern_cpp_pragma_warning_pop
#   define modern_cpp_pragma_warning_pop(expression)
#endif /* modern_cpp_pragma_warning_pop */

#ifndef modern_cpp_pragma_warning_enable_clang
#   define modern_cpp_pragma_warning_enable_clang(expression)
#endif /* modern_cpp_pragma_warning_enable_clang */

#ifndef modern_cpp_pragma_warning_disable_clang
#   define modern_cpp_pragma_warning_disable_clang(expression)
#endif /* modern_cpp_pragma_warning_disable_clang */

#ifndef modern_cpp_pragma_warning_enable_clang_or_gcc
#   define modern_cpp_pragma_warning_enable_clang_or_gcc(expression)
#endif /* modern_cpp_pragma_warning_enable_clang_or_gcc */

#ifndef modern_cpp_pragma_warning_disable_clang_or_gcc
#   define modern_cpp_pragma_warning_disable_clang_or_gcc(expression)
#endif /* modern_cpp_pragma_warning_disable_clang_or_gcc */

#ifndef modern_cpp_pragma_warning_enable_gcc
#   define modern_cpp_pragma_warning_enable_gcc(expression)
#endif /* modern_cpp_pragma_warning_enable_gcc */

#ifndef modern_cpp_pragma_warning_disable_gcc
#   define modern_cpp_pragma_warning_disable_gcc(expression)
#endif /* modern_cpp_pragma_warning_disable_gcc */

#ifndef modern_cpp_pragma_warning_enable_msvc
#   define modern_cpp_pragma_warning_enable_msvc(expression)
#endif /* modern_cpp_pragma_warning_enable_msvc */

#ifndef modern_cpp_pragma_warning_disable_msvc
#   define modern_cpp_pragma_warning_disable_msvc(expression)
#endif /* modern_cpp_pragma_warning_disable_msvc */

#ifdef __cplusplus

#   include <cstdint>
#   include <cstddef>
#   include <memory>
#   include <type_traits>

#   define modern_cpp_bool                                                                      bool

#   if (_MODERN_CPP_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_CPP_STANDARD_17_)

#      define modern_cpp_byte                                                                   std::byte

#   endif /* (_MODERN_CPP_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_CPP_STANDARD_17_) */

#   if defined(__cpp_lib_is_constant_evaluated) && (__cpp_lib_is_constant_evaluated >= 201811)

#       define modern_cpp_is_constant_evaluated(expression)                                     (std::is_constant_evaluated())

#   endif /* defined(__cpp_lib_is_constant_evaluated) && (__cpp_lib_is_constant_evaluated >= 201811) */

#   if defined(__cpp_constexpr) && (__cpp_constexpr >= 200704)

#       define modern_cpp_constexpr                                                             constexpr

#   endif /* defined(__cpp_constexpr) && (__cpp_constexpr >= 200704) */

#   if defined(__cpp_if_constexpr) && (__cpp_if_constexpr >= 201606)

#      define modern_cpp_constexpr_if(expression)                                               constexpr (expression)

#   endif /* defined(__cpp_if_constexpr) && (__cpp_if_constexpr >= 201606) */

#   if defined(__cpp_lib_addressof_constexpr) && (__cpp_lib_addressof_constexpr >= 201603)

#      define modern_cpp_addressof(identifier)                                                  std::addressof(identifier)

#   endif /* defined(__cpp_lib_addressof_constexpr) && (__cpp_lib_addressof_constexpr >= 201603) */

#   if (_MODERN_CPP_LANGUAGE_CPP_STANDARD_ <= _MODERN_CPP_LANGUAGE_CPP_STANDARD_17_)

#       define modern_cpp_struct_member_initialize(identifier)

#   endif /* (_MODERN_CPP_LANGUAGE_CPP_STANDARD_ <= _MODERN_CPP_LANGUAGE_CPP_STANDARD_17_) */

#   if (_MODERN_CPP_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_CPP_STANDARD_11_)

#       define modern_cpp_noexcept                                                              noexcept
#       define modern_cpp_noexcept_expression(expression)                                       noexcept(expression)

#       define modern_cpp_enum_class_use
#       define modern_cpp_enum_class_declare                                                    enum class
#       define modern_cpp_enum_class_base_type(base_type)                                       : base_type

#       define modern_cpp_member_default_value(value)                                           = value

#       define modern_cpp_thread_local                                                          thread_local

#   endif /* _MODERN_CPP_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_CPP_STANDARD_11_ */

#   define modern_cpp_concatenate_scope_with(scope, nested_scope_or_identifier)                 modern_cpp_c_preprocessor_recompile(scope) :: modern_cpp_c_preprocessor_recompile(nested_scope_or_identifier)

#else /* __cplusplus */

#   include <stdint.h>
#   include <stddef.h>

#   if (_MODERN_C_LANGUAGE_CPP_STANDARD_ < _MODERN_CPP_LANGUAGE_C_STANDARD_99_)

        typedef int bool;

#       define false                                                                            0
#       define true                                                                             1

#   elif (_MODERN_C_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_C_STANDARD_99_) && (_MODERN_C_LANGUAGE_CPP_STANDARD_ < _MODERN_CPP_LANGUAGE_C_STANDARD_2X_)

#       include <stdbool.h>

#   endif /* (_MODERN_C_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_C_STANDARD_99_) && (_MODERN_C_LANGUAGE_CPP_STANDARD_ < _MODERN_CPP_LANGUAGE_C_STANDARD_2X_) */

#   define modern_cpp_bool                                                                      bool

#   if (_MODERN_C_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_C_STANDARD_11_)
#       define modern_cpp_thread_local                                                          thread_local
#   endif /* (_MODERN_C_LANGUAGE_CPP_STANDARD_ >= _MODERN_CPP_LANGUAGE_C_STANDARD_11_) */

#   define modern_cpp_concatenate_scope_with(scope, nested_scope_or_identifier)                 modern_cpp_c_preprocessor_concatenate_many(scope, _, nested_scope_or_identifier)

#endif /* __cplusplus */

#ifdef __has_builtin
#   if __has_builtin(__builtin_expect)

#       define modern_cpp_likely(expression)                                                    __builtin_expect((expression), 1)
#       define modern_cpp_unlikely(expression)                                                  __builtin_expect((expression), 0)

#   endif /* __has_builtin(__builtin_constant_p) */
#endif /* __has_builtin */

#define modern_cpp_unused(expression)                                                           (void)(expression)

#ifndef modern_cpp_bool
#   define modern_cpp_bool                                                                      int
#endif /* modern_cpp_bool */

#ifndef modern_cpp_byte
#   define modern_cpp_byte                                                                      uint8_t
#endif /* modern_cpp_byte */

#ifndef modern_cpp_is_constant_evaluated

#   ifdef __has_builtin
#       if __has_builtin(__builtin_constant_p)
#           define modern_cpp_is_constant_evaluated(expression)                                 (__builtin_constant_p(expression))
#       endif /* __has_builtin(__builtin_constant_p) */
#   endif /* __has_builtin */

#   ifndef modern_cpp_is_constant_evaluated
#       define modern_cpp_is_constant_evaluated(expression)                                     (0)
#   endif /* modern_cpp_is_constant_evaluated */

#endif /* modern_cpp_is_constant_evaluated */

#ifndef modern_cpp_constexpr
#   define modern_cpp_constexpr
#endif /* modern_cpp_constexpr */

#ifndef modern_cpp_constexpr_if
#   define modern_cpp_constexpr_if(expression)                                                  (modern_cpp_is_constant_evaluated(expression) && (expression))
#endif /* modern_cpp_constexpr_if */

#ifndef modern_cpp_addressof
#   define modern_cpp_addressof(identifier)                                                     &(identifier)
#endif /* modern_cpp_addressof */

#ifndef modern_cpp_struct_member_initialize
#   define modern_cpp_struct_member_initialize(identifier)                                      .identifier = 
#endif /* modern_cpp_struct_member_initialize */

#ifndef modern_cpp_noexcept
#   define modern_cpp_noexcept
#endif /* modern_cpp_noexcept */

#ifndef modern_cpp_noexcept_expression
#   define modern_cpp_noexcept_expression(expression)
#endif /* modern_cpp_noexcept_expression */

#ifndef modern_cpp_enum_class_use
#   define modern_cpp_enum_class_use                                                            enum
#endif /* modern_cpp_enum_class_use */

#ifndef modern_cpp_enum_class_declare
#   define modern_cpp_enum_class_declare                                                        enum
#endif /* modern_cpp_enum_class_declare */

#ifndef modern_cpp_thread_local
#   define modern_cpp_thread_local
#endif /* modern_cpp_thread_local */

#ifndef modern_cpp_enum_class_base_type
#   define modern_cpp_enum_class_base_type(base_type)
#endif /* modern_cpp_enum_class_base_type */

#ifndef modern_cpp_member_default_value
#   define modern_cpp_member_default_value(value)
#endif /* modern_cpp_member_default_value */

#ifndef modern_cpp_likely
#    define modern_cpp_likely(expression)                                                       expression
#endif /* modern_cpp_likely */

#ifndef modern_cpp_unlikely
#    define modern_cpp_unlikely(expression)                                                     expression
#endif /* modern_cpp_unlikely */

#define modern_cpp_concatenate_1_scope_with(scope_1, nested_scope_or_identifier)                modern_cpp_concatenate_scope_with(scope_1, \
                                                                                                nested_scope_or_identifier)

#define modern_cpp_concatenate_2_scopes_with(scope_1, scope_2, nested_scope_or_identifier)      modern_cpp_concatenate_1_scope_with( \
                                                                                                modern_cpp_concatenate_1_scope_with( \
                                                                                                scope_1, scope_2), nested_scope_or_identifier)

#define modern_cpp_concatenate_3_scopes_with(scope_1, scope_2, scope_3, \
    nested_scope_or_identifier)                                                                 modern_cpp_concatenate_1_scope_with( \
                                                                                                modern_cpp_concatenate_2_scopes_with( \
                                                                                                scope_1, scope_2, scope_3), nested_scope_or_identifier)

#define modern_cpp_concatenate_4_scopes_with(scope_1, scope_2, scope_3, scope_4, \
    nested_scope_or_identifier)                                                                 modern_cpp_concatenate_1_scope_with( \
                                                                                                modern_cpp_concatenate_3_scopes_with( \
                                                                                                scope_1, scope_2, scope_3, scope_4), nested_scope_or_identifier)

#define modern_cpp_concatenate_5_scopes_with(scope_1, scope_2, scope_3, scope_4, scope_5, \
    nested_scope_or_identifier)                                                                 modern_cpp_concatenate_1_scope_with( \
                                                                                                modern_cpp_concatenate_4_scopes_with( \
                                                                                                scope_1, scope_2, scope_3, scope_4, scope_5), \
                                                                                                nested_scope_or_identifier)

#define modern_cpp_concatenate_6_scopes_with(scope_1, scope_2, scope_3, scope_4, scope_5, \
    scope_6, nested_scope_or_identifier)                                                        modern_cpp_concatenate_scope_with( \
                                                                                                modern_cpp_concatenate_5_scopes_with( \
                                                                                                scope_1, scope_2, scope_3, scope_4, scope_5, \
                                                                                                scope_6), nested_scope_or_identifier)

#define modern_cpp_concatenate_7_scopes_with(scope_1, scope_2, scope_3, scope_4, scope_5, \
    scope_6, scope_7, nested_scope_or_identifier)                                               modern_cpp_concatenate_scope_with( \
                                                                                                modern_cpp_concatenate_6_scopes_with( \
                                                                                                scope_1, scope_2, scope_3, scope_4, scope_5, \
                                                                                                scope_6, scope_7), nested_scope_or_identifier)

#define modern_cpp_concatenate_8_scopes_with(scope_1, scope_2, scope_3, scope_4, scope_5, \
    scope_6, scope_7, scope_8, nested_scope_or_identifier)                                      modern_cpp_concatenate_scope_with( \
                                                                                                modern_cpp_concatenate_7_scopes_with( \
                                                                                                scope_1, scope_2, scope_3, scope_4, scope_5, \
                                                                                                scope_6, scope_7, scope_8), nested_scope_or_identifier)

#define modern_cpp_concatenate_9_scopes_with(scope_1, scope_2, scope_3, scope_4, scope_5, \
    scope_6, scope_7, scope_8, scope_9, nested_scope_or_identifier)                             modern_cpp_concatenate_scope_with(, \
                                                                                                modern_cpp_concatenate_8_scopes_with( \
                                                                                                scope_1, scope_2, scope_3, scope_4, scope_5, \
                                                                                                scope_6, scope_7, scope_8, scope_9), nested_scope_or_identifier)

#define modern_cpp_concatenate_10_scopes_with(scope_1, scope_2, scope_3, scope_4, scope_5, \
    scope_6, scope_7, scope_8, scope_9, scope_10, nested_scope_or_identifier)                   modern_cpp_concatenate_scope_with( \
                                                                                                modern_cpp_concatenate_9_scopes_with( \
                                                                                                scope_1, scope_2, scope_3, scope_4, scope_5, \
                                                                                                scope_6, scope_7, scope_8, scope_9, scope_10), nested_scope_or_identifier)

#ifdef __cplusplus

#   define modern_cpp_identifier_declare_scope_prefixed(scope, identifier)                      identifier

#   define modern_cpp_identifier_declare_1_scope_prefixed(scope_1, identifier)                  identifier

#   define modern_cpp_identifier_declare_2_scopes_prefixed(scope_1, scope_2, \
        identifier)                                                                             identifier

#   define modern_cpp_identifier_declare_3_scopes_prefixed(scope_1, scope_2, \
        scope_3, identifier)                                                                    identifier

#   define modern_cpp_identifier_declare_4_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, identifier)                                                           identifier

#   define modern_cpp_identifier_declare_5_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, identifier)                                                  identifier

#   define modern_cpp_identifier_declare_6_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, identifier)                                         identifier

#   define modern_cpp_identifier_declare_7_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, identifier)                                identifier

#   define modern_cpp_identifier_declare_8_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, identifier)                       identifier

#   define modern_cpp_identifier_declare_9_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier)              identifier

#   define modern_cpp_identifier_member_declare_scope_prefixed(scope, identifier, member)       member

#   define modern_cpp_identifier_member_declare_1_scope_prefixed(scope_1, identifier, \
        member)                                                                                 member

#   define modern_cpp_identifier_member_declare_2_scopes_prefixed(scope_1, scope_2, \
        identifier, member)                                                                     member

#   define modern_cpp_identifier_member_declare_3_scopes_prefixed(scope_1, scope_2, \
        scope_3, identifier, member)                                                            member

#   define modern_cpp_identifier_member_declare_4_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, identifier, member)                                                   member

#   define modern_cpp_identifier_member_declare_5_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, identifier, member)                                          member

#   define modern_cpp_identifier_member_declare_6_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, identifier, member)                                 member

#   define modern_cpp_identifier_member_declare_7_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, identifier, member)                        member

#   define modern_cpp_identifier_member_declare_8_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, identifier, member)               member

#   define modern_cpp_identifier_member_declare_9_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier, member)      member

#else /* __cplusplus */

#   define modern_cpp_identifier_declare_scope_prefixed(scope, identifier)                      modern_cpp_concatenate_scope_with(scope, identifier)

#   define modern_cpp_identifier_declare_1_scope_prefixed(scope_1, identifier)                  modern_cpp_identifier_declare_scope_prefixed(scope_1, identifier)

#   define modern_cpp_identifier_declare_2_scopes_prefixed(scope_1, scope_2, \
        identifier)                                                                             modern_cpp_concatenate_2_scopes_with(scope_1, scope_2, identifier)

#   define modern_cpp_identifier_declare_3_scopes_prefixed(scope_1, scope_2, \
        scope_3, identifier)                                                                    modern_cpp_concatenate_3_scopes_with(scope_1, scope_2, scope_3, identifier)

#   define modern_cpp_identifier_declare_4_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, identifier)                                                           modern_cpp_concatenate_4_scopes_with(scope_1, scope_2, scope_3, scope_4, identifier)

#   define modern_cpp_identifier_declare_5_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, identifier)                                                  modern_cpp_concatenate_5_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, identifier)

#   define modern_cpp_identifier_declare_6_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, identifier)                                         modern_cpp_concatenate_6_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, identifier)

#   define modern_cpp_identifier_declare_7_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, identifier)                                modern_cpp_concatenate_7_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, scope_7, identifier)

#   define modern_cpp_identifier_declare_8_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, identifier)                       modern_cpp_concatenate_8_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, scope_7, scope_8, identifier)

#   define modern_cpp_identifier_declare_9_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier)              modern_cpp_concatenate_9_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, scope_7, scope_8, scope_9, identifier)

#   define modern_cpp_identifier_member_declare_scope_prefixed(scope, identifier, member)       modern_cpp_concatenate_2_scopes_with(scope, identifier, member)

#   define modern_cpp_identifier_member_declare_1_scope_prefixed(scope_1, identifier, \
        member)                                                                                 modern_cpp_identifier_member_declare_scope_prefixed(scope_1, identifier, member)

#   define modern_cpp_identifier_member_declare_2_scopes_prefixed(scope_1, scope_2, \
        identifier, member)                                                                     modern_cpp_concatenate_3_scopes_with(scope_1, scope_2, \
                                                                                                identifier, member)

#   define modern_cpp_identifier_member_declare_3_scopes_prefixed(scope_1, scope_2, \
        scope_3, identifier, member)                                                            modern_cpp_concatenate_4_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, identifier, member)

#   define modern_cpp_identifier_member_declare_4_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, identifier, member)                                                   modern_cpp_concatenate_5_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, identifier, member)

#   define modern_cpp_identifier_member_declare_5_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, identifier, member)                                          modern_cpp_concatenate_6_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, scope_5, identifier, member)

#   define modern_cpp_identifier_member_declare_6_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, identifier, member)                                 modern_cpp_concatenate_7_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, scope_5, scope_6, identifier, member)

#   define modern_cpp_identifier_member_declare_7_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, identifier, member)                        modern_cpp_concatenate_8_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, scope_5, scope_6, scope_7, identifier, member)

#   define modern_cpp_identifier_member_declare_8_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, identifier, member)               modern_cpp_concatenate_9_scopes_with(scope_1, scope_2,  \
                                                                                                scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, identifier, member)

#   define modern_cpp_identifier_member_declare_9_scopes_prefixed(scope_1, scope_2, \
        scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier, member)      modern_cpp_concatenate_10_scopes_with(scope_1, scope_2,  \
                                                                                                scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier, member)

#endif /* __cplusplus */

#define modern_cpp_identifier_use_scope_prefixed(scope, identifier)                             modern_cpp_concatenate_scope_with(scope, identifier)

#define modern_cpp_identifier_use_1_scope_prefixed(scope_1, identifier)                         modern_cpp_identifier_use_scope_prefixed(scope_1, identifier)

#define modern_cpp_identifier_use_2_scopes_prefixed(scope_1, scope_2, \
    identifier)                                                                                 modern_cpp_concatenate_2_scopes_with(scope_1, scope_2, identifier)

#define modern_cpp_identifier_use_3_scopes_prefixed(scope_1, scope_2, \
    scope_3, identifier)                                                                        modern_cpp_concatenate_3_scopes_with(scope_1, scope_2, scope_3, identifier)

#define modern_cpp_identifier_use_4_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, identifier)                                                               modern_cpp_concatenate_4_scopes_with(scope_1, scope_2, scope_3, scope_4, identifier)

#define modern_cpp_identifier_use_5_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, identifier)                                                      modern_cpp_concatenate_5_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, identifier)

#define modern_cpp_identifier_use_6_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, identifier)                                             modern_cpp_concatenate_6_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, identifier)

#define modern_cpp_identifier_use_7_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, scope_7, identifier)                                    modern_cpp_concatenate_7_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, scope_7, identifier)

#define modern_cpp_identifier_use_8_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, identifier)                           modern_cpp_concatenate_8_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, scope_7, scope_8, identifier)

#define modern_cpp_identifier_use_9_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier)                  modern_cpp_concatenate_9_scopes_with(scope_1, scope_2, scope_3, scope_4, \
                                                                                                scope_5, scope_6, scope_7, scope_8, scope_9, identifier)

#define modern_cpp_identifier_member_use_scope_prefixed(scope, identifier, member)              modern_cpp_concatenate_2_scopes_with(scope, identifier, member)

#define modern_cpp_identifier_member_use_1_scope_prefixed(scope_1, identifier, member)          modern_cpp_identifier_member_use_scope_prefixed(scope_1, identifier, member)

#define modern_cpp_identifier_member_use_2_scopes_prefixed(scope_1, scope_2, \
    identifier, member)                                                                         modern_cpp_concatenate_3_scopes_with(scope_1, scope_2, \
                                                                                                identifier, member)

#define modern_cpp_identifier_member_use_3_scopes_prefixed(scope_1, scope_2, \
    scope_3, identifier, member)                                                                modern_cpp_concatenate_4_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, identifier, member)

#define modern_cpp_identifier_member_use_4_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, identifier, member)                                                       modern_cpp_concatenate_5_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, identifier, member)

#define modern_cpp_identifier_member_use_5_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, identifier, member)                                              modern_cpp_concatenate_6_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, scope_5, identifier, member)

#define modern_cpp_identifier_member_use_6_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, identifier, member)                                     modern_cpp_concatenate_7_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, scope_5, scope_6, identifier, member)

#define modern_cpp_identifier_member_use_7_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, scope_7, identifier, member)                            modern_cpp_concatenate_8_scopes_with(scope_1, scope_2, \
                                                                                                scope_3, scope_4, scope_5, scope_6, scope_7, identifier, member)

#define modern_cpp_identifier_member_use_8_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, identifier, member)                   modern_cpp_concatenate_9_scopes_with(scope_1, scope_2,  \
                                                                                                scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier, member)

#define modern_cpp_identifier_member_use_9_scopes_prefixed(scope_1, scope_2, \
    scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier, member)          modern_cpp_concatenate_10_scopes_with(scope_1, scope_2,  \
                                                                                                scope_3, scope_4, scope_5, scope_6, scope_7, scope_8, scope_9, identifier, member)

#endif /* _MODERN_CPP_C_COMPATIBILITY_KEYWORDS_H_ */
