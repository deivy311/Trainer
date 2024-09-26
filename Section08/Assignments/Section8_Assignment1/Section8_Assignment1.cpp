#include <iostream>
#include <string>
#include <cctype>  // For toupper and tolower

// Function to convert a string to uppercase
std::string ToUpper(const std::string &str) {
    std::string result;
    result.reserve(str.size());  // Reserve space for efficiency

    try {
        for (char ch : str) {
            result.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(ch))));
        }
    } catch (...) {
        return "";  // Return an empty string in case of error
    }

    return result;
}

// Function to convert a string to lowercase
std::string ToLower(const std::string &str) {
    std::string result;
    result.reserve(str.size());  // Reserve space for efficiency

    try {
        for (char ch : str) {
            result.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
        }
    } catch (...) {
        return "";  // Return an empty string in case of error
    }

    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);  // Read input with spaces

    std::string upperStr = ToUpper(input);
    std::string lowerStr = ToLower(input);

    std::cout << "Original String: " << input << std::endl;
    std::cout << "Uppercase String: " << upperStr << std::endl;
    std::cout << "Lowercase String: " << lowerStr << std::endl;

    return 0;
}

