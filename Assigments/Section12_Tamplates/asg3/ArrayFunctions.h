// ArrayFunctions.h
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <utility>  // For std::pair
#include <cstring>  // For std::strcmp
#include <string>  // For std::string


// 1. ArraySum Function Template
template <typename T, size_t Size>
T ArraySum(const T (&pArr)[Size]) {
    T sum = T();  // Default initialize to 0 or empty (for strings)
    for (size_t i = 0; i < Size; ++i) {
        sum += pArr[i];
    }
    return sum;
}


// Specialization of ArraySum for const char* arrays
template <size_t Size>
const char* ArraySum(const char* (&pArr)[Size]) {
    return "Sum not defined for const char*";
}


// Specialization of ArraySum for std::string arrays
template <size_t Size>
std::string ArraySum(const std::string (&pArr)[Size]) {
    std::string sum;
    for (size_t i = 0; i < Size; ++i) {
        sum += pArr[i];
    }
    return sum;
}



//----------------------------------------------------------------------

// 2. Max Function Template
template <typename T, size_t Size>
T Max(const T (&pArr)[Size]) {
    T maxVal = pArr[0];
    for (size_t i = 1; i < Size; ++i) {
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return maxVal;
}


// Specialization of Max for const char* arrays
template <size_t Size>
const char* Max(const char* (&pArr)[Size]) {
    const char* maxVal = pArr[0];
    for (size_t i = 1; i < Size; ++i) {
        if (std::strcmp(pArr[i], maxVal) > 0) {
            maxVal = pArr[i];
        }
    }
    return maxVal;
}


// Specialization of Max for std::string arrays
template <size_t Size>
std::string Max(const std::string (&pArr)[Size]) {
    std::string maxVal = pArr[0];
    for (size_t i = 1; i < Size; ++i) {
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return maxVal;
}


//----------------------------------------------------------------------


// 3. MinMax Function Template
template <typename T, size_t Size>
std::pair<T, T> MinMax(const T (&pArr)[Size]) {
    T minVal = pArr[0];
    T maxVal = pArr[0];
    for (size_t i = 1; i < Size; ++i) {
        if (pArr[i] < minVal) {
            minVal = pArr[i];
        }
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return std::make_pair(minVal, maxVal);
}



// Specialization of MinMax for const char* arrays
template <size_t Size>
std::pair<const char*, const char*> MinMax(const char* (&pArr)[Size]) {
    const char* minVal = pArr[0];
    const char* maxVal = pArr[0];
    for (size_t i = 1; i < Size; ++i) {
        if (std::strcmp(pArr[i], minVal) < 0) {
            minVal = pArr[i];
        }
        if (std::strcmp(pArr[i], maxVal) > 0) {
            maxVal = pArr[i];
        }
    }
    return std::make_pair(minVal, maxVal);
}


// Specialization of MinMax for std::string arrays
template <size_t Size>
std::pair<std::string, std::string> MinMax(const std::string (&pArr)[Size]) {
    std::string minVal = pArr[0];
    std::string maxVal = pArr[0];
    for (size_t i = 1; i < Size; ++i) {
        if (pArr[i] < minVal) {
            minVal = pArr[i];
        }
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return std::make_pair(minVal, maxVal);
}



#endif // ARRAY_FUNCTIONS_H









