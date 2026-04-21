#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:

    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }
    Complex operator + (Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator - (Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex result;
    result = c1 + c2;
    cout << "Addition: ";
    result.display();
    result = c1 - c2;
    cout << "Subtraction: ";
    result.display();
    Complex c3(10, -2), c4(3, 7);
    result = c3 + c4;
    cout << "Addition: ";
    result.display();
    result = c3 - c4;
    cout << "Subtraction: ";
    result.display();

    return 0;
}
