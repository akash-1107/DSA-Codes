// Question 5: Encapsulation and Access Specifiers

// 5. Design a class BankAccount with private attributes accountNumber, balance, and a public method withdraw() to deduct a specified amount from the balance. Implement encapsulation by providing accessors and mutators for the private attributes.

#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int num, double bal) {
     accountNumber =(num); 
     balance = (bal) ;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

int main() {
    BankAccount account(12345, 1000.0);
    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Balance: " << account.getBalance() << endl;

    account.withdraw(500.0);
    account.withdraw(800.0);

    return 0;
}
