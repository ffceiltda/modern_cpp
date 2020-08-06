#ifndef _MODERN_CPP_DETECTION_LANGUAGE_C_STANDARD_H_
#define _MODERN_CPP_DETECTION_LANGUAGE_C_STANDARD_H_

#ifndef _MODERN_CPP_PROLOG_H_
#   error modern_cpp/detection/language_c_standard.h: you must include <modern_cpp/prolog.h> before including this header
#endif /* _MODERN_CPP_PROLOG_H_ */

#undef _MODERN_CPP_LANGUAGE_C_STANDARD_

#define _MODERN_CPP_LANGUAGE_C_STANDARD_89_                                                     1
#define _MODERN_CPP_LANGUAGE_C_STANDARD_90_                                                     _MODERN_CPP_LANGUAGE_C_STANDARD_89_
#define _MODERN_CPP_LANGUAGE_C_STANDARD_95_                                                     2
#define _MODERN_CPP_LANGUAGE_C_STANDARD_99_                                                     3
#define _MODERN_CPP_LANGUAGE_C_STANDARD_11_                                                     4
#define _MODERN_CPP_LANGUAGE_C_STANDARD_18_                                                     5
#define _MODERN_CPP_LANGUAGE_C_STANDARD_2X_                                                     6

#if !defined(__STDC_VERSION__)
#   define _MODERN_CPP_LANGUAGE_C_STANDARD_                                                     _MODERN_CPP_LANGUAGE_C_STANDARD_89_
#elif (__STDC_VERSION__ == 199409L)
#   define _MODERN_CPP_LANGUAGE_C_STANDARD_                                                     _MODERN_CPP_LANGUAGE_C_STANDARD_95_
#elif (__STDC_VERSION__ == 199901L)
#   define _MODERN_CPP_LANGUAGE_C_STANDARD_                                                     _MODERN_CPP_LANGUAGE_C_STANDARD_99_
#elif (__STDC_VERSION__ == 201112L)
#   define _MODERN_CPP_LANGUAGE_C_STANDARD_                                                     _MODERN_CPP_LANGUAGE_C_STANDARD_11_
#elif (__STDC_VERSION__ == 201710L)
#   define _MODERN_CPP_LANGUAGE_C_STANDARD_                                                     _MODERN_CPP_LANGUAGE_C_STANDARD_18_
#elif (__STDC_VERSION__ > 201710L)
#   define _MODERN_CPP_LANGUAGE_C_STANDARD_                                                     _MODERN_CPP_LANGUAGE_C_STANDARD_2X_
#endif // (__STDC_VERSION__ > ?)

#ifndef _MODERN_CPP_LANGUAGE_C_STANDARD_
#   error modern_cpp/detection/language_c_standard.h: _MODERN_CPP_LANGUAGE_C_STANDARD_ not defined
#endif // _MODERN_CPP_LANGUAGE_C_STANDARD_

#endif // _MODERN_CPP_DETECTION_LANGUAGE_C_STANDARD_H_
