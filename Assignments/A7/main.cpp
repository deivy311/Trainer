#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>
int main()
{
	Checking ch("Latifa", 1000,50);
	
	Transact(&ch);
    //ch.Deposit(-100); 
	ch.Withdraw(-10);  
    return 0;
}
 
