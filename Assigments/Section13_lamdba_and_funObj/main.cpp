#include <iostream>
#include <vector>


// 1. Max(T, T)

//Function Object
template <typename T>
struct MaxFunctor {
    T operator()(T a, T b) const {
        return (a > b) ? a : b;
    }
};

//Lambda Expression
auto Max = [](auto a, auto b) { return (a > b) ? a : b; };


/////////////////////////////////////////////////////////////////////////////////////////////

// 2. Greater(T, T)

//Function Object
template <typename T>
struct GreaterFunctor {
    bool operator()(T a, T b) const {
        return a > b;
    }
};

//Lambda Expression
auto Greater = [](auto a, auto b) { return a > b; };


/////////////////////////////////////////////////////////////////////////////////////////////

// 3. Less(T, T)

//Function Object
template <typename T>
struct LessFunctor {
    bool operator()(T a, T b) const {
        return a < b;
    }
};

//Lambda Expression
auto Less = [](auto a, auto b) { return a < b; };

/////////////////////////////////////////////////////////////////////////////////////////////

// 4. MinMax(ItrBegin, ItrEnd)

//Function Object
template <typename Iterator>
struct MinMaxFunctor {
    using T = typename std::iterator_traits<Iterator>::value_type;

    std::pair<T, T> operator()(Iterator ItrBegin, Iterator ItrEnd) const {
        auto min = *ItrBegin;
        auto max = *ItrBegin;
        for (auto it = ItrBegin; it != ItrEnd; ++it) {
            if (*it < min) min = *it;
            if (*it > max) max = *it;
        }
        return std::make_pair(min, max);
    }
};


//Lambda Expression
auto MinMax = [](auto ItrBegin, auto ItrEnd) {
    auto min = *ItrBegin;
    auto max = *ItrBegin;
    for (auto it = ItrBegin; it != ItrEnd; ++it) {
        if (*it < min) min = *it;
        if (*it > max) max = *it;
    }
    return std::make_pair(min, max);
};


/////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>

int main() {
    // Example usage of Max lambda
    auto max_result = Max(5, 10);
    std::cout << "Max(5, 10) = " << max_result << std::endl;

    // Example usage of Greater and Less lambdas
    std::cout << "Greater(10, 5) = " << Greater(10, 5) << std::endl;
    std::cout << "Less(5, 10) = " << Less(5, 10) << std::endl;

    // Example usage of MinMax lambda
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2};
    auto minmax_result = MinMax(vec.begin(), vec.end());
    std::cout << "MinMax of vec = (" << minmax_result.first << ", " << minmax_result.second << ")" << std::endl;

    return 0;
}


