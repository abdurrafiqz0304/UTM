#include <iostream>
using namespace std;
int main(){

int score, numPass, numFail;
float cpa;
string status;
int x, y;
int a, b, q1, q;

cout << "Enter score, cpa, x, y, a, b: ";
cin >> score >> cpa >> x >> y >> a >> b ;

(score >= 50) ? (numPass++, cout << "Pass\n") : (numFail, cout << "Please try again.\n");
cout << endl;
(cpa >= 2.0) ? ((cpa >= 3.5) ? status = "Dean's List\n" : status = "Normal Pass\n" ) : ((cpa >= 1.7) ? status= "Probation\n" : status = "Fail\n");
cout << endl;
(x == y) ? (q1 = 0) : (q1 = 1);
q = (x < y) ? (a + b) : (x * 2);

cout << score << status << q1 << q;

system("pause");
return 0;
}