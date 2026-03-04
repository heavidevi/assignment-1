#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include "user.h"
#include "vehicle.h"

class Transaction {
private:
    
    User* buyerRef;         
    User* sellerRef;     
    Vehicle* vehicleRef;    
    const int transactionId; 
    double finalPrice;
    string date;
    static int totalTransactions;

public:
    Transaction(User* b, User* s, Vehicle* v, string d) 
        : buyerRef(b), sellerRef(s), vehicleRef(v), 
          date(d), transactionId(++totalTransactions) {
        
        if (v != nullptr) {
            finalPrice = v->getPrice(); 
        } else {
            finalPrice = 0.0;
        }
    }

   
    void executeTrade() {
        if (buyerRef != nullptr && sellerRef != nullptr && vehicleRef != nullptr) {
            cout << "\n[SYSTEM] Processing Transaction #" << transactionId << endl;
            cout << "Transferring " << vehicleRef->getSpecificType() 
                 << " from " << sellerRef->getName() 
                 << " to " << buyerRef->getName() << endl;
        }
    }

    void printInvoice() const {
        cout << "\n---------- INVOICE ----------" << endl;
        cout << "Transaction ID: " << transactionId << endl;
        cout << "Date: " << date << endl;
        cout << "Amount Paid: " << finalPrice << " PKR" << endl;
        cout << "-----------------------------" << endl;
    }

    static int getGlobalCount() {
        return totalTransactions;
    }

    bool validateTransaction() {
        return (buyerRef != nullptr && sellerRef != nullptr && 
                vehicleRef != nullptr && vehicleRef->getApprovedStatus());
    }

    // Getters
    int getTid() const { return transactionId; }
};

int Transaction::totalTransactions = 10000;

#endif