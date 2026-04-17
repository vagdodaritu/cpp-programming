#include <iostream>
#include <string>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel() {
        fuelType = "unknown";
    }

    Fuel(string f) {
        if (f == "petrol" || f == "diesel" || f == "electric")
            fuelType = f;
        else
            fuelType = "unknown";
    }
};

class Brand {
protected:
    string brandName;
public:
    Brand() {
        brandName = "unknown";
    }

    Brand(string b) {
        brandName = b;
    }
};

class Car : public Fuel, public Brand {
public:
    Car() : Fuel(), Brand() {}

    Car(string f, string b) : Fuel(f), Brand(b) {}

    void display() {
        cout << "Brand: " << brandName << " | Fuel: " << fuelType << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of cars: ";
    cin >> n;

    Car* queueCars = new Car[n];

    string fuel, brand;

    for (int i = 0; i < n; i++) {
        cout << "Enter brand and fuel type: ";
        cin >> brand >> fuel;
        queueCars[i] = Car(fuel, brand);
    }

    cout << "\nQueue Processing:\n";
    for (int i = 0; i < n; i++) {
        queueCars[i].display();
    }

    delete[] queueCars;

    cout << "\nStatic Method:\n";

    Car staticCars[3] = {
        Car("petrol", "Toyota"),
        Car("diesel", "Mahindra"),
        Car("electric", "Tesla")
    };

    for (int i = 0; i < 3; i++) {
        staticCars[i].display();
    }

    return 0;
}

