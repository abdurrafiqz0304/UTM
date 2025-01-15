#include <iostream>
using namespace std;
void funcOne(int [], int);
int findSum(int, int);

int main(){

    int list[10] = {1,2,3,4,5,6,7,8,9,10};
    int num;

    funcOne(list, 10);
    cout << findSum(10, list[3]);
    cout << findSum(list[2], list[7]);

    system("pause");
	return 0;
}

void funcOne(int A[], int n){
    int i;
    for(i = 0; i < 10; i++)
        cin >> A[i];
    cout << " " << endl;

}

int findSum(int a, int b){
    return a + b;
}