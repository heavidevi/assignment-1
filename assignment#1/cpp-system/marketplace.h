#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include<iostream>
#include<string>
using namespace std;
#include "vehicle.h"
#include "account.h"

class Marketplace {
private:
    Account** allAccounts;           
    Vehicle** allVehicles;          
    int accountCapacity;            
    int vehicleCapacity;            
    int accountCount;               
    int vehicleCount;               
    const int initialSize;          
    static int totalMarketplaces;    

    
    void resizeAccountArray() {
        int newCapacity = accountCapacity * 2; 
        Account** newArray = new Account*[newCapacity];
        
      
        for(int i = 0; i < accountCount; i++) {
            newArray[i] = allAccounts[i];
        }
        
       
        for(int i = accountCount; i < newCapacity; i++) {
            newArray[i] = nullptr;
        }
        
        delete[] allAccounts;
        allAccounts = newArray;
        accountCapacity = newCapacity;
        
        cout << "Account array resized to capacity: " << newCapacity << endl;
    }

    void resizeVehicleArray() {
        int newCapacity = vehicleCapacity * 2;
        Vehicle** newArray = new Vehicle*[newCapacity];
        
        for(int i = 0; i < vehicleCount; i++) {
            newArray[i] = allVehicles[i];
        }
        
        for(int i = vehicleCount; i < newCapacity; i++) {
            newArray[i] = nullptr;
        }
        
        delete[] allVehicles;
        allVehicles = newArray;
        vehicleCapacity = newCapacity;
        
        cout << "Vehicle array resized to capacity: " << newCapacity << endl;
    }

public:
   
    Marketplace() : initialSize(10), accountCapacity(10), vehicleCapacity(10), 
                   accountCount(0), vehicleCount(0) {
        allAccounts = new Account*[accountCapacity];
        allVehicles = new Vehicle*[vehicleCapacity];
        
        for(int i = 0; i < accountCapacity; i++) allAccounts[i] = nullptr;
        for(int i = 0; i < vehicleCapacity; i++) allVehicles[i] = nullptr;
        
        totalMarketplaces++;
        
    }

    
    Marketplace(int initialCap) : initialSize(initialCap), accountCapacity(initialCap), 
                                 vehicleCapacity(initialCap), accountCount(0), vehicleCount(0) {
        allAccounts = new Account*[accountCapacity];
        allVehicles = new Vehicle*[vehicleCapacity];
        
        for(int i = 0; i < accountCapacity; i++) allAccounts[i] = nullptr;
        for(int i = 0; i < vehicleCapacity; i++) allVehicles[i] = nullptr;
        
        totalMarketplaces++;
        cout << "Marketplace created with initial capacity: " << initialCap << endl;
    }

    
    Marketplace(const Marketplace& other) 
        : initialSize(other.initialSize), accountCapacity(other.accountCapacity),
          vehicleCapacity(other.vehicleCapacity), accountCount(0), vehicleCount(0) {
        allAccounts = new Account*[accountCapacity];
        allVehicles = new Vehicle*[vehicleCapacity];
        
        for(int i = 0; i < accountCapacity; i++) allAccounts[i] = nullptr;
        for(int i = 0; i < vehicleCapacity; i++) allVehicles[i] = nullptr;
        
        totalMarketplaces++;
    }

    // Add Account
    void addAccount(Account* newAcc) {
        if(newAcc == nullptr) {
            cout << "Cannot add null account" << endl;
            return;
        }
        
       
        if(accountCount >= accountCapacity) {
            resizeAccountArray();
        }
        
        allAccounts[accountCount] = newAcc;
        accountCount++;
        
        cout << "Account added: " << newAcc->getName() 
             << " (Total accounts: " << accountCount << ")" << endl;
    }

    
    void addVehicle(Vehicle* newVehicle) {
        if(newVehicle == nullptr) {
            cout << "Cannot add null vehicle" << endl;
            return;
        }
        
     
        if(vehicleCount >= vehicleCapacity) {
            resizeVehicleArray();
        }
        
        allVehicles[vehicleCount] = newVehicle;
        vehicleCount++;
        
        cout << "Vehicle added: " << newVehicle->getManufacturer() << " " << newVehicle->getModelYear()
             << " (Total vehicles: " << vehicleCount << ")" << endl;
    }

  
    void removeAccount(int accountId) {
        for(int i = 0; i < accountCount; i++) {
            if(allAccounts[i] && allAccounts[i]->getAccountId() == accountId) {
                delete allAccounts[i];
                
                
                for(int j = i; j < accountCount - 1; j++) {
                    allAccounts[j] = allAccounts[j + 1];
                }
                
                allAccounts[accountCount - 1] = nullptr;
                accountCount--;
                cout << "Account removed successfully" << endl;
                return;
            }
        }
        cout << "Account not found" << endl;
    }

  
    void displayStatistics() const {
        cout << "\n=== Marketplace Statistics ===" << endl;
        cout << "Total Accounts: " << accountCount << " / " << accountCapacity << endl;
        cout << "Total Vehicles: " << vehicleCount << " / " << vehicleCapacity << endl;
        cout << "Account Array Usage: " << (accountCount * 100.0 / accountCapacity) << "%" << endl;
        cout << "Vehicle Array Usage: " << (vehicleCount * 100.0 / vehicleCapacity) << "%" << endl;
    }

    // Advanced search functions
    Vehicle** searchByLocation(string city, int& resultCount);
    Vehicle** searchByFinancing(double maxMonthlyPayment, int& resultCount);
    Vehicle** searchCombined(string city, double maxPrice, bool needsFinancing, int& resultCount);

    
    Vehicle** advancedSearch(string city, double maxPrice, 
                           bool needsFinancing, int& resultCount) {
        Vehicle** results = new Vehicle*[vehicleCount];
        resultCount = 0;
        
        for(int i = 0; i < vehicleCount; i++) {
            if(allVehicles[i] && 
               allVehicles[i]->getLocation() == city &&  
               allVehicles[i]->getPrice() <= maxPrice) {
                results[resultCount] = allVehicles[i];
                resultCount++;
            }
        }
        return results;
    }
    
   
    void getCarValuation(string manufacturer, string type, int year) {
        for(int i = 0; i < vehicleCount; i++) {
            if(allVehicles[i] && 
               allVehicles[i]->getManufacturer() == manufacturer &&  
               allVehicles[i]->getSpecificType() == type &&          
               allVehicles[i]->getModelYear() == year) {            
                allVehicles[i]->generateValuationReport();
                return;
            }
        }
        cout << "Vehicle not found in database" << endl;
    }

    // Getters
    int getAccountCount() const { return accountCount; }
    int getVehicleCount() const { return vehicleCount; }
    int getAccountCapacity() const { return accountCapacity; }
    int getVehicleCapacity() const { return vehicleCapacity; }
    static int getTotalMarketplaces() { return totalMarketplaces; }

    // Setters
    void setAccountCapacity(int newCap) {
        if(newCap > accountCount) {
            accountCapacity = newCap;
        }
    }

    ~Marketplace() {
       
        for(int i = 0; i < accountCount; i++) {
            delete allAccounts[i];
        }
        delete[] allAccounts;
        
       
        for(int i = 0; i < vehicleCount; i++) {
            delete allVehicles[i];
        }
        delete[] allVehicles;
        
        totalMarketplaces--;
        cout << "Marketplace destroyed, all memory cleaned" << endl;
    }
};

int Marketplace::totalMarketplaces = 0;

#endif