#include <string>
#include "functions.h"


std::string ToLower(const std::string &str) {
    std::string text;
    for (char ch : str) {
        text += std::tolower(static_cast<unsigned char>(ch));
    }
    return text;
}


size_t Find(
    const std::string &source,
    const std::string &search_string,
    Case searchCase,
    size_t offset
) {
    if (searchCase == Case::INSENSITIVE) {
        // Convert to lowercase 
        std::string lower_source = ToLower(source);
        std::string lower_search_string = ToLower(search_string);

        return lower_source.find(lower_search_string, offset);
    } else {
        return source.find(search_string, offset);
    }
}