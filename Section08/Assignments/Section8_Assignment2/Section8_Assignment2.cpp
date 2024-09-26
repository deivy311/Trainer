#include <iostream>
#include <string>
#include <algorithm>  // For std::transform

// Enum for case-sensitive or case-insensitive search
enum class Case {
    SENSITIVE,   // Case-sensitive search
    INSENSITIVE  // Case-insensitive search
};

// Function to convert a string to lowercase for case-insensitive comparison
std::string ToLower(const std::string& str) {
    std::string lowerStr;
    lowerStr.reserve(str.size());
    
    // Convert each character to lowercase
    std::transform(str.begin(), str.end(), std::back_inserter(lowerStr), [](unsigned char c) {
        return std::tolower(c);
    });
    
    return lowerStr;
}

// Function to find a substring with case-sensitive or case-insensitive search
size_t Find(
    const std::string& source,         // Source string to be searched
    const std::string& search_string,  // The string to search for
    Case searchCase = Case::INSENSITIVE, // Case sensitivity selection
    size_t offset = 0                  // Start search from this offset
) {
    // Check if the search is case-sensitive or case-insensitive
    if (searchCase == Case::INSENSITIVE) {
        // Convert both the source string and search string to lowercase for case-insensitive comparison
        std::string lowerSource = ToLower(source);
        std::string lowerSearchString = ToLower(search_string);
        
        // Perform a case-insensitive search using the modified lowercase strings
        return lowerSource.find(lowerSearchString, offset);
    }
    
    // For case-sensitive search, directly use std::string::find
    return source.find(search_string, offset);
}

int main() {
    std::string source = "Hello World, AI CV ADASI";
    std::string searchString;
    
    std::cout << "Enter a string to search for: ";
    std::getline(std::cin, searchString);
    
    // Perform case-insensitive search
    size_t caseInsensitivePos = Find(source, searchString, Case::INSENSITIVE);
    if (caseInsensitivePos != std::string::npos) {
        std::cout << "Case-insensitive search: Found at position " << caseInsensitivePos << std::endl;
    } else {
        std::cout << "Case-insensitive search: Not found" << std::endl;
    }
    
    // Perform case-sensitive search
    size_t caseSensitivePos = Find(source, searchString, Case::SENSITIVE);
    if (caseSensitivePos != std::string::npos) {
        std::cout << "Case-sensitive search: Found at position " << caseSensitivePos << std::endl;
    } else {
        std::cout << "Case-sensitive search: Not found" << std::endl;
    }
    
    return 0;
}
