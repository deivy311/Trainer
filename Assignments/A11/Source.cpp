#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// Lambda Expressions
auto MaxL = [](auto a, auto b)
{ return (a > b) ? a : b; };
auto IsGreaterL = [](auto a, auto b)
{ return a > b; };
auto IsLessL = [](auto a, auto b)
{ return a < b; };
auto MinMaxL = [](auto begin, auto end)
{
    auto min = *std::min_element(begin, end);
    auto max = *std::max_element(begin, end);
    return std::make_pair(min, max);
};

// Function Objects
template <typename T>
struct MaxValue
{
    T operator()(T a, T b) const { return (a > b) ? a : b; }
};

template <typename T>
struct IsGreater
{
    bool operator()(T a, T b) const { return a > b; }
};

template <typename T>
struct IsLess
{
    bool operator()(T a, T b) const { return a < b; }
};

struct MinMax
{
    template <typename Iterator>
    std::pair<typename Iterator::value_type, typename Iterator::value_type>
    operator()(Iterator begin, Iterator end) const
    {
        auto min = *std::min_element(begin, end);
        auto max = *std::max_element(begin, end);
        return std::make_pair(min, max);
    }
};

int main()
{
    int x = 7, y = 5;
    std::vector<int> arr = {3, 5, 1, 4, 9, 2};
    std::cout << "---------------Lambda Objects----------------" << std::endl;
    std::cout << "MaxL(7, 5): " << MaxL(x, y) << std::endl;
    std::cout << "IsGreaterL(7, 5): " << IsGreaterL(x, y) << std::endl;
    std::cout << "IsLessLambda(7, 5): " << IsLessL(x, y) << std::endl;
    auto minmaxL = MinMaxL(arr.begin(), arr.end());
    std::cout << "inMaxL {3, 5, 1, 4, 9, 2}: Min = " << minmaxL.first << ", Max = " << minmaxL.second << std::endl;

    MaxValue<int> maxValueObj;
    IsGreater<int> isGreaterObj;
    IsLess<int> isLessObj;
    MinMax MinMaxObj;

    std::cout << "---------------Function Objects----------------" << std::endl;
    std::cout << "MaxValue (Functor): " << maxValueObj(x, y) << std::endl;
    std::cout << "IsGreater (Functor): " << isGreaterObj(x, y) << std::endl;
    std::cout << "IsLess (Functor): " << isLessObj(x, y) << std::endl;
    auto minmaxFun = MinMaxObj(arr.begin(), arr.end());
    std::cout << "MinMax (Functor): Min = " << minmaxFun.first << ", Max = " << minmaxFun.second << std::endl;

    return 0;
}
