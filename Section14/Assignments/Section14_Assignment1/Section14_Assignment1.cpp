#include <iostream>
#include <functional>

int Calculate(int a, int b, std::function<int(int, int)> op) {
    return op(a, b);
}

int main() {
    // Define operations as lambdas
    std::function<int(int, int)> add = [](int a, int b) { return a + b; };
    std::function<int(int, int)> subtract = [](int a, int b) { return a - b; };
    std::function<int(int, int)> multiply = [](int a, int b) { return a * b; };
    std::function<int(int, int)> divide = [](int a, int b) { return a / b; };  // assuming b != 0

    // Use Calculate function with each operation
    int a = 12, b = 3;
    std::cout << "Addition: " << Calculate(a, b, add) << std::endl;
    std::cout << "Subtraction: " << Calculate(a, b, subtract) << std::endl;
    std::cout << "Multiplication: " << Calculate(a, b, multiply) << std::endl;
    std::cout << "Division: " << Calculate(a, b, divide) << std::endl;

    // Bind an operation (fix 'a' at 10 for addition)
    auto addTen = std::bind(add, 10, std::placeholders::_1);

    // Test the bound function with various values for 'b'
    std::cout << "10 + 5 = " << addTen(5) << std::endl;
    std::cout << "10 + 20 = " << addTen(20) << std::endl;
    std::cout << "10 + 0 = " << addTen(0) << std::endl;

    return 0;
}
