#include <iostream>
#include <string>

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

size_t Find(
    const std::string &source,           // Source string to be searched
    const std::string &search_string,    // The string to search for
    Case searchCase = Case::INSENSITIVE, // Choose case sensitive/insensitive search
    size_t offset = 0)
{ // Start the search from this offset
    // Implementation
    if (search_string.empty() || offset > source.length())
    { // check if search string is empty or offset is out of bounds
        return std::string::npos;
    }

    if (searchCase == Case::INSENSITIVE) // for case insenstive search, for thr string with ignorining upper and lower cases
    {
        std::string source_lower = ToLower(source);
        std::string search_string_lower = ToLower(search_string);
        return source_lower.find(search_string_lower, offset);
    }
    else
    { // for case sensitive, search for the str exactly same the str without ignoring cases
        return source.find(search_string, offset);
    }
    /*
    return position of the first character
    of the substring, else std::string::npos
    */
}

int main()
{

    std::string source = "Assignment Five in CPP Course";
    std::string search_str = "Five";

    // Perform a case-insensitive search
    size_t pos = Find(source, search_str, Case::INSENSITIVE);
    if (pos != std::string::npos)
    {
        std::cout << "Case-insensitive match found at position: " << pos << std::endl;
    }
    else
    {
        std::cout << "No case-insensitive match found." << std::endl;
    }

    // Perform a case-sensitive search
    pos = Find(source, search_str, Case::SENSITIVE);
    if (pos != std::string::npos)
    {
        std::cout << "Case-sensitive match found at position: " << pos << std::endl;
    }
    else
    {
        std::cout << "No case-sensitive match found." << std::endl;
    }

    return 0;
}
