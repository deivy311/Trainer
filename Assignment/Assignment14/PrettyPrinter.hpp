#ifndef PRETTY_PRINTER_HPP
#define PRETTY_PRINTER_HPP

#include <iostream>
#include <vector>

// Generic PrettyPrinter class template
template <typename T>
class PrettyPrinter {
public:
    void Print(const T& data) const {
        std::cout << data << std::endl; // Default print: works for basic types like int, double, string, etc.
    }
};

// Partial specialization of PrettyPrinter::Print for std::vector<std::vector<int>>
template <>
void PrettyPrinter<std::vector<std::vector<int>>>::Print(const std::vector<std::vector<int>>& data) const {
    std::cout << "// Main vector (vector<vector<int>>)" << std::endl;
    std::cout << "{" << std::endl;

    for (const auto& vec : data) {
        std::cout << "    {";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "}," << std::endl;
    }

    std::cout << "}" << std::endl;
}

#endif // PRETTY_PRINTER_HPP
