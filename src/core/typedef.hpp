#pragma once

#ifndef _ALWAYS_INLINE_
#if defined(__GNUC__)   // GNU compiler
    #define _ALWAYS_INLINE_ __attribute__((always_inline)) inline
#elif defined(_MSC_VER) // MSVC compiler
    #define _ALWAYS_INLINE_ __forceinline
#else   // Clang compiler
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