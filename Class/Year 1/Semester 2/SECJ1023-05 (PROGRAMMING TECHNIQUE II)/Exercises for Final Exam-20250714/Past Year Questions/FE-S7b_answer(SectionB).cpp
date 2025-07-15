#include <iostream>
#include <vector>
using namespace std;

class FoodItem {
    protected:
        string name;
        double price;
        int quantity;
    public:
        FoodItem(string n, double p, int q=0) : name(n), price(p), quantity(q) {}
        
        virtual void dispDetails() = 0;
        virtual double calcPrice(){
            return price * quantity;
        }
};

class Pizza : public FoodItem {
    protected:
        string size;
    public:
        Pizza(string n, double p, int q, string s) : FoodItem(n, p, q), size(s) {}

        void dispDetails() {
            cout << "Pizza - " << name << endl;
            cout << "Price: RM" << price << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Size: " << size << endl << endl;;
        }
};

class Burger : public FoodItem {
    protected:
        bool isDoublePatty;
    public:
        Burger(string n, double p,int q, bool dp) : FoodItem(n, p, q), isDoublePatty(dp) {}

        void dispDetails() {
            cout << "Burger - " << name << endl;
            cout << "Price: RM" << price << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Double Patty: " << ((isDoublePatty)? "Yes" : "No");
            cout << endl << endl;
        }

        double calcPrice() {
            double totalPrice = 0;
            if (isDoublePatty) {
                totalPrice =(FoodItem::calcPrice() + 3.8*quantity);
            } else {
                totalPrice = FoodItem::calcPrice();
            }

            return totalPrice;
        }
};

class Order {
    private:
        vector<FoodItem *> items;
    public:
        void addItem(FoodItem* f) {
            items.push_back(f);
        }

        void dispOrder() {
            double total = 0;
            for (auto p : items) {
                p->dispDetails();
                total += p->calcPrice();
            }

            cout << "Total Order Price: RM" << total << endl << endl;

            //! Exeption Handling
            try {
                if (total < 20.00) {
                    throw total;
                }
            } catch (double) {
                cout << "OrderException: The total order amount is less than RM20.\n";
                cout << "To place an online order, the minimum order amount should be RM20!" << endl << endl;
            }
        }
};


int main(){
    Order obj;
    
    FoodItem* orderList[] = {
        /* TUTORIAL
        USE FORMAT: 
        Pizza(name, price, quantity, size)
        BUrger(name, price, quantity, doublePattyOrNot_bool)

        */

        new Pizza("Super Supreme", 52.3, 1, "Large"),
        new Burger("Cheeseburger", 14.5, 3, 0),
        new Pizza("Hawaiian Chicken", 19.9, 3, "Personal"),
        new Pizza("Beef Pepperoni", 40.9, 1, "Regular"),
        new Burger("Chicken", 13.5, 2, 1),
    };

    int size = sizeof(orderList) / sizeof(orderList[0]);

    for (int i=0; i < size; i++) {
        obj.addItem(orderList[i]);
        
    }

    obj.dispOrder();

    for (int i = 0; i < size; i++) {
        delete orderList[i];
    }


    system("pause");
    return 0;
}