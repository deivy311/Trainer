#include <iostream>
#include <functional>
#include <stdexcept>  


int Calculate(int a, int b, std::function<int(int, int)> op)
{
    return op(a, b); // perform the operation and return the result
}

std::function<int(int, int)> add = [](int a, int b)
{ return a + b; };
std::function<int(int, int)> subtract = [](int a, int b)
{ return a - b; };
std::function<int(int, int)> multiply = [](int a, int b)
{ return a * b; };
std::function<int(int, int)> divide = [](int a, int b)
{
    if (b == 0)
        throw std::runtime_error("Division by zero");
    return a / b;
};

auto add_with_10 = std::bind(add, 10, std::placeholders::_1);

int main()
{
    int a = 12;
    int b = 3;

    // Test each operation with calculate function
    std::cout << "Addition (12+3): " << Calculate(a, b, add) << std::endl;
    std::cout << "Subtraction (12-3): " << Calculate(a, b, subtract) << std::endl;
    std::cout << "Multiplication (12*3): " << Calculate(a, b, multiply) << std::endl;
    try
    {
        std::cout << "Division (12 / 3): " << Calculate(a, b, divide) << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test the partially bound addition function with different value of b
    std::cout << "Partial Addition with a=10 and b=5: " << add_with_10(5) << std::endl;

    return 0;
}