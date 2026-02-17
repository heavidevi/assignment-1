#include <iostream>
using namespace std;

class MemberType{
    private:
        string name;
        string memberID;
        int booksbought;
        float Amountspent;
    public:
        MemberType();
        MemberType(string n, string id);
        void setName(string n);
        string getName() const;
        void setMemberID(string id);
        string getMemberID() const;
        void setBooksBought(int num);
        int getBooksBought() const;
        void setAmountSpent(float amount);
        float getAmountSpent() const;
};


MemberType::MemberType() {
    name = "";
    memberID = "";
    booksbought = 0;
    Amountspent = 0.0f;
}

MemberType::MemberType(string n, string id) {
    name = n;
    memberID = id;
    booksbought = 0;
    Amountspent = 0.0f;
}   

void MemberType::setName(string n) {
    name = n;
}

string MemberType::getName() const {
    return name;
}

void MemberType::setMemberID(string id) {
    memberID = id;
}

string MemberType::getMemberID() const {
    return memberID;
}

void MemberType::setBooksBought(int num) {
    if (num >= 0) {
        booksbought = num;
    } else {
        cout << "books bought cannot be negative" << endl;
    }
}

int MemberType::getBooksBought() const {
    return booksbought;
}

void MemberType::setAmountSpent(float amount) {
    if (amount >= 0) {
        Amountspent = amount;
    } else {
        cout << "amount spent cannot be negative" << endl;
    }
}

float MemberType::getAmountSpent() const {
    return Amountspent;
}

int main() {
    MemberType member1("Alice", "M001");
    member1.setBooksBought(5);
    member1.setAmountSpent(150.75f);
    
    cout << "Member Name: " << member1.getName() << endl;
    cout << "Member ID: " << member1.getMemberID() << endl;
    cout << "Books Bought: " << member1.getBooksBought() << endl;
    cout << "Amount Spent: $" << member1.getAmountSpent() << endl;
    
    return 0;
}

