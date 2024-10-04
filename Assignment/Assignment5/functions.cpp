#include "functions.hpp"
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower

// Function to perform case insensitive search
size_t Find(
    const std::string &source,
    const std::string &search_string,
    Case searchCase,
    size_t offset
) {
    if (offset >= source.size()) {
        return std::string::npos; // Return npos if offset is out of bounds
    }

    // Adjusting the range of the source string based on the offset
    std::string::const_iterator start = source.begin() + offset;
    std::string::const_iterator end = source.end();

    // Case-sensitive search
    if (searchCase == Case::SENSITIVE) {
        return source.find(search_string, offset);
    } 
    
    // Case-insensitive search
    std::string source_lower(source.size(), ' ');
    std::string search_lower(search_string.size(), ' ');

    // Convert source and search string to lower case
    std::transform(start, end, source_lower.begin() + offset, [](unsigned char c) { return std::tolower(c); });
    std::transform(search_string.begin(), search_string.end(), search_lower.begin(), [](unsigned char c) { return std::tolower(c); });

    // Perform search on lower case strings
    std::string::size_type pos = source_lower.find(search_lower, offset);
    return pos;
}
