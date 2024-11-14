#include "Checking.h"
#include <iostream>

int main() {
    try {
        // Test 1: Creating a checking account with a valid balance
        Checking checking1("Alice Doe", 500.0f);
        std::cout << "Checking account created: " << checking1.GetName() 
                  << ", Account No: " << checking1.GetAccountNo() 
                  << ", Balance: $" << checking1.GetBalance() << std::endl;

        // Test 2: Withdrawing a valid amount
        checking1.Withdraw(100.0f);
        std::cout << "After withdrawal, Balance: $" << checking1.GetBalance() << std::endl;

        // Test 3: Attempt to withdraw more than allowed (balance < $50)
        try {
            checking1.Withdraw(400.0f);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test 4: Attempt to create a checking account with insufficient initial balance
        try {
            Checking checking2("Bob Doe", 30.0f);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
