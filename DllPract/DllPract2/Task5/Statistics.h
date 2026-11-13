#pragma once
#include "Export.h"
extern "C" API int stats_sum(const int* data, int size);
extern "C" API double stats_average(const int* data, int size);
extern "C" API int stats_count_positive(const int* data, int size);
extern "C" API int stats_count_negative(const int* data, int size);
extern "C" API const char* stats_version();
