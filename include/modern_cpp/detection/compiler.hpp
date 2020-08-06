#ifndef _MODERN_CPP_DETECTION_COMPILER_HXX_
#define _MODERN_CPP_DETECTION_COMPILER_HXX_

#ifndef _MODERN_CPP_PROLOG_HPP_
#   error modern_cpp/detection/compiler.hpp: you must include <modern_cpp/prolog.hpp> before including this header
#endif // _MODERN_CPP_PROLOG_HPP_

#include <modern_cpp/detection/compiler.h>

#define _MODERN_CPP_COMPILER_LLVM_CLANGPP_                                                      _MODERN_CPP_COMPILER_LLVM_CLANG_
#define _MODERN_CPP_COMPILER_GNU_GPP_                                                           _MODERN_CPP_COMPILER_GNU_GCC_
#define _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_CPP_                                              _MODERN_CPP_COMPILER_MICROSOFT_VISUAL_C_

#endif // _MODERN_CPP_DETECTION_COMPILER_HXX_
