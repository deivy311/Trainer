#ifndef GENERAL_TEMPLATES_HPP
#define GENERAL_TEMPLATES_HPP

#include <iostream>
#include <string>
#include <utility>
#include <cstring> // For strlen()

template <typename T, size_t N>
int ArraySum(T (&arr)[N]) {
    int sumLengths = 0;
    for (size_t i = 0; i < N; ++i) {
        if constexpr (std::is_same<T, const char*>::value) {
            sumLengths += std::strlen(arr[i]);
        } else {
            sumLengths += arr[i].length(); // Assumes T has a length() method (like std::string)
        }
    }
    return sumLengths;
}

template <typename T, size_t N>
T Max(T (&arr)[N]) {
    if (N == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }
    T maxElem = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return maxElem;
}

template <typename T, size_t N>
std::pair<T, T> MinMax(T (&arr)[N]) {
    if (N == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }
    T minElem = arr[0];
    T maxElem = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] < minElem) {
            minElem = arr[i];
        }
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return std::make_pair(minElem, maxElem);
}

#endif // GENERAL_TEMPLATES_HPP
