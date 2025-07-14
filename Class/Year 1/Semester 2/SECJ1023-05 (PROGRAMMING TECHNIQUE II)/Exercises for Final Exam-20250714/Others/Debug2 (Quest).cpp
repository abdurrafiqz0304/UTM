#include <iostream>
#include <string>
using namespace std;

#define MOTVEC_TAX_RATE = 0.50

class Product
{
	string desc;
	double price;
	
	
	public:
		static int count;
		Product(string desc, double price) {
			desc = desc;
			price = price;
			count++;
		}
		virtual void display() = 0 {};
		virtual double calcTax() { return 0; }
		void getPrice() const { return price; }
		void getDesc() const {return desc;}
};

int Product::count = 0;

class MotorVehicle: class Product
{
	string motorType;
	
	public:
		MotorVehicle(string desc, double price, string motorType) {
			motorType = motorType;
		}
		
		double calcTax() { return price * MOTVEC_TAX_RATE; }
		
		void display() {
			cout << "Product description: " << desc 
				 << "\nPrice: RM" << price 
				 << "\nMotor Type: " << motorType 
				 << "\nMotor Tax: " << calcTax() << endl << endl;
		}
};

class Food: class Product
{
	int calories;
	
	public:
		Food(string desc, double price, int calories) {
			calories = calories;
		}
		
		void display() {
			cout << "Product description: " << desc 
				 << "\nPrice: RM" << price 
				 << "\nCalories: " << calories << endl << endl;
		}	
};

int main()
{
	Product *p[] = {Food("Meat", 15, 2000),
				    MotorVehicle("Proton", 56000, "Car"),
				    Food("Banana", 2.5, 500)};
	
	cout << "Number of products: " << count << endl;
	for (int i = 0; i < count; i++)
		p[i].display();
	
	return 0;
}

