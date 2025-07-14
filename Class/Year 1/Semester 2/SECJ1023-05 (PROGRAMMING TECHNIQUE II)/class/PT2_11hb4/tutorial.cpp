// Programming Technique II

#include <iostream>
using namespace std;

// * ---------------------------------------------------------------------------------------------
// * Task 1: Declare and define the class Line
// * ---------------------------------------------------------------------------------------------
class Line
{
  private:
	double m;  // the slope of the line
	double c;  // the y-intercept

  public:
	// a)
	Line(): m(0), c(0) {}
	Line(double _m, double _c): m(_m), c(_c) {} // b)
	Line(double x1, double y1, double x2, double y2) { // c)
		m = (y2 - y1)/(x2 - x1);
		c = y1 - m*x1;
	}
	~Line() {
		cout << "The object is being destroyed\n";
	} // d)

	// e)
	double getM() const { return m; }
	double getC() const { return c; }

	// f)
	void setM(double _m) { m = _m; }
	void setC(double _c) { c = _c; }

	void printEquation() const {
		cout << "Eq. y =" << m << "x";
		if(c) {
			if(c>0)
				cout << "+" ;
			cout << c << endl; 
		}
	}

};

int main()
{
	// * ---------------------------------------------------------------------------------------------
	// * Task 2: Create the object 'line1'
	// * ---------------------------------------------------------------------------------------------
	Line line1(2,-5);
	line1.printEquation();


	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create the object 'line2'
	// * ---------------------------------------------------------------------------------------------
	Line line2(0,0,2,8);
	line2.printEquation();


	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Create the object 'line3'
	// * ---------------------------------------------------------------------------------------------
	Line line3;
	double slope, intercept;

	cout << "Enter the slope and y-intercept of the line  m  c => ";
	cin >> slope >> intercept;
	cout << endl;

	line3.setM(slope);
	line3.setC(intercept);
	line3.printEquation();




	system("pause"); // ! remove this line if you are using Dev C++

	return 0;
}
