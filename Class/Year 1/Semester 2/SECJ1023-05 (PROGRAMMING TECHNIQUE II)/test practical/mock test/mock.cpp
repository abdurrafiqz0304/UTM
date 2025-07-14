#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

class Register {
    private:
        int code;
        int quantity;
    
    public:
        Register(int _code=0, int _quantity=0) : code(_code), quantity(_quantity) {};

        void read() {
            cout << "Enter item's code=>";
            cin >> code;
            cout << "Enter amount of items=>";
            cin >> quantity;
            cout << endl;
        }
        friend float Provided(Register reg);
        friend float TotalCost(Register reg);
        friend void Loop();
        friend int main();
};

float Provided(Register reg) {
    float price = 0.0;

    switch (reg.code) {
        case 101 : price = 9.90; break;
        case 201 : price = 6.90; break;
        case 305 : price = 7.99; break;
        case 404 : price = 4.99; break;
        default  : 
            cout << "Invalid code. Please try again!" << endl;
            price = 0.0;
            break;
    }
    return price;
}

float TotalCost(Register reg) {
    float total = 0.0;
    total = Provided(reg) * reg.quantity;
    return total;
}

int main() {
    Register reg;
    float totalAmount = 0.0;
    do {
        reg.read();
        if (reg.code != 0) {
            totalAmount += TotalCost(reg);
        }
    } while (reg.code != 0);

    cout << "Total amount to pay: " << totalAmount << endl;

    system("pause");
    return 0;
}
