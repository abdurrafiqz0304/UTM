//Minute Program DANIEL RAFIQ
/*A24CS0031
A24CS0063*/
#include <iostream>
using namespace std;
 int main() {

    int d;
    int h;
    int m;
    int minutes;
    cout << "Type time in minutes: ";
    cin >> minutes;

    d = (minutes / 1440);
    h = (minutes / 60) - (d * 24);
    m = minutes - (d * 1440) - (h * 60);

    cout << minutes;
    cout << " in Days, Hours, and Minutes is :"
         << d << " Days " << h << " Hours " 
         << m <<" Minutes"<<endl;

    system("pause");
    return 0;
 }