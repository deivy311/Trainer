#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <utility>    // For std::pair
#include <string>     // For std::string
#include <cstring>    // For strlen, strcmp
#include <iostream>

// General template for adding two elements
template <typename T>
T Add(const T& x, const T& y) {
    return x + y;
}

// General template for summing elements in an array (by reference)
template <typename T, size_t N>
T ArraySum(const T (&arr)[N]) {
    T sum = T();
    for (const auto& elem : arr) {
        sum += elem;
    }
    return sum;
}

// Specialization of ArraySum for const char* arrays
template <size_t N>
const char* ArraySum(const char* (&arr)[N]) {
    size_t totalLength = 0;
    for (const char* elem : arr) {
        totalLength += std::strlen(elem);
    }
    char* concatenated = new char[totalLength + 1];
    concatenated[0] = '\0';
    for (const char* elem : arr) {
        std::strcat(concatenated, elem);
    }
    return concatenated;
}

// Specialization of ArraySum for std::string arrays
template <size_t N>
std::string ArraySum(const std::string (&arr)[N]) {
    std::string sum;
    for (const auto& elem : arr) {
        sum += elem;
    }
    return sum;
}

// General template for finding the maximum element in an array (by reference)
template <typename T, size_t N>
T Max(const T (&arr)[N]) {
    T maxVal = arr[0];
    for (const auto& elem : arr) {
        if (elem > maxVal) {
            maxVal = elem;
        }
    }
    return maxVal;
}

// Specialization of Max for const char* arrays
template <size_t N>
const char* Max(const char* (&arr)[N]) {
    const char* maxStr = arr[0];
    for (const char* elem : arr) {
        if (std::strcmp(elem, maxStr) > 0) {
            maxStr = elem;
        }
    }
    return maxStr;
}

// Specialization of Max for std::string arrays
template <size_t N>
std::string Max(const std::string (&arr)[N]) {
    std::string maxStr = arr[0];
    for (const auto& elem : arr) {
        if (elem > maxStr) {
            maxStr = elem;
        }
    }
    return maxStr;
}

// General template for finding both the minimum and maximum elements in an array (by reference)
template <typename T, size_t N>
std::pair<T, T> MinMax(const T (&arr)[N]) {
    T minVal = arr[0];
    T maxVal = arr[0];
    for (const auto& elem : arr) {
        if (elem < minVal) minVal = elem;
        if (elem > maxVal) maxVal = elem;
    }
    return std::make_pair(minVal, maxVal);
}

// Specialization of MinMax for const char* arrays
template <size_t N>
std::pair<const char*, const char*> MinMax(const char* (&arr)[N]) {
    const char* minStr = arr[0];
    const char* maxStr = arr[0];
    for (const char* elem : arr) {
        if (std::strcmp(elem, minStr) < 0) minStr = elem;
        if (std::strcmp(elem, maxStr) > 0) maxStr = elem;
    }
    return std::make_pair(minStr, maxStr);
}

// Specialization of MinMax for std::string arrays
template <size_t N>
std::pair<std::string, std::string> MinMax(const std::string (&arr)[N]) {
    std::string minStr = arr[0];
    std::string maxStr = arr[0];
    for (const auto& elem : arr) {
        if (elem < minStr) minStr = elem;
        if (elem > maxStr) maxStr = elem;
    }
    return std::make_pair(minStr, maxStr);
}

#endif // ARRAY_FUNCTIONS_H
