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


class Doctor : public Person
{	
	protected:
		string department;
	public:
		Doctor(string n="",string d="") : Person(n), department(d)  // n is doctor's name,  d is department
		{}

		string getDepartment() {
			return department;
		}
};

class Guardian : public Person
{  
   protected:
		string phone;
   public:
		Guardian(string n="", string p="") : Person(n), phone(p)// n is guardian's name,  p is phone number
		{}

		string getphone() const {
			return phone;
		}

		void setPhone(string p) {
			phone = p;
		}
};

class Patient : public Person
{   
	protected:
		string illness;
		Guardian guardian;
		Doctor* doctor;
	public:
		Patient(string pn="", string pi="",   // patient's name and the illness
		        string gn="", string gp="" ) : Person (pn), illness(pi), guardian(gn, gp), doctor(nullptr) {}  // guardian's name and phone number

		void print() const
		{          
			cout << "Patient's Name   :" << getName() << endl;
			cout << "Illness          :" << illness << endl;
			cout << "Guardian's Name  :" << guardian.getName() << endl;   
			cout << "Guardian's Phone :" << guardian.getphone() << endl;
			
			if (doctor != nullptr) {
				cout << "Doctor's Name    :" << doctor->getName() << endl;
				cout << "Doctor's Dept.   :" << doctor->getDepartment() << endl;
			} else 
				cout << " *** No doctor assigned yet *** " << endl; 
			
	    }

		void assignDoctor(Doctor* doc) {
			doctor = doc;
		}
};

class Outpatient : public Patient
{   
	protected:
		string diagnosis;
	public:
		Outpatient( string pn="", string pi="",    // patient's name and illness
		            string gn="", string gp="",    // guardian's name and phone number
					string pdiagnosis="")          // diagnosis type
					: Patient(pn, pi, gn, gp), diagnosis(pdiagnosis) {}					
					
		void print() const
		{  	
		    cout << "Patient Type:  OUTPATIENT " << endl;
			cout << "Diagnosis   :  "            << diagnosis << endl;
			cout << endl;
		} 		
};

class Inpatient : public Patient
{   
	protected:
	string ward; 
	public:
		Inpatient( string pn="", string pi="",    // patient's name and illness
		           string gn="", string gp="",    // guardian's name and phone number
				   string pward="")               // patient's ward
				   : Patient(pn, pi, gn, gp), ward(pward) {}					

		void print() const
		{   
			cout << "Patient Type:  INPATIENT "<< endl;
			cout << "Ward        :  "          << ward << endl;
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
	
	Doctor doctor[NDOC] = { Doctor("Dr. Ramli" ,"ICU"),
							Doctor("Dr. Kamariah" ,"Radiology")
	};

	Patient* patient[NPATIENT] = {
		new Outpatient("Rozita", "Sprained ankle", "Salleh", "4466", "X-ray"),
		new Inpatient("Nurdiana", "Respiratory failure", "Jalil", "7731", "ICU 101"),
		new Outpatient("Ali", "Coronary artery", "Bakar", "1234", "CT Scan")
	};

	while (c!=4){
		

		switch (c){
			case 1: // List Doctors

					for (int i=0; i < NDOC; i++){
						cout <<"Doctor's Name: " << doctor[i].getName() <<"\t"        
							 <<"Department: "    << doctor[i].getDepartment() << endl;
					}

				break;

			case 2: // List Patients
					
			for(int i=0; i<NPATIENT; i++) {
					cout << "Patient #" << i+1 << endl;
					patient[i]->print();
					cout << endl;
				}

				break;

			case 3:  // Assign Doctor
				     // The operation regarding getting inputs from the user is given
				     // You must use the exception handling strategy 
				     // to handle the "out of range" error 
				
				int pIndex;   // The array index of the patient to be assigned with a doctor.
				int dIndex;   // The array index of the doctor to assign to the patient.
				
				cout <<"Enter the patient index and doctor index => ";
				cin >> pIndex >> dIndex;

				try {
					if (pIndex<0 || pIndex>NPATIENT || dIndex<0 || dIndex>NDOC){
						throw string("Index is out of range");
					} else {
						patient[pIndex]->assignDoctor(&doctor[dIndex]);
					}
				}  catch (const string& e){
						cout << "** Error: " << e << endl;
					}
				
				break;
		}
		
		c = menu();
	}

	system("pause");
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
