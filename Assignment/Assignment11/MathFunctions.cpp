#include "MathFunctions.hpp"
#include <stdexcept>  // for std::out_of_range

// 1. MathOperations class implementation
template <typename T>
T MathOperations::Add(const T& x, const T& y) {
    return x + y;
}

// 2. ArrayOperations class implementation

// Template implementation for summing the elements of an array
template <typename T>
T ArrayOperations::ArraySum(const T* pArr, size_t arrSize) {
    T sum = 0;
    for (size_t i = 0; i < arrSize; ++i) {
        sum += pArr[i];
    }
    return sum;
}

// Template implementation for finding the maximum element in an array
template <typename T>
T ArrayOperations::Max(const T* pArr, size_t arrSize) {
    if (arrSize == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }
    T maxElem = pArr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (pArr[i] > maxElem) {
            maxElem = pArr[i];
        }
    }
    return maxElem;
}

// Template implementation for finding the minimum and maximum elements in an array
template <typename T>
std::pair<T, T> ArrayOperations::MinMax(const T* pArr, size_t arrSize) {
    if (arrSize == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }
    T minElem = pArr[0];
    T maxElem = pArr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (pArr[i] < minElem) {
            minElem = pArr[i];
        }
        if (pArr[i] > maxElem) {
            maxElem = pArr[i];
        }
    }
    return std::make_pair(minElem, maxElem);
}

// 3. FactorialOperations class implementation

// Template implementation for recursive factorial calculation
template <typename T>
T FactorialOperations::Factorial(T n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * FactorialOperations::Factorial(n - 1);
    }
}

// Explicit instantiation of templates for common types (int, double, etc.)
template int MathOperations::Add<int>(const int&, const int&);
template int ArrayOperations::ArraySum<int>(const int*, size_t);
template int ArrayOperations::Max<int>(const int*, size_t);
template std::pair<int, int> ArrayOperations::MinMax<int>(const int*, size_t);
template int FactorialOperations::Factorial<int>(int);

template double MathOperations::Add<double>(const double&, const double&);
template double ArrayOperations::ArraySum<double>(const double*, size_t);
template double ArrayOperations::Max<double>(const double*, size_t);
template std::pair<double, double> ArrayOperations::MinMax<double>(const double*, size_t);
template double FactorialOperations::Factorial<double>(double);
