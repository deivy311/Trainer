#include "BankAccount.h"

BankAccount::BankAccount(int accNum, const std::string& holderName, double initialBalance)
    : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}
