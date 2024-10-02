#include "convert.h"
#include <cctype>
#include <string>

// Source Files (.cpp): These contain the actual implementation 
// (the code that defines how the declared functions or classes work).:



// Function to convert string to uppercase
std::string ToUpper(const std::string &str) {
    std::string result;
    for (char ch : str) {
        result += std::toupper(static_cast<unsigned char>(ch));
    }
    return result;
}

// Function to convert string to lowercase
std::string ToLower(const std::string &str) {
    std::string result;
    for (char ch : str) {
        result += std::tolower(static_cast<unsigned char>(ch));
    }
    return result;
}
