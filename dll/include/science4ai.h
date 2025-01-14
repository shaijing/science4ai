#ifndef SCIENCE4AI_H
#define SCIENCE4AI_H

#if defined(_MSC_VER)
#ifdef DLL_EXPORTS
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif
// GCC and clang
#elif defined(__GNUC__) &&                                                     \
    ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#define DLLAPI __attribute__((visibility("default")))
#else
#error "Unsupported compiler"
#endif
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

DLLAPI void science4ai();

#ifdef __cplusplus
}
#endif

#endif // SCIENCE4AI_H
