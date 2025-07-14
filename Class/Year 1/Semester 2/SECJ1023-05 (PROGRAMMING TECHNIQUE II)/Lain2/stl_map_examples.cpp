#include <iostream>
#include <map>
using namespace std;

// example containers

// 1 Declarations of a map

map<string, int> numbers = {{"one" , 1}, {"two" , 2}, {"three", 3}, {"ten", 10}, {"five", 5}, {"two", 2}}; // <key,value>

void print(string prompt)
{
    cout << endl;
    cout << prompt << endl;
    for (auto i = numbers.begin(); i != numbers.end(); i++)
        cout << "(key: " << i->first << ", value:" << i->second << " ),"; // Note: i->first is the key and i->second is the value
    cout << endl;
}

int main()
{
    print("Initial list");

    // 3. container's size;
    cout << "size =" << numbers.size() << endl;
    
    // 2. Accessing elements
    cout << "Accessing element with a key: " << numbers["ten"] << endl;
    cout << "Accessing element with at method: " << numbers.at("two") << endl;

    // 3. Iterating the container
    for (auto i=numbers.begin(); i!=numbers.end(); i++)
        cout << "key: " << i->first << ","
             << "value: " << i->second << endl;

    // 3. Adding elements.
    numbers.insert({"twenty", 20});
    
    print("Inserting an element");

    cout << endl;
    // 3. Replacing elements
    numbers["two"] = 200;
    numbers.at("three") = 300;
    print("Replacing elements of key two and three");

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