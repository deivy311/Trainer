#include "Savings.h"
#include <iostream>

Savings::Savings(const std::string &name, float balance, float rate): Account(name, balance), m_Rate(rate) {
    if (rate < 0) {
        throw std::invalid_argument("Interest rate cannot be negative.");
    }
}

Savings::~Savings() {}

float Savings::GetInterestRate() const {
    return m_Rate;
}

void Savings::AccumulateInterest() {
    if (m_Balance < 0) {
        throw std::runtime_error("Cannot accumulate interest on a negative balance.");
    }
    m_Balance += (m_Balance * m_Rate);
}
