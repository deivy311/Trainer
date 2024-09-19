#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::transform, std::tolower

/////////////////////////////////////////////////////////////////////////////
enum class Case { SENSITIVE, INSENSITIVE };

/////////////////////////////////////////////////////////////////////////////

std::string ToLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

/////////////////////////////////////////////////////////////////////////////

std::vector<int> FindAll(
    const std::string& target,               // Target string to be searched
    const std::string& search_string,        // The string to search for
    Case searchCase = Case::INSENSITIVE,     // Choose case-sensitive/insensitive search
    size_t offset = 0) {                     // Start the search from this offset


    std::vector<int> indices; // Vector to store the indices of found substrings
    std::string search_target = target;
    std::string search_term = search_string;

    if (searchCase == Case::INSENSITIVE) {
        search_target = ToLower(target);
        search_term = ToLower(search_string);
    }

    // Find all occurrences of the search string
    size_t pos = search_target.find(search_term, offset);
    while (pos != std::string::npos) {
        indices.push_back(pos); // Store the starting index of the found substring
        pos = search_target.find(search_term, pos + 1); // Continue search from the next position
    }

    /*
    Return indices of found strings,
    else an empty vector
    */
    return indices;
}

int main() {
    // Test cases
    std::string target = "Hi, This is Fatmah, do you know Fatmah Alhefeiti? !";
    std::string search_string = "fatmah";

    // Case-insensitive search
    std::vector<int> indices_insensitive = FindAll(target, search_string, Case::INSENSITIVE);
    std::cout << "Case-insensitive search indices: ";
    for (int index : indices_insensitive) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Case-sensitive search
    std::vector<int> indices_sensitive = FindAll(target, search_string, Case::SENSITIVE);
    std::cout << "Case-sensitive search indices: ";
    for (int index : indices_sensitive) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
