#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    Loan();
    Loan(int, string, double, double, int);
    void inputLoan();
    double calculateEMI() const;
    void displayLoan() const;
};

Loan::Loan() {
    loanID = 0;
    applicantName = "";
    loanAmount = 0.0;
    annualInterestRate = 0.0;
    tenureMonths = 0;
}

Loan::Loan(int id, string name, double amount, double rate, int tenure) {
    loanID = id;
    applicantName = name;
    loanAmount = amount;
    annualInterestRate = rate;
    tenureMonths = tenure;
}

void Loan::inputLoan() {
    cout << "Enter Loan ID: ";
    cin >> loanID;

    cout << "Enter Applicant Name: ";
    cin.ignore();
    getline(cin, applicantName);

    cout << "Enter Loan Amount: ";
    cin >> loanAmount;

    cout << "Enter Annual Interest Rate (%): ";
    cin >> annualInterestRate;

    cout << "Enter Loan Tenure (months): ";
    cin >> tenureMonths;
}

double Loan::calculateEMI() const {
    if (loanAmount <= 0 || annualInterestRate < 0 || tenureMonths <= 0)
        return 0;

    double monthlyRate = annualInterestRate / (12 * 100);
    double emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
                 (pow(1 + monthlyRate, tenureMonths) - 1);
    return emi;
}

void Loan::displayLoan() const {
    cout << "\nLoan ID: " << loanID;
    cout << "\nApplicant Name: " << applicantName;
    cout << "\nLoan Amount: " << loanAmount;
    cout << "\nAnnual Interest Rate: " << annualInterestRate << "%";
    cout << "\nLoan Tenure: " << tenureMonths << " months";
    cout << "\nMonthly EMI: " << calculateEMI() << endl;
}

int main() {
    int choice;

    cout << "1. Use Default Constructor\n";
    cout << "2. Use Parameterized Constructor\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        Loan loan1;
        loan1.inputLoan();
        loan1.displayLoan();
    }
    else if (choice == 2) {
        int id;
        string name;
        double amount, rate;
        int tenure;

        cout << "Enter Loan ID: ";
        cin >> id;

        cout << "Enter Applicant Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Loan Amount: ";
        cin >> amount;

        cout << "Enter Annual Interest Rate (%): ";
        cin >> rate;

        cout << "Enter Loan Tenure (months): ";
        cin >> tenure;

        Loan loan2(id, name, amount, rate, tenure);
        loan2.displayLoan();
    }
    else {
        cout << "Invalid choice";
    }

    return 0;
}
