#include <iostream>
#include <iomanip>
using namespace std;

class Stock {

    string code, name;
    double closePrice, currentPrice;

    public:

        Stock(){
            cout << "Check Stock Constructor\n";        
        }

        ~Stock() {
            cout << "Object" << code << "destroyed" << endl;
        }

        //* Mutators
        void setCode(string c) { code = c; }
        void setName(string n) { name = n; }
        void setCLPR(int clpr) { closePrice = clpr; }
        void setCRPR(int crpr) { currentPrice = crpr; }
        
        //*Accessors
        string getCode() const {
            return code;
        }

        string getName() const {
            return name;
        }

        //* changePercent
        double changePercent() {
            return ((currentPrice-closePrice) / closePrice) * 100;
        }

        //* display
        void display() {
            cout << "Close price  : RM" << closePrice << endl;
            cout << "Current price: RM" << currentPrice << endl;
            cout << "Price change percentage: " << ((changePercent() > 0)? "+": "") << fixed << setprecision(2) << changePercent() << "%" << endl << endl;
        }

};

int main () {

    Stock s1;
    s1.setName("Maybank");
    s1.setCode("MBB");
    s1.setCLPR(5500);
    s1.setCRPR(5250);

    Stock s2;
    s2.setName("CIMB Bank Berhad");
    s2.setCode("CIMB");
    s2.setCLPR(10000);
    s2.setCRPR(15050);

    cout << "Stock: " << s1.getName() << "(" << s1.getCode() << ")\n";
    s1.display();

    cout << "Stock: " << s2.getName() << "(" << s2.getCode() << ")\n";
    s2.display();

    system("pause");
    return 0;
}