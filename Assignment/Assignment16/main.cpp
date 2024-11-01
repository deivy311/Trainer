#include <iostream>
#include <vector>
#include "Operations.hpp"

int main() {
    // Testing Max function
    int a = 15, b = 42;
    std::cout << "Max of " << a << " and " << b << " is: " << Operations::Max(a, b) << std::endl;

    // Using Greater functor
    Operations::Greater<int> greaterFunctor;
    std::cout << "Is " << a << " greater than " << b << "? " << std::boolalpha << greaterFunctor(a, b) << std::endl;

    // Using Less functor
    Operations::Less<int> lessFunctor;
    std::cout << "Is " << a << " less than " << b << "? " << std::boolalpha << lessFunctor(a, b) << std::endl;

    // Testing MinMax function
    std::vector<int> numbers = {7, 3, 9, 1, 6, 4};
    auto [minVal, maxVal] = Operations::MinMax(numbers.begin(), numbers.end());
    std::cout << "Min value: " << minVal << ", Max value: " << maxVal << std::endl;

    return 0;
}
