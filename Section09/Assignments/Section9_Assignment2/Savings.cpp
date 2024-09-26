#include "Savings.h"
#include <stdexcept>
#include <iostream>

Savings::Savings(const std::string &name, float balance, float rate)
	: Account(name, balance), m_Rate(rate) {
	if (rate < 0) {
		throw std::runtime_error("Interest rate cannot be negative");
	}
}

Savings::~Savings() {}

float Savings::GetInterestRate() const {
	return m_Rate;
}

void Savings::AccumulateInterest() {
	// Calculate interest only if the balance is positive
	if (m_Balance <= 0) {
		throw std::runtime_error("Cannot accumulate interest on zero or negative balance");
	}
	m_Balance += (m_Balance * m_Rate);
}
