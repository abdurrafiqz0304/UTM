#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Line {
    private:
        int m, c;
    public:

        // (1) Constructor
        Line(int _m=1, int _c=0) : m(_m), c(_c) {}

        // (2) Read values for m and c
        void read() {
            cout << "Enter the slope (m) and y-intercept of a line (c) => ";
            cin >> m >> c;
        }

        // (3) Overload the - operator
        Line operator-(const Line &right) {
            return Line(m-right.m, c-right.c);
        }

        bool operator!=(const Line &right) {
            return (m*right.m) != -1;
        }

        // (5) Convert to string
        string toString() {
            string equation = "y=";

            if(m==-1)
                equation += "-x";
            else if (m==1)
                equation += "x";
            else
                equation += (to_string(m) + "x"); // convert integer to string
            if (c > 0)
                equation += ("+" + to_string(c));
            else if (c < 0)
                equation += to_string(c);
            return equation;
        }

        // (6) Print lines
        friend void printLines(Line lines[]);
};

void printLines(Line lines[]) {
    for(int i = 0; i < 3; i++) {
        cout << "Line " << (i + 1)
             << " slope(m) = " << lines[i].m
             << ", y-intercept(c) = " << lines[i].c
             << ", equation: " << lines[i].toString()
             << endl;
    }
}

int main() {
    Line lines[3] = {{1,5}};

    cout << "ORIGINAL LINES" << endl;
    printLines(lines);
    cout << endl;

    cout << "Set the second line from user input\n";
    lines[1].read();
    lines[2] = lines[0] -lines[1];

    cout << "UPDATED LINES\n";

    printLines(lines); 
    cout << endl;

    cout << "The first line" 
         << (lines[0].operator!=(lines[2]) ? " is not" : " is")
         << " perpendicular to the last line\n";

    system("pause");
    return 0;
}