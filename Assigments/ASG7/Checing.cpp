#include "Checking.h"
#include <iostream>
#include <stdexcept>

Checking::Checking(const std::string &name, float balance) : Account(name, balance) {
    if (balance < 50.0f) {
        throw std::invalid_argument("Initial balance for Checking account cannot be less than 50.");
    }
    std::cout << "Checking(const std::string &, float)" << std::endl;
}

Checking::~Checking() {
    // Destructor logic if needed
}

void Checking::Withdraw(float amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }
    if (m_Balance - amount < 50.0f) {
        throw std::runtime_error("Balance cannot fall below $50.");
    }
    m_Balance -= amount;
}
