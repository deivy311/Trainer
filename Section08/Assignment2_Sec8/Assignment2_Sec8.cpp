#include <iostream>
#include <string>
#include <algorithm>  // For std::transform

/*The find function in std::string uses a case-sensitive search. Write a function
 that also performs a case insensitive search. Use an enum to decide between 
 case-sensitive and case-insensitive search.    

Note that, we don't have direct write access to the raw string inside std::string.
*/

enum class Case{
    SENSITIVE,
    INSENSITIVE
};

size_t Find(
    const std::string &source,         //Source string to be searched
    const std::string &search_string,  //The string to search for
    Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
    size_t offset = 0 ) {                //Start the search from this offset Implementation
     
         /*
         return position of the first character of the substring, 
         else std::string::npos
         */
    std::string src = source;
    std::string search = search_string;

    // If case-insensitive, convert both strings to lowercase
    if (searchCase == Case::INSENSITIVE) {
        std::transform(src.begin(), src.end(), src.begin(), ::tolower);
        std::transform(search.begin(), search.end(), search.begin(), ::tolower);
    }

    // Perform the search starting from the given offset
    return src.find(search, offset);
}

int main() {
    std::string source = "Hello World, welcome to the world of C++!";
    std::string search_string = "WORLD";

    // Case-insensitive search
    size_t found = Find(source, search_string, Case::INSENSITIVE);
    std::cout << "Case-insensitive search result: " 
              << (found != std::string::npos ? found : -1) << std::endl;

    // Case-sensitive search
    found = Find(source, search_string, Case::SENSITIVE);
    std::cout << "Case-sensitive search result: " 
              << (found != std::string::npos ? found : -1) << std::endl;

    return 0;
}