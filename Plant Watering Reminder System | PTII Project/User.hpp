#ifndef USER_HPP
#define USER_HPP
#include "Plant.hpp"
#include "PlantType.hpp"
#include "valid.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class User {
    private:
        string username;
        int userID;
        vector<Plant> plants;
    public:
        User(string name=" ", int id=1) : username(name), userID(id) {}

        // Add this public method to your User class
void debugDisplayPlants() const {
    cout << "\n=== Current Plants in Vector ===\n";
    if (plants.empty()) {
        cout << "No plants stored yet!\n";
        return;
    }
    
    for (int i = 0; i < plants.size(); i++) {
        cout << "Plant #" << i+1 << ":\n"
             << "  Name: " << plants[i].getName() << "\n"
             << "  Type: " << plants[i].getPlantType() << "\n"
             << "  Water Freq: " << plants[i].getWateringFrequency() << " days\n";
    };
}

        void addPlant() {
            Validator v;
            string tempName; int tempFreq;
            int plantTypeChoice;
            cout << "Enter plant name: ";
            getline(cin, tempName);  // Reads entire line (spaces allowed)

            // Get plant type
            cout << "Select plant type:\n"
                 << "1. Succulent\n"
                 << "2. Flowering\n"
                 << "3. Other\n"
                 << "Enter your choice: ";
            cin >> plantTypeChoice; cin.ignore();

            Plant tempPlant;    

            switch (plantTypeChoice){
                case 1: {Succulent s;
                    tempPlant = Plant(tempName, s.getPlantType(), s.getWateringFrequency());
                        break;
                }
                case 2: {Flowering f;
                    tempPlant = Plant(tempName, f.getPlantType(), f.getWateringFrequency());
                        break;
                }
                case 3: {Other o;
                    tempPlant = Plant(tempName, o.getPlantType(), o.getWateringFrequency());
                        break;
                }
            }

            cout << "Plant added successfully!\n";

            // Get watering frequency (with input validation)
            plants.push_back(tempPlant);

            debugDisplayPlants();
        }

        void viewSchedule() {
            cout << "Watering Schedule:\n";
            
            for (auto i = plants.begin(); i!=plants.end(); i++){
                cout << "- ";
                cout << i->getName() << "(every " << i->getWateringFrequency() << " day(s))\n";
            }
        }
        void markPlantAsWatered() {
            int index = 0;
            
            if (index >= 0 && index < plants.size() && plants[index].isWateredToday() == false){
                plants[index].markAsWatered();
                cout << plants[index].getName() << "has been watered!";
            } else {
                cout << "Has already been watered.";
            }
        }
        void viewReport() const {
                for (int i = 0; i < plants.size(); i++) {
                    cout << plants[i].getReport() << "\n";
            }
        }
        bool allPlantsWatered() {
            for (auto i = plants.begin(); i!=plants.end(); i++){
                if (!(i->isWateredToday())) {
                    return false;
                }
            }
            return 1;
        }
        void proceedDay() {
            cout << "Day has proceeded\n";

            for (auto i = plants.begin(); i!=plants.end(); i++) {
                if (i->getDaysLeft() == 0)
                    cout << "Please water " << i->getName() << "today\n";
                else
                    cout << i->getName() << " is " << i->getDaysLeft() << " day(s) away from needing to be watered.\n";
            }
        }
        string getUsername() {
            return username;
        }
        int getUserID() {
            return userID;
        }
        int getPlantCount() {
            return plants.size();
        }
        Plant* getPlant(int index){
            if (index >= 0 && index < plants.size()) {
                return &plants[index];
            } else {
                return nullptr; // For safety if invalid ----> default
            }
        }
};

#endif