#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int readInput(string name[], float ass[], float lab[], float mid[], float fin[]){

    //opening files
    ifstream input("input.txt");

    //debugging purposes only
    ofstream  NAME("name.txt");
    ofstream   ASS("ass.txt");
    ofstream   LAB("lab.txt");
    ofstream   MID("mid.txt");
    ofstream   FIN("fin.txt");
    ofstream   GRA("gra.txt");


    //Check if file is open or not
    if (!input) {
        cout << "Error opening file" << endl;
        cin.get();
    }
    
    //set initialize variables to 0
    int StudentNum = 0;

    
    //declare a variable for reading each line from the file
    string line;

/*
    //read the first line of the file to get number of student in class
    //counting total number of students
    while (!input.eof() && getline(input, line)){

        if (!line.empty()){

            //Extract names
            getline(input, name[StudentNum], ',');

            NAME << name[StudentNum] << endl;
            //Extract Assignment marks
            ASS  << ass[StudentNum] << endl;
            //Extract Lab marks
            LAB  << lab[StudentNum] << endl;
            //Extract Midterm marks
            MID  << mid[StudentNum] << endl;
            //Extract Final Exam marks
            FIN  << fin[StudentNum] << endl;
            }

            StudentNum++;
        }
*/

    //!!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!
    //This code works but it does not READ FROM LINE 1.
    //I have tried everything i can think of to fix this problem but no luck so far.
    //If you know how to solve this please let me know.

    while (!input.eof()){
        getline(input, line, ',');

        name[StudentNum] = line;
        input >> ass[StudentNum] >> lab[StudentNum] >> mid[StudentNum] >> fin[StudentNum];


        StudentNum++;

    

    }

/*    while (getline(input, line)) {
        if (!line.empty()) {
            stringstream ss(line);

            // Extract the name
            getline(ss, name[StudentNum], ',');

            // Extract the rest of the marks
            ss >> ass[StudentNum] >> lab[StudentNum] >> mid[StudentNum] >> fin[StudentNum];

            //!jap
            NAME << name[StudentNum] << endl;

            StudentNum++;
        }
    }
*/

/*
while (getline(input, line)) { // Read each line
    if (!line.empty()) {
        int comma = -1;

        // Find the position of the first comma manually
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                comma = i;
                break;
            }
        }

        // If a comma is found, process the line
        if (comma != -1) {
            // Extract the name
            name[StudentNum] = line.substr(0, comma);

            // Extract the rest of the fields (scores)
            line = line.substr(comma + 1); // Remove the name part
            int index = 0;

            // Read assignment score
            while (index < line.length() && line[index] != ' ') {
                ass[StudentNum] = ass[StudentNum] * 10 + (line[index] - '0');
                index++;
            }
            index++; // Skip the space

            // Read lab score
            while (index < line.length() && line[index] != ' ') {
                lab[StudentNum] = lab[StudentNum] * 10 + (line[index] - '0');
                index++;
            }
            index++; // Skip the space

            // Read midterm score
            while (index < line.length() && line[index] != ' ') {
                mid[StudentNum] = mid[StudentNum] * 10 + (line[index] - '0');
                index++;
            }
            index++; // Skip the space

            // Read final score
            while (index < line.length()) {
                fin[StudentNum] = fin[StudentNum] * 10 + (line[index] - '0');
                index++;
            }

            // Output data to the files
            NAME << name[StudentNum] << std::endl;
            ASS << ass[StudentNum] << std::endl;
            LAB << lab[StudentNum] << std::endl;
            MID << mid[StudentNum] << std::endl;
            FIN << fin[StudentNum] << std::endl;

            StudentNum++;
        }
    }
}
*/

            cout << "Total Number of Students: " << StudentNum << endl;

    return StudentNum;
}
void calculateTotalAndGrade(string name[], float ass[], float lab[], float mid[], float fin[], float totalMark[], char grade[], int& Studentnum){
    
    //debugging purpose
    ofstream tot("tot.txt");
    ofstream gra("gra.txt");

    //calculate total mark each student has and store them into an array
    for(int i=0;i<Studentnum;i++){
        totalMark[i] = ass[i] + lab[i] + mid[i] + fin[i];
        tot << totalMark[i] << endl;

        //assign grades based on their total mark
        if(totalMark[i]  >=85)                      {grade[i]='A';} else
        if(totalMark[i] >= 70 && totalMark[i] <= 84){grade[i]='B';} else
        if(totalMark[i] >= 55 && totalMark[i] <= 69){grade[i]='C';} else
        if(totalMark[i] >= 40 && totalMark[i] <= 54){grade[i]='D';}
        else{grade[i]='F';
        }
        gra << grade[i] << endl;
    }
    
    //close all files
    tot.close();
    gra.close();
}
void displayOutput(int studentNum, string name[], float ass[], float lab[], float mid[], float fin[], float totalMark[], char grade[]){
    
    //debugging purposes only
    ofstream out("output.txt");
    ofstream out1("output1.txt");
    
    //Display header
    cout << left << setw(20) << "Student Name"          
         << left << setw(14) << "Assignments"          
         << left << setw(16) << "Lab Exercises"      
         << left << setw(16) << "Midterm Tests"         
         << left << setw(14) << "Final Exams"           
         << left << setw(14) << "Total Marks"           
         << left <<             "Grade"
                             << endl
                             << string(100, '-')
                             << endl;

    out << left << setw(20) << "Student Name"          
         << left << setw(14) << "Assignments"          
         << left << setw(16) << "Lab Exercises"      
         << left << setw(16) << "Midterm Tests"         
         << left << setw(14) << "Final Exams"           
         << left << setw(14) << "Total Marks"           
         << left <<             "Grade"
                             << endl
                             << string(100, '-')
                             << endl;

    out1 << left << setw(20) << "Student Name"          
         << left << setw(14) << "Assignments"          
         << left << setw(16) << "Lab Exercises"      
         << left << setw(16) << "Midterm Tests"         
         << left << setw(14) << "Final Exams"           
         << left << setw(14) << "Total Marks"           
         << left <<             "Grade"
                             << endl
                             << string(100, '-')
                             << endl;

    //display output to screen
    for (int i=0;i<studentNum;i++){


        if (i>0){
        cout << left 
                     << fixed << setprecision(1) << setw(23)  <<      name[i] 
                                                 << setw(16)  <<       ass[i] 
                                                 << setw(16)  <<       lab[i] 
                                                 << setw(15)  <<       mid[i] 
                                                 << setw(13)  <<       fin[i] 
                     << fixed << setprecision(2) << setw(13)  << totalMark[i] 
                                                              <<     grade[i];}
            else {
                cout << left 
                     << fixed << setprecision(1) << setw(22)  <<      name[i] 
                                                 << setw(16)  <<       ass[i] 
                                                 << setw(16)  <<       lab[i] 
                                                 << setw(15)  <<       mid[i] 
                                                 << setw(13)  <<       fin[i] 
                     << fixed << setprecision(2) << setw(13)  << totalMark[i] 
                                                              <<     grade[i];
            }

        out << fixed << left << setw(25)                    <<      name[i]
                             << setw(16) << setprecision(1) <<       ass[i]
                             << setw(16)                    <<       lab[i]
                             << setw(15)                    <<       mid[i]
                             << setw(13)                    <<       fin[i]
                             << setw(13) << setprecision(2) << totalMark[i]
                                                            <<     grade[i];

        out1 << left << fixed << setprecision(1) << setw(23) << name[i];

if (i > 0) {
    out1 << " ";
    out1 << left << fixed << setprecision(1) << setw(16) << ass[i];
} else {
    out1 << left << fixed << setprecision(1) << setw(16) << ass[0];
} }

    out << endl;
    cout << endl;

    //close all files
    out.close();
    out1.close();
}
void displayAnalysis(string name[], float totalMark[], char grade[], int& Studentnum){

    //debugging purposes only
    ofstream ana("ana.txt");

    //*Calculate highest marks

    float max = -9999.00;
    for (int i=0;i<Studentnum;i++){
        (totalMark[i]>max) ? max = totalMark[i] : max=max;}

    //Find whos got the highest marks
    string highest;
    for (int i=0;i<Studentnum;i++){ 
        if (max == totalMark[i]) {
            highest=name[i]; break;}}

    //*Calculate lowest marks
    float min = 9999.00;
    for(int i=0;i<Studentnum;i++){
        (totalMark[i]<min) ? min = totalMark[i] : min=min;}

    //Find whos got the lowest marks
    string lowest;
    for (int i=0;i<Studentnum;i++){ 
        if (min == totalMark[i]) {
            lowest=name[i]; break;}}

    //*Calculate average marks

    //Initialize sum
    float sum = 0;
    
    //Sum up all marks
    for(int i=0;i<Studentnum;i++){sum += totalMark[i];}

    //Calculate average
    float avg = sum/Studentnum;

    

    //debugging purposes only
/*    ana << fixed << setprecision(2) << "Class Average Marks: " << avg
                                                               << endl;
    ana << "Highest Score: " << highest << "(" << max << ")"   << endl;
    ana << "Lowest Score: "  << lowest  << "(" << min << ")"   << endl;
*/ 

    cout << endl;
    cout << fixed << setprecision(2) << "Class Average Marks: " << avg
                                                               << endl;

    cout << "Highest Score: " << highest << " (" << max << ")" << endl;
    cout << "Lowest Score: "  << lowest  << " (" << min << ")" << endl;

    //*Calculate how many A's, etc.

    //initialize counters using struct
    struct counter{
        int A=0,
            B=0,
            C=0,
            D=0,
            E=0,
            F=0;
    };

    //Counters for each letter grade
    counter c;
    for (int i=0; i<Studentnum; i++){
        switch (grade[i]){
            case 'A': c.A++;break;
            case 'B': c.B++;break;
            case 'C': c.C++;break;
            case 'D': c.D++;break;
            default:  c.F++;break;}
    }

    /*debugging purposes only
    ana << "A: " << c.A << endl;
    ana << "B: " << c.B << endl;
    ana << "C: " << c.C << endl;
    ana << "D: " << c.D << endl;
    ana << "E: " << c.E << endl;
    ana << "F: " << c.F << endl;
    */


    //*Calculate percentages
    //initialise percentage variables using struct

    struct percentage{
        float a=0,
              b=0,
              c=0,
              d=0,
              e=0,
              f=0;
    };

    //Percentage variables
    percentage p;
    for (int i=0; i<Studentnum; i++){
        switch (grade[i]){
            case 'A': p.a=(c.A*100.0)/Studentnum;break;
            case 'B': p.b=(c.B*100.0)/Studentnum;break;
            case 'C': p.c=(c.C*100.0)/Studentnum;break;
            case 'D': p.d=(c.D*100.0)/Studentnum;break;
            case 'E': p.e=(c.D*100.0)/Studentnum;break;
            case 'F': p.f=(c.D*100.0)/Studentnum;break;
            default:  break;}
    }

    /*debugging purposes only
    ana << endl;
    ana << "A's percentage: " << p.a << "%" << endl;
    ana << "B's percentage: " << p.b << "%" << endl;
    ana << "C's percentage: " << p.c << "%" << endl;
    ana << "D's percentage: " << p.d << "%" << endl;
    ana << "E's percentage: " << p.e << "%" << endl;
    ana << "F's percentage: " << p.f << "%" << endl;
    */

/*
   //count for how many type of grades are there
    bool countedGrades[256] = {false}; // Assuming ASCII characters
    int uniqueGradeCount = 0;
    for (int i = 0; i < Studentnum; i++) {
        if (!countedGrades[grade[i]]) {
            countedGrades[grade[i]] = true;
            uniqueGradeCount++;
        }
    }
        ana <<uniqueGradeCount << endl; */


    //*Print histogram
    
/*    //! make it better
    //!count how many type of grades are there
    //! and put it in declaire GRADE array to make it generalized
    //!and use it as a parameter for histogram function

    //Declaire grade array
    char GRADE[6]={'A','B','C','D','E','F'};

    //count how many gred it has
    //initialize counter
    int cnt = 0;
    for (int i=0; i<GRADE[i]; i++){
            cnt++;
    }
    ana << cnt << endl;
*/

    //check if any of the grade is zero
    //if yes then print nothing
    //! If you can generalize it, change it with "cnt" instead of "6"

    //debugging purposes only
    //ana << endl << "Grade Histogram" << endl;
    cout << endl << "Grade Histogram" << endl;
    
    //Declaire grade array and percentage array
    char GRADE[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    float percentages[6] = {p.a, p.b, p.c, p.d, p.e, p.f};
    int countGrades[6] = {c.A,c.B,c.C,c.D,c.E,c.F};

    //print histogram

    for (int i = 0; i < 6; i++) {
        if (percentages[i] > 0.0) {
            //ana << GRADE[i] << ": ";
            cout << GRADE[i] << ": ";
        
        //set up number symbol to be present as percentage weights
        int plus = countGrades[i]*2;

        //print the symbols
        for (int j = 0; j < plus; j++) {
            //ana << "+" ;
            cout << "+" ;
                }

            ana << " " << "(" << percentages[i] << "%)" ;
            ana << endl;
            cout << " " << "(" << percentages[i] << "%)" ;
            cout << endl;

            }
        }


//if (grade[i]=='A'){
//    ana << grade[i] << ": ";
//}































































    //for (int i=0; i<Studentnum; i++){
    //    if ( < 0){
    //        ana << grade[i] << ": ";
    //    }
    //}

    


    

    //Close all files
    ana.close();
}


int main(){

    //Assume maximum number of students in class is 50
    int NUM_STUDENT = 50;

    //Declare arrays that will hold information about students
    string  name[NUM_STUDENT];
    float    ass[NUM_STUDENT] = {0.0},
             lab[NUM_STUDENT] = {0.0},
             mid[NUM_STUDENT] = {0.0},
             fin[NUM_STUDENT] = {0.0};
    float   totalMark[NUM_STUDENT] = {0.0};
    char   grade[NUM_STUDENT];

    //Read data from input file
    //Get actual number of students in class
    NUM_STUDENT = readInput(name, ass, lab, mid, fin);

    //Calculate Total Mark and Grade for Each Student
    calculateTotalAndGrade(name, ass, lab, mid, fin, totalMark, grade, NUM_STUDENT);

    //To display output to screen
    displayOutput(NUM_STUDENT, name, ass, lab, mid, fin, totalMark, grade);

    //To display analysis data to screen
    displayAnalysis(name, totalMark, grade, NUM_STUDENT);

    system("pause");
    return 0;
}