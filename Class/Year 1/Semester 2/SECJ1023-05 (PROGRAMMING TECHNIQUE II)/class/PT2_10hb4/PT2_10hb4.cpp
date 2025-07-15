#include <iostream>
using namespace std;

class Rectangle {
    int width, length;

    public :
    Rectangle () {
        width = 5;
        length = 5;
        cout << "No argument constructor\n";
    }
    Rectangle (int w) {
        width = 5;
        length = 5;
        cout << "1 - argument constructor\n";
    }
    Rectangle (int w, int l) {
        width = 5;
        length = 5;
        cout << "2 - argument constructor\n";
    }
    
    ~Rectangle() {
        cout << "Object with witdh = " << width << " is destroyed." << endl;
    }

    // Mutators
        setwitdh(int w) {
        width = w;
    } 

    void setlength(int l) {
        length = l;
    }

    // Accessors
    int getwidth() const {
        return width;
    }

    int getLength() const {
        return length;
    }
}

int main() {
    Rectangle r1(20);
    Rectangle r2(50,30);
    Rectangle *r;
    
    r = new Rectangle(99);
    Rectangle r3;

    // Explicit function call
    // r.getLength(10);
    // r.getwidth(5);
    delete r;

    system("pause");
    return 0;

}