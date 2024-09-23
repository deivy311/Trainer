#pragma once
#include <string>
#include "AccountException.h"  // Include custom exception

class Account {
    std::string m_Name;
    int m_AccNo;
    static int s_ANGenerator;  // Static variable to generate account numbers

protected:
    float m_Balance;

public:
    Account(const std::string& name, float balance);  // Constructor
    virtual ~Account();  // Destructor

    // Getter for account name
    const std::string GetName() const;

    // Getter for balance
    float GetBalance() const;

    // Getter for account number
    int GetAccountNo() const;

    // Virtual function for accumulating interest (default does nothing)
    virtual void AccumulateInterest();

    // Withdraw money with error handling
    virtual void Withdraw(float amount);

    // Deposit money with error handling
    void Deposit(float amount);

    // Virtual function to return interest rate (default returns 0)
    virtual float GetInterestRate() const;
};
