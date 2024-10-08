
#include "ArrayFunctions.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Array Sum: " << ArraySum(arr) << std::endl;
    std::cout << "Max Element: " << Max(arr) << std::endl;
    auto [min, max] = MinMax(arr);
    std::cout << "Min Element: " << min << " Max Element: " << max << std::endl;
    return 0;
}

