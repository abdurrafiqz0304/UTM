#include <iostream> 
#include <cmath> 
using namespace std;       
 
const double PI = 3.14159; 
 
struct Circle    
{
    double radius; 
    double diameter; 
    double area; 
 }; 
  
 // (a) Write function prototype for calculating radius. 
 Circle calculateRadius(); 
  
 int main(){ 
 // (b) Declare a structure variable for circle 
        Circle c; 
  
    c = calculateRadius(); 
  
 // (c) Write statement to calculate the circle’s area using  
 //     suitable predefined function. 
  
       c.area = PI * c.radius * c.radius; 
 // (d) Write statement to display the circle data. 
       cout << "Diameter of the circle: " << c.diameter << endl;
       cout << "Radius of the circle: " << c.radius << endl; 
       cout << "Area of the circle: " << c.area; 

    system ("pause");
    return 0; 
    } // end of main function 
  
 // Function to calculate radius 
 Circle calculateRadius() 
 { 
 //(e) Declare a temporary structure variable for circle.
    Circle tempCircle; 

 //(f) Write statement to get input for diameter of circle. 
    cout << "Enter the diameter of circle: ";
    cin >> tempCircle.diameter; 

 //(g) Write statement to calculate radius of circle. 
  
    tempCircle.radius = tempCircle.diameter /2;

    return tempCircle;
    } // end of calculateRadius function