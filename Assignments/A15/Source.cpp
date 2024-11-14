#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <stdexcept>

class BankAccount
{
    double balance;
    std::mutex mutex;

public:
    BankAccount(double initial_balance) : balance(initial_balance) {}

    void deposit(double amount)
    {
        std::lock_guard<std::mutex> lock(mutex);
        balance += amount;
    }

    void withdraw(double amount)
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (amount > balance)
        {
            throw std::runtime_error("No enough money.");
        }
        balance -= amount;
    }
};

void performTransaction(BankAccount &account, bool isDeposit, double amount, std::promise<void> result)
{
    try
    {
        if (isDeposit)
        {
            account.deposit(amount);
        }
        else
        {
            account.withdraw(amount);
        }
        result.set_value();
    }
    catch (...)
    {
        result.set_exception(std::current_exception());
    }
}

int main()
{
    BankAccount account(1000.0);

    std::promise<void> depositResult, withdrawResult;
    std::future<void> depositFuture = depositResult.get_future();
    std::future<void> withdrawFuture = withdrawResult.get_future();

    std::thread depositThread(performTransaction, std::ref(account), true, 200.0, std::move(depositResult));
    std::thread withdrawThread(performTransaction, std::ref(account), false, 1500.0, std::move(withdrawResult));

    depositThread.join();
    withdrawThread.join();

    try
    {
        depositFuture.get();
        std::cout << "Deposit completed successfully." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Deposit failed: " << e.what() << std::endl;
    }

    try
    {
        withdrawFuture.get();
        std::cout << "Withdraw completed successfully." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Withdraw failed: " << e.what() << std::endl;
    }

    return 0;
}
