#include <iostream>
#include <string>
#include "Account.h"
#include "Checking.h"
int main()
{

    // create a checking account
    Checking checking_1("Ahmed", 500.0,50.0);
    std::cout << "A new checking account has been created" << std::endl;
    // add some amount to checking account
    checking_1.Deposit(500);
    std::cout << "Current Balance: " << checking_1.GetBalance() << std::endl;
    // withdraw some amount to see what will happen after its reachs minimum balance for checking account
    checking_1.Withdraw(965);
    std::cout << "Current Balance: " << checking_1.GetBalance() << std::endl;


    


}
