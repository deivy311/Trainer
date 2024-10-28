#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Lambda Expressions
auto max = [](auto a, auto b)
{ return (a > b ? a : b); };
auto greater = [](auto a, auto b)
{ return a > b; };
auto less = [](auto a, auto b)
{ return a < b; };

auto min_max = [](auto begin, auto end)
{
    auto min = *begin;
    auto max = *begin;

    for (auto it = begin; it != end; ++it)
    {
        if (*it < min)
        {
            min = *it;
        }
        if (*it > max)
        {
            max = *it;
        }
    }

    return std::make_pair(min, max);
};

// Equivalent Function Objects
template<typename T>
struct Max {
    T operator()(T a, T b) const {
        return (a > b) ? a : b;
    }
};

template<typename T>
struct Greater {
    bool operator()(T a, T b) const {
        return a > b;
    }
};

template<typename T>
struct Less {
    bool operator()(T a, T b) const {
        return a < b;
    }
};

template<typename Itr>
struct MinMax {
    using T = typename std::iterator_traits<Itr>::value_type;
    
    std::pair<T, T> operator()(Itr begin, Itr end) const {
        auto minElement = *begin;
        auto maxElement = *begin;
        for (auto it = begin; it != end; ++it) {
            if (*it < minElement) {
                minElement = *it;
            }
            if (*it > maxElement) {
                maxElement = *it;
            }
        }
        return std::make_pair(minElement, maxElement);
    }
};





int main()
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7};

    // Testing lambda expressions
    std::cout << "Testing Lambda Expressions:\n";
    std::cout << "Max of 6,4 is " << max(6, 4) << std::endl;
    std::cout << "Is 5 greater than 7: " <<  std::boolalpha << greater(5, 7) << std::endl;
    std::cout << "Is 4 less than 7: " <<  std::boolalpha<< less(4, 7) << std::endl;
    auto minMaxResult = min_max(data.begin(), data.end());
    std::cout << "Min and Max in data: (" << minMaxResult.first << ", " << minMaxResult.second << ")\n";
    
    //Testing Function Objects

    Max<int> maxObj;
    Greater<int> greaterObj;
    Less<int> lessObj;
    MinMax<std::vector<int>::iterator> minMaxObj;
    std::cout << "\nTesting Function Objects:\n";
    std::cout << "Max of 3 and 7: " << maxObj(3, 7) << "\n";
    std::cout << "Is 5 greater than 2: " << std::boolalpha << greaterObj(5, 2) << "\n";
    std::cout << "Is 3 less than 8: " << std::boolalpha << lessObj(3, 8) << "\n";
    auto minMaxObjResult = minMaxObj(data.begin(), data.end());
    std::cout << "Min and Max in data: (" << minMaxObjResult.first << ", " << minMaxObjResult.second << ")\n";
}