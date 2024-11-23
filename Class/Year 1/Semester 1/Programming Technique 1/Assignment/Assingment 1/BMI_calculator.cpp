/*##################################################
  #             ABDURRAFIQ BIN ZAKARIA             #
  #                    (A24CS0031)                 #
  #          DANIEL IMAN HAQIMIE BIN YUSOFF        #
  #                    (A24CS0063)                 #
  ##################################################*/

#include <iostream>
#include <cmath>
using namespace std;

/*##################################################
                      FUNCTION
  ##################################################*/

    //INDEX function - optional
    float INDEX(float h, float w) {
        float bmi;
        
        //Calculation process
        bmi = w / pow((h / 100), 2);

        //Return to the calling environment
        return bmi;
    }

//main function - compulsory
int main(){

    //declaire variables
    float height, weight, BMI;

/*#################################################
                      HEIGHT
  #################################################*/

    //ask height
    cout << "Enter the height (cm): " ,
    cin >> height ,
    cout << endl;

    //!Loop for while (height) (START)
    while (height <= 0) {
        //ask height again
        cout << "Enter the height (cm): " ,
        cin >> height ,
        cout << endl;
    }
    //!Loop for while (height) (END)

/*##################################################
                      WEIGHT
  ##################################################*/

    //ask weight
    cout << "Enter the weight (kg): " ,
    cin >> weight ,
    cout << endl;

   //!Loop for while (weight) (START)
   while (weight <= 0) {
        //ask weight again
        cout << "Enter the weight (kg): " ,
        cin >> weight ,
        cout << endl;
   }
   //!Loop for while (weight) (END)


    //Calling function
    BMI = INDEX(height, weight);
    cout << "Your BMI is: " << BMI << endl;

/*##################################################
                     BMI | CLASSES
  ##################################################*/

    if (BMI <= 18.5) {
        cout << "Underweight\n";
    } else if (BMI <= 24.9) {
        cout << "Which is Normal\n";
    } else if (BMI <= 29.9) {
        cout << "Overweight\n";
    } else {
        cout << "Obese\n";
    }
    

    system("pause");
    return 0;
    }