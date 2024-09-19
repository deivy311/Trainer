#include <iostream>
#include <string>
#include <algorithm> // For std::transform, std::tolower


////////////////////////////////////////////////////////////////////////////

enum class Case { SENSITIVE, INSENSITIVE };


////////////////////////////////////////////////////////////////////////////
// convert a string to lowercase
std::string ToLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}


////////////////////////////////////////////////////////////////////////////
//The function should return the position of the first occurrence of the substring.

size_t Find(
    const std::string& source,               // Source string to be searched
    const std::string& search_string,        // The string to search for
    Case searchCase = Case::INSENSITIVE,     // Choose case-sensitive/insensitive search
    size_t offset = 0) {                     // Start the search from this offset
    
    // Implementation
    if (searchCase == Case::INSENSITIVE) {
        // Convert both source and search_string to lowercase for case-insensitive search
        std::string lower_source = ToLower(source);
        std::string lower_search_string = ToLower(search_string);

        // Perform the search and return the position of the first character of the substring
        // else return std::string::npos if not found
        return lower_source.find(lower_search_string, offset);
    } else {
        // Perform case-sensitive search and return the position of the first character of the substring
        // else return std::string::npos if not found
        return source.find(search_string, offset);
    }
}

////////////////////////////////////////////////////////////////////////////
int main() {
    std::string source = "Fatmah, Rashed!";
    std::string search_string = "RASHED";

    // Perform a case-insensitive search
    size_t pos_insensitive = Find(source, search_string, Case::INSENSITIVE);
    if (pos_insensitive != std::string::npos) {
        std::cout << "Found (case-insensitive) at position: " << pos_insensitive << std::endl;
    } else {
        std::cout << "Not found (case-insensitive)." << std::endl;
    }

    // Perform a case-sensitive search
    size_t pos_sensitive = Find(source, search_string, Case::SENSITIVE);
    if (pos_sensitive != std::string::npos) {
        std::cout << "Found (case-sensitive) at position: " << pos_sensitive << std::endl;
    } else {
        std::cout << "Not found (case-sensitive)." << std::endl;
    }

    return 0;
}
