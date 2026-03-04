#ifndef SELLER_H
#define SELLER_H
#include "vehicle.h"
#include "account.h"

#include<iostream>
using namespace std;

class Seller {
private:
    const int sellerId;             
    Vehicle** listedCars;            // Data member 2 - dynamic array
    int adsCount;                    // Data member 3
    string sellerName;               // Data member 4
    bool isVerified;                 // Data member 5
    static int totalSellers;         // Data member 6 - static ✓

public:
    // Default constructor
    Seller() : sellerId(++totalSellers), adsCount(0), listedCars(nullptr),
               sellerName(" "), isVerified(false) {}

    // Parameterized constructor
    Seller(int id) 
        : sellerId(++totalSellers), adsCount(0), listedCars(nullptr),
          sellerName(), isVerified(true) {}

    // Copy constructor
    Seller(const Seller& other) 
        : sellerId(++totalSellers), adsCount(0), listedCars(nullptr),
          sellerName(other.sellerName + "_COPY"), isVerified(false) {}

    
    void postAd(Vehicle* v) {
        if(v == nullptr) return;
        Vehicle** temp = new Vehicle*[adsCount + 1];
        for (int i = 0; i < adsCount; i++) {
            temp[i] = listedCars[i];
        }
        temp[adsCount] = v;
        delete[] listedCars;
        listedCars = temp;
        adsCount++;
        cout << "Seller " << sellerId << " listed: " << v->getManufacturer() << " " << v->getModelYear() << endl;
    }
    //constant function
    void allAds() const {
        cout << "Ads by " << sellerName << " (ID: " << sellerId << ")" << endl;
        if (adsCount == 0) {
            cout << "No active listings" << endl;
            return;
        }
        for (int i = 0; i < adsCount; i++) {
            cout << i + 1 << ". " << listedCars[i]->getManufacturer() << " " << listedCars[i]->getModelYear() << endl;
        }
    }

    
    void removeAd(int index) {
        if(index < 0 || index >= adsCount) return;
        delete listedCars[index];
        for(int i = index; i < adsCount - 1; i++) {
            listedCars[i] = listedCars[i + 1];
        }
        adsCount--;
        cout << "Ad removed successfully" << endl;
    }

   
    void verifySeller() {
        isVerified = true;
        cout << "Seller " << sellerName << " verified" << endl;
    }

    int getSellerId() const { return sellerId; }
    int getAdsCount() const { return adsCount; }
    string getSellerName() const { return sellerName; }
    bool getVerificationStatus() const { return isVerified; }
    static int getTotalSellers() { return totalSellers; }

  
    void setSellerName(string name) { sellerName = name; }
    void setVerified(bool verified) { isVerified = verified; }

    ~Seller() {
        for(int i = 0; i < adsCount; i++) {
            delete listedCars[i];
        }
        delete[] listedCars;
    }
};

int Seller::totalSellers = 0;

#endif