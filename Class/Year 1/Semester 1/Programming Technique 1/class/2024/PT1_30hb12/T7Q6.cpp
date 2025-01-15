//Program 4 
#include <iostream> 
using namespace std; 
 
int main() 
{ 
 int *p, *q; 
 int num = 20; 
 int arr[] = {11, 22, 33, 44}; 
   
 p = arr; 
 cout << p + 1 << endl; //0x6cfea4
 cout << &p << endl; //0x6cfeb8
 cout << *(p + 3) << endl; //44
 cout << arr << endl; //0x6cfea0
 cout << ++(*p) << endl; //12
  
 q = &num; 
 cout << *q << endl; //20
 cout << &q << endl; //0x6cfeb4
 cout << q << endl; //0x6cfeb0 
  
 return 0; 
} 