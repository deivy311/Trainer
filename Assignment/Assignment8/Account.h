#pragma once
#include <string>
#include <stdexcept>

class Account {
    std::string m_Name;
    int m_AccNo;
    static int s_ANGenerator;
protected:
    float m_Balance;
public:
    Account(const std::string &name, float balance);
    virtual ~Account();
    const std::string GetName()const;
    float GetBalance()const;
    int GetAccountNo()const;

    virtual void AccumulateInterest() = 0;
    virtual void Withdraw(float amount);
    void Deposit(float amount);
    virtual float GetInterestRate()const = 0;
};
