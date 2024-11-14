#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <vector>
#include <chrono>
#include <random>
#include <stdexcept>

class BankAccount {
private:
    int balance;
    std::mutex mtx;

public:
    BankAccount(int initial_balance) : balance(initial_balance) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (amount < 0) throw std::invalid_argument("Deposit amount cannot be negative");
        balance += amount;
        std::cout << "Deposited " << amount << ", Balance: " << balance << "\n";
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (amount < 0) throw std::invalid_argument("Withdrawal amount cannot be negative");
        if (amount > balance) throw std::runtime_error("Insufficient funds");
        balance -= amount;
        std::cout << "Withdrew " << amount << ", Balance: " << balance << "\n";
    }

    int get_balance() const {
        return balance;
    }
};

void customer_transaction(BankAccount& account, int deposit_amount, int withdraw_amount, std::promise<void> result_promise) {
    try {
        // Perform deposit and withdrawal operations
        account.deposit(deposit_amount);
        account.withdraw(withdraw_amount);

        // If everything is successful, set promise to indicate success
        result_promise.set_value();
    } catch (const std::exception& ex) {
        // Set exception in promise if any operation fails
        result_promise.set_exception(std::current_exception());
    }
}

int main() {
    BankAccount account(1000);  // Initial balance of 1000
    std::vector<std::thread> threads;
    std::vector<std::future<void>> results;

    // Create a set of customers with varying deposit and withdrawal amounts
    std::vector<std::pair<int, int>> transactions = {{200, 100}, {500, 200}, {100, 300}, {400, 1000}, {50, 20}};

    for (const auto& transaction : transactions) {
        std::promise<void> result_promise;
        results.push_back(result_promise.get_future());
        threads.emplace_back(customer_transaction, std::ref(account), transaction.first, transaction.second, std::move(result_promise));
    }

    // Wait for all threads to complete and check results
    for (size_t i = 0; i < threads.size(); ++i) {
        try {
            results[i].get();  // Will throw an exception if there was an error in the thread
            std::cout << "Transaction " << i + 1 << " completed successfully.\n";
        } catch (const std::exception& ex) {
            std::cerr << "Transaction " << i + 1 << " failed: " << ex.what() << "\n";
        }
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Final Balance: " << account.get_balance() << "\n";
    return 0;
}
