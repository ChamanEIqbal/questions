"""
Challenge: The Bank Robbery (Concurrency)

Scenario:
A shared bank account starts with $1000, and multiple threads represent customers.
Race conditions allow the balance to drop below zero.

Problem: they are not customers, but are robbers.

Debugging Tasks:
Mutually Exclude all shared variables from the threads using them.
"""

import threading

class BankAccount:
    def __init__(self, initial_balance):
        self.balance = initial_balance

    def withdraw(self, amount):
        if self.balance >= amount:
            print(f"Processing withdrawal of {amount}...")
            self.balance -= amount
            print(f"Withdrawal successful. Remaining balance: {self.balance}")
        else:
            print(f"Withdrawal of {amount} denied. Insufficient funds.")

    def get_balance(self):
        return self.balance

class Customer(threading.Thread):
    def __init__(self, account, withdrawal_amount):
        threading.Thread.__init__(self)
        self.account = account
        self.withdrawal_amount = withdrawal_amount

    def run(self):
        for _ in range(5):
            self.account.withdraw(self.withdrawal_amount)

if __name__ == "__main__":
    account = BankAccount(1000)

    customer1 = Customer(account, 400)
    customer2 = Customer(account, 400)
    customer3 = Customer(account, 400)

    customer1.start()
    customer2.start()
    customer3.start()

    customer1.join()
    customer2.join()
    customer3.join()

    print(f"Final balance: {account.get_balance()}")
