////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Final Exam, Paper 2 (Practical), Question 1
// Template file
//
// program1.cpp
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>

using namespace std;

// Task 1: class Polygon
class Polygon 
{  protected:
		int w, h;
		
	public:
		Polygon(int w=0, int h=0){
			this->w = w;
			this->h = h;
		}
		
		// Define the method display
		//____________________________
		

		// Define the method calcArea
		//____________________________
};

// Task 2: class Rectangle

// Specify the class as a child of class Polygon

class Rectangle
{  public:
		
		// Complete the definition of the constructor
		Rectangle(int width=0, int length=0)
		{
			
		}
		
		// Complete the definition of the method display
		void display() const  
		{
			cout << "Rectangle:\n" 
				 << "\tWidth  = " 
				 << ", Length = " 
				 << endl; 
		}	
		
		// Complete the definition of the method calcArea
		int calcArea() const 
		{
			
		}
};

// Task 3: class Triangle

// Specify the class as a child of class Polygon

class Triangle
{   public:

		// Complete the definition of the constructor
		Triangle(int base=0, int height=0)
		{
			
		}

		// Complete the definition of the method display
		void display() const
		{
			cout << "Triangle:\n" 
				 << "\tBase = " 
				 << ", Height = "
				 << endl; 
		}

		// Complete the definition of the method calcArea
		int calcArea() const 
		{
			
		}
};

int main()
{
  // Task 4: An array of pointers to polygons.
  const int SIZE = 4;      // The size of the array
  
  // Declare the array and fill in it with the polygons.
  //____________________________

  
  // Task 5: Display the polygons and calculate the total area.
  
  cout << fixed << setprecision(2);	
  int totalArea = 0;
  
  for (int i = 0; i < SIZE; i++)
  {
      cout << "Polygon #" << (i+1) << endl;
      
	  // Display the polygon's information
      //____________________________
      
      // Display the polygon's area
      //____________________________
	  
	  // Calculate the total area
	  //____________________________
	  
	  cout << endl << endl;
  }
    
  cout << "The total area of all polygons = " << totalArea << endl;

  return 0;
}

