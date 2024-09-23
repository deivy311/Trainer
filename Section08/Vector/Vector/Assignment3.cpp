#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class Case { SENSITIVE, INSENSITIVE };

std::vector<int>
FindAll(
    const std::string &target,              // Target string to be searched
    const std::string &search_string,       // The string to search for
    Case searchCase = Case::INSENSITIVE,    // Choose case sensitive/insensitive search
    size_t offset = 0) {                    // Start the search from this offset

    std::vector<int> indices;  // To store the indices of found substrings
    std::string target_copy = target;
    std::string search_copy = search_string;
    
    // If the search is case-insensitive, convert both target and search strings to lowercase
    if (searchCase == Case::INSENSITIVE) {
        std::transform(target_copy.begin(), target_copy.end(), target_copy.begin(), ::tolower);
        std::transform(search_copy.begin(), search_copy.end(), search_copy.begin(), ::tolower);
    }
    
    size_t pos = target_copy.find(search_copy, offset);
    while (pos != std::string::npos) {
        indices.push_back(pos);
        pos = target_copy.find(search_copy, pos + 1);  // Continue searching from the next position
    }
    
    return indices;  // Return the indices vector
}

// Test the function
int main() {
    std::string target = "This is a test. Test this function for test cases.";
    std::string search_string = "test";
    
    // Case insensitive search
    std::vector<int> result = FindAll(target, search_string, Case::INSENSITIVE);
    
    std::cout << "Found at indices (Case Insensitive): ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    
    // Case sensitive search
    result = FindAll(target, search_string, Case::SENSITIVE);
    
    std::cout << "Found at indices (Case Sensitive): ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
