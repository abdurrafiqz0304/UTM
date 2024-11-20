//Program 3 
#include <iostream> 
using namespace std; 
int main() 
{ 
char grade;     // one grade 
int aCount = 0; // number of characterAs 
int bCount = 0; // number of Bs 
int cCount = 0; // number of Cs 
cout << "Enter the letter grades[Enter 'e' character  to end input]"<< endl; 
cin >> grade; 

// write while loop with condition input not equals to ‘e’                                  
while(grade != 'e') {// (a)  

//write switch statement for grade 
    switch (grade){ // (b)          
//in case of input A, increment variable aCount       
    case 'A':                          // (c)        
    aCount++;   // (d)     
        break;  // (e)  
//in case of input B, increment variable bCount       
    case 'B': // (f)        
    bCount++;  // (g)  
        break;  // (h) 
//in case of input C, increment variable cCount                               
    case 'C':                           // (i)        
    cCount++;  // (j)     
        break;  // (k)  
//add default statement to catch all other alphabets and prints 
//“Incorrect letter grade entered.”                   
    default:                                 // (l) 
    cout << "\nIncorrect letter grade entered.\n";   // (m) 
        break; 
} // end switch  // (n) 
//ask for another input letter grades                 
cout << "Enter the letter grades[Enter 'e' character  to end input]\n";  // (o) 
cin >> grade;  // (p) 
 
}// end while

// output summary of results    
cout << "Totals for each letter grade are: \n";                            
cout << "A: " << aCount <<endl;  // (q) display number of A grades 
cout << "B: " << bCount <<endl;  // (r) display number of B grades 
cout << "C: " << cCount <<endl;  // (s) display number of C grades  

system("pause");
return 0;     
} // end function main  