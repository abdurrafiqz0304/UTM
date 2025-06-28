#ifndef PLANT_HPP
#define PLANT_HPP
#include "valid.hpp"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Plant {
    protected:
        string name;
        string plantType;
        int wateringFrequency;
        int daysLeft;
        bool wateredToday;
    public:
        Plant(string name=" ", string type=" ", int freq=0) : name(name), plantType(type), wateringFrequency(freq) {
            daysLeft = freq;
            wateredToday = 0;
        }
        Plant(const Plant& other) = default;

        virtual string getPlantType() const { return plantType;}
        virtual int getWateringFrequency() const {return wateringFrequency;}
        void markAsWatered() {
            daysLeft = wateringFrequency;
            wateredToday = true;
        }

        void proceedDay() {
            if (daysLeft > 0) {
                daysLeft--;
            } else {
                daysLeft = getWateringFrequency();
            }
        }

        string getReport() const {
            string outputReport;

            outputReport = "Watering Report:";
            outputReport += "\n";
            outputReport += string(25, '-');
            outputReport += "\n";
            outputReport += "Plant: ";
            outputReport += name;
            outputReport += "Type: \n";
            outputReport += plantType;
            outputReport += "\n";

            if (wateredToday) {
                outputReport += "Has already been watered recently!\n Days until next watering: ";
                outputReport += to_string(daysLeft);
            } else {
                outputReport += "Has not been watered yet today! \n Please water the plant, thank you.";
            }
            return outputReport;
        }    

        string getName() const { return name;}

        void setName(string n) { name = n; }

        bool isWateredToday() const { return wateredToday;}

        int getDaysLeft() const{ return daysLeft;}
    };

#endif