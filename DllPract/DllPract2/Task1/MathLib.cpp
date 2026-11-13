#include "MathLib.h"
#include "Checked.h"
int add(int a, int b) { errno = 0; return checked_int(static_cast<long long>(a) + b); }
