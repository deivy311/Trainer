#include <iostream>
#include "MathFunctions.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    // Using MathOperations class
    std::cout << "Sum of two numbers: " << MathOperations::Add(5, 10) << std::endl;

    // Using ArrayOperations class
    std::cout << "Sum of array elements: " << ArrayOperations::ArraySum(arr, arrSize) << std::endl;
    std::cout << "Max element in array: " << ArrayOperations::Max(arr, arrSize) << std::endl;

    auto minMax = ArrayOperations::MinMax(arr, arrSize);
    std::cout << "Min element: " << minMax.first << ", Max element: " << minMax.second << std::endl;

    // Using FactorialOperations class
    std::cout << "Factorial of 5: " << FactorialOperations::Factorial(5) << std::endl;

    return 0;
}
