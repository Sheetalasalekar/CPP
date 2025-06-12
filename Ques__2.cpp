/*
 * Ques_2.cpp
 *Q2. Create a C++ program for a simple banking system. You need to implement a class
called
1. BankAccount with the following data members:
2. accountNumber (int): The account number of the bank account.
3. accountHolderName (string): The name of the account holder.
4. balance (double): The current balance in the account.
The BankAccount class should have the following member functions:
1. Getter and Setter Methods:
2. deposit method: A method that allows the user to deposit money into the account. It
should take an amount as a parameter and update the balance accordingly.
3. withdraw method: A method that allows the user to withdraw money from the
account. It should take an amount as a parameter and update the balance. Make sure
to check if there is sufficient balance before allowing the withdrawal.
4. displayAccountDetails method: A method that displays the account details (
account number, account holder name, and balance).
Now, create a menu-driven program in the `main` function that allows the user to perform the
following operations:
1. Deposit money into an existing account.
2. Withdraw money from an existing account.
3. Display the account details.
4. Exit the program.
 *

 */

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = initialBalance;
    }

    // Getters
    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    // Setters
    void setAccountHolderName(string name) {
        accountHolderName = name;
    }

    void setBalance(double amount) {
        balance = amount;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        } else {
            cout << "Invalid amount! Deposit failed.\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Withdrawal failed.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance! Withdrawal failed.\n";
        } else {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        }
    }

    // Display account details
    void displayAccountDetails() const {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Current Balance: ₹" << balance << endl;
        cout << "----------------------------\n";
    }
};

int main() {
    int accNo;
    string name;
    double initialBalance;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cin.ignore(); // To clear newline character
    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Initial Balance: ₹";
    cin >> initialBalance;

    BankAccount account(accNo, name, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n==== Banking System Menu ====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ₹";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ₹";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.displayAccountDetails();
                break;

            case 4:
                cout << "Thank you for using our banking system.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}



