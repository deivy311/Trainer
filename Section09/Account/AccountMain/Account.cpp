#include "Account.h"
#include "AccountException.h"  // Include custom exception class
#include <iostream>

// Static member initialization
int Account::s_ANGenerator = 1000;

// Constructor
Account::Account(const std::string &name, float balance)
    : m_Name(name), m_Balance(balance) {
    if (balance < 0.0f) {
        throw AccountException("Initial balance cannot be negative.");
    }
    m_AccNo = ++s_ANGenerator;
}

// Destructor
Account::~Account() {
    // Destructor logic, if any
}

// Getter for account name
const std::string Account::GetName() const {
    return m_Name;
}

// Getter for account balance
float Account::GetBalance() const {
    return m_Balance;
}

// Getter for account number
int Account::GetAccountNo() const {
    return m_AccNo;
}

// Accumulate interest (default behavior does nothing, can be overridden in derived classes)
void Account::AccumulateInterest() {
    // No interest for base Account class; derived classes can override
}

// Withdraw money with error handling
void Account::Withdraw(float amount) {
    /*
    Withdrawals should follow these rules:
    1. The withdrawal amount cannot be negative.
    2. There must be sufficient balance for the withdrawal.
    */
    if (amount < 0.0f) {
        throw AccountException("Withdrawal amount cannot be negative.");
    }
    if (amount > m_Balance) {
        throw AccountException("Insufficient funds for withdrawal.");
    }
    m_Balance -= amount;
}

// Deposit money with error handling
void Account::Deposit(float amount) {
    /*
    Deposits should follow these rules:
    1. The deposit amount cannot be negative.
    */
    if (amount < 0.0f) {
        throw AccountException("Deposit amount cannot be negative.");
    }
    m_Balance += amount;
}

// Get interest rate (base class returns 0, can be overridden in derived classes)
float Account::GetInterestRate() const {
    return 0.0f;  // No interest for the base class
}
