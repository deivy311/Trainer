#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum class Case { SENSITIVE, INSENSITIVE };

std::vector<int> FindAll(
    const std::string &target,
    const std::string &search_string,
    Case searchCase = Case::INSENSITIVE,
    size_t offset = 0
) {
    std::vector<int> indices;

    if (search_string.empty() || target.empty()) {
        return indices;
    }

    std::string modified_target = target;
    std::string modified_search = search_string;

    if (searchCase == Case::INSENSITIVE) {
        std::transform(modified_target.begin(), modified_target.end(), modified_target.begin(), ::tolower);
        std::transform(modified_search.begin(), modified_search.end(), modified_search.begin(), ::tolower);
    }

    size_t pos = modified_target.find(modified_search, offset);

    while (pos != std::string::npos) {
        indices.push_back(static_cast<int>(pos));
        pos = modified_target.find(modified_search, pos + 1);
    }

    return indices;
}

int main() {
    std::string target = "This is a simple test. Testing is essential for tests.";
    std::string search = "test";

    // Perform case-insensitive search
    std::vector<int> result = FindAll(target, search, Case::INSENSITIVE);

    std::cout << "Indices found (case-insensitive): ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Perform case-sensitive search
    result = FindAll(target, search, Case::SENSITIVE);
    std::cout << "Indices found (case-sensitive): ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
