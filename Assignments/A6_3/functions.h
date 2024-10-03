#include <string>
#include <vector>
enum class Case { SENSITIVE, INSENSITIVE };

std::vector<int> FindAll(
    const std::string &target,              
    const std::string &search_string,      
    Case searchCase = Case::INSENSITIVE,   
    size_t offset = 0                       
);

std::string ToLower(const std::string &str);

size_t Find(
    const std::string &source,
    const std::string &search_string,
    Case searchCase = Case::INSENSITIVE,
    size_t offset = 0
);