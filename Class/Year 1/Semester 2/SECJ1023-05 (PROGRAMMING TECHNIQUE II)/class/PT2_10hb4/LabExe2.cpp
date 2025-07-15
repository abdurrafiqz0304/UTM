#include <iostream>
#include <iomanip>
using namespace std;

class Stock {
    string code, name;
    double closePrice, currentPrice;
    
    public :
    // Constructor
   Stock (string n="", string c="" , double clP=0, double cuP=0,) : code(c), name(n) {
    closePrice = clP;
    currentPrice = cuP;
    cout << "Creating object: " << name << endl;
    }

    // Destructor
    ~Stock() {
        cout << "Object " << code << " destroyed" << endl;
    }

    // Accessor
    string getCode() const {return code;}
    string getName() const {return name;}

    // Mutator
    void setCode(string c) {code = c;}
    void setName(string n) {name = n;}
    void setClosePrice(double c) {closePrice = clP;}
    void setCurrentPrice(double c) {currentPrice = cuP;}

    // Other function
    double changePercent() const {
        return (currentPrice / closePrice)
    }

    void display() const {
        double chPercent = changePercent();
        cout << "Close price : RM" << closePrice << endl;
        cout << "Current price: RM" << currentPrice << endl;
        cout << "Price change percentage: " << ((chPercent > 0)? "+" : "" << chPercent) << "%" << endl;
    }
}

int main() {
    Stock s1("Maybank", "MBB", 5500);
    Stock s2("CIMB Bank Berhad");

    cout << fixed << setprecision(2);
    s1.currentPrice(5250);
    s2.setCode("CIMB");
    s2.setClosePrice(10000);
    s2.setCurrPrice(15050);

    cout << "\nStock: " << s1.getName()
         << " (" << s1.getCode() << ")\n";
         s1.display();

    system("pause");
    return 0;
}