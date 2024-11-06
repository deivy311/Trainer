#include <iostream>
#include <functional>
#include <vector>

int Calculate(int a, int b, std::function<int(int, int)> op)
{
    return op(a, b);
}

int main()
{
    std::function<int(int, int)> addition = [](int a, int b)
    { return a + b; };
    std::function<int(int, int)> subtraction = [](int a, int b)
    { return a - b; };
    std::function<int(int, int)> multiplication = [](int a, int b)
    { return a * b; };
    std::function<int(int, int)> division = [](int a, int b)
    { return b != 0 ? a / b : 0; };
    auto boundAddition = std::bind(addition, 10, std::placeholders::_1);

    int a = 12;
    int b = 3;
    std::cout << "Addition (12 + 3): " << Calculate(a, b, addition) << std::endl;
    std::cout << "Subtraction (12 - 3): " << Calculate(a, b, subtraction) << std::endl;
    std::cout << "Multiplication (12 * 3): " << Calculate(a, b, multiplication) << std::endl;
    std::cout << "Division (12 / 3): " << Calculate(a, b, division) << std::endl;
    std::cout << "boundAddition (10 + 1): " << boundAddition(1) << std::endl;
    std::cout << "boundAddition (10 + 5): " << boundAddition(5) << std::endl;
    std::cout << "boundAddition (10 + 10): " << boundAddition(10) << std::endl;
}
