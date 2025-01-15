#include <iostream>
#define N 5
using namespace std;

int main(){

    int A[N] = {3,4,5,1}, B[N], i;
    int sum = 0, max, min, inH, inL;

    for (i = 0; i < N; i++){
        B[i] = A[i] + 3;}

    cout << "\nArray A: ";
    for (i = 0; i < N; i++)
        cout << A[i] << "\t";

    cout << endl;

    //For Array B
    cout << "Array B: ";
    for(i=0;i<N;i++)
        cout<<B[i]<<"\t";

    max = B[0]; //max = -9999;
    min = B[0]; //min = 9999;

    sum = B[0];
    inH = inL = 0;

    for(i=1;i<N;i++){
        sum += B[i];

        //to find max
        if(B[i]>max){
            max = B[i];
            inH = i;
        }

        //to find min
        if(B[i]<min){
            min = B[i];
            inL = i;}
    }

    for(int i=0;i<N;i++){

        if(B[i]>max)
            max=B[i];

        else if(B[i]<min)
            min=B[i];
    }
    
    cout<<"\n\nMax value in array B is "<<max<< '\t'<< (inH+1) <<"th"<<endl;
    cout<<"Min value in array B is "<<min<< '\t'<<(inL+1)<<"th"<<"\n\n";

    system("pause");
    return 0;
}