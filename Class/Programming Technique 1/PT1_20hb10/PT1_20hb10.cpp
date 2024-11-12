 /*_____________________________________________________

                    FUNCTION!!!!!
 ______________________________________________________*/

#include <iostream> //preprocessor directives
using namespace std;
float AVRG(float n1, float n2, float n3); //function prototype to better arrangement


//main function - compulsory
int main() {
    float N, average; //variables declaration

    cout << "Enter a number: ";
    cin >> N; //ask the user to enter the input

    average = AVRG(10, 5, N); //call the AVRG function

    cout << "Average = " << average << endl; //display teh ouput on the screen

    system("pause");

    return 0;
}


//AVRG function - optional
float /*ikutlah nk return sebagai apa, kalau macam ni, float */ AVRG(float n1, float n2, float n3) {
    float sum, result;

    //Calculation process
    sum = n1 + n2 + n3;
    result = sum / 3 ;

    //return to the calling  environment (main)
    return result;
}