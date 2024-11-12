/*_____________________________________________________

                    TUTORIAL 2 | Q5
  _____________________________________________________*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    float v, r;
    const float PI = 3.1415926;

    cout << "Enter the radius of sphere: ";
    cin >> r;

   // v = (4/3.0) * PI *( r * r * r);
   v = 4/3.0 * PI * pow(r, 3);

    cout << "Volume of sphere: " << v << endl;

    system("pause");
    return 0;

}