#ifndef GENERAL_TEMPLATES_HPP
#define GENERAL_TEMPLATES_HPP

#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <stdexcept> // For std::out_of_range

// General template function for summing lengths of array elements
template <typename T, size_t N>
int ArraySum(T (&arr)[N]) {
    int sumLengths = 0;
    for (size_t i = 0; i < N; ++i) {
        sumLengths += arr[i].length(); // Assumes T has a length() method (like std::string)
    }
    return sumLengths;
}

// Specialization for char* to handle C-strings
template <size_t N>
int ArraySum(char* (&arr)[N]) {
    int sumLengths = 0;
    for (size_t i = 0; i < N; ++i) {
        sumLengths += std::strlen(arr[i]); // Assumes each element is a C-string
    }
    return sumLengths;
}

// General template function to find the maximum element in an array
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

// Specialization for char* to handle C-strings
template <size_t N>
char* Max(char* (&arr)[N]) {
    if (N == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }

    char* maxElem = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (std::strcmp(arr[i], maxElem) > 0) {
            maxElem = arr[i];
        }
    }
    return maxElem;
}

// General template function to find the minimum and maximum elements in an array
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

// Specialization for char* to handle C-strings
template <size_t N>
std::pair<char*, char*> MinMax(char* (&arr)[N]) {
    if (N == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }

    char* minElem = arr[0];
    char* maxElem = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (std::strcmp(arr[i], minElem) < 0) {
            minElem = arr[i];
        }
        if (std::strcmp(arr[i], maxElem) > 0) {
            maxElem = arr[i];
        }
    }
    return std::make_pair(minElem, maxElem);
}

#endif // GENERAL_TEMPLATES_HPP
