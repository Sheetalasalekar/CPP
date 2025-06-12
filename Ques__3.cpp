/*
 * Ques_3.cpp
 *
 * Q3. Imagine you are tasked with creating a program to simulate a toll booth. The toll booth
keeps
track of the number of vehicles that have passed through it and the total amount of money
collected. You need to implement a class TollBooth with appropriate data members and
member functions to accomplish this.
Here are the details for the TollBooth class:
1. Data Members: - totalVehicles: An integer to keep track of the total number of vehicles that have
passed through the toll booth. - totalRevenue: A double to store the total revenue collected from tolls.
2. Member Functions:
1. void reset(): Resets both the totalVehicles and totalRevenue to zero.
2. void vehiclePayingToll(int vehicleType, double tollAmount): Accepts an integer
vehicleType and a double tollAmount. The vehicleType represents the type of car (1
for standard car, 2 for truck, 3 for bus). The function should increment totalVehicles
by 1 and add tollAmount to totalRevenue based on the car type.
3. int getTotalVehicles() : A getter method that returns the total number of vehicles
passed through the booth.
4. double getTotalRevenue() : A getter method that returns the total revenue collected.
3. Menu-Driven Program:
Write a menu-driven program in main() that allows the user to interact with the TollBooth
class: - Display a menu with the following options:
1. Add a standard car and collect toll
2. Add a truck and collect toll
3. Add a bus and collect toll
4. Display total cars passed
5. Display total revenue collected
6. Reset booth statistics
7. Exit - Implement the logic for each menu option using appropriate member functions of the
TollBooth class. - Continue displaying the menu until the user chooses to exit. - Define a fixed toll amount for each type of car (e.g., $2 for standard cars, $5 for trucks, $10
for buses).
 */

#include <iostream>
using namespace std;

class TollBooth {
private:
    int totalVehicles;
    double totalRevenue;

public:
    // Constructor to initialize values
    TollBooth() {
        totalVehicles = 0;
        totalRevenue = 0.0;
    }

    // Reset the booth statistics
    void reset() {
        totalVehicles = 0;
        totalRevenue = 0.0;
        cout << "Booth statistics reset successfully.\n";
    }

    // Add vehicle and collect toll
    void vehiclePayingToll(int vehicleType, double tollAmount) {
        totalVehicles++;
        totalRevenue += tollAmount;
        switch (vehicleType) {
            case 1:
                cout << "Standard car added. Toll collected: ₹" << tollAmount << endl;
                break;
            case 2:
                cout << "Truck added. Toll collected: ₹" << tollAmount << endl;
                break;
            case 3:
                cout << "Bus added. Toll collected: ₹" << tollAmount << endl;
                break;
            default:
                cout << "Unknown vehicle type.\n";
        }
    }

    // Getter for total vehicles
    int getTotalVehicles() const {
        return totalVehicles;
    }

    // Getter for total revenue
    double getTotalRevenue() const {
        return totalRevenue;
    }
};

int main() {
    TollBooth booth;

    // Fixed toll amounts
    const double carToll = 2.0;
    const double truckToll = 5.0;
    const double busToll = 10.0;

    int choice;

    do {
        cout << "\n===== Toll Booth Menu =====\n";
        cout << "1. Add a standard car and collect toll\n";
        cout << "2. Add a truck and collect toll\n";
        cout << "3. Add a bus and collect toll\n";
        cout << "4. Display total vehicles passed\n";
        cout << "5. Display total revenue collected\n";
        cout << "6. Reset booth statistics\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                booth.vehiclePayingToll(1, carToll);
                break;

            case 2:
                booth.vehiclePayingToll(2, truckToll);
                break;

            case 3:
                booth.vehiclePayingToll(3, busToll);
                break;

            case 4:
                cout << "Total Vehicles Passed: " << booth.getTotalVehicles() << endl;
                break;

            case 5:
                cout << "Total Revenue Collected: ₹" << booth.getTotalRevenue() << endl;
                break;

            case 6:
                booth.reset();
                break;

            case 7:
                cout << "Exiting Toll Booth System. Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}




