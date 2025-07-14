#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP
#include "Plant.hpp"
#include "valid.hpp"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Schedule {
    private:
        Plant* plant;
        int lastWateredDay, nextWateredDay;
    public:
        void updateSchedule() {
            //plant = &plant;
            lastWateredDay = plant->getWateringFrequency() - plant->getDaysLeft();
        }
    bool isDue() {
        if(plant->getDaysLeft() == plant->getWateringFrequency()) {
            return 1;
        } {
            return false;
        }
    }
    int dayUntilNext() {
        return plant->getDaysLeft();
    }
};

#endif