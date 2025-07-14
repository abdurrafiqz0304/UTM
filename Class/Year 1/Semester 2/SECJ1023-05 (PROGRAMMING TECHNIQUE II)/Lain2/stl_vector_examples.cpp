#include <iostream>
#include <vector>
using namespace std;

// example containers using vector

// 1. Declaration of vector
vector<int> que = {1, 2, 3, 4};

// Function to print vector elements with a prompt
void print(string prompt)
{
    cout << endl;
    cout << prompt << endl;
    for (int i = 0; i < que.size(); i++)
        cout << que[i] << ",";
    cout << endl;
}

int main()
{
    print("Initial list");

    // 2. Container size information
    cout << "size = " << que.size() << endl;
    cout << "capacity = " << que.capacity() << endl;  // vector-specific method

    // 3. Accessing elements
    cout << "Random access second element: " << que[1] << endl;
    cout << "First element: " << que.at(0) << endl;
    cout << "Front element: " << que.front() << endl;
    cout << "Back element: " << que.back() << endl;

    // 4. Iterating through the container
    for (int i = 0; i < que.size(); i++)
        cout << que[i] << ", ";
    cout << endl;

    // 5. Adding elements (back and front)
    que.push_back(5);                 // adds to the back
    que.insert(que.begin(), -5);      // simulate push_front()
    print("Adding an element at the back and in front");

    // 6. Optional: inserting at index 3
    // auto i = que.begin();
    // que.insert(i + 3, 1001);
    // print("Inserting a new element at index 3");

    // 7. Replacing elements
    que[2] = 200;
    que.at(3) = 300;
    print("Replacing elements at index 2 and 3");

    // 8. Removing element at index 4
    auto p = que.begin();
    que.erase(p + 4);
    print("Removing element at index 4");

    // 9. Removing all elements
    que.clear();
    print("Removing all elements");
    cout << "size = " << que.size() << endl;
    cout << "capacity = " << que.capacity() << endl;

    system("pause");
    return 0;
}
