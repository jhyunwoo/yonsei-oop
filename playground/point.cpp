#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;


public:
    static int maxSize;

    Point(const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }

    void move(const int x, const int y)
    {
        this->x += x;
        this->y += y;
    }

    void print() const
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << maxSize << endl;
    }
};
int Point::maxSize = 10;

int main()
{
    Point car(1, 2);
    car.move(2, 3);
    car.print();
    Point::maxSize = 20;
    Point psc(1,2);
    psc.print();
    car.move(-1, 5);
    car.print();
    return 0;
}