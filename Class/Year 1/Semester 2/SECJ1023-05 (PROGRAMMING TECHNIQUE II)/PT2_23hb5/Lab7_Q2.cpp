//Program 7.2 
#include <iostream> 
using namespace std; 
 
class Rectangle { 
    protected: 
       double width; 
       double length; 
       double calculateArea(); 
    public: 
       Rectangle(double=0, double=0); 
       void display(); 
}; 
 
Rectangle::Rectangle(double width, double length){ 
         this->width = width     ; // this is a pointer to the object itself  (a)
         this->length = length     ;  // (a)
} 
 
void Rectangle::display(){ 
    cout<<width<<endl; 
    cout<<length<<endl; 
} 
 
double Rectangle::calculateArea(){ 
    return width*length; 
} 
 
class Square : public Rectangle {  //(b) // calls constructor of base class 
    private: 
       double height; 
    public: 
       Square(double height, double width, double length); // (c) // height and width are passed as parameters 
       double calculateVolume(); 
       void display(); 
}; 
 
Square::Square(double height,double width,double length):Rectangle(width,length) {  // (d) 
    this->height=height; 
    this->width=width; 
    this->length=length; 
} 
 
double Square::calculateVolume(){ 
    return calculateArea()*height; // (e) 
}

void Square::display(){ 
Rectangle::display(); // (f) 
cout<<height<< endl; 
cout<<calculateVolume(); 
} 

int main(){ 
    Square squareBox(15,10,10); // (g) 
    squareBox.calculateVolume(); // (h) 
    squareBox.display(); // (i)
    cout << endl;
    
system("pause"); 
return 0; 
}