#include <iostream>
using namespace std;

int smallest(int a[], int size) {
    int min = a[0];
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int maximum(int a[], int size) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int main() {
    int arr[8] = {11, 2, -22, 105, 10, 105, 2, -22};

    // Call Functions
    cout << "Index of the smallest element: " << smallest(arr, 8) << endl;
    cout << "Largest element: " << maximum(arr, 8) << endl;

    system("pause");
    return 0;
}
