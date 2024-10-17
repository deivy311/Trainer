#include "Checking.h"
#include <stdexcept>
#include <iostream>

Checking::Checking(const std::string &name, float balance) : Account(name, balance) {
    if (balance < 50) {
        throw std::invalid_argument("Initial balance for Checking account cannot be less than 50.");
    }
}

Checking::~Checking() {}

void Checking::Withdraw(float amount) {
    if (amount < 0) {
        throw std::invalid_argument("Withdraw amount cannot be negative.");
    }
    if (m_Balance - amount < 50) {
        throw std::runtime_error("Balance cannot fall below 50 after withdrawal.");
    }
    m_Balance -= amount;
}

float Checking::GetInterestRate() const {
    return 0.0f;  // No interest rate for Checking accounts
}

void Checking::AccumulateInterest() {
    // No interest accumulation for Checking accounts
}
