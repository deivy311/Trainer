#include "GeneralTemplates.hpp"
#include <iostream>
#include <string>

int main() {
    // Example using std::string array
    std::string strArr[] = {"apple", "orange", "banana"};
    size_t strArrSize = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "String Array Sum: " << ArraySum(strArr) << std::endl;
    std::cout << "Max String: " << Max(strArr) << std::endl;

    auto [minStr, maxStr] = MinMax(strArr);
    std::cout << "Min String: " << minStr << ", Max String: " << maxStr << std::endl;

    // Example using char* array (C-strings)
    char* cstrArr[] = {"apple", "orange", "banana"};
    size_t cstrArrSize = sizeof(cstrArr) / sizeof(cstrArr[0]);

    std::cout << "C-String Array Sum: " << ArraySum(cstrArr) << std::endl;
    std::cout << "Max C-String: " << Max(cstrArr) << std::endl;

    auto [minCStr, maxCStr] = MinMax(cstrArr);
    std::cout << "Min C-String: " << minCStr << ", Max C-String: " << maxCStr << std::endl;

    return 0;
}
