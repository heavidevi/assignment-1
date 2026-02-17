#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <iostream>
#include <string>
using namespace std;

class MemberType {
    private:
        string name;
        string memberID;
        int booksPurchased;
        double totalAmountSpent;
        double last10BooksTotal;
        int last10Counter;
        bool membershipPaid;
        
    public:
        MemberType();
        MemberType(string n, string id);
        
        void setName(string n);
        string getName() const;
        void setMemberID(string id);
        string getMemberID() const;
        
        int getBooksPurchased() const;
        double getTotalAmountSpent() const;
        bool isMembershipPaid() const;
        
        void payMembership();
        double purchaseBook(double bookPrice);
        void displayMemberInfo() const;
        bool isSameMember(string id) const;
};

#endif
