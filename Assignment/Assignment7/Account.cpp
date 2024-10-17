#include "Account.h"
#include <iostream>

int Account::s_ANGenerator = 1000;

Account::Account(const std::string &name, float balance): m_Name(name), m_Balance(balance) {
    if (balance < 0) {
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    m_AccNo = ++s_ANGenerator;
}

Account::~Account() {}

const std::string Account::GetName() const {
    return m_Name;
}

float Account::GetBalance() const {
    return m_Balance;
}

int Account::GetAccountNo() const {
    return m_AccNo;
}

void Account::AccumulateInterest() {
}

void Account::Withdraw(float amount) {
    if (amount < 0) {
        throw std::invalid_argument("Withdraw amount cannot be negative");
    }
    if (amount > m_Balance || m_Balance <= 0) {
        throw std::runtime_error("Insufficient balance");
    }
    m_Balance -= amount;
}

void Account::Deposit(float amount) {
    if (amount < 0) {
        throw std::invalid_argument("Deposit amount cannot be negative");
    }
    m_Balance += amount;
}

float Account::GetInterestRate() const {
    return 0.0f;
}
