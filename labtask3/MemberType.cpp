#include "MemberType.h"

MemberType::MemberType() {
    name = "";
    memberID = "";
    booksPurchased = 0;
    totalAmountSpent = 0.0;
    last10BooksTotal = 0.0;
    last10Counter = 0;
    membershipPaid = false;
}

MemberType::MemberType(string n, string id) {
    name = n;
    memberID = id;
    booksPurchased = 0;
    totalAmountSpent = 0.0;
    last10BooksTotal = 0.0;
    last10Counter = 0;
    membershipPaid = false;
}

void MemberType::setName(string n) { name = n; }
string MemberType::getName() const { return name; }
void MemberType::setMemberID(string id) { memberID = id; }
string MemberType::getMemberID() const { return memberID; }
int MemberType::getBooksPurchased() const { return booksPurchased; }
double MemberType::getTotalAmountSpent() const { return totalAmountSpent; }
bool MemberType::isMembershipPaid() const { return membershipPaid; }
bool MemberType::isSameMember(string id) const { return memberID == id; }

void MemberType::payMembership() {
    membershipPaid = true;
    cout << "membership fee of $10 paid for " << name << endl;
}

double MemberType::purchaseBook(double bookPrice) {
    if (!membershipPaid) {
        cout << "please pay membership fee first" << endl;
        return 0.0;
    }
    
    double discountedPrice = bookPrice * 0.95;
    booksPurchased++;
    totalAmountSpent += discountedPrice;
    last10BooksTotal += discountedPrice;
    last10Counter++;
    
    if (booksPurchased % 11 == 0 && last10Counter >= 10) {
        double averageDiscount = last10BooksTotal / 10.0;
        double finalPrice = discountedPrice - averageDiscount;
        if (finalPrice < 0) finalPrice = 0;
        
        cout << "special discount applied! average of last 10 books: $" << averageDiscount << endl;
        cout << "final price after special discount: $" << finalPrice << endl;
        
        totalAmountSpent = finalPrice;
        last10BooksTotal = 0.0;
        last10Counter = 0;
        
        return finalPrice;
    }
    
    return discountedPrice;
}

void MemberType::displayMemberInfo() const {
    cout << "Name: " << name << endl;
    cout << "ID: " << memberID << endl;
    cout << "Books purchased: " << booksPurchased << endl;
    cout << "Total spent: $" << totalAmountSpent << endl;
    cout << "Membership paid: " << (membershipPaid ? "yes" : "no") << endl;
    cout << endl;
}
