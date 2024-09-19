#include <iostream>
#include <string>
#include <cctype> // For toupper and tolower

// Function to convert a string to uppercase
std::string ToUpper(const std::string &str) {
    std::string result;
    for (char ch : str) {
        // Check if conversion is possible
        if (std::isprint(static_cast<unsigned char>(ch))) { // Checks if the character is printable and has a values
            result += std::toupper(static_cast<unsigned char>(ch)); // Convert to uppercase
        } else {
            return ""; // Return empty string if the character is not printable
        }
    }
    return result; // Return the converted string
}


// Function to convert a string to lower
std::string ToLower(const std::string &str) {
    std::string result;
    for (char ch : str) {
        // Check if conversion is possible
        if (std::isprint(static_cast<unsigned char>(ch))) { // Checks if the character is printable and has a values
            result += std::tolower(static_cast<unsigned char>(ch)); // Convert to uppercase
        } else {
            return ""; // Return empty string if the character is not printable
        }
    }
    return result; // Return the converted string
}



///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    std::string example = "Hi, this is for testing!";
    std::string upper = ToUpper(example);
    std::string lower = ToLower(example);

    // Print results
    std::cout << "Example - original Size: " << example << std::endl;
    std::cout << "Example in Uppercase: " << upper << std::endl;
    std::cout << "Example in Lowercase: " << lower << std::endl;

    return 0;
}

