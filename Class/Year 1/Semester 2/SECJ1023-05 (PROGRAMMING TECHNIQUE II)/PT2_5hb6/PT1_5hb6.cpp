#include <iostream>
using namespace std;

class Parent {
    public:
    virtual void print() = 0; // Pure virtual function

};

class Child: public Parent {
    public:
    void print() 
};

int main() {
    Parent *p;
    Child c;

    system("pause");
    return 0;
}