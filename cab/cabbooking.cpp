#include <iostream>
#include <string>
using namespace std;

// define a class name as Cab
class Cab
{
private :
    int cabId;
    string driverName;
    string cabType;
    double farePerKm;

public:

    // Constructor to initialize cab details
    Cab(int id, string driver, string type, double fare)
    {
        cabId = id;
        driverName = driver;
        cabType = type;
        farePerKm = fare;
    }

    // member  Function void displayCab() to display cab details
    void displayCab()
    {
        cout << "\nCab ID      : " << cabId;
        cout << "\nDriver Name : " << driverName;
        cout << "\nCab Type    : " << cabType;
        cout << "\nFare/Km     : Rs. " << farePerKm << endl;
    }

    // Function to calculate fare
    double calculateFare(double distance)
    {
        return distance * farePerKm;
    }
};

// Derived class for booking
class Booking : public Cab
{
private:
    string customerName;
    string pickup;
    string destination;
    double distance;

public:

    // Constructor of Booking class
    Booking(int id, string driver, string type, double fare,
            string customer, string pick, string dest, double dist)
        : Cab(id, driver, type, fare)
    {
        customerName = customer;
        pickup = pick;
        destination = dest;
        distance = dist;
    }

    // Function to display booking details
    void displayBooking()
    {
        double totalFare = calculateFare(distance);

        cout << "\n========== CAB BOOKING DETAILS ==========";
        cout << "\nCustomer Name : " << customerName;
        cout << "\nPickup        : " << pickup;
        cout << "\nDestination   : " << destination;
        cout << "\nDistance      : " << distance << " km";

        // Display cab information
        displayCab();

        cout << "Total Fare    : Rs. " << totalFare;
        cout << "\n==========================================\n";
    }
};

int main()
{
    // Variables for customer details
    string customerName;
    string pickup;
    string destination;
    double distance;

   cout << "========== CAB BOOKING SYSTEM ==========";

    // Taking customer Details input
    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter pickup location: ";
    getline(cin, pickup);

    cout << "Enter destination: ";
    getline(cin, destination);

    cout << "Enter distance in km: ";
    cin >> distance;

    // Creating a booking object
    // Cab ID = 101
    // Driver = Rahul
    // Cab Type = Sedan
    // Fare per km = Rs. 15
    Booking booking(
        101,
        "Rahul",
        "Sedan",
        15,
        customerName,
        pickup,
        destination,
        distance
    );

    // Display all booking details
    booking.displayBooking();

    return 0;
}