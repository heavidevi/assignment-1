#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
#include "account.h"
#include "vehicle.h"

class Admin : public Account {
public:
    Admin(string n, string p) : Account(n, p) {}

    
    void approveListing(Vehicle* v) {
        if (v != nullptr) {
            v->setApproved(true); 
            cout << "Admin " << getName() << " approved Vehicle ID: " << v->getVehicleNumber() << endl;
        }
    }

   
    void removeListing(Vehicle**& globalList, int& currentSize, string vNum) {
        int targetIndex = -1;

        for (int i = 0; i < currentSize; i++) {
            if (globalList[i]->getVehicleNumber() == vNum) {
                targetIndex = i;
                break;
            }
        }

        if (targetIndex != -1) {
            delete globalList[targetIndex];

            for (int i = targetIndex; i < currentSize - 1; i++) {
                globalList[i] = globalList[i + 1];
            }

            currentSize--;
            cout << "Admin " << getName() << " removed listing: " << vNum << endl;
        } else {
            cout << "Error: Listing not found." << endl;
        }
    }

    void showDashboard() {
        cout << "\n--- ADMIN CONTROL CENTER ---" << endl;
        cout << "Logged in as: " << getName() << " (ID: " << getAccountId() << ")" << endl;
        cout << "Commands: [Approve], [Remove], [Manage Users]" << endl;
    }
};

#endif