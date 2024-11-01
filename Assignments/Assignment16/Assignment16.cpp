#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// Lambda expressions
auto maxLambda = [](auto a, auto b) {
    return (a > b) ? a : b;
};

auto greaterLambda = [](auto a, auto b) {
    return a > b;
};

auto lessLambda = [](auto a, auto b) {
    return a < b;
};

auto minMaxLambda = [](auto begin, auto end) {
    auto min = *begin;
    auto max = *begin;
    for (auto itr = begin; itr != end; ++itr) {
        if (*itr < min) min = *itr;
        if (*itr > max) max = *itr;
    }
    return std::make_pair(min, max);
};

// Equivalent function objects
template <typename T>
struct MaxFunctor {
    T operator()(T a, T b) const {
        return (a > b) ? a : b;
    }
};

template <typename T>
struct GreaterFunctor {
    bool operator()(T a, T b) const {
        return a > b;
    }
};

template <typename T>
struct LessFunctor {
    bool operator()(T a, T b) const {
        return a < b;
    }
};

template <typename Iterator>
struct MinMaxFunctor {
    std::pair<typename Iterator::value_type, typename Iterator::value_type> operator()(Iterator begin, Iterator end) const {
        auto min = *begin;
        auto max = *begin;
        for (auto itr = begin; itr != end; ++itr) {
            if (*itr < min) min = *itr;
            if (*itr > max) max = *itr;
        }
        return std::make_pair(min, max);
    }
};

int main() {
    int a = 10, b = 20;
    std::vector<int> nums = {1, 3, 5, 2, 9, 4};

    // Using Lambda Expressions
    std::cout << "Using Lambda Expressions:\n";
    std::cout << "Max: " << maxLambda(a, b) << "\n";
    std::cout << "Greater: " << std::boolalpha << greaterLambda(a, b) << "\n";
    std::cout << "Less: " << std::boolalpha << lessLambda(a, b) << "\n";
    
    auto minMaxValLambda = minMaxLambda(nums.begin(), nums.end());
    std::cout << "MinMax: (" << minMaxValLambda.first << ", " << minMaxValLambda.second << ")\n\n";

    // Using Function Objects
    MaxFunctor<int> maxFunctor;
    GreaterFunctor<int> greaterFunctor;
    LessFunctor<int> lessFunctor;
    MinMaxFunctor<std::vector<int>::iterator> minMaxFunctor;

    std::cout << "Using Function Objects:\n";
    std::cout << "Max: " << maxFunctor(a, b) << "\n";
    std::cout << "Greater: " << std::boolalpha << greaterFunctor(a, b) << "\n";
    std::cout << "Less: " << std::boolalpha << lessFunctor(a, b) << "\n";
    
    auto minMaxValFunctor = minMaxFunctor(nums.begin(), nums.end());
    std::cout << "MinMax: (" << minMaxValFunctor.first << ", " << minMaxValFunctor.second << ")\n";

    return 0;
}
