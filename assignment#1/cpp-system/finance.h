#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include <string>
#include "autoparts.h"
using namespace std;

class Finance {
private:
    const int transactionId;         
    double featuredAdRevenue;        
    double inspectionRevenue;        
    double sifmRevenue;             
    double dealerPackageRevenue;    
    double autoPartsRevenue;        
    double totalPakWheelsRevenue;   
    AutoParts** soldParts;          
    int soldPartsCount;
    const int maxTransactions;      
    static int totalTransactions;  
    static const double commissionRate; 
    bool financingAvailable;         
    double monthlyPayment;           
    int loanTenure;                 
public:
    // Default constructor
    Finance() : transactionId(++totalTransactions), featuredAdRevenue(0.0),
                inspectionRevenue(0.0), sifmRevenue(0.0), dealerPackageRevenue(0.0),
                autoPartsRevenue(0.0), totalPakWheelsRevenue(0.0),
                maxTransactions(1000), soldPartsCount(0), financingAvailable(false),
                monthlyPayment(0.0), loanTenure(0) {
        soldParts = new AutoParts*[maxTransactions];
        for(int i = 0; i < maxTransactions; i++) {
            soldParts[i] = nullptr;
        }
    }

    // Parameterized constructor
    Finance(double adRev, double inspRev, double sifmRev, double dealerRev) 
        : transactionId(++totalTransactions), featuredAdRevenue(adRev),
          inspectionRevenue(inspRev), sifmRevenue(sifmRev), 
          dealerPackageRevenue(dealerRev), autoPartsRevenue(0.0),
          maxTransactions(1000), soldPartsCount(0), financingAvailable(false),
          monthlyPayment(0.0), loanTenure(0) {
        totalPakWheelsRevenue = adRev + inspRev + sifmRev + dealerRev;
        soldParts = new AutoParts*[maxTransactions];
        for(int i = 0; i < maxTransactions; i++) {
            soldParts[i] = nullptr;
        }
    }

    // Copy constructor
    Finance(const Finance& other) 
        : transactionId(++totalTransactions), featuredAdRevenue(0.0),
          inspectionRevenue(0.0), sifmRevenue(0.0), dealerPackageRevenue(0.0),
          autoPartsRevenue(0.0), totalPakWheelsRevenue(0.0),
          maxTransactions(1000), soldPartsCount(0), financingAvailable(false),
          monthlyPayment(0.0), loanTenure(0) {
        soldParts = new AutoParts*[maxTransactions];
        for(int i = 0; i < maxTransactions; i++) {
            soldParts[i] = nullptr;
        }
    }

    
    void processAutoPartsSale(AutoParts* part, int quantity) {
        if(part == nullptr || quantity <= 0) return;
        
        double saleAmount = part->calculateTotalPrice(quantity);
        if(part->sellPart(quantity)) {
            autoPartsRevenue += saleAmount;
            totalPakWheelsRevenue += saleAmount;
            
            
            if(soldPartsCount < maxTransactions) {
                soldParts[soldPartsCount] = part;
                soldPartsCount++;
            }
            
            cout << "AutoParts sale processed: PKR " << saleAmount << endl;
            cout << "Updated AutoParts Revenue: PKR " << autoPartsRevenue << endl;
        }
    }

   
    void addFeaturedAdRevenue(double amount) {
        if(amount > 0) {
            featuredAdRevenue += amount;
            totalPakWheelsRevenue += amount;
            cout << "Featured Ad Revenue: PKR " << amount << " added" << endl;
            cout << "Total Featured Ads Revenue: PKR " << featuredAdRevenue << endl;
        }
    }

   
    void addInspectionRevenue(double amount) {
        if(amount > 0) {
            inspectionRevenue += amount;
            totalPakWheelsRevenue += amount;
            cout << "Inspection Service Revenue: PKR " << amount << " added" << endl;
            cout << "Total Inspection Revenue: PKR " << inspectionRevenue << endl;
        }
    }

    void generateRevenueReport() const {
        cout << "\n=== PAKWHEELS REVENUE REPORT ===" << endl;
        cout << "Transaction ID: " << transactionId << endl;
        cout << "Featured Ads Revenue: PKR " << featuredAdRevenue << endl;
        cout << "Inspection Services: PKR " << inspectionRevenue << endl;
        cout << "Sell It For Me (SIFM): PKR " << sifmRevenue << endl;
        cout << "Dealer Packages: PKR " << dealerPackageRevenue << endl;
        cout << "AutoParts Sales: PKR " << autoPartsRevenue << endl;
        cout << "================================" << endl;
        cout << "TOTAL PAKWHEELS REVENUE: PKR " << totalPakWheelsRevenue << endl;
        cout << "Auto Parts Sold: " << soldPartsCount << " transactions" << endl;
    }

    
    void addSIFMRevenue(double amount) {
        if(amount > 0) {
            sifmRevenue += amount;
            totalPakWheelsRevenue += amount;
            cout << "SIFM Service Revenue: PKR " << amount << " added" << endl;
        }
    }

    void addDealerPackageRevenue(double amount) {
        if(amount > 0) {
            dealerPackageRevenue += amount;
            totalPakWheelsRevenue += amount;
            cout << "Dealer Package Revenue: PKR " << amount << " added" << endl;
        }
    }

    // Getters
    int getTransactionId() const { return transactionId; }
    double getFeaturedAdRevenue() const { return featuredAdRevenue; }
    double getInspectionRevenue() const { return inspectionRevenue; }
    double getAutoPartsRevenue() const { return autoPartsRevenue; }
    double getTotalRevenue() const { return totalPakWheelsRevenue; }
    int getSoldPartsCount() const { return soldPartsCount; }
    static int getTotalTransactions() { return totalTransactions; }

    // Setters
    void setFeaturedAdRevenue(double amount) { if(amount >= 0) featuredAdRevenue = amount; }
    void setInspectionRevenue(double amount) { if(amount >= 0) inspectionRevenue = amount; }

    ~Finance() {
        delete[] soldParts;
        cout << "Finance transaction " << transactionId << " completed" << endl;
    }
};

int Finance::totalTransactions = 0;
const double Finance::commissionRate = 0.05; 

#endif