#ifndef PASSENGER_CAR_H
#define PASSENGER_CAR_H

#include "vehicle.h"
#include <iostream>
#include <string>

using namespace std;

class PassengerCar : public Vehicle {
private:
    int seatingCapacity;    
    string transmission;    
    string fuelType;        
    bool hasSunroof;       
    int numberOfDoors;      

public:
    
    PassengerCar(VehicleCategory cat, string name, double p, int year, int seats, string trans, string fuel, string vNum)
        : Vehicle(cat, name, p, year, "Unknown", "Unknown", vNum), 
          seatingCapacity(seats), 
          transmission(trans), 
          fuelType(fuel), 
          hasSunroof(false), 
          numberOfDoors(4) 
    {
        cout << "Passenger Car created successfully." << endl;
    }

    //Getters
    int getSeatingCapacity() const { return seatingCapacity; }
    string getTransmission() const { return transmission; }
    string getFuelType() const { return fuelType; }
    bool getHasSunroof() const { return hasSunroof; }
    int getNumberOfDoors() const { return numberOfDoors; }

    //Setters
    void setSeatingCapacity(int s) { seatingCapacity = s; }
    void setTransmission(string t) { transmission = t; }
    void setFuelType(string f) { fuelType = f; }
    void setHasSunroof(bool s) { hasSunroof = s; }
    void setNumberOfDoors(int d) { numberOfDoors = d; }


    void calculateRegistrationFee() {
        double currentPrice = getPrice(); 
        double fee = (currentPrice > 2000000) ? currentPrice * 0.02 : currentPrice * 0.01;
        cout << "Registration Fee: " << fee << " PKR" << endl;
    }

    void checkAcEfficiency() {
        cout << "AC Check: Cooling optimized for " << seatingCapacity << " passengers." << endl;
    }

    void safetyInspection() {
        cout << "Safety Check: ABS and Airbags verified for " << getSpecificType() << endl;
    }

    void toggleSunroof() {
        hasSunroof = !hasSunroof;
        cout << "Sunroof status changed to: " << (hasSunroof ? "Open" : "Closed") << endl;
    }

    
    ~PassengerCar() {
        cout << "Passenger Car record removed from system." << endl;
    }
};

#endif