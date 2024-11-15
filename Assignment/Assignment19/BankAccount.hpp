#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <vector>

class BankAccount {
private:
    int balance;
    std::mutex balanceMutex;

public:
    BankAccount(int initialBalance);
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance() const;
    static void performTransaction(BankAccount& account, int amount, std::promise<int>&& prom);
};

#endif // BANK_ACCOUNT_HPP
