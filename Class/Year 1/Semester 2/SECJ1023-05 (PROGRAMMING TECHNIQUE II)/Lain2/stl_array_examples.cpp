#include <iostream>
#include <array> //! 1
using namespace std;

// example of STL Array containers

// 1 Declarations of containers

array<int,4> numbers = {11, 12 }; //! 2

void print(string prompt)
{
    cout << endl;
    cout << prompt << endl;
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << ",";
    cout << endl;
}

int main()
{
    print("Initial list");

    // 3. container's size;
    cout << "size =" << numbers.size() << endl;
    cout << "capacity =" << numbers.max_size() << endl;

    // 2. Accessing elements
    cout << "Random access second element: " << numbers[1] << endl;
    cout << "First element: " << numbers.at(0) << endl;
    cout << "Front Element: " << numbers.front() << endl;
    cout << "Back element: " << numbers.back() << endl;
    int *p= numbers.data();// data() returns the pointer of the first element
    cout << "Element at index 2"<< p[2]<< endl;

    // 3. Iterating the container
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << ", ";

    
    cout << endl;
    // 3. Replacing elements
    numbers[2] = 200;
    numbers.at(3) = 300;
    print("Replacing elements at index 2 and 3");

    
     system("pause");
    return 0;
}