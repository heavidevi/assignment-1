#ifndef VEHICLES_H
#define VEHICLES_H

#include <iostream>
#include <string>
#include <cmath>
#include "audit.h"
using namespace std;

enum VehicleCategory { UNKNOWN, TWO_WHEELER, PASSENGER_CAR, HEAVY_DUTY };

class Vehicle { 
private:
    VehicleCategory category;
    string specificType;
    double price;
    int modelYear;
    string location;
    string manufacturer;
    const string vehicle_number;
    bool isApproved;
    Audit* auditReport;
    double estimatedValue;
    double depreciationRate;
    
public:
    Vehicle() 
        : category(VehicleCategory::UNKNOWN), 
          specificType("None"), 
          price(0.0), 
          modelYear(0), 
          location("Unknown"), 
          manufacturer("Unknown"),
          vehicle_number("N/A"),
          isApproved(false),
          auditReport(nullptr),
          estimatedValue(0.0),
          depreciationRate(0.15) {}

    Vehicle(VehicleCategory cat, string type, double p, int year, string loc, string man, string vNum)
        : category(cat), 
          specificType(type), 
          price(p), 
          modelYear(year), 
          location(loc), 
          manufacturer(man), 
          vehicle_number(vNum),
          isApproved(false),
          auditReport(nullptr),
          estimatedValue(p),
          depreciationRate(0.15) {}

    void setAudit(Audit* a) {
        if (auditReport != nullptr) {
            delete auditReport;
        }
        auditReport = a; 
    }

    double calculateMarketValue() const {
        int currentYear = 2024;
        int vehicleAge = currentYear - modelYear;
        double currentValue = price * pow(1 - depreciationRate, vehicleAge);
        return currentValue;
    }
    
    void generateValuationReport() const {
        cout << "=== VEHICLE VALUATION REPORT ===" << endl;
        cout << "Original Price: PKR " << price << endl;
        cout << "Current Market Value: PKR " << calculateMarketValue() << endl;
        cout << "Depreciation: " << (depreciationRate * 100) << "% per year" << endl;
    }

    virtual void display() const {
        cout << "\nVehicle Details [" << (isApproved ? "APPROVED" : "PENDING") << "]" << endl;
        cout << "Number: " << vehicle_number << " | " << manufacturer << " " << specificType << endl;
        cout << "Year: " << modelYear << " | Price: " << price << " PKR" << endl;
        cout << "Location: " << location << endl;
        
        if (auditReport != nullptr) {
            auditReport->printAuditSummary();
        } else {
            cout << "Audit Status: Not yet inspected." << endl;
        }
    }

    Audit* getAudit() const { return auditReport; }
    VehicleCategory getCategory() const { return category; }
    string getSpecificType() const { return specificType; }
    double getPrice() const { return price; }
    int getModelYear() const { return modelYear; }
    string getLocation() const { return location; }
    string getManufacturer() const { return manufacturer; }
    string getVehicleNumber() const { return vehicle_number; }
    bool getApprovedStatus() const { return isApproved; }
    double getEstimatedValue() const { return estimatedValue; }
    double getDepreciationRate() const { return depreciationRate; }

    void setCategory(VehicleCategory cat) { category = cat; }
    void setSpecificType(string type) { specificType = type; }
    void setApproved(bool status) { isApproved = status; }
    void setEstimatedValue(double value) { if(value >= 0) estimatedValue = value; }
    void setDepreciationRate(double rate) { if(rate >= 0 && rate <= 1) depreciationRate = rate; }
    
    void setPrice(double p) { 
        if(p >= 0) price = p; 
        else cout << "Price cannot be negative!" << endl;
    }

    void setModelYear(int year) { 
        if(year > 1886) modelYear = year; 
    }

    void setLocation(string loc) { location = loc; }
    void setManufacturer(string man) { manufacturer = man; }

    virtual ~Vehicle() {
        delete auditReport;
    } 
};

#endif