#include "Account.h"
#include <iostream>
#include <stdexcept>
#include <typeinfo>

int Account::s_ANGenerator = 1000;

Account::Account(const std::string &name, float balance) : m_Name(name), m_Balance(balance) {
    if (balance < 0) {
        throw std::invalid_argument("Initial balance cannot be negative.");
    }
    m_AccNo = ++s_ANGenerator;
    std::cout << "Account(const std::string &, float)" << std::endl;
}

Account::~Account() {
    // Destructor logic if needed
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
    // Placeholder for future interest accumulation logic
}




void Account::Withdraw(float amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }
    if (amount > m_Balance) {
        throw std::runtime_error("Insufficient balance.");
    }
    m_Balance -= amount;
}

void Account::Deposit(float amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
    m_Balance += amount;
}

float Account::GetInterestRate() const {
    // Interest rate logic could be added here
    return 0.0f;
}







///////////////////////////////////////////////////////////////////////////////////////////


int main() {
    try {
        // Test 1: Creating an account with a valid balance
        Account account1("John Doe", 1000.0f);
        std::cout << "Account created: " << account1.GetName() 
                  << ", Account No: " << account1.GetAccountNo() 
                  << ", Balance: $" << account1.GetBalance() << std::endl;

        // Test 2: Depositing a valid amount
        account1.Deposit(500.0f);
        std::cout << "After deposit, Balance: $" << account1.GetBalance() << std::endl;

        // Test 3: Withdrawing a valid amount
        account1.Withdraw(300.0f);
        std::cout << "After withdrawal, Balance: $" << account1.GetBalance() << std::endl;

        // Test 4: Attempt to withdraw more than the balance
        try {
            account1.Withdraw(2000.0f);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test 5: Attempt to withdraw a negative amount
        try {
            account1.Withdraw(-100.0f);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test 6: Attempt to deposit a negative amount
        try {
            account1.Deposit(-50.0f);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test 7: Attempt to create an account with a negative balance
        try {
            Account account2("Jane Doe", -100.0f);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
