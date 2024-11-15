#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <random>
#include <chrono>
#include <exception>

class BankAccount {
public:
    BankAccount(int balance) : balance(balance) {}

    // Method to deposit money into the account
    void deposit(int amount) {
        std::lock_guard<std::mutex> guard(account_mutex);
        balance += amount;
        std::cout << "Deposited " << amount << ", new balance: " << balance << std::endl;
    }

    // Method to withdraw money from the account
    void withdraw(int amount) {
        std::lock_guard<std::mutex> guard(account_mutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ", new balance: " << balance << std::endl;
        } else {
            throw std::runtime_error("Insufficient funds for withdrawal");
        }
    }

    int get_balance() const {
        return balance;
    }

private:
    int balance;
    mutable std::mutex account_mutex; // Mutex to protect access to balance
};

// Simulate a bank customer who performs random transactions
void customer_simulation(BankAccount &account, int transactions, std::promise<int> result_promise) {
    try {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 100); // Random transaction amounts
        std::uniform_int_distribution<> transaction_type(0, 1); // 0 for deposit, 1 for withdrawal

        for (int i = 0; i < transactions; ++i) {
            int amount = dist(gen);
            if (transaction_type(gen) == 0) {
                account.deposit(amount);
            } else {
                account.withdraw(amount);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate time taken per transaction
        }
        result_promise.set_value(account.get_balance()); // Set final balance
    } catch (...) {
        // Capture any exception and set it in the promise
        result_promise.set_exception(std::current_exception());
    }
}

int main() {
    BankAccount account(1000); // Starting balance

    std::vector<std::thread> threads;
    std::vector<std::future<int>> results;
    int num_customers = 5;
    int transactions_per_customer = 10;

    for (int i = 0; i < num_customers; ++i) {
        std::promise<int> result_promise;
        results.push_back(result_promise.get_future());
        
        threads.emplace_back(customer_simulation, std::ref(account), transactions_per_customer, std::move(result_promise));
    }

    // Join all threads and process results
    for (auto &th : threads) {
        th.join();
    }

    for (size_t i = 0; i < results.size(); ++i) {
        try {
            int final_balance = results[i].get(); // Get the result from future
            std::cout << "Customer " << i + 1 << " final balance: " << final_balance << std::endl;
        } catch (const std::exception &ex) {
            std::cerr << "Customer " << i + 1 << " encountered an error: " << ex.what() << std::endl;
        }
    }

    std::cout << "Bank account final balance: " << account.get_balance() << std::endl;
    return 0;
}
