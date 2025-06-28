#ifndef PLANT_TYPE_HPP
#define PLANT_TYPE_HPP
#include "Plant.hpp"
#include "valid.hpp"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Succulent : public Plant {
    public:
        string getPlantType()const override {
            return "Succulent";
        }
        int getWateringFrequency() const override {
            return 3;
        }
};

class Flowering : public Plant {
    public:
        string getPlantType()const override {
            return "Flowering";
        }
        int getWateringFrequency() const override {
            return 1;
        }
};


class Other : public Plant {
    public:
        string getPlantType() {
            cout << "Enter plant type: ";
            string type;
            getline(cin, type);
            return type;
        }
        int getWateringFrequency() const override{
            cout << "Enter watering frequency (days): ";
            int freq;
            cin >> freq;
            Validator v;
            v.validateFreq(freq);
            return freq;
        }
};

#endif