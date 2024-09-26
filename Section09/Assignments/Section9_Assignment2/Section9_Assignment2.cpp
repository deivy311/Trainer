#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>

int main() {
    try {
        // Create a Checking account with a balance of 100
        Checking ch("Bob", 100);

        // Perform a transaction on the Checking account
        Transact(&ch);

        // Uncomment these lines to test error cases
        // Checking ch2("Alice", 40); // This will throw an error due to insufficient initial balance
        // ch.Withdraw(60); // This will throw an error due to the minimum balance requirement
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
