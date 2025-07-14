#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1("Programming");
    string s2(s1); //string copy constructor, Programming
    string s3(s1, 4); //string copy constructor with position, ming
    string s4(s1, 4, 3); //string copy constructor with position and length, min, take 3 characters from position 4
    string s5(100, '-'); //string constructor with length and character, - 100 times
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    
    s1.insert(2, s4); //insert s4 into s1 at position 2, s1 becomes Pro-min-gramming
    s4.insert(1, 3, '#'); //insert 3 '#' into s4 at position 1, s4 becomes m###in

    cout << "s1: " << s1 << endl;
    cout << "s4: " << s4 << endl;
      
    s1.replace(0, 7, "Khairul Aming "); //replace 7 characters from position 0 with Khairul Aming, s1 becomes Khairul Aming min-gramming

    cout << "s1: " << s1 << endl;

    system("pause");
    return 0;
}