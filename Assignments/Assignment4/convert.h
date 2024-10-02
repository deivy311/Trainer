#ifndef CONVERT_H
#define CONVERT_H

#include <string> //o include the string handling functionality that is part of the C++ Standard Library.

//Header Files (.h): These files contain declarations of functions or classes. A declaration tells the compiler,
// "This function or class exists and can be used," but doesn't show how it works: 

// Function to convert string to uppercase (The & symbol here denotes that str is a reference to a std::string object, not a new copy of it.)

std::string ToUpper(const std::string &str);

// Function to convert string to lowercase
std::string ToLower(const std::string &str);

#endif // CONVERT_H
