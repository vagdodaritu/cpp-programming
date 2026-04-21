#include <iostream>
#include <string>
using namespace std;

string logs[100];
int logindex = 0;
void addlog(string msg) {
    logs[logindex++] = msg;
}
class insufficientbalanceexception {
public:
    const char* message() const {
        return "error: Insufficient balance!";
    }
};

class invalidamountexception {
public:
    const char* message() const {
        return "Error: Invalid amount!";
    }
};
class bankaccount {
private:
    double balance;

public:
    bankaccount(double b) {
        balance = b;
        addlog("bankaccount constructor called");
    }

    void deposit(double amount) {
        addlog("entered deposit()");

        if (amount <= 0) {
            throw invalidamountexception();
        }

        balance += amount;
        addlog("deposit successful");

        addlog("exiting deposit()");
    }

    void withdraw(double amount) {
        addlog("entered withdraw()");

        if (amount <= 0) {
            throw invalidamountexception();
        }

        if (amount > balance) {
            throw insufficientbalanceexception();
        }

        balance -= amount;
        addlog("withdrawal successful");

        addlog("exiting withdraw()");
    }

    double getbalance() {
        return balance;
    }
};
void processwithdraw(bankaccount &acc, double amt) {
    addlog("entered processwithdraw()");
    acc.withdraw(amt);

    addlog("exiting processwithdraw()");
}


void performtransaction(bankaccount &acc, double amt) {
    addlog("entered performtransaction()");

    processwithdraw(acc, amt);

    addlog("exiting performtransaction()");
}

int main() {
    bankaccount acc(1000);

    try {
        addlog("Entered main try block");

        performtransaction(acc, 1500);

        addlog("transaction completed");
    }
    catch (insufficientbalanceexception e) {
        addlog("Caught InsufficientBalanceException in main");
        cout << e.message() << endl;
    }
    catch (invalidamountexception e) {
        addlog("Caught InvalidAmountException in main");
        cout << e.message() << endl;
    }


    cout << "\n--- Transaction Logs ---\n";
    for (int i = 0; i < logindex; i++) {
        cout << logs[i] << endl;
    }

    return 0;
}

