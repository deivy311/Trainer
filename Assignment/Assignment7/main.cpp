#include <iostream>
#include "Savings.h"

int main()
{
    try {
        Savings account("Alice", 500, 0.05f);

        // Test deposit
        account.Deposit(100);
        std::cout << "Balance after deposit: " << account.GetBalance() << std::endl;

        // Test withdraw
        account.Withdraw(50);
        std::cout << "Balance after withdrawal: " << account.GetBalance() << std::endl;

        // Test interest accumulation
        account.AccumulateInterest();
        std::cout << "Balance after accumulating interest: " << account.GetBalance() << std::endl;

        // Test negative deposit
        account.Deposit(-50);  // This will throw an exception

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
