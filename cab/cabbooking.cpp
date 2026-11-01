#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Base class
class Cab
{
private:
    int cabId;
    string driverName;
    string cabType;
    double farePerKm;

public:
    // Constructor
    Cab(int id, string driver, string type, double fare)
    {
        cabId = id;
        driverName = driver;
        cabType = type;
        farePerKm = fare;
    }

    // Display cab details
    void displayCab()
    {
        cout << "\n----------- CAB DETAILS -----------\n";
        cout << left << setw(18) << "Cab ID" << ": " << cabId << endl;
        cout << left << setw(18) << "Driver Name" << ": " << driverName << endl;
        cout << left << setw(18) << "Cab Type" << ": " << cabType << endl;
        cout << left << setw(18) << "Fare per Km" << ": Rs. "
             << fixed << setprecision(2) << farePerKm << endl;
    }

    // Calculate fare
    double calculateFare(double distance)
    {
        return distance * farePerKm;
    }
};

// Derived class
class Booking : public Cab
{
private:
    string customerName;
    string pickup;
    string destination;
    double distance;

public:
    // Constructor
    Booking(int id, string driver, string type, double fare,
            string customer, string pick, string dest, double dist)
        : Cab(id, driver, type, fare)
    {
        customerName = customer;
        pickup = pick;
        destination = dest;
        distance = dist;
    }

    // Display booking receipt
    void displayBooking()
    {
        double totalFare = calculateFare(distance);

        cout << "\n============================================\n";
        cout << "           CAB BOOKING RECEIPT              \n";
        cout << "============================================\n";

        cout << left << setw(18) << "Customer Name" << ": "
             << customerName << endl;
        cout << left << setw(18) << "Pickup Location" << ": "
             << pickup << endl;
        cout << left << setw(18) << "Destination" << ": "
             << destination << endl;
        cout << left << setw(18) << "Distance" << ": "
             << distance << " km" << endl;

        displayCab();

        cout << "\n----------- FARE SUMMARY -----------\n";
        cout << left << setw(18) << "Distance" << ": "
             << distance << " km" << endl;
        cout << left << setw(18) << "Rate per Km" << ": Rs. "
             << fixed << setprecision(2) << 15.00 << endl;

        cout << "-----------------------------------\n";
        cout << left << setw(18) << "TOTAL FARE" << ": Rs. "
             << fixed << setprecision(2) << totalFare << endl;
        cout << "============================================\n";
        cout << "       Thank you for booking with us!       \n";
        cout << "============================================\n";
    }
};

int main()
{
    string customerName, pickup, destination;
    double distance;

    cout << "\n";
    cout << "============================================\n";
    cout << "             CAB BOOKING SYSTEM             \n";
    cout << "============================================\n";

    cout << "\nEnter Customer Name   : ";
    getline(cin, customerName);

    cout << "Enter Pickup Location : ";
    getline(cin, pickup);

    cout << "Enter Destination     : ";
    getline(cin, destination);

    cout << "Enter Distance (km)   : ";
    cin >> distance;

    // Create booking object with predefined cab details
    Booking booking(
        101,             // Cab ID
        "Rahul",         // Driver Name
        "Sedan",         // Cab Type
        15.00,           // Fare per Km
        customerName,
        pickup,
        destination,
        distance
    );

    booking.displayBooking();

    return 0;
}