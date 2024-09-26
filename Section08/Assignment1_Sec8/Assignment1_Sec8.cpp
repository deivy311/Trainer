#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

/*The std::string function does not provide any function to convert the underlying string to 
upper case or lower case. Write two functions that provide this behavior. Both functions return 
a copy of the converted string. In case of error, return an empty string.

    std::string ToUpper(const std::string &str) ;
    std::string ToLower(const std::string &str) ;

Hint : Use toupper & tolower from C string library.
*/

// Convert a string to uppercase
std::string ConvertToUpper(const std::string &str) {
    std::string result = str;  
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = std::toupper(result[i]);
    }
    return result;
}


// Convert a string to lowercase
std::string ConvertToLower(const std::string &str) {
    std::string result = str;  
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = std::tolower(result[i]);
    }
    return result;
}

int main() {
    
    std::cout << "Write two functions that convert the underlying string to upper case or lower case."<< std::endl; 
    std::cout << "Both functions return a copy of the converted string or an empty string\n"<< std::endl; 

    std::string input = "Hi this Assignmt 1";
    
    std::string upper = ConvertToUpper(input);
    std::string lower = ConvertToLower(input);
    
    std::cout << "Original: " << input << std::endl;
    std::cout << "Uppercase: " << upper << std::endl;
    std::cout << "Lowercase: " << lower << std::endl;

    return 0;
}
