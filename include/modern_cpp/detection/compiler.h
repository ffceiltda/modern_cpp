#ifndef _MODERN_CPP_DETECTION_COMPILER_H_
#define _MODERN_CPP_DETECTION_COMPILER_H_

#ifndef _MODERN_CPP_PROLOG_H_
#   error modern_cpp/detection/compiler.h: you must include <modern_cpp/prolog.h> before including this header
#endif /* _MODERN_CPP_PROLOG_H_ */

#undef _MODERN_CPP_COMPILER_
#undef _MODERN_CPP_COMPILER_VERSION_
#undef _MODERN_CPP_COMPILER_FULL_VERSION_

#define _MODERN_CPP_COMPILER_LLVM_CLANG_                                                        1
#define _MODERN_CPP_COMPILER_GNU_GCC_                                                           2
#define _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_                                                3

#define modern_cpp_encode_compiler_version(major, minor)                                        (((major) * 100) + (minor))
#define modern_cpp_encode_compiler_full_version(major, minor)                                   (((major) * 10000000) + ((minor) * 100000))
#define modern_cpp_encode_compiler_full_version_with_patch(major, minor, patch)                 (((major) * 10000000) + ((minor) * 100000) + (patch))

#include <modern_cpp/detection/detail/compiler_llvm_clang.h>
#include <modern_cpp/detection/detail/compiler_gnu.h>
#include <modern_cpp/detection/detail/compiler_microsoft.h>

#ifndef _MODERN_CPP_COMPILER_
#   error modern_cpp/detection/compiler.h: _MODERN_CPP_COMPILER_ not defined
#endif // _MODERN_CPP_COMPILER_

#ifndef _MODERN_CPP_COMPILER_VERSION_MAJOR_
#   error modern_cpp/detection/compiler.h: _MODERN_CPP_COMPILER_VERSION_MAJOR_ not defined
#endif // _MODERN_CPP_COMPILER_VERSION_MAJOR_

#ifndef _MODERN_CPP_COMPILER_VERSION_MINOR_
#   error modern_cpp/detection/compiler.h: _MODERN_CPP_COMPILER_VERSION_MINOR_ not defined
#endif // _MODERN_CPP_COMPILER_VERSION_MINOR_

#ifndef _MODERN_CPP_COMPILER_VERSION_BUILD_
#   error modern_cpp/detection/compiler.h: _MODERN_CPP_COMPILER_VERSION_BUILD_ not defined
#endif // _MODERN_CPP_COMPILER_VERSION_BUILD_

#ifndef _MODERN_CPP_COMPILER_VERSION_
#   error modern_cpp/detection/compiler.h: _MODERN_CPP_COMPILER_VERSION_ not defined
#endif // _MODERN_CPP_COMPILER_VERSION_

#ifndef _MODERN_CPP_COMPILER_FULL_VERSION_
#   error modern_cpp/detection/compiler.h: _MODERN_CPP_COMPILER_FULL_VERSION_ not defined
#endif // _MODERN_CPP_COMPILER_FULL_VERSION_

#endif // _MODERN_CPP_DETECTION_COMPILER_H_
