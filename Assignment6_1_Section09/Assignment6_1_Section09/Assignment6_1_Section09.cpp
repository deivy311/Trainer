#include <iostream>
#include <string>
#include "Account.h"
int main()
{

    Account account_1("Ahmed", 1000.00);
    std::cout << "New Account for " << account_1.GetName() << " has been created successfuly" << std::endl;
    // test deposit function with negative amount
    account_1.Deposit(50.0);
    // test withdraw with negative ammount
    account_1.Withdraw(-100);
    std::cout << "Cuurent Balance: " << account_1.GetBalance() << std::endl;


}
