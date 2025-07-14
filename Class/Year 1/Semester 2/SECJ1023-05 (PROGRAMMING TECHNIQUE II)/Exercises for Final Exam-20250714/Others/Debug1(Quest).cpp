#include <iostream>
#include <iomanip>
#include <string>
#define MAX 5
using namespace std;

class Person 
{
    string name, ic_no;

	public:
    	Person(string name, string ic_no) {
        	name = name; 
        	ic_no = ic_no;
    	}

    	void virtual printInfo() {
        	cout << "Name: " << name << endl
        		 << "IC No.: " << ic_no << endl;
    	}
};

class Item {
    	string name, spec;
    	double price;
    	int qty;
	
	public:
    	Item(string name="", double price=0, string spec="", int qty=0) {
        	name = name;
        	price = price;
        	spec = spec;
        	qty = qty;
   	 	}

    	void getTotalPrice() {
			return qty * price;
		}

    	void printInfo() {
        	cout << "Item Name: " << name << endl
        		 << "Price: " << price << endl
        		 << "Type: MATERIAL" << endl
        		 << "Specification: " << spec << endl
        		 << "Quantity: " << qty << endl
        		 << "Total Price: " << getTotalPrice() << endl;
    	}
};

class Customer: public class Person {
    string address, phone; 
	int count;      
    Item item[MAX];  

	public:
    	Customer(string name, string ic_no, string address, string phone) {
	    	address = address;      
        	phone = phone;  
        	count = 0; 
    	}

    	void addItem(Item *item) {
        	item[count++] = item;
    	}

		void printInfo() {    
        	double grand_total = 0;  
			printInfo();
        	cout << "Address: " << address << endl
        		 << "Phone: " << phone << endl << endl
				 << "Ordered Item(s):" << endl
				 << "................" << endl;
				 
            for (int i = 0; i <= count; i++) {
            	item[i]->printInfo();
            	cout << endl;
				grand_total += item[i]->getTotalPrice();
        	}

        	cout << fixed << setprecision(2)
				 << "GRAND TOTAL PRICE: RM" << grand_total << endl;
    	}
};

int main() {
	Item *m1 = Item("Engine Oil", 135.80, "Semi Synthetic 15W/40", 2);
    Item *m2 = Item("Oil Filter", 15.50, "Saga OEM", 3);

    Customer c1("Lisa", "12345678", "No. 5, KTDI UTM, Johor", "012-3456789");
    c1.addItem(*m1);
    c1.addItem(*m2);
    c1.printInfo();
    
    return 0;
}
