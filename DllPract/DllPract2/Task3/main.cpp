#include "ArrayLib.h"
#include <iostream>
#include <vector>
#include <cerrno>
#include <cmath>
int main() {
    for (const std::vector<int>& data : std::vector<std::vector<int>>{{4,-2,7,10,1},{5},{-4,-8,-1},{0,0,0}}) {
        for (int x : data) std::cout << x << ' ';
        int n=static_cast<int>(data.size());
        std::cout << "| Sum: " << array_sum(data.data(),n)
          << " Min: " << array_min(data.data(),n) << " Max: " << array_max(data.data(),n)
          << " Average: " << array_average(data.data(),n)
          << " Greater than 3: " << count_greater(data.data(),n,3) << '\n';
    }
    array_min(nullptr, 1);
    std::cout << "nullptr rejected: " << (errno == EINVAL) << '\n';
    int value=5;
    double result=array_average(&value,0);
    std::cout << "Empty array rejected: " << (errno == EINVAL && std::isnan(result)) << '\n';
}
