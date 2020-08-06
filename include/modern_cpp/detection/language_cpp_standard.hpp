#ifndef _MODERN_CPP_DETECTION_LANGUAGE_CPP_STANDARD_H_
#define _MODERN_CPP_DETECTION_LANGUAGE_CPP_STANDARD_H_

#ifndef _MODERN_CPP_PROLOG_HPP_
#   error modern_cpp/detection/language_cpp_standard.hpp: you must include <modern_cpp/prolog.hpp> before including this header
#endif // _MODERN_CPP_PROLOG_HPP_

#undef _MODERN_CPP_LANGUAGE_CPP_STANDARD_

#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_98_                                                   1
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_03_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_98_
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_1X_                                                   2
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_11_                                                   3
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_1Y_                                                   4
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_14_                                                   5
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_1Z_                                                   6
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_17_                                                   7
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_2A_                                                   8
#define _MODERN_CPP_LANGUAGE_CPP_STANDARD_20_                                                   9

#ifdef _MSVC_LANG
#   define _MODERN_CPP_LANGUAGE_CPP_CHECK_                                                      _MSVC_LANG
#else // _MSVC_LANG
#   define _MODERN_CPP_LANGUAGE_CPP_CHECK_                                                      __cplusplus
#endif // _MSVC_LANG

#if (_MODERN_CPP_LANGUAGE_CPP_CHECK_ == 199711L)
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_98_
#elif ((_MODERN_CPP_LANGUAGE_CPP_CHECK_ > 199711L) && (_MODERN_CPP_LANGUAGE_CPP_CHECK_ < 201103L))
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_1X_
#elif (_MODERN_CPP_LANGUAGE_CPP_CHECK_ == 201103L)
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_11_
#elif ((_MODERN_CPP_LANGUAGE_CPP_CHECK_ > 201103L) && (_MODERN_CPP_LANGUAGE_CPP_CHECK_ < 201402L))
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_1Y_
#elif (_MODERN_CPP_LANGUAGE_CPP_CHECK_ == 201402L)
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_14_
#elif ((_MODERN_CPP_LANGUAGE_CPP_CHECK_ > 201402L) && (_MODERN_CPP_LANGUAGE_CPP_CHECK_ < 201703L))
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_1Z_
#elif (_MODERN_CPP_LANGUAGE_CPP_CHECK_ == 201703L)
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_17_
#elif ((_MODERN_CPP_LANGUAGE_CPP_CHECK_ > 201703L) && (_MODERN_CPP_LANGUAGE_CPP_CHECK_ < 202002L))
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_2A_
#elif (_MODERN_CPP_LANGUAGE_CPP_CHECK_ == 202002L)
#   define _MODERN_CPP_LANGUAGE_CPP_STANDARD_                                                   _MODERN_CPP_LANGUAGE_CPP_STANDARD_20_
#endif

#ifndef _MODERN_CPP_LANGUAGE_CPP_STANDARD_
#   error modern_cpp/detection/language_c_standard.h: _MODERN_CPP_LANGUAGE_CPP_STANDARD_ not defined
#endif // _MODERN_CPP_LANGUAGE_CPP_STANDARD_

#endif // _MODERN_CPP_DETECTION_LANGUAGE_CPP_STANDARD_H_
