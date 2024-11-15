#include "BankAccount.hpp"
#include <vector>

int main() {
    BankAccount account(1000); // Initial balance

    std::vector<std::thread> threads;
    std::vector<std::promise<int>> promises(4);
    std::vector<std::future<int>> futures;

    for (auto& prom : promises) {
        futures.push_back(prom.get_future());
    }

    // Create threads to perform transactions (both deposits and withdrawals)
    threads.emplace_back(&BankAccount::performTransaction, std::ref(account), 500, std::move(promises[0]));
    threads.emplace_back(&BankAccount::performTransaction, std::ref(account), -300, std::move(promises[1]));
    threads.emplace_back(&BankAccount::performTransaction, std::ref(account), 200, std::move(promises[2]));
    threads.emplace_back(&BankAccount::performTransaction, std::ref(account), -800, std::move(promises[3]));

    // Join all threads
    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    // Collect and print the results
    for (size_t i = 0; i < futures.size(); ++i) {
        try {
            int result = futures[i].get();
            std::cout << "Final balance after transaction " << i + 1 << ": " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception in thread " << i + 1 << ": " << e.what() << std::endl;
        }
    }

    std::cout << "Final Account Balance: " << account.getBalance() << std::endl;
    return 0;
}
