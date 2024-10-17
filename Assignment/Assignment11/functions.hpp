#ifndef FIND_ALL_HPP
#define FIND_ALL_HPP

#include <vector>
#include <string>

// Enum to define case sensitivity
enum class Case { SENSITIVE, INSENSITIVE };

// Helper function to convert a string to lowercase (for case-insensitive search)
std::string ToLower(const std::string &str);

// Function to find all occurrences of a search string in a target string
std::vector<int> FindAll(const std::string &target, const std::string &search_string, Case searchCase = Case::INSENSITIVE, size_t offset = 0);

// Factorial function using recursion
int Factorial(int n);

#endif  // FIND_ALL_HPP
