#include <iostream>
#include <utility>  // For std::pair

// 1. Add Function Template
template <typename T>
T Add(const T& x, const T& y) {
    return x + y;
}

//##################################################

// 2. ArraySum Function Template
template <typename T>
T ArraySum(const T* pArr, size_t arrSize) {
    T sum = T();  // Default initialize (e.g., 0 for numbers)
    for (size_t i = 0; i < arrSize; ++i) {
        sum += pArr[i];
    }
    return sum;
}

//##################################################

// 3. Max Function Template
template <typename T>
T Max(const T* pArr, size_t arrSize) {
    T maxVal = pArr[0];
    for (size_t i = 1; i < arrSize; ++i) {
        if (pArr[i] > maxVal) {
            maxVal = pArr[i];
        }
    }
    return maxVal;
}

//##################################################

// 4. MinMax Function Template
template <typename T>
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


//####################################################################################################




int main() {
    // Test data for int
    int intArr[] = {1, 3, 5, 7, 9};
    size_t intArrSize = sizeof(intArr) / sizeof(intArr[0]);

    // Test data for double
    double doubleArr[] = {2.5, 3.5, 5.0, 8.5, 1.2};
    size_t doubleArrSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    //#####################

    // Test Add function
    std::cout << "(( Test Add function )) " << std::endl;
    std::cout << "Add(10, 20) Int: " << Add(10, 20) << std::endl;
    std::cout << "Add(1.5, 2.5) Double: " << Add(1.5, 2.5) << std::endl;
    std::cout << "((-----------------------------)) "  << std::endl;

    //#####################

    // Test ArraySum function
    std::cout << "(( Test ArraySum function )) "  << std::endl;
    std::cout << "ArraySum(intArr): " << ArraySum(intArr, intArrSize) << std::endl;
    std::cout << "ArraySum(doubleArr): " << ArraySum(doubleArr, doubleArrSize) << std::endl;
    std::cout << "((-----------------------------)) "  << std::endl;

    //#####################

    // Test Max function
    std::cout << "(( Test Max function )) "  << std::endl;
    std::cout << "Max(intArr): " << Max(intArr, intArrSize) << std::endl;
    std::cout << "Max(doubleArr): " << Max(doubleArr, doubleArrSize) << std::endl;
    std::cout << "((-----------------------------)) "  << std::endl;

    // Test MinMax function
    std::cout << "(( Test MinMax function )) "  << std::endl;
    std::pair<int, int> intMinMax = MinMax(intArr, intArrSize);
    std::cout << "MinMax(intArr): Min = " << intMinMax.first << ", Max = " << intMinMax.second << std::endl;

    std::pair<double, double> doubleMinMax = MinMax(doubleArr, doubleArrSize);
    std::cout << "MinMax(doubleArr): Min = " << doubleMinMax.first << ", Max = " << doubleMinMax.second << std::endl;

    return 0;
    std::cout << "((-----------------------------)) " << std::endl;

}
