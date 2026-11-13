#include "Geometry.h"
#include <cmath>
#include <limits>
double rectangle_area(double width, double height) {
    if (!std::isfinite(width) || !std::isfinite(height) || width < 0 || height < 0)
        return std::numeric_limits<double>::quiet_NaN();
    return width*height;
}
