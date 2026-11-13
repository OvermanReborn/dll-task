#pragma once
#include "Export.h"
extern "C" API int array_sum(const int* data, int size);
extern "C" API int array_min(const int* data, int size);
extern "C" API int array_max(const int* data, int size);
extern "C" API double array_average(const int* data, int size);
extern "C" API int count_greater(const int* data, int size, int value);
