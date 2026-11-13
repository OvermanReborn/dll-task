#pragma once

#if defined(_WIN32)
    #if defined(MATHLIB_EXPORTS) || defined(ARRAYLIB_EXPORTS) || \
        defined(GEOMETRY_EXPORTS) || defined(STATISTICS_EXPORTS)
        #define API __declspec(dllexport)
    #else
        #define API __declspec(dllimport)
    #endif
#else
    #define API __attribute__((visibility("default")))
#endif
