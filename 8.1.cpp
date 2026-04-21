#include <iostream>
using namespace std;
int main() {
    int a, b;
   try {
        if (!(cin >> a)) {
            throw "Invalid input for numerator!";
        }
        if (!(cin >> b)) {
            throw "Invalid input for denominator!";
        }

        if (b == 0) {
            throw b;
        }
        cout << "Result = " << (a / b) << endl;
    }
      catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
      catch (int) {
        cout << "Error: Division by zero is not allowed!" << endl;
    }
    return 0;
}

