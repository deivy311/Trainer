#include <iostream>
#include "StringSpecializations.hpp"

int main() {
    // Array of C-strings (const char*)
    const char* cStringArr[] = {"apple", "orange", "banana", "grape"};
    size_t cStringArrSize = sizeof(cStringArr) / sizeof(cStringArr[0]);

    std::cout << "Sum of lengths of C-string array elements: " << ArraySum(cStringArr, cStringArrSize) << std::endl;
    std::cout << "Max element in C-string array: " << Max(cStringArr, cStringArrSize) << std::endl;

    auto minMaxCString = MinMax(cStringArr, cStringArrSize);
    std::cout << "Min element: " << minMaxCString.first << ", Max element: " << minMaxCString.second << std::endl;

    // Array of std::string
    std::string stringArr[] = {"cat", "dog", "elephant", "bear"};
    size_t stringArrSize = sizeof(stringArr) / sizeof(stringArr[0]);

    std::cout << "Sum of lengths of std::string array elements: " << ArraySum(stringArr, stringArrSize) << std::endl;
    std::cout << "Max element in std::string array: " << Max(stringArr, stringArrSize) << std::endl;

    auto minMaxString = MinMax(stringArr, stringArrSize);
    std::cout << "Min element: " << minMaxString.first << ", Max element: " << minMaxString.second << std::endl;

    return 0;
}