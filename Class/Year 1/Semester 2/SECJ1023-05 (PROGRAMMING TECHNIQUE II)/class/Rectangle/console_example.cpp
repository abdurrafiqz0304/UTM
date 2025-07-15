//----------------------------------------------------------------------------------------------------
// An example of console program
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// Notes on working with VSCode
//   You don't want to open any .cpp file directly in VSCode.
//   Instead, you want to open a folder first. Then open your .cpp file.
//   VSCode works mostly based on (what so called "workspace").
//   Which in this case, you need to work inside a folder.
//
//   So, for this program (console_example.cpp), in order to run it,
//     1). open the folder named "c:\vscode_cpp_workspace" into VSCode
//     2). open this program file (i.e. console_example.cpp) into VSCode
//     3). In debug mode choose "Console program"
//     4). Start debugging or running by pressing F5
//
// If you want to use your own folder, copy the folder ".vscode" from "vscode_cpp_workspace"
// and put it inside your own folder.
//
//----------------------------------------------------------------------------------------------------

#include <iostream>

using namespace std;

int main()
{

	char name[40];

	cout << "What is your name? => ";
	cin.getline(name, 40);

	cout << endl;
	cout << "Hi " << name << "!" << endl;
	cout << "Welcome to the world of C++ programming." << endl
		 << endl;

	system("pause");
	return 0;
}
