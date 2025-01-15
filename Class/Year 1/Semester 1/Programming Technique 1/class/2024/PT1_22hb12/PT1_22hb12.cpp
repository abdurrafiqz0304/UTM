#include <iostream>
#define R 3 //no. of rows
#define C 4 //no. of columns
using namespace std;

void disArray2D(int arr[][C]){
    for (int i=0; i<R;i++){ //to access each row
        for (int j = 0;j<C;j++) // to access each column in row i
            cout <<arr[i][j]<<" ";
        cout<<endl;
    }
}

void dispsumAllElementsRows(int arr[][C]){
    int sumC;

    for(int i=0; i<C; i++){ //to controll row
        sumC=0;
        for(int j=0; j<R; j++){ //to control column
        sumC+=arr[i][j];
        cout << arr[i][j]<<": "<<sumC<<"\n";}
        cout << sumC << endl;}
}

void dispsumAllElementsCol(int arr[][C]){
    int sumR;

    for(int i=0; i<R; i++){ //to controll row
        sumR=0;
        for(int j=0; j<C; j++){ //to control column
        sumR+=arr[i][j];
        cout << arr[i][j]<<": "<<sumR<<"\n";}
        cout << sumR << endl;}
}

int sumAllElements(int arr[][C], int rows){
    int sum = 0;
    for (int i=0; i<C;i++){ //to access each column
        for (int j = 0;j<rows;j++) //to access each row in column i
            sum += arr[i][j];
    }
    return sum;
}

int main(){
    int A[R][C] = {{2,3},{4,5,1},{3}};
    int B[R][C] = {};

    cout << "Contents of array A:\n";
    disArray2D(A);
    cout << "\nContents of array B:\n";
    disArray2D(B);
    cout << "Sum of all element in array A: " << sumAllElements(A,R)<<endl;
    cout << "\nSum of all element in each row:  " << sumAllElements(B,C)<<endl;
    dispsumAllElementsRows(A); //display the sum of elements in each row
    dispsumAllElementsCol(A);//display the sum of elements in each col

    system("pause");
    return 0;
}