#include <iostream>
#include <multiset>
using namespace std;

// example containers

// 1 Declarations of a map

set<string> numbers = {"one","two","three", "ten", "two"};

void print(string prompt)
{
    cout << endl;
    cout << prompt << endl;
    for (auto i = numbers.begin(); i != numbers.end(); i++)
        cout << *i<<",";
    cout << endl;
}

int main()
{
    print("Initial list");

    // 3. container's size;
    cout << "size =" << numbers.size() << endl;
    
    // 3. Iterating the container
    for (auto i=numbers.begin(); i!=numbers.end(); i++)
        cout << *i << ",";

    // 3. Adding elements.
    numbers.insert("twenty");
    print("Inserting an element");

    cout << endl;
        // 4. Removing elements
    auto i=numbers.begin();
    numbers.erase(i);
    print("Removing by iterator");

    numbers.erase("twenty");
    print("Removing by key");

    print("Removing all elements");
    numbers.clear();
    cout << "size =" << numbers.size() << endl;
    

    system("pause");
    return 0;
}