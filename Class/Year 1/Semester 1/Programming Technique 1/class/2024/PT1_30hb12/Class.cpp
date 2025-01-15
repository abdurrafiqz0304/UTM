#include <iostream>
using namespace std;

int main(){

int val[] = {14, 9, 5, 2}; 

for (int i=0; i<4; i++){
    cout << "va[" << i << "] = " 
         << *(val + i) << " -> " //contents //val[i]
         << (val + i) << endl; //address

    // val[0] -> 0xfcb0 , ect
}

int *vals /*value*/ = val+1 , *temp; //vals=9, temp=pointer

cout << "vals = " << vals //vals = address for 9
     << "(" << *vals << ")" // (9)
     << "->" << &vals << endl; //-> address for pointer vals

//!----------------------------------------------------------

*temp /*value*/ = *vals + 2; //point to val[3] which is 2
cout << "vals = " << temp
     << "(" << *temp << ")"
     << "->" << &temp << endl;

//!----------------------------------------------------------

*temp = *--vals; //update value pointing to temp
cout << "vals = " << temp 
     << "(" << *temp << ")" 
     << "->" << &temp << endl;

//!----------------------------------------------------------

val[2] = *(vals + 1) + 7; /*update from 9 to 16 */ //!vals is (val+1)

for (int i=0; i<4; i++){
    cout << "va[" << i << "] = " 
         << *(val + i) << " -> " //contents //val[i]
         << (val + i) << endl; //address
}

*vals += 3; //pointing to 17
cout << "vals = " << vals
     << "(" << *vals << ")"
     << "->" << &vals << endl;

//!----------------------------------------------------------

*(val+1) = *vals + 5; // update val[1] to 23 (17+5)
for (int i=0; i<4; i++){
    cout << "va[" << i << "] = " 
         << *(val + i) << " -> "
         << (val + i) << endl; 

//!----------------------------------------------------------



/*int *vals = val+1, *temp; 
temp = vals + 2; 
*temp = *--vals; 
val[2] = *(vals+1) + 7; 
*vals += 3; 
*(val+1) = *vals + 5; */


system("pause");
return 0;
}