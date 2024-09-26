#include "Account.h"
#include <iostream>
#include <stdexcept> // Include for exceptions

int Account::s_ANGenerator = 1000;

Account::Account(const std::string &name, float balance) : m_Name(name), m_Balance(balance) {
	if (balance < 0) {
		throw std::runtime_error("Initial balance cannot be negative");
	}
	m_AccNo = ++s_ANGenerator;
}

Account::~Account() {
	//std::cout << "~Account()" << std::endl;
}

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
	// No interest for base class, but should be overridden by derived classes
}

void Account::Withdraw(float amount) {
	// Ensure that amount is valid
	if (amount < 0) {
		throw std::runtime_error("Withdrawal amount cannot be negative");
	}
	if (amount > m_Balance) {
		throw std::runtime_error("Insufficient balance for withdrawal");
	}
	if (m_Balance <= 0) {
		throw std::runtime_error("Account balance is zero or negative, cannot withdraw");
	}
	// Perform the withdrawal
	m_Balance -= amount;
}

void Account::Deposit(float amount) {
	// Ensure that deposit amount is valid
	if (amount < 0) {
		throw std::runtime_error("Deposit amount cannot be negative");
	}
	// Perform the deposit
	m_Balance += amount;
}

float Account::GetInterestRate() const {
	return 0.0f;
}
