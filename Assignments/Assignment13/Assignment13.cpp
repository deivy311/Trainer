#include "ArrayFunctions.h"
#include <iostream>

int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    const char* arrChar[] = {"apple", "orange", "banana", "pear"};
    std::string arrStr[] = {"apple", "orange", "banana", "pear"};

    std::cout << "ArraySum (int): " << ArraySum(arrInt) << std::endl;
    std::cout << "Max (int): " << Max(arrInt) << std::endl;

    std::cout << "ArraySum (const char*): " << ArraySum(arrChar) << std::endl;
    std::cout << "Max (const char*): " << Max(arrChar) << std::endl;

    std::cout << "ArraySum (std::string): " << ArraySum(arrStr) << std::endl;
    std::cout << "Max (std::string): " << Max(arrStr) << std::endl;

    auto minMaxInt = MinMax(arrInt);
    std::cout << "MinMax (int): (" << minMaxInt.first << ", " << minMaxInt.second << ")" << std::endl;

    auto minMaxChar = MinMax(arrChar);
    std::cout << "MinMax (const char*): (" << minMaxChar.first << ", " << minMaxChar.second << ")" << std::endl;

    auto minMaxStr = MinMax(arrStr);
    std::cout << "MinMax (std::string): (" << minMaxStr.first << ", " << minMaxStr.second << ")" << std::endl;

    return 0;
}
