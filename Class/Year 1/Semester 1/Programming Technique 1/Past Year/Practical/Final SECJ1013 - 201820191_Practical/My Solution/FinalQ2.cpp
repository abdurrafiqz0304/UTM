////////////////////////////////////////////////////////////////////////////////
// School of Computing, Universiti Teknologi Malaysia
// SCSJ1013 - Programming Technique I
// Semester 1, 2018/2019
// Final Exam (Practical)
// Question 2 - 40 Marks
//
//  Student Name: ABDURRAFIQ BIN ZAKARIA
//  Section     : 04  
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
    ifstream data("data.txt");			
    
    //				b. check whether the input file can be opened
    if (!data) {
        cout << "Error opening input file" << endl;
        exit(1);
    }
    
    //				c. read the data from the input file
    
    //				d. while reading the input file, calculate the average temperature
    // 				   for each month
    for (int i=0;i<NUM_MONTHS;i++){
        data >> year[i].rain >> year[i].rainDays >> year[i].high >> year[i].low;
        data.ignore();
        data.getline(year[i].month,15);
        averageTemp[i] = ((year[i].high + year[i].low)/2);
    }
    
    //				e. close the input file
    data.close();
    


    
    // End of TASK 1:
    
    // ***************************************************************************
    
    
    // TASK 2: Calculate: 								[12 marks]
    //                  a. total annual rainfall
    //                  b. the average of monthly rainfall
    //                  c. the average temperature of the year.
    double totalAnnualRainfall = 0;
    double avgMonthlyRainfall = 0;
    double avgYearlyTemperature = 0;

    for (int i=0;i<NUM_MONTHS;i++){
        totalAnnualRainfall += static_cast<double>(year[i].rain);
        avgMonthlyRainfall += year[i].rain / NUM_MONTHS;
        avgYearlyTemperature += averageTemp[i]/NUM_MONTHS;
    }
    
    
    
    // End of TASK 2:
    
    // ***************************************************************************
    
    
    
    // TASK 3: Find the highest & lowest temperatures	[12 marks]
    double maxtemp=year[0].high;
    double mintemp=year[0].low;
    int maxMonth=0,minMonth=0;

    for (int u=0;u<NUM_MONTHS;u++){
        if(maxtemp<year[u].high){
            maxtemp=year[u].high;
            maxMonth=u;
        } else if(mintemp>year[u].low){
            mintemp=year[u].low;
            minMonth=u;
        }
    }

    // End of TASK 3:

	// ***************************************************************************	
	
    
    
    // TASK 4: Display the weather report.			[20 marks]
    cout << fixed << setprecision(2) << "Total Rainfall: " << totalAnnualRainfall << endl;
	cout << fixed << setprecision(2) << "Average Monthly Rain: " << avgMonthlyRainfall << endl;
	cout << fixed << setprecision(2) << "Highest Temperature: " << maxtemp << '\t' << "(Month " << (maxMonth + 1) << ": " << year[maxMonth].month << ")" << endl;
    cout << fixed << setprecision(2) << "Lowest Temperature: "  << mintemp << '\t' << "(Month " << (minMonth + 1) << ": " << year[minMonth].month << ")" << endl;
    cout << endl;
   
    cout << left << setw(11) << "Month" 
                 << setw(7)  << "Rain" 
                 << setw(10) << "Rain days" 
                 << setw(8)  << "Hi TEMP" 
                 << setw(8)  << "Lo TEMP" 
                 << setw(8)  << "Avg TEMP" 
                 << endl;

    cout << string(9,'=');
    cout << string(2,' ');
    cout << string(6,'=');
    cout << string(1,' ');
    cout << string(9,'=');
    cout << string(1,' ');
    cout << string(7,'=');
    cout << string(1,' ');
    cout << string(7,'=');
    cout << string(1,' ');
    cout << string(8,'=');
    cout << endl;

    for (int i=0;i<NUM_MONTHS;i++){
        cout << setw(11) << left                                          << year[i].month 
                                  << setw(7)  << fixed << setprecision(2) << year[i].rain 
                                  << setw(10)                             << year[i].rainDays 
                                  << setw(8)                              << year[i].high 
                                  << setw(8)                              << year[i].low 
                                                                          << averageTemp[i]
                                  << endl;
    }
    
 
    
    

	// End of TASK 4:

    system("pause");
    return 0;
}