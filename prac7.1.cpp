#include <iostream>
using namespace std;

class calculator {
private:
    float results[50];
    int index;

public:

    calculator() {
        index = 0;
    }


    int add(int a, int b) {
        int res = a + b;
        results[index++] = res;
        return res;
    }

    float add(float a, float b) {
        float res = a + b;
        results[index++] = res;
        return res;
    }

    float add(int a, float b) {
        float res = a + b;
        results[index++] = res;
        return res;
    }

    float add(float a, int b) {
        float res = a + b;
        results[index++] = res;
        return res;
    }


    void displayResults() {cout << "\nStored Results:\n";
        for (int i = 0; i < index; i++) {
            cout << "Result " << i + 1 << " = " << results[i] << endl;
        }
    }
};


int main() {
    calculator calc;

    cout << "Addition of integers: " << calc.add(10, 20) << endl;
    cout << "Addition of floats: " << calc.add(5.5f, 2.3f) << endl;
    cout << "Mixed (int, float): " << calc.add(10, 3.5f) << endl;
    cout << "Mixed (float, int): " << calc.add(2.5f, 4) << endl;

    calc.displayResults();

    return 0;
}

