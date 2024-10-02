#ifndef SEARCH_UTIL_H
#define SEARCH_UTIL_H

#include <string>

// Enum class to define case-sensitive or case-insensitive search
enum class Case { SENSITIVE, INSENSITIVE };

// Helper function to convert a string to lowercase
std::string ToLower(const std::string &str);

// Find function with case-sensitive and case-insensitive options
size_t Find(const std::string &source, 
            const std::string &search_string, 
            Case searchCase = Case::INSENSITIVE, 
            size_t offset = 0);

#endif  // SEARCH_UTIL_H
