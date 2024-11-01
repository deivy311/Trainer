#include <iostream>
#include <functional>
#include "Calculator.hpp"

int main() {
    int a = 12, b = 3;

    // Use Calculate function with different operations
    try {
        std::cout << "Addition of " << a << " and " << b << ": " << Calculate(a, b, add) << std::endl;
        std::cout << "Subtraction of " << a << " and " << b << ": " << Calculate(a, b, subtract) << std::endl;
        std::cout << "Multiplication of " << a << " and " << b << ": " << Calculate(a, b, multiply) << std::endl;
        std::cout << "Division of " << a << " and " << b << ": " << Calculate(a, b, divide) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Use std::bind to partially bind the addition operation
    auto boundAdd = std::bind(add, 10, std::placeholders::_1);

    // Test the partially bound addition function with various values for b
    std::cout << "Partially bound addition (a = 10, b = 5): " << boundAdd(5) << std::endl;
    std::cout << "Partially bound addition (a = 10, b = 20): " << boundAdd(20) << std::endl;
    std::cout << "Partially bound addition (a = 10, b = -3): " << boundAdd(-3) << std::endl;

    return 0;
}
