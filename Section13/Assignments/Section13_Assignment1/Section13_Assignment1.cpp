#include <iostream>
#include <utility> // For std::pair

// Template for Add function
template<typename T>
T Add(T x, T y) {
    return x + y;
}

// Template for ArraySum function
template<typename T>
T ArraySum(const T* pArr, size_t arrSize) {
    T sum{};
    for (size_t i = 0; i < arrSize; ++i) {
        sum += pArr[i];
    }
    return sum;
}

// Template for Max function
template<typename T>
T Max(const T* pArr, size_t arrSize) {
    T maxVal = pArr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return maxVal;
}

// Template for MinMax function
template<typename T>
std::pair<T, T> MinMax(const T* pArr, size_t arrSize) {
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
    int arr[]{ 3, 1, 9, 7 };
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    // Add function
    std::cout << "Add: " << Add(3, 7) << std::endl;

    // ArraySum function
    std::cout << "ArraySum: " << ArraySum(arr, arrSize) << std::endl;

    // Max function
    std::cout << "Max: " << Max(arr, arrSize) << std::endl;

    // MinMax function
    auto [minVal, maxVal] = MinMax(arr, arrSize);
    std::cout << "Min: " << minVal << ", Max: " << maxVal << std::endl;

    return 0;
}
