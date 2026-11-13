#include "SharedLibrary.h"
#include <iostream>
int main(int argc, char** argv) {
    try {
#ifdef _WIN32
        const char* path="./Statistics.dll";
#else
        const char* path="./libStatistics.so";
#endif
        SharedLibrary library(argc>1 ? argv[1] : path);
        using IntFunction=int(*)(const int*,int);
        using AverageFunction=double(*)(const int*,int);
        using VersionFunction=const char*(*)();
        auto sum=library.get<IntFunction>("stats_sum");
        auto average=library.get<AverageFunction>("stats_average");
        auto positive=library.get<IntFunction>("stats_count_positive");
        auto negative=library.get<IntFunction>("stats_count_negative");
        auto version=library.get<VersionFunction>("stats_version");
        const int values[]={12,-4,0,7,-9,15,3,-1,8,0};
        const int n=sizeof(values)/sizeof(values[0]);
        std::cout << "Array: ";
        for(int x:values) std::cout << x << ' ';
        std::cout << "\nSum: " << sum(values,n) << "\nAverage: " << average(values,n)
          << "\nPositive: " << positive(values,n) << "\nNegative: " << negative(values,n)
          << "\nVersion: " << version() << '\n';
    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
