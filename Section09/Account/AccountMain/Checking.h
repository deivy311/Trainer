#pragma once
#include "Account.h"



///////////////////////////////
// The only difference is that the account mandates the balance should not fall below 50. So, you'll have to re-implement the Withdraw function accordingly. 

class Checking :
	public Account {
	float m_MinimumBalance;


public:
	using Account::Account;

	Checking(const std::string &name, float balance, float minbalance);
	~Checking();
	void Withdraw(float amount)override;
	
	float GetMinimumBalance()const;
};

