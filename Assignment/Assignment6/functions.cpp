#include "functions.hpp"
#include <algorithm>
#include <cctype>

// Helper function to convert a string to lowercase (for case-insensitive search)
std::string ToLower(const std::string &str) {
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lower_str;
}

// Function to find all occurrences of a search string in a target string
std::vector<int> FindAll(const std::string &target, const std::string &search_string, Case searchCase, size_t offset) {
    std::vector<int> indices;

    // Validate inputs
    if (search_string.empty() || target.empty() || offset >= target.size()) {
        return indices;  // Return empty vector if invalid inputs
    }

    std::string mod_target = target;
    std::string mod_search_string = search_string;

    // Handle case insensitivity
    if (searchCase == Case::INSENSITIVE) {
        mod_target = ToLower(target);
        mod_search_string = ToLower(search_string);
    }

    size_t pos = mod_target.find(mod_search_string, offset);  // Find first occurrence
    while (pos != std::string::npos) {
        indices.push_back(static_cast<int>(pos));  // Store the index
        pos = mod_target.find(mod_search_string, pos + 1);  // Find next occurrence
    }

    return indices;  // Return all found indices
}

// Recursive factorial function
int Factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}
