#include <iostream>
#include <iomanip>
#define PI 3.142
using namespace std;

class Cone {
    private:
        float radius, height; //attributes

        public: //regular function
            void readInput();
            float calcArea() const;
            float calcVolume(float) const;
            void dispOutput(float, float) const;
};

// function implementation/ definition
void Cone::readInput() {
    cout << "Enter radius: "; //user input
                    cin >> radius;
                    cout << "Enter height: ";
                    cin >> height;
}
            float Cone::calcArea() const{ // Read the two private data
                /*float baseArea;
                baseArea = PI * radius * radius;*/
                return PI * radius * radius; 
            }

            float Cone::calcVolume(float baseArea) const{
                return (1/3.0) * baseArea * height;
            }
            void Cone::dispOutput(float baseArea, float volume) const{
                cout << "\n\n2 private data:\n"
                     << "\tRadius = " << radius << endl
                     << "\tHeight = " << height << endl;
                cout << "\nOutput:\n"
                     << "\nBase area = " << baseArea << ednl
                     << "\tVolume = " << volume << endl;
            }

int main() {
    Cone cn1; // create an object
    float area, vol;

    cout << fixed << setprecision(2);
    cn1.readInput();
    /*area = cn1.calcArea();
    vol = cn1.calcVolume(area);*/
    cn1.dispOutput(cn1.calcArea, cn1.calcVolume(cn1.calcArea()));

    system("pause");
    return 0;
}