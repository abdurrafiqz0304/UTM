// ABDURRAFIQ BIN ZAKARIA A24CS0031
// Programming Technique II
// Tutorial 8: Inheritance

#include<iostream>
using namespace std;

class Project{
	private:
		string title;
	public:
		Project(string _title=""){ setTitle(_title); }

		void setTitle(string _title) {title = _title;}
		string getTitle()const {return title;}
}; // End of class Project


class Contact{
	private:
		string phone;
		string email;
	public:
		Contact(string _phone="", string _email=""){
			setPhone(_phone); setEmail(_email);
		}

		void setPhone(string _phone) {phone = _phone;}
		void setEmail(string _email) {email = _email;}
		
		string getPhone() const {return phone;}
		string getEmail()const {return email;}
}; // End of class Contact


class Person{
	protected:
		string name;
		
		// Task 1: Add the attribute to implement the relationship between this class and 
		//         the class Contact
		Contact contact; // This will hold the contact information (phone and email) for the person
	
		public:
		Person(string _name="", string _phone="", string _email="") : contact(_phone, _email) {
			// Task 2: Initialize the member variable contact using the constructor of Contact
			// The initialization is done in the member initializer list above
			setName(_name);
			
		}

		void setName(string _name) {name = _name;}
		string getName() const {return name;}		
		
		// Task 3: Complete the code for the methods setEmail and setPhone
		void setEmail(string _email) { 
			
			// You can add validation for email format if needed
			contact.setEmail(_email); // Set the email in the contact object
		
		}
		void setPhone(string _phone) {
			// You can add validation for phone number format if needed
			contact.setPhone(_phone); // Set the phone in the contact object
		}

		// Task 4: Complete the code for the methods getEmail and getPhone, respectively.
		string getPhone() const {
			return contact.getPhone(); // Get the phone from the contact object
		}

		string getEmail() const {
			return contact.getEmail(); // Get the email from the contact object
		
		}
		
}; // End of class Person



class Staff : public Person { // Task 1: Derive this class from Person
	protected:
		string position;  // e.g., Lecturer, Technician, Research Officer
	public:
		
		// Task 5: Complete the constructor
		Staff(string _name="", string _phone="", string _email="", string _position="") : Person(_name, _phone, _email), position(_position) {}

		void setPosition(string _position) {position = _position;}
		string getPosition() const {return position;}
		
};  // End of class Staff


class Student : public Person { // Task 1: Derive this class from Person
	protected:
		string program;  // e.g., Computer Science, Electrical Engineering, etc.

		// Task 6: Add the attributes to implement the relationship between this class and 
		//         the classes Project and Staff
		Project project; // This will hold the project title for the student
		Staff *advisor; // Pointer to the advisor of the student

	public:
		
		// Task 7: Complete the constructor
		Student(string _name="", string _phone="", string _email="", 
		        string _program="", string _projectTitle="") : Person(_name, _phone, _email), project(_projectTitle), program(_program) {
			
			// Initialize the advisor to nullptr
			advisor = nullptr; // Initially, the advisor is not set // Because the student may not have an advisor at the time of creation
		}

		void setProgram(string _program) {program = _program;}
		string getProgram() const {return program;}
		
		// Task 8: Complete the code for the method setAdvisor
		void setAdvisor(Staff *_advisor) {
			advisor = _advisor;
		}

		// Task 9: Complete the code for the method getProjectTitle 
		
		string getProjectTitle() const {
			return project.getTitle();
		}
		
		// Task 10: Complete the code for the methods getAdvisorName and getAdvisorPosition, respectively
		string getAdvisorName() const {
			return (advisor == nullptr) ?"": advisor->getName(); // If advisor is nullptr, return "No Advisor"
		}

		string getAdvisorPosition() const {
			if (advisor == nullptr) {
				return ""; // If advisor is nullptr, return "No Advisor"
			} else {
				return advisor->getPosition();
			}
		}
		
}; // End of class Student




int main()
{
	Staff advisor1("Prof. Dr. Muhammad Roslan Abdullah", "019-9875678", "mroslana29@gmail.com","Lecturer");
	Staff advisor2("Mr. Qamarool Zaman", "011-56781234", "qam23@gmail.com","Senior Technician");
	Staff advisor3("Dr. Siti Zubaidah Rosli", "010-1117456", "ctzr983@gmail.com","Research Officer");
	
	// Task 11: Create an array of students with the following information
    //
	Student student[] = {Student("Lim Sew Ying", "010-897634045", "lsying1212@live.utm.my","Electrical Engineering", "Smart Dustbin"),
	Student("Abu Bakar Razali", "011-1210000", "abraz78@live.utm.my","Computer Science", "Money Recognition for Blind People"),
	Student("Nur Amalina Muhammad", "012-9000123", "nama978@live.utm.my","Biomedical Engineering", "Dengue Testing Kit")
	};

	// Task 12: Print the information of all the students along with their project's title

	cout << endl << "-------------- First Printing -----------------------" << endl << endl;
	for (int i=0; i<3; i++){
		cout << "Student # " << (i+1) << endl;
		cout << "Name                : " << student[i].getName() << endl;
		cout << "Phone               : " << student[i].getPhone() << endl;
		cout << "Email               : " << student[i].getEmail() << endl;
		cout << "Project Title       : " << student[i].getProjectTitle()  << endl;
		cout << "Advisor's Name      : " << student[i].getAdvisorName() << endl;		
		cout << "Advisor's Position  : " << student[i].getAdvisorPosition() << endl;
		cout << endl;
	}

	
	// Task 13: You should notice that in Task 12 there is no information about the advisors because they have not been set yet for each of the students
	//          Thus, assign each student with an advisor. You may arrange the assignment on your own.
	student[0].setAdvisor(&advisor3); // Assigning advisor3 to the first student
	student[1].setAdvisor(&advisor2); // Assigning advisor2 to the second student
	student[2].setAdvisor(&advisor1); // Assigning advisor3 to the third student

	// Task 14: Print again the information of all the students along with their project's title and advisor

	cout << endl << "-------------- Second Printing -----------------------" << endl << endl;
	
	for (int i=0; i<3; i++){
		cout << "Student # " << (i+1) << endl;
		cout << "Name                : " << student[i].getName() << endl;
		cout << "Phone               : " << student[i].getPhone() << endl;
		cout << "Email               : " << student[i].getEmail() << endl;
		cout << "Project Title       : " << student[i].getProjectTitle()  << endl;
		cout << "Advisor's Name      : " << student[i].getAdvisorName() << endl;		
		cout << "Advisor's Position  : " << student[i].getAdvisorPosition() << endl;
		cout << endl;
	}


	// Task 15: Suddenly, the first and second students want to change their advisor each other, while  
	//          the advisor for the third student wants to withdraw from being appointed as an advisor.
	//          Write the code to implement these situations.
	student[0].setAdvisor(&advisor2); // First student changes advisor to advisor2
	student[1].setAdvisor(&advisor3); // Second student changes advisor to advisor3
	student[2].setAdvisor(nullptr); // Third student withdraws advisor

	// Task 16: Print again the information of all the students

	cout << endl << "-------------- Third Printing -----------------------" << endl << endl;

	for (int i=0; i<3; i++){
		cout << "Student # " << (i+1) << endl;
		cout << "Name                : " << student[i].getName() << endl;
		cout << "Phone               : " << student[i].getPhone() << endl;
		cout << "Email               : " << student[i].getEmail() << endl;
		cout << "Project Title       : " << student[i].getProjectTitle()  << endl;
		cout << "Advisor's Name      : " << student[i].getAdvisorName() << endl;		
		cout << "Advisor's Position  : " << student[i].getAdvisorPosition() << endl;
		cout << endl;
	}
	                      
	system("pause");
	return 0;
}
