#include<iostream>
#include<string>
using namespace std;

 class DigitalAccount{
  private:
     int accountID;
     string coustomername;
     double balance;

  public:
     DigitalAccount(int id, string name) {
        accountID = id;
        coustomername = name;
        balance = 0.0;
    }
    DigitalAccount(int id, string name, double initialBalance) {
        accountID = id;
        coustomername = name;

        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0.0;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Withdrawal failed! Insufficient balance." << endl;
        }
    }
    void displayAccount() {
        cout << " Account Summary " << endl;
        cout << "Customer Name : " << coustomername << endl;
        cout << "Account ID    : " << accountID << endl;
        cout << "Balance       : " << balance << endl;
    }
 };
 int main()
 {
     DigitalAccount acc1(105, "hetvi");
    DigitalAccount acc2(106, "feni", 5000);

    acc1.deposit(2000);
    acc1.withdraw(500);

    acc2.deposit(1500);
    acc2.withdraw(8000);

    acc1.displayAccount();
    acc2.displayAccount();

    return 0;
 }

