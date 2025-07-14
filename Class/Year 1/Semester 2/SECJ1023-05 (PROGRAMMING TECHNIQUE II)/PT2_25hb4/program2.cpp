#include<iostream>
#include<string>
#define CURR_YEAR 2025 // Define the current year as 2025, you can change this to the current year if needed


using namespace std;

int main()
{
	string name;
	string id;
	
	// Task 1: Allow user to enter his or her full name and id number
	cout << "Enter your full name => ";
	getline(cin, name); // Use getline to read the full name including spaces
	


	cout << "Enter your ID Number => ";
	getline(cin, id); // Use getline to read the ID number


	// Task 2: To determine the gender from the last digit
	// Task 2a: Extract the last digit from the id
	string sLastDigit = id.substr(id.length() - 1, 1); // Extract the last character from the ID, want to extract only one character


	// Task 2b: Convert the last digit to a number
	int lastDigit = stoi(sLastDigit); // Convert the last digit to an integer, use stoi to convert string to int

	
	// Task 2c: Determine the gender such that, an odd value is male and even is female
	string gender;
	gender = (lastDigit % 2) ? "Male" : "Female"; // Ternary operator to determine the gender based on the last digit
	
	
	// Task 3: To extract the dob
	// Task 3a: Extract the year, month and day from the id

	string sYear  = id.substr(0,2);
	string	sMonth = id.substr(2,2); // Extract the month from the ID, starting from position 2 and take 2 characters
	string sDay   = id.substr(4,2); // Extract the day from the ID, starting from position 4 and take 2 characters

	// Task 3b: Convert the year, month and day to integers
	int nyear = stoi(sYear); // Convert the year to an integer
	int nmonth = stoi(sMonth); // Convert the month to an integer
	int nday = stoi(sDay); // Convert the day to an integer


	// Task 3c: Convert the year to be in full value form, e.g. 99 becomes 1999 and 02 becomes 2002
	nyear += (nyear > 25)? 1900 : 2000;

	
	// Task 4: Calculate the age
	int age = CURR_YEAR - nyear; // Calculate the age by subtracting the year from the current year

	
	// Task 5: Determine the string name for the month
	string lMonth[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; // Array of month names
	string namemonth = lMonth[nmonth - 1]; // Get the month name from the array using the month number, subtract 1 to get the correct index


	// Task 6: Using a loop, convert the name to capital letters
	for(int i=0;i<name.size();i++)
		name[i] = toupper(name[i]); // Convert each character to uppercase using toupper function


	// Task 7: print all the required output
	cout << "Output: " << endl << endl;
	cout << "Name    : " << name << endl;
	cout << "ID      : " << id << endl;
	cout << "Gender  : " << gender << endl;
	cout << "Age     : " << age<< " years old" << endl;
	cout << "DOB     : " << nday << " " << namemonth << " " << nyear << endl << endl << endl;

	system("pause"); //! remove this line if you are using Dev C++
    return 0;
}

