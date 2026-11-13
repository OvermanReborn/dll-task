#include "Statistics.h"
#include "Checked.h"
#include <limits>
int stats_sum(const int* data, int size) {
    if (!valid_array(data,size)) return 0;
    long long sum=0;
    for(int i=0;i<size;++i) sum+=data[i];
    return checked_int(sum);
}
double stats_average(const int* data, int size) {
    if (!valid_array(data,size)) return std::numeric_limits<double>::quiet_NaN();
    long long sum=0;
    for(int i=0;i<size;++i) sum+=data[i];
    return static_cast<double>(sum)/size;
}
int stats_count_positive(const int* data, int size) {
    if (!valid_array(data,size)) return 0;
    int n=0; for(int i=0;i<size;++i) if(data[i]>0) ++n; return n;
}
int stats_count_negative(const int* data, int size) {
    if (!valid_array(data,size)) return 0;
    int n=0; for(int i=0;i<size;++i) if(data[i]<0) ++n; return n;
}
const char* stats_version() { return "Statistics DLL version 1.0"; }
