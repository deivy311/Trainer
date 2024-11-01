#include <iostream>
#include <string>
#include <algorithm>  // For std::transform
#include <cctype>     // For std::tolower

// Define the Case enum class
enum class Case {
    SENSITIVE,
    INSENSITIVE
};

// Helper function to convert a string to lower case
std::string ToLower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

// The Find function with case-sensitive and case-insensitive search options
size_t Find(const std::string &source, 
            const std::string &search_string, 
            Case searchCase = Case::INSENSITIVE,
            size_t offset = 0) {
    
    // Handle case-insensitive search
    if (searchCase == Case::INSENSITIVE) {
        std::string lower_source = ToLower(source);             // Convert source string to lower case
        std::string lower_search_string = ToLower(search_string); // Convert search string to lower case
        
        // Use the find function on the lowercased strings
        return lower_source.find(lower_search_string, offset);
    }
    
    // Handle case-sensitive search (default behavior)
    return source.find(search_string, offset);
}

// Example usage
int main() {
    std::string source = "Hello World!";
    std::string search_string = "WORLD";

    // Case-insensitive search
    size_t pos = Find(source, search_string, Case::INSENSITIVE);
    if (pos != std::string::npos) {
        std::cout << "Case-insensitive match found at position: " << pos << std::endl;
    } else {
        std::cout << "No case-insensitive match found." << std::endl;
    }

    // Case-sensitive search
    pos = Find(source, search_string, Case::SENSITIVE);
    if (pos != std::string::npos) {
        std::cout << "Case-sensitive match found at position: " << pos << std::endl;
    } else {
        std::cout << "No case-sensitive match found." << std::endl;
    }

    return 0;
}
