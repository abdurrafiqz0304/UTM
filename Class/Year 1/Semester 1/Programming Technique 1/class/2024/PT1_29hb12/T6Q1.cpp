#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
float num, average = 0, sum = 0;
int cnt = 0;
fstream inputfile, outputfile;

//a) Open the input file named “fileInp.txt”
inputfile.open("fileInp.txt", ios::in);

//b) Open the output file named “fileOut.txt”
outputfile.open("fileOut.txt", ios::out);

//c) Check for successful opening file
if (!inputfile)
 cout << "ERROR!! Input file could not be opened\n";
 else {

//d) Read data from the input file
while (inputfile >> num) { //(!inputfile.of()) {

//e) Write data to the output file
 outputfile << setw(10) << setprecision(3) << num << endl; 

//f) Calculate sum of all data
 sum += num;
cnt++;
}
 }

//g) Calculate average
 if (cnt > 0) {
    average = sum / cnt;
    
//h) Display average to the output file
 outputfile << "average=" << fixed  << average << endl; //setprecision(3) && fixed
}

//i) Close the input file
inputfile.close();

//j) Close the output file 
outputfile.close();

system("pause");
 return 0;
}
