#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor Called" << endl;
    }
};

class Derived : public Base {
    int* data;

public:
    Derived() {
        data = new int[5];
        cout << "Derived Constructor Called" << endl;
    }

    ~Derived() {
        delete[] data;
        cout << "Derived Destructor Called" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}

