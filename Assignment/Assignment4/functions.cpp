#include "functions.hpp"
#include <cctype> // for toupper and tolower
#include <stdexcept> // for exception handling

// Function to convert a string to uppercase
std::string ToUpper(const std::string &str) {
    std::string result;
    try {
        result.resize(str.size());
        for (size_t i = 0; i < str.size(); ++i) {
            result[i] = static_cast<char>(toupper(static_cast<unsigned char>(str[i])));
        }
    } catch (...) {
        return ""; // Return empty string in case of error
    }
    return result;
}

// Function to convert a string to lowercase
std::string ToLower(const std::string &str) {
    std::string result;
    try {
        result.resize(str.size());
        for (size_t i = 0; i < str.size(); ++i) {
            result[i] = static_cast<char>(tolower(static_cast<unsigned char>(str[i])));
        }
    } catch (...) {
        return ""; // Return empty string in case of error
    }
    return result;
}

// Function to add two integers and return the result through a reference parameter
void Add(int a, int b, int &result) {
    result = a + b;
}

// Recursive function to find the factorial of a number and return it through a reference parameter
void Factorial(int a, int &result) {
    if (a < 0) {
        result = 0; // Factorial is not defined for negative numbers
        return;
    }
    if (a == 0 || a == 1) {
        result = 1; // Base case
        return;
    }
    int temp = a; // Store the current value
    a--; // Decrease the value for recursion
    Factorial(a, result); // Recursive call
    result *= temp; // Multiply result with the current value
}

// Function to swap two integers through reference arguments
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
