#include <iostream>
using namespace std;

class gradingsystem {
protected:
    int marks;

public:
    gradingsystem(int m) {
        marks = m;
    }
    virtual char computegrade() = 0;

    virtual void display() = 0;

    //virtual ~gradingsystem() {}
};

class undergraduate : public gradingsystem {
    string name;

public:
    undergraduate(string n, int m) : gradingsystem(m), name(n) {}

    char computegrade() override {
        if (marks >= 75) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }

    void display() override {
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << computegrade() << endl;
    }
};
class postgraduate : public gradingsystem {
    string name;

public:
    postgraduate(string n, int m) : gradingsystem(m), name(n) {}

    char computegrade() override {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 60) return 'C';
        else return 'F';
    }

    void display() override {

        cout << "\nname: " << name;
        cout << "\nmarks: " << marks;
        cout << "\ngrade: " << computegrade() << endl;
    }
};

int main() {
    gradingsystem* students[100];
    int count = 0;

    int choice, marks;
    string name;

    do {
        cout << "\n1. add undergraduate student";
        cout << "\n2. add postgraduate student";
        cout << "\n3. display all students";
        cout << "\n4. exit";
        cout << "\nenter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nenter name: ";
            cin >> name;
            cout << "enter marks: ";
            cin >> marks;

            students[count++] = new undergraduate(name, marks);
            break;

        case 2:
            cout << "\nenter name: ";
            cin >> name;
            cout << "enter marks: ";
            cin >> marks;

            students[count++] = new postgraduate(name, marks);
            break;

        case 3:

            for (int i = 0; i < count; i++) {
                students[i]->display();
            }
            break;

        case 4:
            cout << "\nexit\n";
            break;

        default:
            cout << "\ninvalid";
        }

    } while (choice != 4);


    for (int i = 0; i < count; i++) {
        delete students[i];
    }

    return 0;
}

