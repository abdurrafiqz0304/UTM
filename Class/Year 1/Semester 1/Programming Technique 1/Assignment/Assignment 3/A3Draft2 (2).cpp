/* DETAILS OF US
    //*Program Title: Assignment 3
    //*PROGRAMMING TECHNIQUE 1 (SECJ1013)
    //*SECTION 04, SEM 1 (2024/2025)

    Lecturer: LIZAWATI BINTI MI YUSUF

    Name: ABDURRAFIQ BIN ZAKARIA
    Matric Number: A24CS0031

    Name: DANIEL IMAN HAQIMIE BIN YUSOFF
    Matric Number: A24CS0063

    Date of completion: 22 January 2025
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream destin("destinations.txt");
ifstream visin("visitors.txt");
ifstream revin("revenue.txt");
ifstream maintin("maintenance.txt");

//! Task 1 - Define a structure to store the following data for each destination
struct MD{
    int vis[12], rev[12], maint[12];
};

struct AD{
    int totVis=0, totRev=0, totMaint=0, netRev=0;
    float avgRevPerVis, avgMaintPerVis;
};

struct Destination{
    string code, name, state;
    MD MonthlyData;
    AD AnnualData;
    int numDest;
};

//! Task 2 - Checks if the all input files exist
//!        - Verifies that all files have the same number of lines to ensure data consistency.
//!        - Terminates the program with an appropriate error message if any file is missing or inconsistent.
//!        - Read data from the input files and store it in an array of Tourist Destination structures.
//!        - Dynamically determine the number of tourist destinations based on the number of lines in the files.
void ReadValidateInput(int &numDest, Destination*& dest){

    //? Begin file check
    if (!destin.is_open()){
        cout << "The Destination input file can't be opened!" << endl;
        system("pause");
        exit(0);
    }
    if (!visin.is_open()){
        cout << "The Visitors input file can't be opened!" << endl;
        system("pause");
        exit(0);
    }
    if (!revin.is_open()){
        cout << "The Revenue input file can't be opened!" << endl;
        system("pause");
        exit(0);
    }
    if (!maintin.is_open()){
        cout << "The Maintenance input file can't be opened!" << endl;
        system("pause");
        exit(0);
    }

    destin.close(); 
    visin.close(); 
    revin.close(); 
    maintin.close();
    //? End

    //* Creating a structure to count lines of each file
    struct FileLines{
        int dcnt=0, vcnt=0, rcnt=0, mcnt=0;
    } count;

    // Counting lines in each file
    string line;

    destin.open("destinations.txt");
    visin.open("visitors.txt");
    revin.open("revenue.txt");
    maintin.open("maintenance.txt");

    while(getline(destin,line)){
        count.dcnt++; //* Also doubles as number of destinations
    }
    while(getline(visin,line)){
        count.vcnt++;
    }
    while(getline(revin,line)){
        count.rcnt++;
    }
    while(getline(maintin,line)){
        count.mcnt++;
    }

    destin.close();
    visin.close();
    revin.close();
    maintin.close();

    //* Validating each file to check for inconsistent lines between all files
    if(count.dcnt == count.vcnt && count.dcnt == count.rcnt && count.dcnt == count.mcnt){\
        numDest = count.dcnt;
    }
    else{
        cout << "Inconsistent number of lines found! Terminating program..." << endl;
        system("pause");
        exit(0);
    }

    //* Reading and storing data
    destin.open("destinations.txt");
    visin.open("visitors.txt");
    revin.open("revenue.txt");
    maintin.open("maintenance.txt");

    //* Dynamically allocate an array of structures
    dest = new Destination[numDest];

    //* Reading data per destination
    for (int i = 0; i < numDest; i++) {

        getline(destin, dest[i].code);

        //* Reading data per month
        for (int month=0; month<12; month++) {
            visin >> dest[i].MonthlyData.vis[month];
            revin >> dest[i].MonthlyData.rev[month];
            maintin >> dest[i].MonthlyData.maint[month];
        }
    }

/* //?Remove comment to check if data is being stored correctly
    for (int i=0; i<numDest; i++) {
        cout << "Destination Code: " << dest[i].code << endl;
        cout << "Monthly Visitors: ";
        for (int month=0; month<12; month++) {
            cout << dest[i].MonthlyData.vis[month] << " ";
        }
        cout << endl;
        cout << "Monthly Revenue: ";
        for (int month=0; month<12; month++) {
            cout << dest[i].MonthlyData.rev[month] << " ";
        }
        cout << endl;
        cout << "Monthly Maintenance: ";
        for (int month=0; month<12; month++) {
            cout << dest[i].MonthlyData.maint[month] << " ";
        }
        cout << endl << endl;
    }   
*/ //?End

    destin.close();
    visin.close();
    revin.close();
    maintin.close();
}

//! Task 3 - Maps each destination code to its corresponding name and state.
//!        - Updates the array of Tourist Destination structures with the destination name and state.
void DetermineDestDetails(const int numDest, Destination* dest){

    string state[numDest] = {"Kedah", "Pahang", "Melaka", "Penang", "Sabah", "Pahang", "Terengganu"};
    string name[numDest] =  {"Langkawi Geopark", "Genting Highlands", "Melaka Historical City",
                             "Penang Hill", "Kinabalu National Park", "Tasik Chini","Kuala Terengganu Beach"};

    for(int i=0; i<numDest; i++){
        dest[i].state = state[i];
        dest[i].name = name[i];

        //* There now exists parallel arrays between code, state and name.

        /* //?Remove comment to check if data is being stored correctly
        cout << "Destination Code: " << dest[i].code 
             << ", State: "          << dest[i].state
             << ", Name: "           << dest[i].name << endl;
        */
    }
}

//! Task 4 - Computes the annual totals for visitor count, ticket revenue, and maintenance cost for each destination.
//!        - Calculates the net revenue for each destination
//!        - Computes the total visitors, revenue, and maintenance costs for each month across all destinations. 
//!        - Calculates the average revenue per visitor for each destination. 
//!        - Calculates the maintenance cost per visitor for each destination. 
void DataAnalysis(Destination* dest){

    //* Reading data per destination
    for(int i=0; i<7; i++){

        //* Reading data per month
        for(int month=0; month<12; month++){
            dest[i].AnnualData.totVis += dest[i].MonthlyData.vis[month];
            dest[i].AnnualData.totRev += dest[i].MonthlyData.rev[month];
            dest[i].AnnualData.totMaint += dest[i].MonthlyData.maint[month];
        }

        //* Net Revenue formula = Total Revenue - Total Maintenance Cost
        dest[i].AnnualData.netRev = dest[i].AnnualData.totRev - dest[i].AnnualData.totMaint;

        //* static_cast<float> used to convert integer into float
        dest[i].AnnualData.avgRevPerVis = static_cast<float>(dest[i].AnnualData.totRev)/dest[i].AnnualData.totVis;
        dest[i].AnnualData.avgMaintPerVis = static_cast<float>(dest[i].AnnualData.totMaint)/dest[i].AnnualData.totVis;

        /* //?Remove comment to check if data is being stored correctly
        cout << "Destination Code: " << dest[i].code << endl;
        cout << "Annual Visitors: " << dest[i].AnnualData.totVis << endl;
        cout << "Annual Revenue: " << dest[i].AnnualData.totRev << endl;
        cout << "Annual Maintenance: " << dest[i].AnnualData.totMaint << endl;
        cout << "Net Revenue: " << dest[i].AnnualData.netRev << endl;
        cout << "Average Revenue per Visitor: " << dest[i].AnnualData.avgRevPerVis << endl;
        cout << "Average Maintenance per Visitor: " << dest[i].AnnualData.avgMaintPerVis << endl;
        cout << endl;
        */
    }
}

//! Functions to find :
//! - highest and lowest visitors for each month across all destinations [view TourismReport function]
//! - highest and lowest net revenue for each destination [view TourismReport function]
void HighLowVis(const int numDest, Destination* dest){
    int monthVis[12] = {0};

    //? Summing up total visitors for each month from all destinations
    for(int i=0; i<numDest; i++){
        for(int month=0; month<12; month++){
            monthVis[month] += dest[i].MonthlyData.vis[month];
        }
    }

    //* Initializing variables to :
    //* -   hold values of highest and lowest visitors
    //* -   hold index of months with highest and lowest visitors
    int maxVis = monthVis[0];
    int minVis = monthVis[0];
    int monthMax=0, monthMin=0;

    for(int month=1; month<12; month++){
        if(monthVis[month] > maxVis){
            maxVis = monthVis[month];
            monthMax = month;
        }
        if(monthVis[month] < minVis){
            minVis = monthVis[month];
            monthMin = month;
        }
    }

    cout << "Month with Highest Visitors: Month " << monthMax+1 << " (" << maxVis << " visitors)" << endl;
    cout << "Month with Lowest Visitors : Month " << monthMin+1 << " (" << minVis << " visitors)" << endl;

}

void HighLowRev(const int numDest, Destination* dest){

    //? Initializing variables to :
    //* -   hold values of highest and lowest net revenue
    //* -   hold index of destination with highest and lowest net revenue
    int maxRev = dest[0].AnnualData.netRev;
    int minRev = dest[0].AnnualData.netRev;
    int destMax=0, destMin=0;

    for(int i=0; i<numDest; i++){
        if(dest[i].AnnualData.netRev > maxRev){
            maxRev = dest[i].AnnualData.netRev;
            destMax = i;
        }
        if(dest[i].AnnualData.netRev < minRev){
            minRev = dest[i].AnnualData.netRev;
            destMin = i;
        }
    }

    cout << "Destination with Highest Net Revenue: " << dest[destMax].name << " (" << dest[destMax].state<< ")" << endl;
    cout << "Destination with Lowest Net Revenue : " << dest[destMin].name << " (" << dest[destMin].state<< ")" << endl;
}

//! Task 5 - Displays the following data in a formatted table for each destination.
//!        - total visitor count / ticket revenue / maintenance costs across all destinations.
//!        - The month with highest / lowest visitors and its value.
//!        - The destination with highest / lowest net revenue and its value.
void TourismReport(const int numDest, Destination* dest){

    cout << string(123,'-') << endl;

    cout << left << setw(8)  << "CODE"
                 << setw(25) << "NAME"
                 << setw(12) << "STATE"
                 << setw(10) << "VISITORS"
                 << setw(13) << "REVENUE(RM)"
                 << setw(16) << "MAINT COST(RM)"
                 << setw(13) << "NET REV(RM)"
                 << setw(13) << "AVG REV/VIS"
                             << "MAINT/VIS(RM)\n";

    cout << string(123,'-') << endl;

    for(int i=0; i<numDest; i++){
        cout << left    << setw(8)  << dest[i].code
                        << setw(25) << dest[i].name
                        << setw(13) << dest[i].state
                        << setw(11) << dest[i].AnnualData.totVis
                        << setw(15) << dest[i].AnnualData.totRev
                        << setw(14) << dest[i].AnnualData.totMaint
                        << setw(14) << dest[i].AnnualData.netRev
                        << fixed << setprecision(2)
                        << setw(14) << dest[i].AnnualData.avgRevPerVis
                                    << dest[i].AnnualData.avgMaintPerVis
                                    << endl;
    }

    cout << string(123,'-') << endl;

    //? Summing total visitors / ticket revenue / maintenance cost from all destinations
    int allVis=0;
    double allRev=0, allMaint=0;

    for(int i=0; i<numDest; i++){
        allVis += dest[i].AnnualData.totVis;
        allRev += static_cast<double>(dest[i].AnnualData.totRev);
        allMaint += static_cast<double>(dest[i].AnnualData.totMaint);
    }

    //? Displaying total visitors / ticket revenue / maintenance cost
    cout << "Total Visitors: " << allVis << endl;
    cout << fixed << setprecision(2)
         << "Total Revenue: RM" << allRev << endl;
    cout << "Total Maintenance Costs: RM" << allMaint << endl;

    //? Displaying month with the highest / lowest visitors
    //? Displaying destination with the highest / lowest net revenue
    HighLowVis(numDest, dest);
    HighLowRev(numDest, dest);

};

int main(){

    //? Initialize with null pointer
    int numDest = 0;
    Destination* dest = nullptr;

    //! Task 2
    ReadValidateInput(numDest, dest);

    //! Task 3
    DetermineDestDetails(numDest, dest);

    //! Task 4
    DataAnalysis(dest);

    //! Task 5
    TourismReport(numDest, dest);

    delete[] dest; // Clean up dynamically allocated memory

    system("pause");
    return 0;
}