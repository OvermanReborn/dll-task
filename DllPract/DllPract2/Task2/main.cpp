#include "MathLib.h"
#include <cerrno>
#include <cmath>
#include <iostream>
int main() {
    for (;;) {
        std::cout << "1 Add\n2 Subtract\n3 Multiply\n4 Divide\n0 Exit\nChoice: ";
        int choice;
        if (!(std::cin >> choice)) return 1;
        if (choice == 0) return 0;
        if (choice < 1 || choice > 4) { std::cerr << "Invalid choice\n"; continue; }
        if (choice == 4) {
            double a, b;
            std::cout << "Enter two numbers: ";
            if (!(std::cin >> a >> b)) return 1;
            double result = divide(a, b);
            if (std::isnan(result)) std::cerr << "Division by zero or invalid operands\n";
            else std::cout << "Result: " << result << '\n';
        } else {
            int a, b;
            std::cout << "Enter two integers: ";
            if (!(std::cin >> a >> b)) return 1;
            int result = choice == 1 ? add(a,b) : choice == 2 ? subtract(a,b) : multiply(a,b);
            if (errno) std::cerr << "Integer overflow\n";
            else std::cout << "Result: " << result << '\n';
        }
    }
}
