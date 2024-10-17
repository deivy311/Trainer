#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>
int main()
{
	Checking ch("Latifa", 1000,50);
	
	Transact(&ch);


    ch.Withdraw(200);
    std::cout << "Balance after withdrawing 200 (pass): " << ch.GetBalance() << std::endl;
    
    std::cout << "Withdraw 800 (fail):" << std::endl;
    ch.Withdraw(800);  // Error: balance will fall below 50

    std::cout << "Withdraw -10 (fail):" << std::endl;
    ch.Withdraw(-10);  // Error: negative withdrawal amount
    
    return 0;
}
 
