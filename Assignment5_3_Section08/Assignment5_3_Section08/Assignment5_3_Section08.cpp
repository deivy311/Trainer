#include <iostream>
#include <string>
#include <vector>

// Enum for case-sensitive or insensitive search
enum class Case
{
    SENSITIVE,
    INSENSITIVE
};

// Function to convert string to lowercase
std::string ToLower(const std::string &str)
{
    if (str.empty())
    {
        return ""; // Return empty string if input is empty
    }

    std::string result = str; // Copy the input string
    for (char &ch : result)
    {
        ch = std::tolower(static_cast<unsigned char>(ch)); // Convert each character to lowercase
    }

    return result;
}

// Function to find all indices of the search string in the target
std::vector<int> FindAll(
    const std::string &target,           // Target string to be searched
    const std::string &search_string,    // The string to search for
    Case searchCase = Case::INSENSITIVE, // Choose case sensitive/insensitive search
    size_t offset = 0)                   // Start the search from this offset
{
    std::vector<int> indices; // To store the found indices
    std::string target_copy = target; // Create copies of target and search string
    std::string search_copy = search_string;

    if (searchCase == Case::INSENSITIVE)
    {
        target_copy = ToLower(target_copy);        // Convert target to lowercase
        search_copy = ToLower(search_copy);        // Convert search string to lowercase
    }

    size_t pos = target_copy.find(search_copy, offset); // Find the first occurrence
    while (pos != std::string::npos)
    {
        indices.push_back(pos);                         // Store the index
        pos = target_copy.find(search_copy, pos + 1);   // Find the next occurrence
    }

    return indices; // Return vector of indices or an empty vector if no match
}

int main()
{

    std::string source = "This is a simple test. This test is simple.";
    std::string search_str = "test";

    // Perform a case-insensitive search
    auto results_insensitive = FindAll(source, search_str, Case::INSENSITIVE);
    std::cout << "Case-insensitive results: ";
    for (int index : results_insensitive)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Perform a case-sensitive search
    auto results_sensitive = FindAll(source, search_str, Case::SENSITIVE);
    std::cout << "Case-sensitive results: ";
    for (int index : results_sensitive)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
