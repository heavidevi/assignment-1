#ifndef BUYER_H
#define BUYER_H

#include "vehicle.h"
#include "account.h" 
#include <iostream>

class Buyer : public Account {
private:
    int buyerid;
    int maxCapacity;   
    int currentSize;   
    Vehicle** favourite; 

public:
    
    Buyer(int id, string n, string p) : Account(n, p), buyerid(id), maxCapacity(10), currentSize(0) {
        favourite = new Vehicle*[maxCapacity];
        for (int i = 0; i < maxCapacity; i++) favourite[i] = nullptr;
    }


    void showDashboard() const override {
        cout << "--- BUYER DASHBOARD ---" << endl;
        cout << "Buyer ID: " << buyerid << " | Saved Ads: " << currentSize << endl;
    }


    void addToFavorite(Vehicle* v) {
        if (currentSize < maxCapacity) {
            favourite[currentSize++] = v; 
            cout << "Added to favorites: " << v->getSpecificType() << endl;
        }
    }

    void removeFavorite(string vNum) {
        for(int i = 0; i < currentSize; i++) {
            if(favourite[i]->getVehicleNumber() == vNum) {
                for(int j = i; j < currentSize - 1; j++) {
                    favourite[j] = favourite[j+1];
                }
                currentSize--;
                return;
            }
        }
    }

    void showfavourite() const {
        cout << "\n--- Favorites List ---" << endl;
        for (int i = 0; i < currentSize; i++) {
            cout << "- " << favourite[i]->getManufacturer() << " " << favourite[i]->getSpecificType() << endl;
        }
    }

   
    bool isFavorited(string vNum) {
        for(int i = 0; i < currentSize; i++) {
            if(favourite[i]->getVehicleNumber() == vNum) return true;
        }
        return false;
    }

    ~Buyer() {
        delete[] favourite; 
    }
};

#endif