#include "MathLib.h"
#include <cerrno>
#include <iostream>
int main() {
    std::cout << "2 + 3 = " << add(2, 3) << '\n';
    int a, b;
    std::cout << "Enter two integers: ";
    if (!(std::cin >> a >> b)) { std::cerr << "Invalid input\n"; return 1; }
    int result = add(a, b);
    if (errno) { std::cerr << "Integer overflow\n"; return 1; }
    std::cout << a << " + " << b << " = " << result << '\n';
}
