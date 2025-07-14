#include <iostream>
using namespace std;

template <class A>
A findMax(A n1, A n2) {
    return (n1 > n2) ? n1 : n2;
}

template <class B, class C>
void display(B b, C c) {
    cout << b << " + " << c << endl;
}

template <class D>
class Point {


    D x, y;

    public:
    void set(D _x, D _y) {
        x = _x;
        y = _y;
    }

    void display(string label) {
        cout << label << ": " << x << ", " << y << endl;
    }
};

int main() {

    cout << "Max = " << findMax(4.5, 1.2) << endl;
    display("Hello", 90);
    display(3.4, 'A');
    display("Good", "Morning");

    Point<char> p1;
    Point<int> p2;
    Point<string> p3;

    p3.set("X", "Y");
    p1.set('a', 'b');
    p2.set(1, 2);

    p1.display("Characters");
    p2.display("Integers");
    p3.display("Strings");

    system("pause");
    return 0;
}