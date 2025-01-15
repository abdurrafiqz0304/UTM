#include <iostream>
using namespace std;
#define N 4

void readInput(int[]);
void dispOutput(int[]);

int main(){

    int arr[N] = {7, 4, 3};

    cout << arr[1] << endl; //value at index 1

    cout << &arr[0] << endl; //address of first element in array
    cout << &arr << endl;   //same as above
    cout << arr << endl;    //same as above
    cout << *(&arr) << endl; //value at address of first element in array
    cout << *(arr + 1) << endl;//value at second element in array


    readInput(arr);
    dispOutput(arr);
    readInput(arr);
    dispOutput(arr);

    system("pause");
	return 0;
}

void readInput(int A[]){
    cout << A << endl;
    cout << "Enter the elements of array: ";
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cout << A+1 << endl;
}

void dispOutput(int B[]){
    cout << B << endl;
    cout << "The elements are: ";
    for (int i = 0; i < N; i++)
        cout << B[i] << " " << endl;

}