#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    float temp;

public:
    Celsius(float t = 0) {
     temp = t; }
   float getTemp() { return temp; }
   operator Fahrenheit();
   bool operator == (Celsius c) {
        return temp == c.temp;
    }

    void display() {
        cout << temp << " °C" << endl;
    }
};
class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit(float t = 0) { temp = t; }

    float getTemp() { return temp; }
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }
    bool operator == (Fahrenheit f) {
        return temp == f.temp;
    }

    void display() {
        cout << temp << " °F" << endl;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}


int main() {


    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;
    cout << "Celsius to Fahrenheit: ";
    f1.display();

    Celsius c2;
    c2 = f1;
    cout << "Fahrenheit to Celsius: ";
    c2.display();


    Celsius c3(25);
    if (c1 == c3)
        cout << "Celsius values are equal\n";

    Fahrenheit f2(77);
    if (f1 == f2)
        cout << "Fahrenheit values are equal\n";
    Celsius arr[3];

    arr[0] = Celsius(10);
    arr[1] = Celsius(20);
    arr[2] = Celsius(30);
    for (int i = 0; i < 3; i++) {
        arr[i].display();
    }
    cout << "\nConverted to Fahrenheit:\n";
    for (int i = 0; i < 3; i++) {
        Fahrenheit tempF = arr[i];
        tempF.display();
    }

    return 0;
}

