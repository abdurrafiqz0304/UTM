#include <iostream>
#include <string>
#define SIZE 3

using namespace std;

void getSpec(string caption, string *p_data) {
    cout << caption;
    cin >> *p_data; //!
}

void getSpec(string caption, int *p_data) { //!
    cout << caption;
    cin >> *p_data;
}

int fastestModel(string *m[], int *hp[], int w[]) { //!
    float whp_ratio, whp_ratio_lowest = (float)w[0] / *hp[0]; //!
    int idx = 0; //!
    
    cout << "Check weight and horsepower ratio: \n";
    
    for (int i = 0; i < SIZE; i++) {
        whp_ratio = (float)w[i] / *hp[i]; //!
        cout << *m[i] << " - " << whp_ratio << "\n"; //!
        
        if (whp_ratio < whp_ratio_lowest) { 
            whp_ratio_lowest = whp_ratio;
            idx = i;
        }
    }
    
    cout << "\n";
    
    return idx;
}

// Start main function
int main() {
    string *models [SIZE];
    int *horsepower [SIZE];
    int weight [SIZE];
    
    // Examples of car's models, horse power and weight
    // Almera - 76 hp - 1035 Kg
    // City - 88 hp - 1110 Kg
    // Persona - 80 hp - 1210 Kg
    // Vios - 78 hp - 1112 Kg
    for (int i = 0; i < SIZE; i++) {
        models[i] = new string; 
        getSpec("Car's model: ", models[i]);
        
        horsepower[i] = new int; //!
        getSpec("Horsepower (hp): ", horsepower[i]); //!
        
        getSpec("Weight (Kg): ", &weight[i]); //!

        cout << "\n";
    }
    
    int idx_fastest = fastestModel(models, horsepower, weight); //!
    
    cout << "Fastest car's model is " << *models[idx_fastest] //!
         << " with " << *horsepower[idx_fastest] << " horsepower and " //!
         << weight[idx_fastest] << " Kg of weight\n\n"; //!
    
    // delete array data from memory 
    for (int i = 0; i < SIZE; i++) {
        delete models[i];
        delete horsepower[i];
        //! delete weight[i];
    }
    

    system("pause");
    return 0; 
}
