#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace PlantSystem {

class Plant {
protected:
    string name, status;
    int wateringFrequency, daysLeft;
    bool wateredToday;

public:
    Plant(string name, int freq)
        : name(name), wateringFrequency(freq), daysLeft(freq), status("Healthy"), wateredToday(false) {}
    virtual ~Plant() {}

    virtual string getPlantType() const = 0;
    virtual int getWateringFrequency() const = 0;

    void markAsWatered() {
        daysLeft = wateringFrequency;
        wateredToday = true;
        status = "Watered";
    }

    void nextDay() {
        if (!wateredToday && daysLeft == 0) status = "Needs Water";
        else if (daysLeft > 0) daysLeft--;
        wateredToday = false;
    }

    string getStatus() const { return status; }
    string getName() const { return name; }
    int getDaysLeft() const { return daysLeft; }
    bool hasBeenWateredToday() const { return wateredToday; }
};

class Succulent : public Plant {
public:
    Succulent(string name, int freq) : Plant(name, freq) {}
    string getPlantType() const override { return "Succulent"; }
    int getWateringFrequency() const override { return wateringFrequency; }
};

class Flowering : public Plant {
public:
    Flowering(string name, int freq) : Plant(name, freq) {}
    string getPlantType() const override { return "Flowering"; }
    int getWateringFrequency() const override { return wateringFrequency; }
};

class Other : public Plant {
public:
    Other(string name, int freq) : Plant(name, freq) {}
    string getPlantType() const override { return "Other"; }
    int getWateringFrequency() const override { return wateringFrequency; }
};

class Validator {
public:
    static bool validateFrequency(int freq) { return freq > 0 && freq <= 30; }
    static bool validateMenuChoice(int choice, int min, int max) {
        return choice >= min && choice <= max;
    }
};

class User {
public:
    string name;
    vector<Plant*> plants;

    User(string name) : name(name) {}
    ~User() {
        for (auto p : plants) delete p;
    }
};

} // namespace PlantSystem

using namespace PlantSystem;

void plantMenu(User* user) {
    while (true) {
        cout << "\n==PLANT MENU==\n"
             << "1. Add New Plant\n2. View Watering Schedule\n3. Mark Plant as Watered\n4. View Watering Report\n5. Proceed day\n6. Exit\nEnter your choice: ";
        int choice; cin >> choice;
        if (choice == 6) {
            cout << "\nExiting the plant menu, returning to the user menu.\n";
            break;
        }
        if (!Validator::validateMenuChoice(choice, 1, 6)) {
            cout << "Invalid choice.\n";
            continue;
        }

        if (choice == 1) {
            string pname, ptype;
            int freq;
            cout << "Enter plant name: "; cin >> ws; getline(cin, pname);
            cout << "Enter plant type (Succulent/Flowering/Other): "; getline(cin, ptype);
            cout << "Enter watering frequency (in days): "; cin >> freq;

            if (!Validator::validateFrequency(freq)) {
                cout << "Invalid frequency.\n"; continue;
            }
            if (ptype == "Succulent") user->plants.push_back(new Succulent(pname, freq));
            else if (ptype == "Flowering") user->plants.push_back(new Flowering(pname, freq));
            else user->plants.push_back(new Other(pname, freq));
            cout << "\nPlant added successfully!\n";
        }
        else if (choice == 2) {
            cout << "\nWatering Schedule:\n";
            for (auto* p : user->plants)
                cout << "- " << p->getName() << " (every " << p->getWateringFrequency() << " day(s))\n";
        }
        else if (choice == 3) {
            cout << "\nWhich plant did you water?\n";
            for (size_t i = 0; i < user->plants.size(); ++i)
                cout << i + 1 << ". " << user->plants[i]->getName() << endl;
            int idx; cout << "Enter choice: "; cin >> idx;
            if (idx < 1 || idx > user->plants.size()) {
                cout << "Invalid index.\n"; continue;
            }
            user->plants[idx - 1]->markAsWatered();
            cout << "\n❀❀❀ " << user->plants[idx - 1]->getName() << " has been watered ! ❀❀❀\n";
        }
        else if (choice == 4) {
            cout << "\nWatering Report:\n-------------------------\n";
            for (auto* p : user->plants) {
                cout << "Plant: " << p->getName() << "\nType: " << p->getPlantType() << endl;
                if (p->hasBeenWateredToday())
                    cout << "Has already been watered today!\nDays until next watering : " << p->getDaysLeft() << "\n\n";
                else
                    cout << "Has not been watered yet today!\nPlease water the plant, thank you.\n\n";
            }
        }
        else if (choice == 5) {
            bool allWatered = true;
            for (auto* p : user->plants) {
                if (!p->hasBeenWateredToday()) {
                    allWatered = false;
                    break;
                }
            }
            if (!allWatered) {
                cout << "\nThe day cannot proceed unless all plants have been watered.\nPlant(s) that have not been watered yet:\n";
                for (size_t i = 0; i < user->plants.size(); ++i) {
                    if (!user->plants[i]->hasBeenWateredToday())
                        cout << i + 1 << ") " << user->plants[i]->getName() << endl;
                }
            } else {
                for (auto* p : user->plants) p->nextDay();
                cout << "\nDay has proceeded!\n\n";
                for (auto* p : user->plants) {
                    if (p->getDaysLeft() == 0)
                        cout << "Please water " << p->getName() << " today.\n";
                    else
                        cout << p->getName() << " is " << p->getDaysLeft() << " day(s) away from needing to be watered.\n";
                }
            }
        }
    }
}

int main() {
    vector<User*> users;
    int currentUser = -1;
    cout << "===================================\n       Plant Watering Reminder System\n===================================\n";
    while (true) {
        cout << "\n==USER MENU==\n1. Add New User\n2. Current User\n3. Configure Plants\n4. Exit System\nEnter your choice: ";
        int choice; cin >> choice;

        if (choice == 4) {
            cout << "\nExiting the Plant Watering Reminder System, thank you for your time!\n";
            break;
        }
        if (!Validator::validateMenuChoice(choice, 1, 4)) {
            cout << "Invalid choice.\n"; continue;
        }

        if (choice == 1) {
            string uname;
            cout << "\nEnter user name: "; cin >> ws; getline(cin, uname);
            users.push_back(new User(uname));
            cout << "User " << uname << " has been added as User " << users.size() << ".\n";
        }
        else if (choice == 2) {
            if (users.empty()) {
                cout << "\nNo users available. Add one first.\n"; continue;
            }
            cout << "\nChoose your user:\n";
            for (size_t i = 0; i < users.size(); ++i)
                cout << i + 1 << ") " << users[i]->name << endl;
            cout << "\nPlease insert using the given order of numbers :\nUser No : ";
            int idx; cin >> idx;
            if (idx < 1 || idx > users.size()) {
                cout << "Invalid index.\n"; continue;
            }
            currentUser = idx - 1;
            cout << "\nCurrent user is now " << users[currentUser]->name << "!\n";
        }
        else if (choice == 3) {
            if (currentUser == -1) {
                cout << "\nPlease select a user first.\n";
                continue;
            }
            plantMenu(users[currentUser]);
        }
    }
    for (auto* u : users) delete u;
    return 0;
}
