#include "Calculator.hpp"
#include <stdexcept> // For runtime_error
#include <iostream>  // For cout

// Calculate function definition
int Calculate(int a, int b, std::function<int(int, int)> op) {
    return op(a, b);
}

// Define lambdas for arithmetic operations
std::function<int(int, int)> add = [](int a, int b) {
    return a + b;
};

std::function<int(int, int)> subtract = [](int a, int b) {
    return a - b;
};

std::function<int(int, int)> multiply = [](int a, int b) {
    return a * b;
};

std::function<int(int, int)> divide = [](int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        throw std::runtime_error("Division by zero");
    }
};
