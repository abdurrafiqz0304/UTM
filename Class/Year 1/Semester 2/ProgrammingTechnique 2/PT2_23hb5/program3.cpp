// Programming Technique II
// Tutorial 8: Inheritance

#include <iostream>
#include <string>
using namespace std;


// The class Student and Project have been given.
// Do nothing on these classes

class Student
{
  protected:
	string name;
	string matric;

  public:
	Student(string _name = "", string _matric = "") : name(_name), matric(_matric)
	{}

	string getName() const { return name; }
	string getMatric() const { return matric; }
	void setName(string n) { matric = n; }
	void setMatric(string m) { matric = m; }

	void input()
	{
		cout << "Enter name => ";
		getline(cin, name);
		cout << "Enter matric => ";
		getline(cin, matric);
	}

	void print() const
	{
		cout << "Name  : " << name << endl;
		cout << "Matric: " << matric << endl;
	}
};

class Project
{
  protected:
	string title;
	string area;

  public:
	Project(string _title = "", string _area = "") : title(_title), area(_area)
	{}

	string getTitle() const { return title; }
	string getArea() const { return area; }

	void setTitle(string t) { title = t; }
	void setArea(string a) { area = a; }
};


class Undergraduate : public Student // Task 1: Derive this class from Student
{
  protected:
	double cgpa;

  public:
	Undergraduate(string _name = "",
	              string _matric = "",
				  double _cgpa = 0.0) : Student(_name,_matric), cgpa(_cgpa) // Task 3: Initialize the base class using initializer list
	{}

	double getCGPA() const { return cgpa; }
	void setCGPA(double c) { cgpa = c; }

	void input() // redefine the method input()
	{
			// Task 4: Call the method input() in the base class and read the value of cgpa
		Student::input(); // call the method input() in the base class
		cout << "Enter CGPA => ";
		cin >> cgpa;
		cin.ignore(); // clear the buffer
	}

	void print() const // redefine the method print()
	{
			// Task 5: Call the method print() in the base class and display the value of cgpa
		Student::print(); 
        cout << "CGPA  : " << cgpa << endl;
	}
};


// Task 4: Complete the implementation of the class Postgraduate

class Postgraduate : public Student // Task 2: Derive this class from Student
{
  private:
	Project project; // Task 1: Declare a variable of type Project here
  public:
	Postgraduate(string _name = "",
	              string _matric = "",
				  string prjTitle = "",
				  string prjArea = "") : Student(_name,_matric), project(prjTitle,prjArea) // Task 3: Initialize the base class and the member variable project using initializer list
	{

	}

	string getProjectTitle() const
	{
		return project.getTitle(); // Task 2: Return the title of the project
	}


	string getProjectArea() const
	{
		return project.getArea(); // Task 3: Return the area of the project
	}

	void setProject(string _title, string _area)
	{
		project.setTitle(_title); // Task 4: Set the title of the project
		project.setArea(_area); // Task 5: Set the area of the project
	}

	void input()
	{
			// Task 6: Call the method input() in the base class and read the values of project title and area
		string t, a;
		Student::input(); // call the method input() in the base class
		cout << "Enter project title => ";
		getline(cin,t);
		cout << "Enter project area => ";
		getline(cin,a);
		setProject(t,a); // use the setter methods to set the values of project title and area
	}

	void print() const
	{
			// Task 7: Call the method print() in the base class and display the values of project title and area
		Student::print();
        cout << "Project Title: " << project.getProjectTitle() << endl;
		cout << "Project Area : " << project.getProjectArea() << endl;
	}

};

int menu()
{
	cout << "=============[ Menu ]=============" << endl;
	cout << "1. Add an undergraduate student" << endl;
	cout << "2. Add a postgraduate student" << endl;
	cout << "3. Display all students" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "Choose an operation [1,2,3 or 9] => ";

	int choice;
	cin >> choice;
	cin.ignore();
	return choice;
}

//-------------------------------------------------------
// The main function
//-------------------------------------------------------

int main()
{
	// Task 5: Create two arrays to hold lists of undergraduate and postgraduate students, respectively.
	//        Tips: You also need to declare variables to hold the number of undergraduate and postgraduate
	//        students, respectively.

	Undergraduate ugList[10]; // create an array to hold up to 10 undergraduate students
	Postgraduate pgList[10]; // create an array to hold up to 10 postgraduate students
	int numPG=0;          // initialize the number of postgraduate students
    int numUG=0;         // initialize the number of undergraduate students


	int c = menu();

	while (c != 9)
	{
		switch (c)
		{
		case 1:
		    // Task 6: Read data for an undergraduate student and add it to the relevant array.
			cout << endl << "Adding a postgraduate student: " << endl << endl;
			
			break;

		case 2:
			// Task 7: Read data for a postgraduate student and add it to the relevant array.
			cout << "The list of undergraduate students:" << endl << endl;

			break;

		case 3:
			// Task 8: Diplay the list of undergraduate and postgraduate students.

			cout << endl << "The list of undergraduate students:" << endl << endl;


			cout << endl << "The list of postgraduate students:" << endl << endl;


			break;
		}

		c = menu();
	}

	system("pause");
	return 0;
}
