#include <iostream>
#include <list>
using namespace std;

// example containers

// 1 Declarations of list


list<int> theList;


void print(string prompt)
{
    cout << endl;
    cout << prompt << endl;
    for (auto i = theList.begin(); i != theList.end(); i++)
        cout << *i << ",";
    cout << endl;
}

int main()
{
    
    print("Initial list");
    cout << "Size:"<< theList.size();

    // 3. container's size;
    cout << "size =" << theList.size() << endl;

    // 2. Accessing elements
    // list does not support random access
   
    cout << "Front Element: " << theList.front() << endl;
    cout << "Back element: " << theList.back() << endl;

    // 3. Iterating the container
    for (auto i = theList.begin(); i != theList.end(); i++)
        cout << *i << ", ";
    cout << endl;

    // 3. Adding elements
    theList.push_back(5);
    theList.push_front(0);
    print("Adding an element at the back and infront");


    auto i = theList.begin();
    theList.insert(i,1001);
    print("Inserting a new element to the first");
    
     theList.insert(theList.end(),2002);
    print("Inserting a new element to the last element");

    cout << endl;
    // 3. Replacing elements
    i=theList.begin();
    i++;
    *i = 300;
    print("Replacing the second element");

    // 4. Removing elements
    i=theList.begin();
    for (int c=1; c<3; c++, i++);
    theList.erase(i);
    print("Removing the third element");
    
    theList.pop_front();
    theList.pop_back();
    print("Removing front and back elements");

    print("Removing all elements");
    theList.clear();
    cout << "size =" << theList.size() << endl;


    system("pause");
    return 0;
}