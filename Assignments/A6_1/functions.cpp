#include <iostream>
#include "functions.h"
#include <cctype> 

std::string ToUpper(const std::string &str) {
    std::string text;
    for (char ch : str) {
        text += std::toupper(static_cast<unsigned char>(ch));
    }
    return text;
}

std::string ToLower(const std::string &str) {
    std::string text;
    for (char ch : str) {
        text += std::tolower(static_cast<unsigned char>(ch));
    }
    return text;
}
