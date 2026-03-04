#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string name;           
    const string password; 
    int accountId;
    static int nextId;    
public:
   
    Account() : name(""), password(""), accountId(-1) {}


    Account(string name, string password) : name(name), password(password) {
        accountId = nextId++;
    }


    string getName() const { return name; }
    string getPassword() const { return password; }
    int getAccountId() const { return accountId; }

    virtual void showDashboard() const = 0; 

    virtual ~Account() {}
};


int Account::nextId = 0;

#endif