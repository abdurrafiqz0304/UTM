#include <iostream>
#include <exception>

using namespace std;
const int MAX = 3;   // The maximum number of elements the array can hold

class Array
{
	private:
  		int data[MAX];   // array elements
  		int count;       // the number of element currently held by the array
	
	public:
  		
		// Task 1: Define three exception classes named 'Full', 'Empty' and 'NegativeIndex'   (6 marks)
		
		//___________________
		//___________________
		//___________________
  		
  		Array(){ count = 0;}  
  		int getCount() const {return count;}

  		// Method add: To add an element to the array
		void add(int element)    
  		{
		   // Task 2: Throw a  'Full' exception if the array already holds the maximum number of elements. (4 marks).
		   //___________________
		   //___________________
    
		   data[count] = element;
		   count++;
        }

		// Method remove: To remove an element from the array.
		void remove()
		{
		   // Task 3: Throw an 'Empty' exception if the array is empty, i.e., no item held in the array)   (4 marks)
		   //___________________ 
		   //___________________
		   
		   count--;
		}
		
		
		// Method displayElement: To display an element based on its index entered from the keyboard.
		void displayElement()
		{
			int index;
			
			cout << "Enter the index of the element you want to display => ";
			cin >> index;
			
			// Task 4: Throw a 'NegativeIndex' exception if the user entered a negative value for the index.  (4 marks)
			//___________________ 
			//___________________ 


			// Task 5: Throw the user input if the input is larger than the valid index that the array currently has.  (4 marks)
			//___________________ 
			 //___________________ 
				
					
			cout << "Index: " << index << ", Element: " << data[index] << endl;
		}
};  // End of class Array


int main()
{
    Array a;

	a.add(11); 
	cout << "Number 11 has been added. Current number of element = "  << a.getCount() << endl;

	a.add(22); 
	cout << "Number 22 has been added. Current number of element = "  << a.getCount() << endl;

	cout << endl;
	try{
		a.displayElement(); 
	}
	
	// Task 6: Handle the case where the user has entered a negative index. See the example output in Figure 1.2. (3 marks)
	//___________________ 
	//___________________ 
	
	
	// Task 7: Handle the case where the user has entered the index that is larger than the valid index. See the example output in Figure 1.3. (4 marks)
	//___________________ 
	//___________________ 
	//___________________ 
	
	catch (...){}
	
	cout << endl;
	try{
		a.add(33); 
		cout << "Number 33 has been added. Current number of element = "  << a.getCount() << endl;

		a.add(44); 
		cout << "Number 44 has been added. Current number of element = "  << a.getCount() << endl;
	}
	
	// Task 8: Handle the case where an element wants to be added but the array is already full. See the example output in Figure 1.1 to 1.3. (3 marks)
	//___________________ 
	//___________________ 
	
	catch (...){}

	cout << endl;
	try{
		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;

		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;

		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;

		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;
	}
	
	// Task 9: Handle the case where an element wants to be removed but the array is empty. See the example output in Figure 1.1 to 1.3. (3 marks)
	//___________________ 
	//___________________ 

	catch (...){}

	return 0;
}  // End of main function
