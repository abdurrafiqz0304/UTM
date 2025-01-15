#include <iostream>
using namespace std;

int smallest(int a[], int size) {
    for (int i = 1; i < size; i++) {
        if (a[i] < min) {
        }
    }
    return min;
}


int maximum(int a[], int size) {
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
        }
    }
    return max;
}

int main() {
    int arr[8] = {11, 2, -22, 105, 10, 105, 2, -22};

    //Call Functions
    cout << "Smallest element: " << smallest(arr, 8) << endl;
    cout << "Largest element: " << maximum(arr, 8) << endl;

    system("pause");
    return 0;
}
