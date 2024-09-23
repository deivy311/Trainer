#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>
int main()
{
	Account acc("Bob", 1000);
	std::cout << "initial balance:" << acc.GetBalance() << std::endl;
	acc.Deposit(200);
	acc.Withdraw(380);
	std::cout <<"Balance: " << acc.GetBalance() << std::endl;
	//Checking ch("Bob", 100, 50);
	//Transact(&ch);

    //return 0;
}
 
