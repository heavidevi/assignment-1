#ifndef USER_H
#define USER_H

#include "account.h"
#include "buyer.h"
#include "seller.h"
#include "message.h"
#include "autoparts.h"

class User : public Account {
private:
   
    Buyer* buyerProfile;   
    Seller* sellerProfile; 
    string phoneNumber;
    string preferredCity;      
    double budgetLimit;        
    
    static int activeUsers;

public:
    User():Account(),buyerProfile(),sellerProfile(),phoneNumber(""){}

    //parameterized constructor

    User(string n, string p, string phone) 
        : Account(n, p), phoneNumber(phone){
    
        buyerProfile = new Buyer(this->getAccountId(), n, p);
        sellerProfile = new Seller(this->getAccountId());
        activeUsers++;
    }

    void showDashboard() const override {
        cout << "\n--- USER PROFILE: " << name << " ---" << endl;
        cout << "Phone: " << phoneNumber << " | Status: " <<endl;
    }

    
    void sendMessage(User* recipient, string text) {
        if (recipient != nullptr) {
            Message* msg = new Message(this->name, recipient->getName(), text);
            cout << "Message sent from " << name << " to " << recipient->getName() << endl;
           
        }
    }

    // Additional function to buy auto parts
    void buyAutoPart(AutoParts* part, int quantity, Finance* finance) {
        if(part != nullptr && finance != nullptr) {
            cout << getName() << " is purchasing auto parts..." << endl;
            finance->processAutoPartsSale(part, quantity);
            cout << "Purchase completed by " << getName() << endl;
        }
    }

    // Function to pay for featured ad
    void payForFeaturedAd(Finance* finance, double amount) {
        if(finance != nullptr && amount > 0) {
            finance->addFeaturedAdRevenue(amount);
            cout << getName() << " paid PKR " << amount << " for featured ad" << endl;
        }
    }
  
    static int getActiveUserCount() {
        return activeUsers;
    }

   
    Buyer* getBuyer() { return buyerProfile; }
    Seller* getSeller() { return sellerProfile; }

    // Function: Search with user preferences
    void searchWithPreferences(Marketplace* market) {
        int resultCount;
        Vehicle** results = market->advancedSearch(
            preferredCity, budgetLimit, true, resultCount
        );
        
        cout << "Found " << resultCount << " vehicles matching your criteria:" << endl;
        for(int i = 0; i < resultCount; i++) {
            results[i]->display();
            results[i]->generateValuationReport();
        }
        delete[] results;
    }
   
    ~User() {
        delete buyerProfile;
        delete sellerProfile;
        activeUsers--;
    }
};


int User::activeUsers = 0;

#endif