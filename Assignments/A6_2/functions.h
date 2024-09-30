#include <string>

enum class Case { SENSITIVE, INSENSITIVE };

std::string ToLower(const std::string &str);

size_t Find(
    const std::string &source,
    const std::string &search_string,
    Case searchCase = Case::INSENSITIVE,
    size_t offset = 0
);