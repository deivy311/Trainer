// ArrayFunctions.h
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <cstring>
#include <string>
#include <utility>

// Primary template for general types
template<typename T, size_t N>
T ArraySum(const T (&arr)[N]) {
    T sum{};
    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
    }
    return sum;
}

template<typename T, size_t N>
T Max(const T (&arr)[N]) {
    T max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template<typename T, size_t N>
std::pair<T, T> MinMax(const T (&arr)[N]) {
    T min = arr[0], max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    return std::make_pair(min, max);
}

// Specialization for arrays of C-style strings (const char*)
template<size_t N>
const char* ArraySum(const char* (&arr)[N]) {
    // Just return the concatenation of strings or something meaningful for strings
    static char buffer[1024] = "";
    for (size_t i = 0; i < N; ++i) {
        strcat(buffer, arr[i]);
    }
    return buffer;
}

template<size_t N>
const char* Max(const char* (&arr)[N]) {
    const char* max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (strcmp(arr[i], max) > 0) {
            max = arr[i];
        }
    }
    return max;
}

template<size_t N>
std::pair<const char*, const char*> MinMax(const char* (&arr)[N]) {
    const char* min = arr[0], * max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (strcmp(arr[i], min) < 0) min = arr[i];
        if (strcmp(arr[i], max) > 0) max = arr[i];
    }
    return std::make_pair(min, max);
}

// Specialization for arrays of std::string
template<size_t N>
std::string ArraySum(const std::string (&arr)[N]) {
    std::string sum;
    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
    }
    return sum;
}

template<size_t N>
std::string Max(const std::string (&arr)[N]) {
    std::string max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template<size_t N>
std::pair<std::string, std::string> MinMax(const std::string (&arr)[N]) {
    std::string min = arr[0], max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    return std::make_pair(min, max);
}

#endif // ARRAY_FUNCTIONS_H

