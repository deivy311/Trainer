#include "Transaction.h"
#include <iostream>
#include <stdexcept>
#include "Checking.h"

void Transact(Account *pAccount) {
	try {
		std::cout << "Transaction started" << std::endl; 
		std::cout << "Initial balance: " << pAccount->GetBalance() << std::endl;

		// Try deposit
		pAccount->Deposit(100);
		pAccount->AccumulateInterest();

		Checking *pChecking = dynamic_cast<Checking*>(pAccount);
		if (pChecking != nullptr) {
			std::cout << "Minimum balance of Checking: " << pChecking->GetMinimumBalance() << std::endl;
		}

		// Try withdrawal
		pAccount->Withdraw(170);
		std::cout << "Interest rate: " << pAccount->GetInterestRate() << std::endl;
		std::cout << "Final balance: " << pAccount->GetBalance() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Transaction failed: " << e.what() << std::endl;
	}
}
