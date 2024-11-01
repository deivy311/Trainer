#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <utility>
#include <vector>
#include <iterator>

// Operations class declaration
class Operations {
public:
    // Member function templates
    template <typename T>
    static T Max(const T& a, const T& b);

    // Functor to determine if one value is greater than another
    template <typename T>
    struct Greater {
        bool operator()(const T& a, const T& b) const;
    };

    // Functor to determine if one value is less than another
    template <typename T>
    struct Less {
        bool operator()(const T& a, const T& b) const;
    };

    // Member function to find min and max elements in a container
    template <typename Iterator>
    static std::pair<typename std::iterator_traits<Iterator>::value_type,
                     typename std::iterator_traits<Iterator>::value_type>
    MinMax(Iterator begin, Iterator end);
};

#endif // OPERATIONS_HPP
