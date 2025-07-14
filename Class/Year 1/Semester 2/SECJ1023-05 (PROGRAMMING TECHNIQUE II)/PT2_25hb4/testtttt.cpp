#include <iostream>
using namespace std;

typedef double(Binaryfunction)(double, double);

void doCalculation(double a, double b, Binaryfunction f){
    double r = f(2,3);
    cout << "result: " << r << endl;
}

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }

int main() {
    doCalculation(2,3, add);
    doCalculation(10, 5, sub);
    
    system("pause");
    return 0;
}
