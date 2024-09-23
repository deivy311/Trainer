#pragma once
#include <stdexcept>
#include <string>

// Custom exception class for Account-related errors
class AccountException : public std::runtime_error {
public:
    // Constructor that takes an error message
    AccountException(const std::string& message) : std::runtime_error(message) {}
};
