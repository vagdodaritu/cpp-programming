#include<iostream>
using namespace std;

class Shape {
protected:
    float radius;
public:
    void setRadius(float r) {
        if (r > 0)
            radius = r;
        else
            radius = 0;
    }

    float getRadius() {
        return radius;
    }
};


class Circle : public Shape {
public:
    float area() {
        return 3.1416 * radius * radius;
    }
};

int main() {

    int n;
    cout << "Enter number of circles : ";
    cin >> n;

    Circle c[100];

    for (int i = 0; i < n; i++) {
        float r;
        cout << "enter radius of circle " << i + 1 << ": ";
        cin >> r;
        c[i].setRadius(r);
    }


    for (int i = 0; i < n; i++) {
        cout << "circle " << i + 1
             << " area = " << c[i].area() << endl;
    }


    int m;
    cout << "\nEnter number of circles : ";
    cin >> m;

    Circle* d = new Circle[m];

    for (int i = 0; i < m; i++) {
        float r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;
        d[i].setRadius(r);
    }

    cout << "\nAreas :\n";
    for (int i = 0; i < m; i++) {
        cout << "Circle " << i + 1
             << " Area = " << d[i].area() << endl;
    }

    delete[] d;

    return 0;
}
