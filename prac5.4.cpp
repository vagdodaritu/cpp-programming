#include <iostream>
#include <iomanip>
using namespace std;


ostream& currency(ostream& output) {
    output << "₹";
    return output;
}

int main() {

    string name[] = {"abc", "def", "ghi"};
    int marks[] = {85, 92, 78};
    float fees[] = {25000.5, 30000.75, 22000.25};
    int percent;

    int n = 3;


    cout << setfill('=') << setw(50) << "=" << endl;
    cout << setfill(' ')
         << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(10) << "Percent"
         << setw(15) << "Fees" << endl;
    cout << setfill('-') << setw(50) << "-" << endl;


    for (int i = 0; i < n; i++) {

        cout << setfill(' ')
             << left << setw(15) << name[i]
             << right << setw(10) << marks[i]
             << setw(10) << fixed << setprecision(2) << percent
             << setw(10) << currency << fixed << setprecision(2) << fees[i]
             << endl;
    }

    cout << setfill('=') << setw(50) << "=" << endl;

    return 0;
}
