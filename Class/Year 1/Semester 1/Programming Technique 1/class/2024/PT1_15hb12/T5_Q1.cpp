#include <iostream>
#define n 6
using namespace std;

int main(){

    int arr[n] = {156, -25, 24}, temp[n];
    int calc, i;

    calc = (arr[0] - arr[5]);

    cout << "The difference between the first and fith element is: "<<calc<<endl;
    
    arr[5] = calc;

    //c)
    for (i = 0; i < n; i++){
        cout << arr[i] << '\t';
    }

    cout <<endl;

    //d)
    int min = 9999;

     if(arr[i]<min){
            min = arr[i];
        }
    
    cout << "min: "<< min << endl;

    //e)
    // Reverse the array
    for (i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    // Print the reversed array
    cout << "Reversed array:" << endl;
    for (i = 0; i < n; i++) {
        cout << arr[i] << '\t';
    }
    cout << endl;






//logical error min not working properly


    system("pause");
    return 0;
}