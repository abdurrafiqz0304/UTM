#include <iostream>
using namespace std;

class Point {
    int x, y;

    public:
        Point(): x(0), y(0) {
            cout << "1-arg constructor\n";
        } 
        
        Point(int _x): x(_x), y(3) {
            cout << "2-arg constructor\n";
        } 

        Point(int _x, int _y): x(_x), y(_y) {
            cout << "3-arg constructor\n";
        } 
    };

int main() {
    Point pArr[5] = {Point(), 33, Point(1), Point(2, 3)}; // 1-arg constructor

    system("pause");
    return 0;
}