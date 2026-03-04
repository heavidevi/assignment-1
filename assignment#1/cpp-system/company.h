#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
using namespace std;
#include "user.h"
#include "seller.h"

class Company : public User {
private:
    const string companyLicense;     
    string location;                
    bool isAuthorized;             
    Seller** registeredSellers;     
    int sellerCount;              
    static int totalDealerships;   

public:
    // Default constructor
    Company() : User(), companyLicense("DEL001"), location("Lahore"), 
                isAuthorized(true), sellerCount(0) {
        registeredSellers = new Seller*[50];
        for(int i = 0; i < 50; i++) {
            registeredSellers[i] = nullptr;
        }
        totalDealerships++;
    }

    // Parameterized constructor
    Company(string username, string pass, string phonenumber,string license, string loc) 
        : User(username, pass,phonenumber),
          companyLicense(license), location(loc), isAuthorized(true), sellerCount(0) {
        registeredSellers = new Seller*[50];
        for(int i = 0; i < 50; i++) {
            registeredSellers[i] = nullptr;
        }
        totalDealerships++;
    }

    // Copy constructor
    Company(const Company& other) 
        : User(other), companyLicense(other.companyLicense), 
          location(other.location), isAuthorized(false), sellerCount(0) {
        registeredSellers = new Seller*[50];
        for(int i = 0; i < 50; i++) {
            registeredSellers[i] = nullptr;
        }
        totalDealerships++;
    }

    void showDashboard() const override {      
        cout << "Company: " << getName() << endl;
        cout << "License: " << companyLicense << endl;
        cout << "Location: " << location << endl;
        cout << "Registered Sellers: " << sellerCount << endl;
        cout << "Status: " << (isAuthorized ? "Authorized" : "Pending") << endl;
    }

    void registerSeller(Seller* seller) {
        if(sellerCount < 50 && seller != nullptr && isAuthorized) {
            registeredSellers[sellerCount] = seller;
            sellerCount++;
            cout << "Seller registered with company" << endl;
        }
    }

    void displaySellers() const {
        cout << "Company Sellers:" << endl;
        for(int i = 0; i < sellerCount; i++) {
            if(registeredSellers[i]) {
                cout << "Seller: " << registeredSellers[i]->getSellerName() << endl;
            }
        }
    }

    void authorizeCompany() {
        isAuthorized = true;
        cout << "Company authorized" << endl;
    }

    int getTotalListings() const {
        int total = 0;
        for(int i = 0; i < sellerCount; i++) {
            if(registeredSellers[i]) {
                total += registeredSellers[i]->getAdsCount();
            }
        }
        return total;
    }

    // Getters
    string getCompanyLicense() const { return companyLicense; }
    string getLocation() const { return location; }
    bool getAuthorizationStatus() const { return isAuthorized; }
    int getSellerCount() const { return sellerCount; }
    static int getTotalDealerships() { return totalDealerships; }

    // Setters
    void setLocation(string loc) { location = loc; }
    void setAuthorization(bool auth) { isAuthorized = auth; }

    ~Company() {
        delete[] registeredSellers; 
        totalDealerships--;
    }
};

int Company::totalDealerships = 0;

#endif
