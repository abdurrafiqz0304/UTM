// Programming Technique II (SECSJ1023)
// Semester 2, 2021/2022

// Skill-Based Test (Practical)

// Student's Name:.....................
// Matric Number:.....................
// Location:..................... (e.g. area and state name if in malaysia, or country name if outside Malaysia)

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Line
{
private:
	int m, c;

public:
	//(1) Constructor
	Line(int _m=1, int _c=0): m(_m), c(_c) {}
	/*Line(int _m=1, int _c=0) {
	m = _m;
	c = _c }*/

	//(2)
	void read() {
		cout << "Enter the slope (m) and y-intercept of a line (c) => ";
		cin >> m >> c;
	}

	//(3)
	Line operator-(Line right) {
		return Line(m-right.m, c-right.c);
	}

	/*Line operator-(Line right) {
		Line temp;
		temp.m = m - right.m;
		temp.c = c - right.c;
		return temp;
	}
	*/

	//(4)
	bool operator!=(const Line &right) {
		if ((m*right.m) != -1)
			return true;
		return false;

		//return ((m*right.m) != -1);
	}

	//(5)
	string toString() {
		string equation = "y=";
		//equation += (m == -1)? "-": to_string(m);

		if (m == -1)
			equation += "-x";
		else
		if (m == 1)
			equation += "x";
		else
			equation += (to_string(m)+"x");
		
		if (c > 0)
			equation += ("+" + to_string(c));
		else
		if (c < 0)
			equation += to_string(c);

		return equation;
	}

	//(6)
	friend void printLines(Line []); 
};


// This function is partially given.
void printLines(Line lines[])
{
	cout << endl;
	for (int i = 0; i < 3; i++){
		cout << "Line " << (i + 1)
			 << " slope(m) = " << lines[i].m
			 << ", y-intercept(c) = " << lines[i].c
			 << ", equation: " << lines[i].toString()
			 << endl;
	}
	cout << endl;
}

int main()
{
	//(7)
	Line lines[3] = {{1, 5}};
	//Line lines[3] = {Line(1, 5)};

	cout << "ORIGINAL LINES";
	printLines(lines);

	//(8)
	cout << "Set the second line from user input\n";
	lines[1].read();
	lines[2] = lines[0].operator-(lines[1]);
	//lines[2] = lines[0] - lines[1];

	cout << "\nUPDATED LINES";
	printLines(lines);

	//(9)
	cout << "The first line is "
		 << ((lines[0] != lines[2])? "not ": "")
		 << "perpendicular to the last line";
	
	/*
	if (lines[0] != lines[2])
		cout << "The first line is not perpendicular to the last line";
	else
		cout << "The first line is perpendicular to the last line";
	*/

	cout << endl;
	system("pause"); // ! remove this line if you are using Dev C++
	return 0;
}
