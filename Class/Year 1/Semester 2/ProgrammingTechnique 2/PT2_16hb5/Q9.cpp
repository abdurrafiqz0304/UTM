#include <iostream>
#include <string>
#define MAX 3
using namespace std;

// ABDURRAFIQ ZAKARIA A24CS0031

class Cat {
    private:
        string name;
        int age;
        int yearAdopt;

    public:
        Cat(string _n, int _add, int _age): name(_n), age(_add), yearAdopt(_age) {}
        string getname() {return name;}
        int getAge() {return age;}
        int calcNumOfYear() {
            return 2025 - yearAdopt;
        }
};

class Person {
    private:
        string name;
        string address;
        int count;
        Cat *myCat[MAX];

    public:
        Person(string _name, string _address) : name(_name), address(_address), count(0) {}
        string getName() { return name; }
        string getAddress() { return address; }
        int getCount() { return count; }
        void adopt(Cat* c) {

            myCat[count] = c;

            if (count > MAX - 1 ) {
                cout << "Sorry!! You already reach the max number of cat adopted" << endl;
            } else {
                cout << "Success adopted!!";
                myCat[count++];
            }


            //  This function is used to add objects from the Cat class to myCat array. The objects added to array refers to the cats adopted by person.
            //if (count == NULL)
            //    myCat[count] = new Cat();
            //else if(count > MAX)
            //    cout << "Sorry!! You already reach the max number of cat adopted" << endl;
            //    else
            //        myCat[count++] = new Cat();
            //        cout << "Success adopted!!";
        };    
        void print() {

            for (int i=0 ; i<MAX ; i++){

            cout << i+1 << ")";
            cout << "Cat's name: " << getName() << endl
                 << "Cat's age " << myCat[i]->getAge() << endl
                 << "Year adopted: " << myCat[i]->calcNumOfYear() << endl; }
        };

};

int main() {

    string ownerName = "Aisyah Ali";
    string ownerAddress = "Skudai, Johor";
    Person p1(ownerName, ownerAddress);
    
    Cat c1("Cutie", 6, 2018);
    Cat c2("Oscar", 4, 2016);
    Cat c3("Orked", 3, 2018);
    
    p1.print();

    system("pause");
    return 0;
}


