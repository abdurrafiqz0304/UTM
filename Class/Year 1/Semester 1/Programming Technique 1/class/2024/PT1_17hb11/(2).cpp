#include <iostream>
#include <cctype>
using namespace std;

int main(){

    char text[100];
    //counter variable
    int c = 0;

    cout << "Enter the sentences: ";
    //if use cin only, e.g: Liza Wati, output = Liza
    cin.getline(text, 100);

    while (text[c] != '\0') {
        if(isupper(text[c]))
            text[c] = tolower(text[c]);
        else 
            if(islower(text[c]))
            text[c] = toupper(text[c]);

            else {
                if(isspace(text[c]))
                text[c] = '#';

                if(text[c] == '.')
                text[c] = '?';}
        //update
        c++;
    }

    cout << text << endl;

    system("pause");
    return 0;

}