#ifndef _MODERN_CPP_DETECTION_DETAIL_COMPILER_MICROSOFT_VISUAL_C_H_
#define _MODERN_CPP_DETECTION_DETAIL_COMPILER_MICROSOFT_VISUAL_C_H_

#ifndef _MODERN_CPP_DETECTION_COMPILER_H_
#   error modern_cpp/detection/detail/compiler_microsoft_visual_c.h: you must include <modern_cpp/detection/compiler.h> before including this header
#endif /* _MODERN_CPP_DETECTION_COMPILER_H_ */

#ifndef _MODERN_CPP_COMPILER_

#   ifdef _MSC_VER

#       define _MODERN_CPP_COMPILER_                                                            _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_

#       define _MODERN_CPP_COMPILER_VERSION_MAJOR_                                              (_MSC_VER / 100)
#       define _MODERN_CPP_COMPILER_VERSION_MINOR_                                              (_MSC_VER % 100)_
#       define _MODERN_CPP_COMPILER_VERSION_BUILD_                                              (_MSC_FULL_VER % 100000)

#       define _MODERN_CPP_COMPILER_VERSION_                                                    _MSC_VER
#       define _MODERN_CPP_COMPILER_FULL_VERSION_                                               _MSC_FULL_VER

#   endif // _MSC_VER

#endif // _MODERN_CPP_COMPILER_

#endif // _MODERN_CPP_DETECTION_DETAIL_COMPILER_MICROSOFT_VISUAL_C_H_
