#include <utility>  // For std::pair
#include <cstddef>  // For size_t

#include <iostream>
#include <vector>


// Function template for adding two elements
template <typename T>
T Add(const T &x, const T &y) {
    return x + y;
}

// Function template for summing elements in an array
template <typename T>
T ArraySum(const T *pArr, size_t arrSize) {
    T sum = T();  // Default initialize sum to handle different types
    for (size_t i = 0; i < arrSize; ++i) {
        sum += pArr[i];
    }
    return sum;
}

// Function template for finding the maximum element in an array
template <typename T>
T Max(const T *pArr, size_t arrSize) {
    T maxVal = pArr[0];  // Initialize max to the first element
    for (size_t i = 1; i < arrSize; ++i) {
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return maxVal;
}

// Function template for finding both the minimum and maximum elements in an array
template <typename T>
std::pair<T, T> MinMax(const T *pArr, size_t arrSize) {
    T minVal = pArr[0];
    T maxVal = pArr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (pArr[i] < minVal) {
            minVal = pArr[i];
        }
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return std::make_pair(minVal, maxVal);
}


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Add: " << Add(3, 5) << std::endl;
    std::cout << "ArraySum: " << ArraySum(arr, arrSize) << std::endl;
    std::cout << "Max: " << Max(arr, arrSize) << std::endl;

    auto minMax = MinMax(arr, arrSize);
    std::cout << "MinMax: (" << minMax.first << ", " << minMax.second << ")" << std::endl;

    return 0;
}