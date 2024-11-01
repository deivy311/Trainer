#include <iostream>
#include <string>
#include <cctype>  // For toupper, tolower

// Function to convert a string to upper case
std::string ToUpper(const std::string &str) {
    std::string result;

    try {
        for (char ch : str) {
            result += std::toupper(static_cast<unsigned char>(ch));  // Convert each character to upper case
        }
    } catch (...) {
        return "";  // In case of any error, return an empty string
    }

    return result;
}

// Function to convert a string to lower case
std::string ToLower(const std::string &str) {
    std::string result;

    try {
        for (char ch : str) {
            result += std::tolower(static_cast<unsigned char>(ch));  // Convert each character to lower case
        }
    } catch (...) {
        return "";  // In case of any error, return an empty string
    }

    return result;
}

// Example usage
int main() {
    std::string text = "Hello, World!";
    
    std::string upper = ToUpper(text);
    std::string lower = ToLower(text);
    
    std::cout << "Original: " << text << std::endl;
    std::cout << "Uppercase: " << upper << std::endl;
    std::cout << "Lowercase: " << lower << std::endl;
    
    return 0;
}
