#include <iostream>
using namespace std;

class Base {
    private:
        int x;
    protected:
        int y;
    public:
        int z;
};

class Derived1 : private Base {
    public:
        void print() {
            cout << y << z << endl;
        }
};

class Derived2 : public Derived1 {
    public:
        void print() {
            cout << y << z << endl;
        }
};

int main() {
    Derived1 d1;
    d1.print();

    Derived2 d2;
    d2.print();

    system("pause");
    return 0;
}