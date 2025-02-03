#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Structure definition
struct ImmunisationData {
    int year;
    double percentages[5]; // Measles, MMR, DPT, Hepatitis B, Polio
};

// Function to read data from file
void readInput(ImmunisationData data[], int &size, const string &filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
    size = 0;
    while (inputFile >> data[size].year) {
        for (int i = 0; i < 5; i++) {
            inputFile >> data[size].percentages[i];
        }
        size++;
    }
    inputFile.close();
}

// Function to calculate averages
void calculateAverage(const ImmunisationData data[], int size, double avg[]) {
    for (int i = 0; i < 5; i++) {
        double sum = 0;
        for (int j = 0; j < size; j++) {
            sum += data[j].percentages[i];
        }
        avg[i] = sum / size;
    }
}

// Function to display lowest and highest percentages
void displayAnalysis(const ImmunisationData data[], int size, const string diseases[]) {
    double minVal = 100, maxVal = 0;
    int minYear, maxYear;
    string minDisease, maxDisease;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            if (data[j].percentages[i] < minVal) {
                minVal = data[j].percentages[i];
                minYear = data[j].year;
                minDisease = diseases[i];
            }
            if (data[j].percentages[i] > maxVal) {
                maxVal = data[j].percentages[i];
                maxYear = data[j].year;
                maxDisease = diseases[i];
            }
        }
    }
    cout << "The lowest level of immunisation: " << minDisease << " (" << minVal << "%) in year " << minYear << endl;
    cout << "The highest level of immunisation: " << maxDisease << " (" << maxVal << "%) in year " << maxYear << endl;
}

// Function to display results
void displayOutput(const ImmunisationData data[], int size, const string diseases[], const double avg[]) {
    cout << "The Percentage of Infants who have been Immunised against Measles, MMR, DPT, Hepatitis B, and Polio (2004-2015)\n";

    cout << string(68, '-') << endl;

    cout << "Year     Measles    MMR        DPT        Hepatitis B  Polio\n";

    cout << string(68, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(4) << data[i].year;
        for (int j = 0; j < 5; j++) {
            cout << setw(10) << fixed << setprecision(2) << data[i].percentages[j];
        }
        cout << endl;
    }

    cout << string(68, '-') << endl;
    cout << "Average  ";
    for (int i = 0; i < 5; i++) {
        cout << setw(10) << fixed << setprecision(2) << avg[i];
    }
    cout << endl;
    cout << string(68, '-') << endl;
    displayAnalysis(data, size, diseases);
    cout << string(68, '-') << endl;
}

int main() {
    ImmunisationData data[20]; // Array to store data
    double avg[5]; // Array for averages
    int size = 0;
    string diseases[5] = {"Measles", "MMR", "DPT", "Hepatitis B", "Polio"};
    
    readInput(data, size, "input.txt");
    calculateAverage(data, size, avg);
    displayOutput(data, size, diseases, avg);
    
    system("pause");
    return 0;
}
