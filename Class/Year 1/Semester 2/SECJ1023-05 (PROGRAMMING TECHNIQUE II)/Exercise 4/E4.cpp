//ABDURRAFIQ ZAKARIA A24CS0031

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TennisShop {
    private:
        string brand;
        double price;
        int quantity;
    public:
    TennisShop() {}

    TennisShop(int quantity) {
        this->quantity = quantity;
    }

    void setBrandPrice(string brand, double price) {
        this->price = price;
        this->brand = brand;
    }

    string getBrand() { return brand; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }

    virtual void display() = 0;
    virtual double calcPrice() = 0;
};

class Racket : public TennisShop {
    private:
        int racketType;
    public:
        Racket() {}
        Racket(int quantity, int racketType) : TennisShop(quantity) {
            this->racketType = racketType;
            switch(racketType) {
                case 1:
                    setBrandPrice("Wilson", 569.70); break;
                case 2:
                    setBrandPrice("Yonex", 719.70);  break;
                case 3:
                    setBrandPrice("Yonex", 1289.70); break;
                case 4:
                    setBrandPrice("Dunlop", 989.70); break;
            }
        }

        void display() override {
            cout << "Tennis Racket" << endl;
            cout << "Brand: " << getBrand() << endl;
            // cout << "Price: " << getPrice() << endl;
            string typeName;
            switch(racketType) {
                case 1: typeName = "Junior Tennis Racket"; break;
                case 2: typeName = "Beginners Tennis Racket"; break;
                case 3: typeName = "Advanced Tennis Racket"; break;
                case 4: typeName = "All Tennis Racket"; break;
            }
            cout << "Type: " << typeName << endl;
            cout << fixed << setprecision(2);
            cout << "Price: RM" << getPrice() << endl;
            cout << "No Discount" << endl;
            cout << "Quantity: " << getQuantity() << endl;
            cout << "Subtotal: RM" << calcPrice() << endl;
        }
        double calcPrice() override {
            return getPrice() * getQuantity();
        }
};

class Ball : public TennisShop {
    private:
        int numBalls;
        int ballID;
    public:
        Ball() {}
        Ball(int ballID, int quantity) : TennisShop(quantity) {
            this->ballID = ballID;
            switch (ballID){
                case 1: setBrandPrice("Wilson", 38.40); break;
                case 2: setBrandPrice("Wilson", 28.80); break;
                case 3: setBrandPrice("Dunlop", 81.00); break;
                case 4: setBrandPrice("Dunlop", 33.00); break;
            }
            }
        double calcDisc() {
            return getPrice() * 0.85;
        }

        double calcPrice() {
            return calcDisc() * getQuantity();
        }
};

class Customer {
    private:
        string CustName;
        TennisShop* itemList[10];
        int numOfItem;
    public:
        Customer(string custName) {CustName = custName; numOfItem = 0;}
        string getName() { return CustName;}
        void buy(TennisShop* item) {
            if (numOfItem < 10) {
                itemList[numOfItem++] = item;
            }
        }
        void print() {
            cout << "LIST OF TENNIS ITEMS BOUGHT" << endl;
            double total = 0.0;
            for (int i = 0; i<numOfItem; i++) {
                itemList[i]->display();
                cout << endl;
                total += itemList[i]->calcPrice();
            }
            cout << "TOTAL: RM" << fixed << setprecision(2) << total << endl;
        }

        int displayMainMenu() { 
        int choice; 
        cout << "==========[MENU]============\n" 
             << "  [1] Buy item\n" 
             << "  [2] Print all items\n" 
             << "  [3] Exit\n" 
             << "============================\n" 
             << "Choice: "; 
        cin >> choice; 
        return choice; 
    } 
 
int displayRacketMenu() { 
 int choice; 
 cout << "  [1] Wilson: Junior Tennis Racket\n" 
   << "  [2] Yonex: Beginners Tennis Racket\n" 
   << "  [3] Yonex: Advanced Tennis Racket\n" 
   << "  [4] Dunlop: All Tennis Racket\n" 
   << "Choice: "; 
 cin >> choice; 
 return choice; 
} 
 
int displayBallMenu() { 
 int choice; 
 cout << "  [1] Wilson: Roland Garros All Court\n" 
   << "  [2] Wilson: US Open\n" 
   << "  [3] Dunlop: Fort Max TP KNLTB\n" 
   << "  [4] Dunlop: Fort All Court\n" 
   << "Choice: "; 
 cin >> choice; 
 return choice; 
} 
};

int main() {
    TennisShop *p;
    Customer c("ARIF AIMAN");

    cout << "WELCOME " << c.getName() << endl;
    int choice;
    choice = c.displayMainMenu();
    switch (choice) {
        cout << "<<" << " Item to buy " << ">>" << endl;
        cout << "[1] Racket\n";
        cout << "[2] Ball\n";
        cout << "Choice: ";
        int itemChoice;
        cin >> itemChoice;
         if (itemChoice == 1) {
                    cout << "\n*** Racket ***\n";
                    int rchoice = c.displayRacketMenu();
                    int qty = 0;
                    cout << "Quantity: ";
                    cin >> qty;
                    p = new Racket(rchoice, qty);
                    c.buy(p);
                } else if (itemChoice == 2) {
                    cout << "\n*** Ball ***\n";
                    int bchoice = c.displayBallMenu();
                    int qty = 0;
                    cout << "Quantity: ";
                    cin >> qty;
                    //p = new Ball(bchoice, qty);
                    c.buy(p);
                } else {
                    cout << "Invalid input. Try again!\n";
                }
                break;
            }

            system("pause");
            return 0;
        }     