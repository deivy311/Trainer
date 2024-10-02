#include "search_util.h"
#include <cctype>

// Helper function to convert a string to lowercase
std::string ToLower(const std::string &str) {
    std::string result;
    for (char ch : str) {
        result += std::tolower(static_cast<unsigned char>(ch));
    }
    return result;
}

// Find function with case-sensitive and case-insensitive options
size_t Find(const std::string &source, 
            const std::string &search_string, 
            Case searchCase, 
            size_t offset) {
    
    // Check if case-insensitive search is selected
    if (searchCase == Case::INSENSITIVE) {
        // Convert both the source and search_string to lowercase
        std::string lower_source = ToLower(source);
        std::string lower_search_string = ToLower(search_string);
        // Use std::string::find on the converted strings
        return lower_source.find(lower_search_string, offset);
    }
    
    // If case-sensitive search is selected, perform a standard find
    return source.find(search_string, offset);
}
