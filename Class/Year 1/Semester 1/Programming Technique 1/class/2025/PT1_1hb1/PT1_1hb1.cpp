//constant pointer
#include <iostream>
using namespace std;

void display(const int *ptr){
    *ptr += 2;
    cout << *ptr << end;
}

void display1(int *ptr){
    *ptr += 2;
    cout << *ptr << end;
}

int main(){

    int num = 10, /*lain*/n=7;
    /*lain*/int *const ptr = &num;

    //normal
    display1(&num);

    //pointer to constant
    display(&num);

    //constant to pointer
    display(&num);
    ptr = &num; //if want to try to change the address

    system("pause");
    return 0;
}