#include <iostream>
#include <vector>
#include "PrettyPrinter.hpp"

int main() {
    // Example of printing an integer
    PrettyPrinter<int> intPrinter;
    intPrinter.Print(42);

    // Example of printing a string
    PrettyPrinter<std::string> stringPrinter;
    stringPrinter.Print("Hello, World!");

    // Example of printing a vector<vector<int>>
    std::vector<std::vector<int>> nestedVector = {
        {1, 2, 3},
        {4, 5, 6}
    };

    PrettyPrinter<std::vector<std::vector<int>>> nestedVectorPrinter;
    nestedVectorPrinter.Print(nestedVector);

    return 0;
}
