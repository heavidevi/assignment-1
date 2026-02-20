#include <iostream>
#include <string>

using namespace std;

class RentCalculator {
private:
    const double RentPerDay = 1000.85;
    
    const string CustomerName;
    int NumberOfDays;
    double CustomerRent;

public:
    RentCalculator(string name, int days) : CustomerName(name), NumberOfDays(days) {
        if (NumberOfDays > 7) {
            RentWithDiscount();
        } else {
            RentWithoutDiscount();
        }
    }

    void RentWithDiscount() {
        CustomerRent = (NumberOfDays - 1) * RentPerDay;
    }

    void RentWithoutDiscount() {
        CustomerRent = NumberOfDays * RentPerDay;
    }

    void DisplayRent() const {
        cout << "Customer " << CustomerName << " stayed for " << NumberOfDays << " days" << endl;
        cout << "Total rent: " << CustomerRent << endl;
        cout << endl;
    }
};

int main() {
    RentCalculator customer1("Ali Adeel", 5);
    customer1.DisplayRent();

    RentCalculator customer2("shagufta begum", 10);
    customer2.DisplayRent();

    return 0;
}