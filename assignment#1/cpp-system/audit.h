#ifndef AUDIT_H
#define AUDIT_H

#include <iostream>
#include <string>
using namespace std;

class Audit {
private:
    const int auditID;          
    int engineHealth;         
    int bodyCondition;          
    string tireStatus;          
    double estimatedRepairCost;
    bool isVerified;

public:
    
    Audit(int id, int eng, int body, string tires, double repair)
        : auditID(id), engineHealth(eng), bodyCondition(body), 
          tireStatus(tires), estimatedRepairCost(repair), isVerified(false) {}

   
    bool passSafetyStandards() const { 
        return (engineHealth > 50 && bodyCondition > 40); 
    }

    double calculateValueDeduction() const {
        return (100 - engineHealth) * 500.0; 
    }

    void printAuditSummary() const {
        cout << "Audit #" << auditID << " | Engine: " << engineHealth << "% | Body: " << bodyCondition << "%" << endl;
        cout << "Repair Estimate: " << estimatedRepairCost << " PKR" << endl;
    }

 
    void verifyAudit() {
        if(passSafetyStandards()) isVerified = true;
    }

    int getAuditID() const { return auditID; }
};

#endif