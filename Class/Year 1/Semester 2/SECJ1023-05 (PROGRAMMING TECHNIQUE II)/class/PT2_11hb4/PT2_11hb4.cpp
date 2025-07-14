#include <iostream>
#include <cmath>
using namespace std;

class Compute {

    private:
    double a, b, c;
    double discriminant;

    public:
    // Constructor definition
    Compute(double a, double b, double c) : a(a), b(b), c(c) {
        calcDiscriminant();
    }

    // Function to calculate the discriminant
    void calcDiscriminant() {
        discriminant = pow(b, 2) - 4 * a * c;
    }

    // Function to calculate the positive root
    double positive_root() {
        return (-b + sqrt(discriminant)) / (2 * a);
    }

    // Function to calculate the negative root
    double negative_root() {
        return (-b - sqrt(discriminant)) / (2 * a);
    }

    void setA(double num_a) { a = num_a; }
    void setB(double num_b) { b = num_b; }
    void setC(double num_c) { c = num_c; }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
};

// Program 3.2
int main() {

    double a, b, c;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;

    // (a) Pass arguments a, b, c to the constructor
    Compute compute(a, b, c);

    cout << "The roots of the quadratic equation are x = ";
    // (b) Execute function members to display the value x1
    cout << compute.positive_root();
    cout << ", ";
    // (c) Execute function members to display the value x2
    cout << compute.negative_root() << endl;

    system("pause");
    return 0;
}
