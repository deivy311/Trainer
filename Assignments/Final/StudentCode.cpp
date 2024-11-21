#include "StudentCode.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

#include <iostream>
#include <stdexcept>

int main()
{
    // Savings Account Tests
    try
    {
        // Print banner for Savings Account
        std::cout << "\033[33m\n------------------------------------------------------------------------\n\033[0m";
        std::cout << "\033[33m|    Latifa Savings Account:  initial balance 1000 .. interest rate 5%   |\n\033[0m";
        std::cout << "\033[33m------------------------------------------------------------------------\n\033[0m";

        SavingsAccount account(89899982, "Latifa", 1000.0, 5.0);

        // Display initial account information
        account.displayAccountInfo();

        // Test deposit
        std::cout << "\033[33m\nAfter deposit of 500 AED:\n\033[0m";
        account.deposit(500);
        account.displayAccountInfo();

        // Test applyInterest
        std::cout << "\033[33m\nAfter applying interest:\n\033[0m";
        account.applyInterest();
        account.displayAccountInfo();

        // Test withdraw
        std::cout << "\033[33m\nAfter withdrawal of 300 AED:\n\033[0m";
        account.withdraw(300);
        account.displayAccountInfo();

        // Deposit -
        std::cout << "\033[33m\nDeposit -200 AED:\n\033[0m";
        try
        {
            account.deposit(-200);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl; // Error in red
        }

        // Withdraw > balance
        std::cout << "\033[33m\nWithdraw 2000 AED (> balance):\n\033[0m";
        try
        {
            account.withdraw(2000);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl; // Error in red
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
    }

    // Checking Account Tests
    try
    {
        std::cout << "\033[33m\n-----------------------------------------------------------------------------\n\033[0m";
        std::cout << "\033[33m|     Ali Checking Account: initial balance 1000 .. overdraft limit 500%      |\n\033[0m";
        std::cout << "\033[33m-----------------------------------------------------------------------------\n\033[0m";

        CheckingAccount checkingAccount(2552525, "Ali", 1000.0, 500.0);

        // Display initial account information
        checkingAccount.displayAccountInfo();

        // Test deposit
        std::cout << "\033[33m\nAfter deposit of 300 AED:\n\033[0m";
        checkingAccount.deposit(300);
        checkingAccount.displayAccountInfo(); // 1300

        // Test withdraw
        std::cout << "\033[33m\nAfter withdrawal of 800 AED: \n\033[0m";
        checkingAccount.withdraw(800); // 500
        checkingAccount.displayAccountInfo();

        // Test withdraw < overdraft limit
        std::cout << "\033[33m\nWithdrawal of 700 (> balance, within overdraft limit)\n\033[0m";
        checkingAccount.withdraw(700); // -200
        checkingAccount.displayAccountInfo();

        // Withdraw |> overdraft limit
        std::cout << "\033[33m\nWithdraw 1000 AED (> overdraft limit):\n\033[0m";
        try
        {
            checkingAccount.withdraw(1000);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl; // Error in red
        }
        checkingAccount.displayAccountInfo();

        // Withdraw -
        std::cout << "\033[33m\nWithdraw -100 AED:\n\033[0m";
        try
        {
            checkingAccount.withdraw(-100);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl; // Error in red
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
