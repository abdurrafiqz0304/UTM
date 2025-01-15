#include <iostream>
using namespace std;

int main(){
    int num1 = 455, *n;
    double num2 = 345.678;

    n = &num1;

    cout << num1 << " -> " << &num1 << endl;
    cout << num2 << " -> " << &num2 << endl;

    cout << n << " -> " << &n << endl;
    cout << *n << endl;

    system("pause");
	return 0;
}

/*n = address
*n = value
&n = address pointing*/