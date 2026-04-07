#include <iostream>
using namespace std;

class employee {
private:
    string name;
    float basicsalary;
    float bonus;

public:

    employee(string n = "", float b = 0, float bon = 1000) {
        name = n;
        basicsalary = b;
        bonus = bon;
    }


    inline float calculatesalary() {
        return basicsalary + bonus;
    }

    void input() {
        int choice;
        cout << "\nEnter Name: ";
        cin >> name;

        cout << "Enter Basic Salary: ";
        cin >> basicsalary;

        cout << "Use default bonus? (1-Yes / 0-No): ";
        cin >> choice;

        if(choice == 0) {
            cout << "enter bonus: ";
            cin >> bonus;
        } else {
            bonus = 1000;
        }
    }

    void display() {
        cout << "name: " << name;
        cout << "basic Salary: " << basicsalary;
        cout << "bonus: " << bonus;
        cout << "total salary: " << calculatesalary() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;


    employee* emp = new employee[n];

    for(int i = 0; i < n; i++) {
        cout << "\n--- employee " << i+1 << " ---";
        emp[i].input();
    }

    cout << "--- employee details ---";
    for(int i = 0; i < n; i++) {
        emp[i].display();
    }

    delete[] emp;

    return 0;
}
