#include <iostream>
#include <cmath>
using namespace std;

class negativenumberexception {
public:
    const char* message() const {
        return "Error: negative number entered";
    }
};
int main() {
    double num;
    char choice;

    do {
        cout << "\nenter a number: ";
        cin >> num;
        try {

            if (num < 0) {
                throw negativenumberexception();
            }
            double result = sqrt(num);
            cout << "Square root of " << num << " is: " << result << endl;
        }
        catch (negativenumberexception e) {
            cout << e.message() << endl;
        }
        cout << "Do you want to enter another number? : ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

