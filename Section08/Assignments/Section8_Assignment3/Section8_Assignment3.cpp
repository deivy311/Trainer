#include <iostream>
#include <string>
#include <vector>
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

// Function to find all occurrences of a substring with case-sensitive or case-insensitive search
std::vector<int> FindAll(
    const std::string& target,            // Target string to be searched
    const std::string& search_string,     // The string to search for
    Case searchCase = Case::INSENSITIVE,  // Case sensitivity selection
    size_t offset = 0                     // Start search from this offset
) {
    std::vector<int> indices;  // Vector to store the starting indices of found substrings

    // Convert both target and search_string to lowercase if case-insensitive search is selected
    std::string modifiedTarget = (searchCase == Case::INSENSITIVE) ? ToLower(target) : target;
    std::string modifiedSearchString = (searchCase == Case::INSENSITIVE) ? ToLower(search_string) : search_string;

    // Find all occurrences of the search_string in the target
    size_t foundIndex = modifiedTarget.find(modifiedSearchString, offset);
    
    while (foundIndex != std::string::npos) {
        indices.push_back(foundIndex);  // Store the index where the substring was found
        foundIndex = modifiedTarget.find(modifiedSearchString, foundIndex + 1);  // Continue searching from the next position
    }
    
    return indices;  // Return the vector containing all the indices
}

// Main function to test the implementation
int main() {
    std::string target = "Hello world, hello universe, HELLO cosmos!";
    std::string searchString;
    
    std::cout << "Enter a string to search for: ";
    std::getline(std::cin, searchString);
    
    // Perform case-insensitive search for all occurrences
    std::vector<int> caseInsensitiveIndices = FindAll(target, searchString, Case::INSENSITIVE);
    
    std::cout << "Case-insensitive search: Found at indices: ";
    if (!caseInsensitiveIndices.empty()) {
        for (int index : caseInsensitiveIndices) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    // Perform case-sensitive search for all occurrences
    std::vector<int> caseSensitiveIndices = FindAll(target, searchString, Case::SENSITIVE);
    
    std::cout << "Case-sensitive search: Found at indices: ";
    if (!caseSensitiveIndices.empty()) {
        for (int index : caseSensitiveIndices) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    return 0;
}
