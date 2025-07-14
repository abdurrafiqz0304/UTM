// Abdurrafiq Bin Zakaria A24CS0031
// Muhammad Afiq Irfan Bin Zuraimi

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_HOURS 24
#define Car 2
#define Motorcycle 1
#define Truck 3.50
#define surcharge 10

class Parking {

    private:
        string vehicleNumber;
        string vehicleType;
        int hoursParked;
        double fee;

    public:
        // Constructor definition
        Parking(string vNumber, string vType, int hours) {
            vehicleNumber = vNumber;
            vehicleType = vType;
            hoursParked = hours;
            calculateFee(vehicleType, hoursParked);
        }

        ~Parking() {
            cout << "Record closed for vehicle " << vehicleNumber << "." << endl;
        }

        bool isValidType(string type) {
            return (type == "Car" || type == "Motorcycle" || type == "Truck");
        }

        bool isValidHours(int hours) {
            return (hours >= 0 && hours <= MAX_HOURS);
        }

        void calculateFee(string vehicleType, int hoursParked) {
            if (vehicleType == "Car") {
                fee = Car * hoursParked;
            } else if (vehicleType == "Motorcycle") {
                fee = Motorcycle * hoursParked;
            } else if (vehicleType == "Truck") {
                fee = Truck * hoursParked;
                if (hoursParked > 12) {
                    fee += surcharge;
                }
            }
        }

        void displayReceipt() {
            cout << "Vehicle Number: " << vehicleNumber << endl;
            cout << "Vehicle Type: " << vehicleType << endl;
            cout << "Hours Parked: " << hoursParked << endl;
            cout << "Base Fee: RM" << fee << endl;
            cout << "Surcharge: RM" << (vehicleType == "Truck" && hoursParked > 12 ? surcharge : 0) << endl;
            cout << "Total Fee: RM" << fee << endl;
        }
};

int main() {
    string vehicleNumber;
    string vehicleType;
    int hoursParked;

    cout << "Enter vehicle number: ";
    cin >> vehicleNumber;
    cout << endl;

    cout << "Enter vehicle type: ";
    cin >> vehicleType;
    cout << endl;

    cout << "Enter number of hours parked: ";
    cin >> hoursParked;
    cout << endl;

    if (vehicleType == "Car" || vehicleType == "Motorcycle" || vehicleType == "Truck") {
        if (hoursParked >= 0 && hoursParked <= MAX_HOURS) {
            Parking p(vehicleNumber, vehicleType, hoursParked);
            p.displayReceipt();
        } else {
            cout << "Invalid hours. Maximum parking duration is 24 hours." << endl;
        }
    } else {
        cout << "Invalid vehicle type. The accepted types are: Car, Motorcycle, Truck." << endl;
        return 0;
    }

    system("pause");
    return 0;
}
