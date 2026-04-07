#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string name;
    int m1, m2, m3;
    int average;

public:
    Student(int r, string n, int a, int b, int c) {
        roll = r;
        name = n;
        m1 = (a >= 0 && a <= 100) ? a : 0;
        m2 = (b >= 0 && b <= 100) ? b : 0;
        m3 = (c >= 0 && c <= 100) ? c : 0;

        average = (m1 + m2 + m3) / 3;
    }

    void display() {
        cout << "Roll No : " << roll << endl;
        cout << "Name    : " << name << endl;
        cout << "Marks   : " << m1 << ", " << m2 << ", " << m3 << endl;
        cout << "Average : " << average << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student* students[n];

    for (int i = 0; i < n; i++) {
        int roll, m1, m2, m3;
        string name;

        cout << "\nEnter details of student " << i + 1 << endl;
        cout << "Roll No: ";
        cin >> roll;

        cout << "Name: ";
        cin >> name;

        cout << "Marks in 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        students[i] = new Student(roll, name, m1, m2, m3);
    }

    cout << " Student Records";
    for (int i = 0; i < n; i++) {
        students[i]->display();
    }

    return 0;
}
