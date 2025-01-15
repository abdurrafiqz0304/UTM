#include <iostream>
using namespace std;

int main(){
    
    int *ptr, num = 10;

    ptr = &num;
    cout << *ptr << endl; //10

    ptr = new int[4]; //allocate the memory to ptr dynamically

    cout << "Enter 4 integer numbers: ";
    //input using pointer
    for (int i = 0; i < 4; i++){
        cin >> *(ptr + i);
    }

    //output using subscript (array concept)
    for (int i = 0; i < 4; i++){
        cout << ptr[i] * 2<< "\t";
        cout << endl;
    }

    delete [] ptr; //release the memory allocated for ptr

    system("pause");
    return 0;
}