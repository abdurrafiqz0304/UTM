////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Final Exam, Paper 2 (Practical), Question 2
// Template file
// 
// program2.cpp
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

// The class Person is FULLY given
// Do not change anything for this class
class Person
{ 
	protected:
		string name;
	public:
		Person(string name=""){ setName(name); }
		string getName() const{return name;}
		void setName(string name) {this->name = name;}
};


class Doctor
{ 
	public:
		Doctor(string n="",string d="")  // n is doctor's name,  d is department
		{}
};

class Guardian
{  
   public:
		Guardian(string n="", string p="") // n is guardian's name,  p is phone number
		{
		}       
};

class Patient
{   
	public:
		Patient(string pn="", string pi="",   // patient's name and the illness
		        string gn="", string gp="" )  // guardian's name and phone number
		{      
	    }
	   
		void print() const
		{          
			cout << "Patient's Name   :" << endl;
			cout << "Illness          :" << endl;
			cout << "Guardian's Name  :" << endl;   
			cout << "Guardian's Phone :" << endl;  
			
			cout << "Doctor's Name    :" << endl;
			cout << "Doctor's Dept.   :" << endl;
			
			cout << " *** No doctor assigned yet *** " << endl; 
	    }
};

class Outpatient
{   
	public:
		Outpatient( string pn="", string pi="",    // patient's name and illness
		            string gn="", string gp="",    // guardian's name and phone number
					string pdiagnosis="")          // diagnosis type
        { 
		}					
					
		void print() const
		{  	
		    cout << "Patient Type:  OUTPATIENT " << endl;
			cout << "Diagnosis   :  "            << endl;
			cout << endl;
		} 		
};

class Inpatient
{    
	public:
		Inpatient( string pn="", string pi="",    // patient's name and illness
		           string gn="", string gp="",    // guardian's name and phone number
				   string pward="")               // patient's ward 
        { 
		}					

		void print() const
		{   
			cout << "Patient Type:  INPATIENT "<< endl;
			cout << "Ward        :  "          << endl;
			cout << endl;
		} 		
};


// The menu function is fully given
int menu()
{
	cout << endl;
	cout << "========== Menu ==========" << endl;
	cout << "1. List Doctors"   << endl;
	cout << "2. List Patients" << endl;
	cout << "3. Assign Doctor"  << endl;
	cout << "4. Exit"  << endl;
	cout << endl;
	
	int choice;
	cout << "Choose an operation [1-4] => ";
	cin >> choice;
	
	cin.ignore();
	cout << endl;
	
	return choice;
}

int main()
{
	const int NDOC = 2;  // Number of of doctor. 
	const int NPATIENT   = 3;  // Number of patients. 
	
	// For convenience (for copy-and-paste purposes), the data of doctors and patients 
	//  are given at the bottom of this program.
	
	// The program structure regarding the menu operation is given
	int c = menu();
	
	while (c!=4){
		
		switch (c){
			case 1: // List Doctors
				
					cout <<"Doctor's Name: " << "\t"        
					     <<"Department: "    << endl;

				break;

			case 2: // List Patients
					cout << "Patient #" << endl;
					
					cout << endl;

				break;

			case 3:  // Assign Doctor
				     // The operation regarding getting inputs from the user is given
				     // You must use the exception handling strategy 
				     // to handle the "out of range" error 
				
				int pIndex;   // The array index of the patient to be assigned with a doctor.
				int dIndex;   // The array index of the doctor to assign to the patient.
				
				cout <<"Enter the patient index and doctor index => ";
				cin >> pIndex >> dIndex;
				
				break;
		}
		
		c = menu();
	}
	
	return 0;
}

/*

Doctors and patients data

Doctors:
name and department

Dr. Ramli , ICU 
Dr. Kamariah ,  Radiology

Patients:
name, illness,guardian'name, guardian's phone, diagnosis, ward number, and patient type

Rozita   , Sprained ankle , Salleh , 4466, X-ray , Outpatient
Nurdiana , Respiratory failure , Jalil, 7731, ICU 101, Inpatient
Ali , Coronary artery , Bakar , 1234 ,CT Scan, Outpatient 

*/
