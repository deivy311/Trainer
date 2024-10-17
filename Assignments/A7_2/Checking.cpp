#include "Checking.h"

#include <iostream>
Checking::Checking(const std::string &name, float balance, float minbalance):
m_MinimumBalance(minbalance), Account(name, balance){
}


Checking::~Checking() {
}

void Checking::Withdraw(float amount) {
    if (amount < 0) {
        throw std::invalid_argument("Error!! Withdraw amount should be more than 0.");
    }
    if (m_Balance - amount < m_MinimumBalance) {
        throw std::runtime_error("Error!! balance should not fall below 50.");
    }
    Account::Withdraw(amount);
}




float Checking::GetMinimumBalance() const {
	return m_MinimumBalance;
}
