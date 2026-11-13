#include "MathLib.h"
#include "Checked.h"
#include <cmath>
#include <limits>
int add(int a, int b) { errno = 0; return checked_int(static_cast<long long>(a) + b); }
int subtract(int a, int b) { errno = 0; return checked_int(static_cast<long long>(a) - b); }
int multiply(int a, int b) { errno = 0; return checked_int(static_cast<long long>(a) * b); }
double divide(double a, double b) {
    errno = 0;
    if (b == 0 || !std::isfinite(a) || !std::isfinite(b)) {
        errno = EDOM; return std::numeric_limits<double>::quiet_NaN();
    }
    return a / b;
}
