#include <iostream>
using namespace std;

class Chemical {
    private:
        string name, symbol;
        int atomicNumber;
        double atomicWeight;

    public:
        // Regular functions
        void setName(string);
        void setSymbol(string);
        void setNumber(int);
        void setWeight(double);
        void readInput();

        // inline functions
        string getName() { return name;}
        string getSymbol() { return symbol;}
        int getNumber() { return atomicNumber;}
        double getWeight() {return atomicWeight;}
};

void Chemical::setName(string n) {
    name = n;
}

void Chemical::setSymbol(string s) {
    symbol = s;
}

void Chemical::setNumber(int n) {
    atomicNumber = m;
}

void Chemical::setWeight(double w) {
    atomicWeight = w;
}

void Chemical::readInput() {
    cout << "Please enter the requested information to create a new chemical object." << endl;
         << "Eter the chemical's name: ";
    cin >> name;
    cout << "Enter the chemical's symbol: ";
    cin >> symbol;
    cout << "Enter the chemical's atomic number: ";
    cin >> atomicNumber;
    cout << "Enter the chemical's atomic weight: ";
    cin >> atomicWeight;
}

int main(){
    Chemical c1, c2; // c1-H, c2-Na

    c1.readInput();
    cout << "You just entered information for " << c1.getName() << ".\n\n";
    cout << "And here are the details: " << c1.getName()
         << " [" << c1.getSymbol() << ", #" << c1.getNumber() << ", " << c1.getWeight() << "]\n";

    // mutator
    c2.setname("Sodium");
    c2.setSymbol("Na");
    c2.setNumber(11);
    c2.setWeight(22.98977);

    cout << "Here is another chemical: " << c2.getName() << ".\n\n";
    cout << "And here are the details: " << c2.getName()
         << " [" << c2.getSymbol() << ", #" << c2.getNumber() << ", " << c2.getWeight() << "]\n";

         system("pause");
         return 0;
}