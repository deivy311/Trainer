#include "BankAccount.hpp"

BankAccount::BankAccount(int initialBalance) : balance(initialBalance) {}

void BankAccount::deposit(int amount) {
    std::lock_guard<std::mutex> guard(balanceMutex);
    balance += amount;
    std::cout << "Deposited: " << amount << ", New Balance: " << balance << std::endl;
}

void BankAccount::withdraw(int amount) {
    std::lock_guard<std::mutex> guard(balanceMutex);
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Withdrew: " << amount << ", New Balance: " << balance << std::endl;
    } else {
        std::cout << "Withdrawal of " << amount << " failed. Insufficient funds. Current Balance: " << balance << std::endl;
    }
}

int BankAccount::getBalance() const {
    return balance;
}

void BankAccount::performTransaction(BankAccount& account, int amount, std::promise<int>&& prom) {
    try {
        if (amount > 0) {
            account.deposit(amount);
        } else {
            account.withdraw(-amount);
        }
        prom.set_value(account.getBalance());
    } catch (...) {
        prom.set_exception(std::current_exception());
    }
}
