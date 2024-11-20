#include <iostream>
using namespace std;

int a = 10, b = 4, c, d;  
2 float x = 3.5, y;  
3 c = a++ % static_cast<int> (x) / 4;  
4 d = x * a + --c;  
5 a /= d % b++ * x;  
6 y = a * c + b / x;  
7 b += -c * static_cast<int> (++y);  
8 x = y-- * a - x;  
9   
10 cout << "a = " << a << endl;  
11 cout << "b = " << b << endl;  
12 cout << "c = " << c << endl;  
13 cout << "d = " << d << endl;  
14 cout << "x = " << x << endl;  
15 cout << "y = " << y << endl; 