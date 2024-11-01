#include <iostream>
#include <functional>

// Calculator function that takes two integers and an operation
int Calculate(int a, int b, std::function<int(int, int)> op) {
    return op(a, b);
}

int main() {
    // Define operations as lambda expressions and store in std::function
    std::function<int(int, int)> addition = [](int a, int b) {
        return a + b;
    };

    std::function<int(int, int)> subtraction = [](int a, int b) {
        return a - b;
    };

    std::function<int(int, int)> multiplication = [](int a, int b) {
        return a * b;
    };

    std::function<int(int, int)> division = [](int a, int b) {
        return (b != 0) ? a / b : 0;  // Avoid division by zero
    };

    // Use std::bind to create a partially bound version of addition with a fixed first argument of 10
    auto add10 = std::bind(addition, 10, std::placeholders::_1);

    // Test the calculator with various operations
    int a = 12, b = 3;
    std::cout << "Addition (12 + 3): " << Calculate(a, b, addition) << "\n";
    std::cout << "Subtraction (12 - 3): " << Calculate(a, b, subtraction) << "\n";
    std::cout << "Multiplication (12 * 3): " << Calculate(a, b, multiplication) << "\n";
    std::cout << "Division (12 / 3): " << Calculate(a, b, division) << "\n";

    // Test the partially bound addition function (10 + b) with various values of b
    std::cout << "Add 10 + 5: " << add10(5) << "\n";
    std::cout << "Add 10 + 15: " << add10(15) << "\n";
    std::cout << "Add 10 + 20: " << add10(20) << "\n";

    return 0;
}
