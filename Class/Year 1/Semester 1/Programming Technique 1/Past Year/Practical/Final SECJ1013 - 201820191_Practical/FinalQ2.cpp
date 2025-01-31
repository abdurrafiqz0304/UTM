////////////////////////////////////////////////////////////////////////////////
// School of Computing, Universiti Teknologi Malaysia
// SCSJ1013 - Programming Technique I
// Semester 1, 2018/2019
// Final Exam (Practical)
// Question 2 - 40 Marks
//
//  Student Name: ____________________
//  Section     : ____________________  
//
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Constant for the number of months
const int NUM_MONTHS = 12;

// Declaration of the WeatherData structure
struct WeatherData
{
    
    double rain;        // Total rainfall
    int rainDays; 		// Number of rain days per month    
    double high;        // High temperature
    double low;         // Low temperature
    char   month[15];	// String for month names
    
};

int main()
{
    // Create an array of WeatherData structures
    WeatherData year[NUM_MONTHS];
    double averageTemp[NUM_MONTHS]; // calculated average temperature of each month

    
    // TASK 1: Read weather data from input file      	[16 marks]
    
    //				a. open input file					
    
    //				b. check whether the input file can be opened
    
    //				c. read the data from the input file
    
    //				d. while reading the input file, calculate the average temperature
    // 				   for each month
    
    //				e. close the input file
    


    
    // End of TASK 1:
    
    // ***************************************************************************
    
    
    // TASK 2: Calculate: 								[12 marks]
    //                  a. total annual rainfall
    //                  b. the average of monthly rainfall
    //                  c. the average temperature of the year.
    
    
    
    
    // End of TASK 2:
    
    // ***************************************************************************
    
    
    
    // TASK 3: Find the highest & lowest temperatures	[12 marks]
    

    // End of TASK 3:

	// ***************************************************************************	
    
    
    
    // TASK 4: Display the weather report.			[20 marks]
    
 
    
    

	// End of TASK 4:

    
    return 0;
}
