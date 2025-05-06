//(c) 24L - 6116

#include <iostream>
using namespace std;

class bankAccount {
protected:
    int accountNumber;
    double balance;
public:
    bankAccount() {accountNumber = 0; balance = 0.0;}
    bankAccount(int accNum = 0, double bal = 0.0) : accountNumber(accNum), balance(bal) {}

    void setAccountNumber(int accNum) {accountNumber = accNum;}
    int getAccountNumber() const {return accountNumber;}
    void setBalance (double accBal) {balance = accBal;}
    double getBalance() const {return balance;}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Insufficient funds" << endl;
        }
    }

    void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl << "Balance: " << balance << endl;
    }
};

class savingsAccount : public bankAccount {
private:
    double interestRate;
public:
    savingsAccount(int accNum = 0, double bal = 0.0, double rate = 0.0) : bankAccount(accNum, bal), interestRate(rate) {}
    void setInterestRate(double rate) {interestRate = rate;}
    double getInterestRate() const {return interestRate;}
    void applyInterest() {balance += balance * (interestRate / 100);}
    void printAccountInfo() const {
        cout << "Savings Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
    }
};

int main() {
    savingsAccount acc(123456, 1000, 13);

    acc.printAccountInfo();

    acc.deposit(500);
    cout << endl << "After depositing 500:" << endl;
    acc.printAccountInfo();

    acc.withdraw(300);
    cout << endl << "After withdrawing 300:" << endl;
    acc.printAccountInfo();

    acc.applyInterest();
    cout << endl <<"After applying interest:" << endl;
    acc.printAccountInfo();

    return 0;
}

/*Exercise 2: (10 points)
Define a class called bankAccount to store a bank customer’s account number and balance.
Suppose that account number is of type int, and balance is of type double. Your class should, at
least, provide the following operations: set the account number, retrieve the account number,
retrieve the balance, deposit and withdraw money, and print account information. Add
appropriate constructors.

Every bank offers a savings account. Derive the class savingsAccount from the class
bankAccount. This class inherits members to store the account number and the balance from the
base class. A customer with a savings account typically receives interest, makes deposits, and
withdraws money. In addition to the operations inherited from the base class, this class should
provide the following operations: set interest rate, retrieve interest rate, post interest and print
account information. Add appropriate constructors.

Write a program to test your classes designed. */