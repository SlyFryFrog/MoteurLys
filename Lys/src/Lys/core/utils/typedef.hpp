#pragma once

#ifndef _ALWAYS_INLINE_
#if defined(__GNUC__) // GNU compiler
#define _ALWAYS_INLINE_ __attribute__((always_inline)) inline
#elif defined(_MSC_VER) // MSVC compiler
#warning The engine was not tested using the MSVC compiler and may not work correctly or at all.
#define _ALWAYS_INLINE_ __forceinline
#else // Clang compiler
#define _ALWAYS_INLINE_ inline
#endif
#endif

#ifndef _FORCE_INLINE_
#ifdef DEV_ENABLED
// Optimizes for development builds
#define _FORCE_INLINR_ inline
#else
// Optimizes for release
#define _FORCE_INLINE_ _ALWAYS_INLINE_
#endif
#endif

// Decide precision between float and double
#ifdef USE_DOUBLE
#define fp_type double
#else
#define fp_type float
#endif