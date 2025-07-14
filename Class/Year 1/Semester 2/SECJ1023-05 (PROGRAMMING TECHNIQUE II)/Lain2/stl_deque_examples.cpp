#include <iostream>
#include <deque>
using namespace std;

// example containers

// 1 Declarations of containers
// dq

deque<int> dq = {1, 2, 3, 4};

void print(string prompt)
{
    cout << endl;
    cout << prompt << endl;
    for (int i = 0; i < dq.size(); i++)
        cout << dq[i] << ",";
    cout << endl;
}

int main()
{
    print("Initial list");

    // 3. container's size;
    cout << "size =" << dq.size() << endl;

    // 2. Accessing elements
    cout << "Random access second element: " << dq[1] << endl;
    cout << "First element: " << dq.at(0) << endl;
    cout << "Front Element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // 3. Iterating the container
    for (int i = 0; i < dq.size(); i++)
        cout << dq[i] << ", ";

    // 3. Adding elements
    dq.push_back(5);
    dq.push_front(0);
    print("Adding an element at the back and infront");


    // auto i = dq.begin();
    // dq.insert(i+3,1001);
    // print("Inserting a new element at index 3");

    cout << endl;
    // 3. Replacing elements
    dq[2] = 200;
    dq.at(3) = 300;
    print("Replacing elements at index 2 and 3");

    // 4. Removing elements
    auto p= dq.begin();
    dq.erase(p+4);
    
    
    print("Removing all elements");
    dq.clear();
    cout << "size =" << dq.size() << endl;


    system("pause");
    return 0;
}