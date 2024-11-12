//Minute Program DANIEL RAFIQ
#include <iostream>
using namespace std;

int main() {
    double day, hr, min, minute_inp;
    cout << "Please insert the amount of minutes: ";
    cin >> minute_inp;
    day = (minute_inp/1440);
    hr = (minute_inp/60) - (day*24);
    min = minute_inp - (hr*60) - (day*1440);

    cout << "Day(s): " << day
         << "\nHour(s): " << hr
         << "\nMinute(s): " << min;

    system("pause");
    return 0;
}