#ifndef STRING_SPECIALIZATIONS_HPP
#define STRING_SPECIALIZATIONS_HPP

#include <iostream>
#include <string>
#include <utility>
#include <cstring>

// Specialization for arrays of const char* (C-strings)
template <>
int ArraySum(const char* const (&arr)[], size_t arrSize) {
    int sumLengths = 0;
    for (size_t i = 0; i < arrSize; ++i) {
        sumLengths += std::strlen(arr[i]);
    }
    return sumLengths;
}

template <>
const char* Max(const char* const (&arr)[], size_t arrSize) {
    if (arrSize == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }

    const char* maxElem = arr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (std::strcmp(arr[i], maxElem) > 0) {
            maxElem = arr[i];
        }
    }
    return maxElem;
}

template <>
std::pair<const char*, const char*> MinMax(const char* const (&arr)[], size_t arrSize) {
    if (arrSize == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }

    const char* minElem = arr[0];
    const char* maxElem = arr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (std::strcmp(arr[i], minElem) < 0) {
            minElem = arr[i];
        }
        if (std::strcmp(arr[i], maxElem) > 0) {
            maxElem = arr[i];
        }
    }
    return std::make_pair(minElem, maxElem);
}

// Specialization for arrays of std::string
template <>
int ArraySum(const std::string (&arr)[], size_t arrSize) {
    int sumLengths = 0;
    for (size_t i = 0; i < arrSize; ++i) {
        sumLengths += arr[i].length();
    }
    return sumLengths;
}

template <>
std::string Max(const std::string (&arr)[], size_t arrSize) {
    if (arrSize == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }

    std::string maxElem = arr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return maxElem;
}

template <>
std::pair<std::string, std::string> MinMax(const std::string (&arr)[], size_t arrSize) {
    if (arrSize == 0) {
        throw std::out_of_range("Array size must be greater than 0");
    }

    std::string minElem = arr[0];
    std::string maxElem = arr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (arr[i] < minElem) {
            minElem = arr[i];
        }
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return std::make_pair(minElem, maxElem);
}

#endif // STRING_SPECIALIZATIONS_HPP
