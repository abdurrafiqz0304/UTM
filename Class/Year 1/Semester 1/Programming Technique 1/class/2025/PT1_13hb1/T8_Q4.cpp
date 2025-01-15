#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    float x, y;
};

struct Line {
    Point A, B; // Use Point type for A and B
    float length;
};

const int SIZE = 5;

int main() {
    Line ln[SIZE];

    // Get input data
    for (int i = 0; i < SIZE; i++) {
        cout << "LINE - " << i + 1 << endl;

        cout << "Enter x-coordinate and y-coordinate of point A: ";
        cin >> ln[i].A.x >> ln[i].A.y;

        cin.ignore();
        
        cout << "Enter x-coordinate and y-coordinate of point B: ";
        cin >> ln[i].B.x >> ln[i].B.y;
    }

    // Calculate length of line
    for (int i = 0; i < SIZE; i++) {
        float diffX, diffY;

        // Calculate difference in x-coordinate for 2 points
        diffX = ln[i].B.x - ln[i].A.x;

        // Calculate difference in y-coordinate for 2 points
        diffY = ln[i].B.y - ln[i].A.y;

        // Calculate length between 2 points
        ln[i].length = sqrt(pow(diffX, 2) + pow(diffY, 2));

        cout << "Length of line - " << i + 1 << " is ";

        // Display length
        cout << ln[i].length << endl;
    }

    system("pause");
    return 0;
}
