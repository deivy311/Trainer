#include <iostream>
#include "Savings.h"
#include "Checking.h"

int main()
{
    try {
        // Test Savings Account
        Savings savingsAccount("Alice", 500, 0.05f);
        std::cout << "Savings Account created with initial balance: " << savingsAccount.GetBalance() << std::endl;

        savingsAccount.Deposit(100);
        std::cout << "Savings balance after deposit: " << savingsAccount.GetBalance() << std::endl;

        savingsAccount.AccumulateInterest();
        std::cout << "Savings balance after interest accumulation: " << savingsAccount.GetBalance() << std::endl;

        // Test Checking Account
        Checking checkingAccount("Bob", 100);
        std::cout << "Checking Account created with initial balance: " << checkingAccount.GetBalance() << std::endl;

        checkingAccount.Deposit(100);
        std::cout << "Checking balance after deposit: " << checkingAccount.GetBalance() << std::endl;

        checkingAccount.Withdraw(50);
        std::cout << "Checking balance after withdrawal: " << checkingAccount.GetBalance() << std::endl;

        // Test withdraw that drops balance below 50 (should throw an exception)
        checkingAccount.Withdraw(101);

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
