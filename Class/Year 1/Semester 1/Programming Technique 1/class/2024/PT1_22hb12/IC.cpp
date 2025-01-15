//slide 81, C5
#include <iostream>
#define R 4
#define C 3
using namespace std;

//get user input for number of gold silver bronze medal won by a country
//and store it in an array of medals
void getMedal(int medal[R][C]) {
    for (int i = 0; i < R; i++){ //referring to each country
        cout << "Enter the medals for country " << i+1 << ": ";
        for (int j = 0 ; j < C ; j++) {
            cin >> medal[i][j]; //number of medal
        }
    }

}

//Return total number of medals won by a country3
int callTotCountry3(int medal[R][C]) {
    int totMedals = 0;

    for (int i = 0; i < C; i++){ // to control column
        totMedals += medal[2][i];
    }

    return totMedals;
}

//Return the largest number of medals won
int callLargestMedal(int medal[R][C]) {
    int large = -9999;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++) {
            if(medal[i][j] > large)
                large = medal[i][j];
        }
    }

    return large;
}

//Return the largest number of medals won
int callLargestMedal(int medal[R][C]) {
    int large = -9999;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++) {
            if(medal[i][j] > large)
                large = medal[i][j];
        }
    }

    return large;
}

//Return the smallest number of medals won
int callsmallestMedal(int medal[R][C]) {
    int small = 9999;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++) {
            if(medal[i][j] < small)
                small = medal[i][j];
        }
    }

    return small;
}

//Return the highest number of gold medal won
int findHighestGold(int medal[R][C]){
    int highGold = -9999;
    for (int i = 0; i < R; i++){
        if(medal[i][0] > highGold){
            highGold = medal[i][0];
            high = medal[i][0];
        }
    }
    return highGold;
}

//Return the total number of bronze medal won
int calcTotalBronze(int medal[R][C]){
    int totalB = 0;
    for (int i = 0; i < R; i++){
        totalB += medal[i][2];
    }
    return totalB;
}


int main () 
{
    int countryMedal[R][C];

    getMedal(countryMedal[R][C]);
    cout << "\nTotal medals won by country 3: " << callTotCountry3(countryMedal) << endl;
    cout << "\nLargest: " << callLargestMedal(countryMedal);
    cout << "\nSmallest: " << callsmallestMedal(countryMedal);
    cout << "\nHighest Gold Medal: " << findHighestGold(countryMedal);
    cout << "\nTotal Bronze Medals Won: " << calcTotalBronze(countryMedal);
    
    system("pause");
    return 0;
}
