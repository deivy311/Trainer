#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

// Function to convert a string to uppercase
std::string ToUpper(const std::string &str);

// Function to convert a string to lowercase
std::string ToLower(const std::string &str);

// Function to add two integers and return the result through a reference parameter
void Add(int a, int b, int &result);

// Recursive function to find the factorial of a number and return it through a reference parameter
void Factorial(int a, int &result);

// Function to swap two integers through reference arguments
void Swap(int &a, int &b);

#endif // FUNCTIONS_HPP
