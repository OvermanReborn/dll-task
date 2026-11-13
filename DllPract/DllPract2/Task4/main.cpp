#include "SharedLibrary.h"
#include <iostream>
#include <cmath>
int main(int argc, char** argv) {
    try {
#ifdef _WIN32
        const char* path="./Geometry.dll";
#else
        const char* path="./libGeometry.so";
#endif
        SharedLibrary library(argc>1 ? argv[1] : path);
        using RectangleAreaFunction = double(*)(double,double);
        auto area=library.get<RectangleAreaFunction>(argc>2 ? argv[2] : "rectangle_area");
        double width, height;
        std::cout << "Enter width and height: ";
        if (!(std::cin >> width >> height)) { std::cerr << "Invalid input\n"; return 1; }
        double result=area(width,height);
        if (!std::isfinite(result)) { std::cerr << "Invalid dimensions or area overflow\n"; return 1; }
        std::cout << "Area: " << result << '\n';
    } catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
