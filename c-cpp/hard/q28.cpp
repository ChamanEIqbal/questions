/*
Challenge: The Bank Robbery (Concurrency)

Scenario:
A shared bank account starts with $1000, and multiple threads represent customers.
Race conditions allow the balance to drop below zero.

Problem: they are not customers, but are robbers.

Debugging Tasks:
Mutually Exclude all shared variables from the threads using them.
*/

#include <iostream>
#include <thread>
#include <vector>

using namespace std::count, std::endl;

class BankAccount {
    int balance;

public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    void withdraw(int amount) {
        if (balance >= amount) {
            cout << "Processing withdrawal of " << amount << "...\n";
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << "\n";
        } else {
            cout << "Withdrawal denied. Insufficient funds.\n";
        }
    }

    int getBalance() {
        return balance;
    }
};

void customer(BankAccount& account, int amount) {
    for (int i = 0; i < 5; ++i) {
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account(1000);
    vector<thread> threads;

    for (int i = 0; i < 3; ++i) {
        threads.push_back(thread(customer, ref(account), 400));
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "Final Balance: " << account.getBalance() << "\n";
    return 0; // Expected output, should allow 2 customers to withdraw 400
}
