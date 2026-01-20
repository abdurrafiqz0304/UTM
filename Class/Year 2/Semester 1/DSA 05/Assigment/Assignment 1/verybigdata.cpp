#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <ctime>

using namespace std; 
int main() { 
    srand((unsigned)time(NULL)); 
    const int dataSize = 800004; 
    int data; 
    ofstream output("verybigdata.dat", ios::out | ios::binary); 
    if (!output) { 
    cout << "Cannot open file!" << endl; 
    return 1; 
    } 
    for (int i = 0; i < dataSize; i++) 
    { 
    data =(rand() % 1000000); 
    output.write((char*)&data, sizeof(data)); 
    } 
    output.close(); 
    if (!output.good()) { 
    cout << "Error occurred at writing time!" << endl; 
    return 1; 
    } 
    ifstream input("verybigdata.dat", ios::in | ios::binary); 
    int readData; 
    cout << "Display first 100 values:" << endl; 
    for (int i = 0; i < 100; i++) 
    { 
    input.read((char*)&readData, sizeof(readData)); 
    cout << readData << " "; 
    } 
    input.close(); 

    system("pause");
    return 0;
} 