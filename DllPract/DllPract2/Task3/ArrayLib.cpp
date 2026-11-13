#include "ArrayLib.h"
#include "Checked.h"
#include <algorithm>
#include <limits>
int array_sum(const int* data, int size) {
    if (!valid_array(data,size)) return 0;
    long long sum = 0;
    for (int i=0; i<size; ++i) sum += data[i];
    return checked_int(sum);
}
int array_min(const int* data, int size) {
    if (!valid_array(data,size)) return 0;
    return *std::min_element(data,data+size);
}
int array_max(const int* data, int size) {
    if (!valid_array(data,size)) return 0;
    return *std::max_element(data,data+size);
}
double array_average(const int* data, int size) {
    if (!valid_array(data,size)) return std::numeric_limits<double>::quiet_NaN();
    long long sum = 0;
    for (int i=0; i<size; ++i) sum += data[i];
    return static_cast<double>(sum)/size;
}
int count_greater(const int* data, int size, int value) {
    if (!valid_array(data,size)) return 0;
    int count=0;
    for (int i=0; i<size; ++i) if (data[i]>value) ++count;
    return count;
}
