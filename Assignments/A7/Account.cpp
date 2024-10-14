#include "Account.h"
#include <iostream>
int Account::s_ANGenerator = 1000;
Account::Account(const std::string &name, float balance):
m_Name(name), m_Balance(balance){
	if (balance < 0) {
		throw std::invalid_argument("Error!! Amount should be more than 0.");
	}
	m_AccNo = ++s_ANGenerator;
	//std::cout << "Account(const std::string &, float)" << std::endl; 
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
}


void Account::Withdraw(float amount) {
	/*
	Balance should be greater than 0 & the amount
	to withdraw should be less than balance
	*/
    if (amount < 0) {
        throw std::invalid_argument("Error!! Amount should be more than 0.");  
    }
    if (amount > m_Balance) {
        throw std::runtime_error("Insufficient balance");  
    }
    m_Balance -= amount;  
}
void Account::Deposit(float amount) {
	if (amount < 0){
		throw std::invalid_argument("Error!! Amount should be more than 0.");

	}
	m_Balance += amount;
}

float Account::GetInterestRate() const {
	return 0.0f;
}
