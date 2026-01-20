#include <iostream>
#include <string>
using namespace std;

// Program 7.10
class nodePhone
{
public:
    string brand, model;
    float price;
    nodePhone * next;

    nodePhone (string br, string md, float pr) {
        brand = br;
        model = md;
        price = pr;
    }

    nodePhone() { }
};

nodePhone * first = NULL;

int main()
{
    nodePhone *ptr1;
    nodePhone *ptr2;

    // a)
    ptr1 = new nodePhone("Nokee", "Lumia", 1200.00);
    ptr1->next = NULL;

    ptr2 = new nodePhone("HTSee", "Desire", 900.00);
    ptr2->next = NULL;

    // b)
    first = ptr2;                
    ptr2->next = ptr1;           
    ptr1->next = first;          
    ptr1->next->model = "Xperia";

    first = NULL; 
    
    nodePhone *n1 = new nodePhone("Nokee", "Lumia", 1720.00);
    nodePhone *n2 = new nodePhone("HTSee", "Desire", 1900.00);
    nodePhone *n3 = new nodePhone("Smsung", "Galaxy", 2500.00);

    first = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    
    nodePhone *current = first;

    if (current != NULL) {
        first = current->next;
        delete current;
    }

    first = NULL;
    n1 = new nodePhone("Nokee", "Lumia", 1720.00);
    n2 = new nodePhone("HTSee", "Desire", 1900.00);
    n3 = new nodePhone("Smsung", "Galaxy", 2500.00);

    first = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    cout << "--- OUTPUT FOR PART E (Display < 2000) ---" << endl;
    cout << "List of Affordable Smart Phones" << endl << endl;

    nodePhone *temp = first;
    while (temp != NULL) {
        if (temp->price < 2000.00) {
            cout << "Brand : " << temp->brand << endl;
            cout << "Model : " << temp->model << endl;
            cout << "Price : RM" << temp->price << endl;
            cout << "The phone is affordable for students." << endl << endl;
        }
        temp = temp->next;
    }

    current = n2; 

    nodePhone *prevNode = first;

    while (prevNode->next != current) {
        prevNode = prevNode->next;
    }

    prevNode->next = current->next;
    
    delete current;

    system("pause");
    return 0;
}