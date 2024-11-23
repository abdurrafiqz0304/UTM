#include <iostream>
using namespace std;

int main(){

int n;

cout << "Enter integer number: ";
cin >> n;

for (int i = 0; i < n ; i++) { //control row
    for (int j = n; j>i; j--) //control column
        cout << "* ";
    cout << endl;
}

for (int i = 1; i < n ; i++) {
    for(int j = i; j >= 0 ; j--)
        cout << "* ";
    cout << endl;
}
    system("pause");
    return 0;
}