#include "Operations.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

// Implementation of Max function
template <typename T>
T Operations::Max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Implementation of Greater functor
template <typename T>
bool Operations::Greater<T>::operator()(const T& a, const T& b) const {
    return a > b;
}

// Implementation of Less functor
template <typename T>
bool Operations::Less<T>::operator()(const T& a, const T& b) const {
    return a < b;
}

// Implementation of MinMax function
template <typename Iterator>
std::pair<typename std::iterator_traits<Iterator>::value_type,
          typename std::iterator_traits<Iterator>::value_type>
Operations::MinMax(Iterator begin, Iterator end) {
    if (begin == end) {
        throw std::runtime_error("Empty range provided.");
    }
    auto result = std::minmax_element(begin, end);
    return { *result.first, *result.second };
}

// Explicit template instantiation
template int Operations::Max<int>(const int&, const int&);
template bool Operations::Greater<int>::operator()(const int&, const int&) const;
template bool Operations::Less<int>::operator()(const int&, const int&) const;
template std::pair<int, int> Operations::MinMax<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);

