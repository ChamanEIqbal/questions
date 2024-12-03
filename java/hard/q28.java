/*
Challenge: The Bank Robbery (Concurrency)

Scenario:
A shared bank account starts with $1000, and multiple threads represent customers.
Race conditions allow the balance to drop below zero.

Problem: they are not customers, but are robbers.

Debugging Tasks:
Mutually Exclude all shared variables from the threads using them.
*/


class BankAccount {
    private int balance;

    public BankAccount(int initialBalance) {
        this.balance = initialBalance;
    }

    public void withdraw(int amount) {
        if (balance >= amount) {
            System.out.println("Processing withdrawal of " + amount + "...");
            balance -= amount;
            System.out.println("Withdrawal successful. Remaining balance: " + balance);
        } else {
            System.out.println("Withdrawal of " + amount + " denied. Insufficient funds.");
        }
    }

    public int getBalance() {
        return balance;
    }
}

class Customer implements Runnable {
    private BankAccount account;
    private int withdrawalAmount;

    public Customer(BankAccount account, int withdrawalAmount) {
        this.account = account;
        this.withdrawalAmount = withdrawalAmount;
    }

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            account.withdraw(withdrawalAmount);
        }
    }
}

public class BankRobbery {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(1000);

        Thread customer1 = new Thread(new Customer(account, 400));
        Thread customer2 = new Thread(new Customer(account, 400));
        Thread customer3 = new Thread(new Customer(account, 400));

        customer1.start();
        customer2.start();
        customer3.start();

        try {
            customer1.join();
            customer2.join();
            customer3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Final balance: " + account.getBalance());
    }
}
