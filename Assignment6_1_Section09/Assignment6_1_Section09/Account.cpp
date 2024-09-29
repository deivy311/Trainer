#include "Account.h"
#include <iostream>
int Account::s_ANGenerator = 1000;
Account::Account(const std::string &name, float balance) : m_Name(name), m_Balance(balance)
{
	m_AccNo = ++s_ANGenerator;
}

Account::~Account()
{
}

const std::string Account::GetName() const
{
	return m_Name;
}

float Account::GetBalance() const
{
	return m_Balance;
}

int Account::GetAccountNo() const
{
	return m_AccNo;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float amount)
{
	/*
	Balance should be greater than 0 & the amount
	to withdraw should be less than balance
	*/

	if (amount > 0)
	{
		if (amount < m_Balance && m_Balance > 0)
			m_Balance -= amount;
		else
		{
			// Throw an exception instead of printing a message
			std::cout << "Insufficient balance" << std::endl;
			// throw std::runtime_error("Insufficient balance");
		}
	}
	else
	{
		std::cout << "Amount cannot be withdraw becuase its less than zero" << std::endl;
	}
}

void Account::Deposit(float amount)
{
	// ammount to be deposit to account should be greater than zero
	if (amount > 0)
	{
		m_Balance += amount;
	}
	else
	{
		std::cout << "Amount cannot be addded" << std::endl;
	}
}

float Account::GetInterestRate() const
{
	return 0.0f;
}
