#include <iostream>
using namespace std;
class Shape {
public:
    virtual float Area() = 0;};


class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float Area() {
        return length * width;
    }
};
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float Area() {
        return 3.14 * radius * radius;
    }
};
int main() {

Shape* shapes[2];

shapes[0] = new Rectangle(5, 3);
shapes[1] = new Circle(2.5);

    for (int i = 0; i < 2; i++) {
        cout << shapes[i]->Area() << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }
cout<<"static"<<endl;
    Rectangle r1(4, 6);
    Circle c1(3);

    Shape* arr[2];
    arr[0] = &r1;
    arr[1] = &c1;

    for (int i = 0; i < 2; i++) {
        cout << "Area: " << arr[i]->Area() << endl;
    }

    return 0;
}
