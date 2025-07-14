#ifndef REMINDER_HPP
#define REMINDER_HPP
#include "User.hpp"
#include "Plant.hpp"
#include "PlantType.hpp"
#include "Schedule.hpp"
#include "valid.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Reminder {
    private:
        vector<User> users;
        int currentUserIndex = 1;
        public:
        void addUser() {
            string usernames;
            cout << "Enter your username: ";
            getline(cin, usernames);

            User addUser(usernames);
            users.push_back(addUser);

            cout << "\nUser " << usernames << " has been added as User " << currentUserIndex++ << ".\n";
            //currentUserIndex = users.size() - 1;
        }
        void switchUser() {
            int index=0;

            if (users.empty()) {
                cout << "No users available.\n";
                return;
            }

            cout << "\nChoose your user:\n";
            for (size_t i = 0; i < users.size(); i++) {
            cout << i + 1 << ") " << users[i].getUsername() << "\n";
            }

            cout << "Please insert using the given order of numbers:\nUser No : ";
            cin >> index;

            int choice;
            while (true) {
                cout << "Enter user number: ";
                cin >> choice;
                    if (choice >= 1 && choice <= static_cast<int>(users.size())) {
                        currentUserIndex = choice - 1;
                        cout << "Switched to user: " << users[currentUserIndex].getUsername() << "\n";
                    break;
                    }
            cout << "Invalid input. Try again.\n";
        }
        }
        void showUserMenu() {
            cout << "\n==USER MENU==\n";
            cout << "1. Add New User\n";
            cout << "2. Current User\n";
            cout << "3. Configure Plants\n";
            cout << "4. Exit System\n";
            cout << "Enter your choice: ";
        }
        void showPlantMenu() {
            cout << "\n==PLANT MENU==\n";
            cout << "1. Add New Plant\n";
            cout << "2. View Watering Schedule\n";
            cout << "3. Mark Plant as Watered\n";
            cout << "4. View Watering Report\n";
            cout << "5. Proceed Day\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
        }
        void proceedDay() {
            if (currentUserIndex != -1) {
                users[currentUserIndex].proceedDay();
            } else {
                cout << "No user selected.\n";
            }
        }

        void handlePlantMenu() {
            int choice;
            while (true) {
                Validator v;
                showPlantMenu();
                cin >> choice;
                cin.ignore();

                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    while (cin.get() != '\n'); // flush junk
                    continue; // skip rest of the loop
                }

                try {
                    v.validateMenuChoice(choice, 1, 6);  // throws if out of range

                    switch (choice) {
                        case 1: users[currentUserIndex].addPlant();             break;
                        case 2: users[currentUserIndex].viewSchedule();         break;
                        case 3: users[currentUserIndex].markPlantAsWatered();   break;
                        case 4: users[currentUserIndex].viewReport();           break;
                        case 5: users[currentUserIndex].proceedDay();           break;
                        case 6: return;  // Exit plant menu
                    }
                }
                catch (const char* errMsg){
                    cout << "Invalid option. Try again.\n";
                }
            }
        }
        
        void run() {
            Validator v;
            addUser();

            int choice;

            while (true){
                showUserMenu();
                cin >> choice;
                cin.ignore();

                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    while (cin.get() != '\n'); // flush junk
                    continue; // skip rest of the loop
                }

                try {
                    v.validateMenuChoice(choice, 1, 4);  // throws if out of range

                    switch (choice){
                        case 1: addUser(); break;
                        case 2: switchUser(); break;
                        case 3: handlePlantMenu(); break;
                        case 4: cout << "Exiting the Plant Watering Reminder System, thank you for time!\n";
                                system ("pause");
                                return;
                    }
                }
                catch (const char* errMsg) {
                    cout << "Invalid option. Try again.\n";
                }
            }
        }
};

#endif