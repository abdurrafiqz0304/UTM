#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin; //(2a) declaire first
    ofstream fout("output.txt"); //(1) to declaire and open input file
    int num;
    string str;

    //before use must open first
    fin.open("input.txt"); //(2b) open the input file


    // file checking
    if (!fin.is_open()){     //if (fin.fail()){    //if(!fin){
        cout << "The input file can't be opened!!" << endl;
        
        system("pause");
        exit(0);
    }

    //to get only second word
    while(fin >> num >> str){ //to get input from file
    getline(fin,str);
    cout << str << endl; //display the ouput on the screen
    fout << num << endl; //write the output into the output file
    }

    //to get full sentences
     while(!fin.eof()/*while not reach the end of file*/) {//(fin >> num){ //to get input from file
    fin >> num;
    getline(fin,str);
    cout << str << endl; //display the ouput on the screen
    fout << num << endl; //write the output into the output file
    }

    fin.close();
    fout.close();

    system("pause");
    return 0;
}