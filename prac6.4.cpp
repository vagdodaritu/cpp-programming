#include <iostream>
using namespace std;


struct Transaction {
    string type;
    double amount;
};


class Account {
protected:
    int accountNumber;
    double balance;

    Transaction history[100];
    int top;

public:

    Account(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
        top = -1;
    }


    virtual ~Account() {
        cout << "Account " << accountNumber << " closed.\n";
    }


    virtual void deposit(double amount) {
        balance += amount;

        top++;
        history[top].type = "deposit";
        history[top].amount = amount;
    }


    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;

            top++;
            history[top].type = "withdraw";
            history[top].amount = amount;
        } else {
            cout << "Insufficient balance!\n";
        }
    }


    void undoLastTransaction() {
        if (top == -1) {
            cout << "No transactions to undo.\n";
            return;
        }

        Transaction last = history[top];

        if (last.type == "deposit") {
            balance -= last.amount;
        } else if (last.type == "withdraw") {
            balance += last.amount;
        }

        cout << "Last transaction undone.\n";
    }


    virtual void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, double bal, double rate)
        : Account(accNo, bal) {
        interestRate = rate;
    }

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;

        top++;
        history[top].type = "interest";
        history[top].amount = interest;
    }

    void display() override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};


class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, double bal, double limit)
        : Account(accNo, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;

            top++;
            history[top].type = "withdraw";
            history[top].amount = amount;
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void display() override {
        Account::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};


int main() {
    SavingsAccount s1(101, 5000, 5);
    CurrentAccount c1(201, 3000, 2000);

    s1.deposit(1000);
    s1.addInterest();
    s1.withdraw(2000);
    s1.display();

    cout << "\nUndo last transaction:\n";
    s1.undoLastTransaction();
    s1.display();

    cout << "\n------------------\n";

    c1.deposit(2000);
    c1.withdraw(4500);
    c1.display();

    cout << "\nUndo last transaction:\n";
    c1.undoLastTransaction();
    c1.display();

    return 0;
}
