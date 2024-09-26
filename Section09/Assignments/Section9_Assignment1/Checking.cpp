#include "Checking.h"
#include <stdexcept>
#include <iostream>

Checking::Checking(const std::string &name, float balance, float minbalance)
	: m_MinimumBalance(minbalance), Account(name, balance) {
	if (balance < minbalance) {
		throw std::runtime_error("Initial balance cannot be less than the minimum balance");
	}
}

Checking::~Checking() {}

void Checking::Withdraw(float amount) {
	if (amount < 0) {
		throw std::runtime_error("Withdrawal amount cannot be negative");
	}
	// Ensure the balance remains above minimum balance after withdrawal
	if ((m_Balance - amount) < m_MinimumBalance) {
		throw std::runtime_error("Cannot withdraw, balance would drop below minimum");
	}
	// Perform withdrawal if valid
	Account::Withdraw(amount);
}

float Checking::GetMinimumBalance() const {
	return m_MinimumBalance;
}
