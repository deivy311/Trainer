#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <functional> // For std::function

// Calculate function declaration
int Calculate(int a, int b, std::function<int(int, int)> op);

// Operations declaration
extern std::function<int(int, int)> add;
extern std::function<int(int, int)> subtract;
extern std::function<int(int, int)> multiply;
extern std::function<int(int, int)> divide;

#endif // CALCULATOR_HPP
