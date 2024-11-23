#include <iostream>
using namespace std;

int main(){

    float pr, npr;

    cout << "Enter the price: ";
    cin >> pr;

    if (pr > 10){

        npr = pr*0.9;
        cout << "Total price is: ";
        cout << npr << endl;
                }
        else {
            pr = pr;
            cout << "Total price is: ";
            cout << pr << endl;
        }
        
    system("pause");

}