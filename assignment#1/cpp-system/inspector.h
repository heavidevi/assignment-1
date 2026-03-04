#ifndef INSPECTOR_H
#define INSPECTOR_H
#include<iostream>
using namespace std;
#include "account.h"
#include "audit.h"
#include "vehicle.h"


class Inspector : public Account {
private:
    string rank;                
    int totalAuditsPerformed;
    double monthlyBonus;
    static int globalAuditCount; 
    const int licenseNumber;     
public:
    Inspector(string n, string p, int lNum) : Account(n, p), licenseNumber(lNum), rank("Junior"), 
          totalAuditsPerformed(0), monthlyBonus(0.0) {}

   
    void createAuditRecord(Vehicle* v, int eng, int body, string tires, double repair) {
        if (v == nullptr) return;
        
       
        Audit* newAudit = new Audit(++globalAuditCount, eng, body, tires, repair);
        v->setAudit(newAudit); 

        totalAuditsPerformed++;
        cout << "Inspector " << name << " submitted Audit #" << globalAuditCount << endl;
    }

    void updateBonus() {
        monthlyBonus = totalAuditsPerformed * 1000.0;
    }

    static int getSystemTotalAudits() {
        return globalAuditCount;
    }


    void showDashboard() const {
        cout << "INSPECTOR: " << name << " | License: " << licenseNumber << endl;
        cout << "Rank: " << rank << " | Total Audits: " << totalAuditsPerformed << endl;
    }
};


int Inspector::globalAuditCount = 0;

#endif