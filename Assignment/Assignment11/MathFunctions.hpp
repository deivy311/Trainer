#ifndef MATH_FUNCTIONS_HPP
#define MATH_FUNCTIONS_HPP

#include <utility>  // for std::pair
#include <cstddef>  // for size_t

// 1. MathOperations class with basic math functions
class MathOperations {
public:
    // Template function for adding two elements
    template <typename T>
    static T Add(const T& x, const T& y);
};

// 2. ArrayOperations class with array-related functions
class ArrayOperations {
public:
    // Template function for summing the elements of an array
    template <typename T>
    static T ArraySum(const T* pArr, size_t arrSize);

    // Template function for finding the maximum element in an array
    template <typename T>
    static T Max(const T* pArr, size_t arrSize);

    // Template function for finding the minimum and maximum elements in an array
    template <typename T>
    static std::pair<T, T> MinMax(const T* pArr, size_t arrSize);
};

// 3. FactorialOperations class with recursive factorial function
class FactorialOperations {
public:
    // Template function for calculating factorial using recursion
    template <typename T>
    static T Factorial(T n);
};

#include "MathFunctions.cpp"  // Include the implementation

#endif // MATH_FUNCTIONS_HPP
