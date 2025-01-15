#include <iostream>
#include <cstring>
#define N 30
using namespace std;

int main(){

    char s1[N] = "Liza";
    char s2[N];

    //s1 = "Liza";
    strcpy(s2, "Hello");
    cout << s1 << endl << s2 << endl;

    //we put s1 value to update new value to s2, Liza --> Hello, Hello now is updated to Liza
    strcpy(s2, s1);
    cout << s1 << endl << s2 << endl;

    cout << strlen(s2) << endl;

    strcat(s1, "*****");
    cout << s1 << endl << s2 << endl;

    strcat(s1, s2);
    cout << s1 << endl << s2 << endl;

    cout << strstr(s1, "iz") << endl;

    //null
    cout << strstr(s1,"old") << endl;

    strcpy(s1, s2);
    cout << s1 << " " << s2 << endl;

    //same value will display 0, otherwise, positive or negative
    cout << strcmp(s1, s2) << endl;

    //logical error cuz its compare the address (different string but same value)
    if(s2 == s1)
        cout << "Same strings" << endl;
    else 
        cout << "Different strings" << endl;

    //if not 0, its true , we use !strcmp(s1, s2)
    //if we change the order, we will get positive value
    // 0=same, -1@1= different string
    if(!strcmp(s1, s2))
        cout << "Same strings" << endl;
    else 
        cout << "Different strings" << endl;

    //value will show -1 because not same
    strcpy(s1, "Lili");
    cout << s1 << " " << s2 << endl;

    system("pause");
    return 0;
}