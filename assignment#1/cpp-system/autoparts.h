#ifndef AUTOPARTS_H
#define AUTOPARTS_H

#include <iostream>
#include <string>
using namespace std;

class AutoParts {
private:
    const int partId;                // Data member 1 - constant ✓
    string partName;                 // Data member 2
    string category;                 // Data member 3 (Tires, Engine, Body, etc.)
    double price;                    // Data member 4
    int stockQuantity;               // Data member 5
    bool isGenuine;                  // Data member 6
    static int totalParts;           // Static member ✓
    static const double taxRate;     // Static constant ✓

public:
    // Default constructor
    AutoParts() : partId(++totalParts), partName("Generic Part"), 
                  category("Accessories"), price(1000.0), stockQuantity(10), 
                  isGenuine(true) {}

    // Parameterized constructor
    AutoParts(string name, string cat, double pr, int stock) 
        : partId(++totalParts), partName(name), category(cat), 
          price(pr), stockQuantity(stock), isGenuine(true) {}

    // Copy constructor
    AutoParts(const AutoParts& other) 
        : partId(++totalParts), partName(other.partName + "_COPY"), 
          category(other.category), price(other.price), 
          stockQuantity(0), isGenuine(other.isGenuine) {}

    // Function 1: Display part info - constant function ✓
    void displayPartInfo() const {
        cout << "Part ID: " << partId << endl;
        cout << "Name: " << partName << endl;
        cout << "Category: " << category << endl;
        cout << "Price: PKR " << price << endl;
        cout << "Stock: " << stockQuantity << endl;
        cout << "Genuine: " << (isGenuine ? "Yes" : "No") << endl;
    }

    // Function 2: Sell part (reduces stock)
    bool sellPart(int quantity) {
        if(quantity > 0 && quantity <= stockQuantity) {
            stockQuantity -= quantity;
            cout << "Sold " << quantity << " x " << partName << endl;
            return true;
        }
        cout << "Insufficient stock or invalid quantity" << endl;
        return false;
    }

    // Function 3: Restock inventory
    void restockPart(int quantity) {
        if(quantity > 0) {
            stockQuantity += quantity;
            cout << "Restocked " << quantity << " units of " << partName << endl;
        }
    }

    // Function 4: Calculate total price with tax - constant function ✓
    double calculateTotalPrice(int quantity) const {
        double subtotal = price * quantity;
        double tax = subtotal * taxRate;
        return subtotal + tax;
    }

    // Getters
    int getPartId() const { return partId; }
    string getPartName() const { return partName; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getStock() const { return stockQuantity; }
    bool getGenuineStatus() const { return isGenuine; }
    static int getTotalParts() { return totalParts; }

    // Setters
    void setPartName(string name) { partName = name; }
    void setCategory(string cat) { category = cat; }
    void setPrice(double pr) { if(pr > 0) price = pr; }
    void setGenuineStatus(bool genuine) { isGenuine = genuine; }

    ~AutoParts() {
        // Destructor
    }
};

int AutoParts::totalParts = 0;
const double AutoParts::taxRate = 0.17; // 17% tax rate

#endif