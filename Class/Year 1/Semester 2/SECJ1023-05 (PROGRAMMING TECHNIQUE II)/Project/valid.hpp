#ifndef VALID_HPP
#define VALID_HPP

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Validator {
public:
    void validateFreq(int freq) {
        if (freq <= 0) {
            throw "Frequency must be greater than 0.";
        }
    }

    void validateMenuChoice(int choice, int min, int max) {
        if (choice < min || choice > max) {
            throw "Menu choice must be within valid range.";
        }
    }
};

#endif