#ifndef _MODERN_CPP_DETECTION_DETAIL_COMPILER_GNU_C_H_
#define _MODERN_CPP_DETECTION_DETAIL_COMPILER_GNU_C_H_

#ifndef _MODERN_CPP_DETECTION_COMPILER_H_
#   error modern_cpp/detection/detail/compiler_gnu_c.h: you must include <modern_cpp/detection/compiler.h> before including this header
#endif /* _MODERN_CPP_DETECTION_COMPILER_H_ */

#ifndef _MODERN_CPP_COMPILER_

#   ifdef __GNUC__

#       define _MODERN_CPP_COMPILER_                                                            _MODERN_CPP_COMPILER_GNU_GCC_

#       define _MODERN_CPP_COMPILER_VERSION_MAJOR_                                              __GNUC__
#       define _MODERN_CPP_COMPILER_VERSION_MINOR_                                              __GNUC_MINOR__
#       define _MODERN_CPP_COMPILER_VERSION_BUILD_                                              __GNUC_PATCHLEVEL__

#       define _MODERN_CPP_COMPILER_VERSION_                                                    modern_cpp_encode_compiler_version(__GNUC__, __GNUC_MINOR__)
#       define _MODERN_CPP_COMPILER_FULL_VERSION_                                               modern_cpp_encode_compiler_full_version_with_patch(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)

#   endif // __GNUC__

#endif // _MODERN_CPP_COMPILER_

#endif // _MODERN_CPP_DETECTION_DETAIL_COMPILER_GNU_C_H_
