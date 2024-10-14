#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>
int main()
{
	Checking ch("Latifa", 100, -50);
	
	Transact(&ch);
    ch.Deposit(-50); 
	ch.Withdraw(10);  
    return 0;
}
 
