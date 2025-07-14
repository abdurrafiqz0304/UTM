#include <iostream>
using namespace std;

class Point; // forward declaration

class Extra {
    public:
        static void print(Point);
};

class Point {
    int x, y;

    public:
        Point(int _x=5, int _y=5) {
            x = _x;
            y = _y;
        }

        friend void print(Point); // stand-alone function
        friend class Extra; // Allow Extra class to access private members
};

void print(Point p) { // Access all information in Point class object
    cout << "Coordinate using stand alone function: (" << p.x << ", " << p.y << ")" << endl;
}

void Extra::print(Point p) { // Access only coordinate of Point class object
    cout << "Coordinate using friend with Extra class: (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    Point p(3, 6); // Define the Point object once
    Extra e;
    
    e.print(p);
    print(p);

    cin.get(); // Use cin.get() for a pause
    return 0;
}
