#include <iostream>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point(const Point &p) : x(p.x), y(p.y) {}
    Point() : x(0.0), y(0.0) {}

    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    void input() {
        cout << "Enter the coordinates (x and y) => ";
        cin >> x >> y;
    }

    Point add(const Point &right) {
        return Point(x + right.x, y + right.y);
    }

    Point operator+(const Point &right) {
        return Point(x + right.x, y + right.y);
    }

    Point divide(int n) {
        return Point(x / n, y / n);
    }

    Point operator/(int n) {
        return Point(x / n, y / n);
    }

    friend Point addPoints(const Point &, const Point &);
    friend Point dividePoint(Point, int);
};

Point addPoints(const Point &p1, const Point &p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point dividePoint(Point p, int n) {
    return Point(p.x / n, p.y / n);
}

int main() {
    int nPoint;
    cout << "How many points you want to enter => ";
    cin >> nPoint;
    cout << endl;

    Point* arrPoints = new Point[nPoint];
    Point sum1, sum2, sum3;

    for (int i = 0; i < nPoint; i++) {
        arrPoints[i].input();
    }

    for (int i = 0; i < nPoint; i++) {
        sum1 = sum1.add(arrPoints[i]);
        sum2 = sum2 + arrPoints[i];
        sum3 = addPoints(sum3, arrPoints[i]);
    }

    Point div1, div2, div3;
    div1 = sum1.divide(nPoint);
    div2 = sum2 / nPoint;
    div3 = dividePoint(sum3, nPoint);

    cout << endl;

    cout << "Printing all points" << endl;
    
    for (int i = 0; i < nPoint; i++) {
        arrPoints[i].print();
    }

    cout << endl;

    cout << "Printing the middle point with different approaches" << endl;
    div1.print();
    div2.print();
    div3.print();

    delete[] arrPoints;
    system("pause");
    return 0;
}
