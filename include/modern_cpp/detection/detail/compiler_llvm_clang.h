#ifndef _MODERN_CPP_DETECTION_DETAIL_COMPILER_LLVM_CLANG_H_
#define _MODERN_CPP_DETECTION_DETAIL_COMPILER_LLVM_CLANG_H_

#ifndef _MODERN_CPP_DETECTION_COMPILER_H_
#   error modern_cpp/detection/detail/compiler_llvm_clang.h: you must include <modern_cpp/detection/compiler.h> before including this header
#endif /* _MODERN_CPP_DETECTION_COMPILER_H_ */

#ifndef _MODERN_CPP_COMPILER_

#   ifdef __clang__

#       define _MODERN_CPP_COMPILER_                                                            _MODERN_CPP_COMPILER_LLVM_CLANG_

#       define _MODERN_CPP_COMPILER_VERSION_MAJOR_                                              __clang_major__
#       define _MODERN_CPP_COMPILER_VERSION_MINOR_                                              __clang_minor__
#       define _MODERN_CPP_COMPILER_VERSION_BUILD_                                              __clang_patchlevel__

#       define _MODERN_CPP_COMPILER_VERSION_                                                    modern_cpp_encode_compiler_full_version(__clang_major__, __clang_minor__)
#       define _MODERN_CPP_COMPILER_FULL_VERSION_                                               modern_cpp_encode_compiler_full_version_with_patch(__clang_major__, __clang_minor__, __clang_patchlevel__)

#   endif // __clang__

#endif // _MODERN_CPP_COMPILER_

#endif // _MODERN_CPP_DETECTION_DETAIL_COMPILER_LLVM_CLANG_H_
