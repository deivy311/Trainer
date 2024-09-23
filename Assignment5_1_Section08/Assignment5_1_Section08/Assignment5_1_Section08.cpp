#include <iostream>
#include <string>

// Function to convert string to uppercase
std::string ToUpper(const std::string &str)
{
    if(str.empty())
    {
        return ""; // Return empty string if input is empty
    }

    std::string result = str; // Copy the input string
    for (char &ch : result)
    {
        ch = std::toupper(static_cast<unsigned char>(ch)); // Convert each character to uppercase
    }

    return result;
}

// Function to convert string to lowercase
std::string ToLower(const std::string &str) {
    if (str.empty()) {
        return ""; // Return empty string if input is empty
    }

    std::string result = str; // Copy the input string
    for (char &ch : result) {
        ch = std::tolower(static_cast<unsigned char>(ch)); // Convert each character to lowercase
    }

    return result;
}
int main()
{

    std::string str;
    std::getline(std::cin, str);

    std::cout << "String in upper case: " << ToUpper(str) << std::endl;
    std::cout << "String in lower case: " << ToLower(str) << std::endl;
}
