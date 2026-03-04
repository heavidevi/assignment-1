#ifndef TWO_WHEELER_H
#define TWO_WHEELER_H

#include "vehicle.h"
#include <iostream>
#include <string>

using namespace std;

class TwoWheeler : public Vehicle {
private:
    int engineCC;             
    string startType;    
    double fuelTankCapacity; 
    bool used;                
    string bikeCategory;

public:
    // Constructor
    TwoWheeler(VehicleCategory cat, string name, double p, int year, int cc, string start, string vNum)
        : Vehicle(cat, name, p, year, "Unknown", "Unknown", vNum), 
          engineCC(cc), startType(start), fuelTankCapacity(0.0), used(false), bikeCategory("Standard") 
    {
        cout << "TwoWheeler created successfully." << endl;
    }

    //Getters 
    int getEngineCC() const { return engineCC; }
    string getStartType() const { return startType; }
    bool getIsUsed() const { return used; }
    string getBikeCategory() const { return bikeCategory; }

    //Setters
    void setEngineCC(int cc) { engineCC = cc; }
    void setStartType(string start) { startType = start; }
    void setIsUsed(bool u) { used = u; }
    void setBikeCategory(string cat) { bikeCategory = cat; }



    // methods
    void calculateBikeTax() {
        double tax;
        if (engineCC < 100) tax = 500.0;
        else if (engineCC <= 250) tax = 1500.0;
        else tax = 5000.0; 
        
        cout << "Calculated Bike Tax for " << engineCC << "cc: " << tax << " PKR" << endl;
    }

    
    void performService() {
        cout << "Service: Oil and filter changed for " << getSpecificType() << endl;
    }

    
    void checkWheelBalance() {
        cout << "Alignment check complete for both wheels." << endl;
    }

    void checkTouringAbility() {
        if (engineCC > 200 && fuelTankCapacity > 10.0)
            cout << "This bike is recommended for long tours." << endl;
        else
            cout << "Recommended for city commute only." << endl;
    }

    ~TwoWheeler() {
        cout << "TwoWheeler record removed from memory." << endl;
    }
};

#endif