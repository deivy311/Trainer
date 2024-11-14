#include <iostream>
#include "ArrayFunctions.h"

int main() {
    int intArr[] = {1, 3, 5, 7};
    const char* cstrArr[] = {"apple", "banana", "cherry"};
    std::string strArr[] = {"alpha", "beta", "gamma"};

    std::cout << "ArraySum(intArr): " << ArraySum(intArr) << "\n";
    std::cout << "Max(intArr): " << Max(intArr) << "\n";

    std::cout << "ArraySum(cstrArr): " << ArraySum(cstrArr) << "\n";
    std::cout << "Max(cstrArr): " << Max(cstrArr) << "\n";

    std::cout << "ArraySum(strArr): " << ArraySum(strArr) << "\n";
    std::cout << "Max(strArr): " << Max(strArr) << "\n";

    auto [minVal, maxVal] = MinMax(intArr);
    std::cout << "MinMax(intArr): Min = " << minVal << ", Max = " << maxVal << "\n";

    auto [minStr, maxStr] = MinMax(cstrArr);
    std::cout << "MinMax(cstrArr): Min = " << minStr << ", Max = " << maxStr << "\n";

    auto [minStdStr, maxStdStr] = MinMax(strArr);
    std::cout << "MinMax(strArr): Min = " << minStdStr << ", Max = " << maxStdStr << "\n";

    return 0;
}
