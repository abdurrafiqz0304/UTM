#include <iostream>
using namespace std;

int main() {
int a = 10, b = 4, c, d;  
float x = 3.5, y;  
c = a++ % static_cast<int> (x) / 4;  
d = x * a + --c;  
a /= d % b++ * x;  
y = a * c + b / x;  
b += -c * static_cast<int> (++y);  
x = y-- * a - x;  
   
cout << "a = " << a << endl;  
cout << "b = " << b << endl;  
cout << "c = " << c << endl;  
cout << "d = " << d << endl;  
cout << "x = " << x << endl;  
cout << "y = " << y << endl;

system("pause");
return 0;
} 