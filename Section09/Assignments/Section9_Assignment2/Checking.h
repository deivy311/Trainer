#pragma once
#include "Account.h"

class Checking : public Account {
    float m_MinimumBalance; // Minimum balance allowed for Checking account
public:
    Checking(const std::string &name, float balance); // Constructor to initialize with name and balance
    ~Checking(); // Destructor

    // Override the Withdraw function to ensure balance doesn't fall below minimum
    void Withdraw(float amount) override;

    // No need to override GetInterestRate or AccumulateInterest because Checking doesn't have interest

    // Helper function to get minimum balance
    float GetMinimumBalance() const;
};
