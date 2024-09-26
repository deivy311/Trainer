#include "Checking.h"
#include <stdexcept>
#include <iostream>

// Initialize minimum balance to 50 in the constructor
Checking::Checking(const std::string &name, float balance)
    : Account(name, balance), m_MinimumBalance(50) {
    // Ensure initial balance is not less than the minimum balance
    if (balance < m_MinimumBalance) {
        throw std::runtime_error("Initial balance cannot be less than the minimum balance of 50");
    }
}

Checking::~Checking() {}

// Override the Withdraw function to ensure the balance doesn't fall below the minimum
void Checking::Withdraw(float amount) {
    if (amount < 0) {
        throw std::runtime_error("Withdrawal amount cannot be negative");
    }
    if ((m_Balance - amount) < m_MinimumBalance) {
        throw std::runtime_error("Cannot withdraw, balance would drop below the minimum balance of 50");
    }
    // Perform withdrawal if valid
    Account::Withdraw(amount);
}

// Helper function to return the minimum balance
float Checking::GetMinimumBalance() const {
    return m_MinimumBalance;
}
