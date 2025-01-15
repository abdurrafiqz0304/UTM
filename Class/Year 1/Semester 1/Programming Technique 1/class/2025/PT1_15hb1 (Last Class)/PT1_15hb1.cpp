#include <iostream>
using namespace std;

int main(){
    struct Point {
        int x, y;
    };

    union Rectangle {
        float width, length;
    };

    enum Fruit {orange, apple=7, grape, banana=2};

    Point p = {2,5};
    Rectangle r = {3};
    Fruit f = grape;

    //f = static_cast<Fruit>(0); OR
    //f = (Fruit) 0; OR
    f = Fruit (0);
    //grape = 4   **cannot, cuz grape is integer constant
    cout << f << '\t' << grape << endl;
    cout << "r: " << r.length << '\t' << r.width << endl;
    cout << "p: " << p.x << '\t' << endl;

    r.width = 4.5;
    p.x = 10;

    cout << "\nr: " << r.length << '\t' << r.width << endl;

    cout << "p: " << p.x << '\t' << endl;

    system("pause");
    return 0;
}