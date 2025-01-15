#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main() {

    char d1[10] = "disease"; 
    char d2[10] = "autism "; 
    char d3[15]; 
    int len;

    //a)
    // d1 into d2
    cout << strcat(d2, d1) << endl;

    //b)
    // make it same value
    cout << strcpy(d3, d2) << endl;

    //c)
    // to know length
    len = strlen(d3);
    cout << len << endl;

    //d)
    // make it uppercase
    for (int x = 0; x < len; x++)   
    d3[x] = toupper(d3[x]);
    cout << d3 << endl;

    system("pause");
    return 0;
}