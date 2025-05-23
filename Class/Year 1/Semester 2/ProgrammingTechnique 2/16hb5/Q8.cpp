#include <iostream>
using namespace std;

class Contact {
    private:
        string phone;

    public:
        Contact(string p) : phone(p) {}
        string getPhone() {return phone;} // access private member variable
};

class Car {
    private:
        string plate;

    public:

        Class(string p) : plate(p) {}

        string getplate() {return plate;}
};

class Customer {
    private:
        string name;
        Contact contact; // composition: a customer has a contact
        Car *car; // aggregation: a customer can have many cars. Object contains pointer to object of another class.

    public:
        Customer(string _name, string _phone) : name(_name), contact(_phone), car(NULL) {}
        string getName() {return name;}
        string getPhone() {return contact.getPhone();} // use the getter method in Contact class
        void rentCar(Car *c) {
            car = c; // assign the parameter to the car pointer
        }
        Car *getCar() {return car;} // return the pointer to the car object

};

int main() {

    Car car("JSQ245");
    Customer cList[] = {{"Ahmad Kamal"}, {"015-75769800"}, Customer("Siti Nurdiana Abdullah","014-8889900")};
    cList[0].rentCar(&car);

    for (int i=0; i<3; i++) {
        Customer c = cList[i]; 
        cout << "Customer's Name: " << c.getName();
        cout << "Phone Number: " << c.getPhone();
        Car *c1 = c.getCar();
        cout << "Rented Car: " 
             << ((c1 != NULL)? c1->getplate() : "") << endl << endl; // use arrow operator to call methods from Car class
            }


    system("pause");
    return 0;
}