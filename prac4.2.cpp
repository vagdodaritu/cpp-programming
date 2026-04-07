#include <iostream>
using namespace std;

class point {
private:
    int x, y;

public:
point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
point& move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return *this;
    }
void display() {
cout << "(" << x << ", " << y << ")" << endl;
    }
};
void movepoint(point* p, int dx, int dy) {
if (p != nullptr) {
        p->move(dx, dy);
    }
}
int main() {

point p(2, 3);
p.display();
p.move(2, 3).move(-1, 4);
p.display();
movepoint(&p, 5, -2);
p.display();

    return 0;
}

