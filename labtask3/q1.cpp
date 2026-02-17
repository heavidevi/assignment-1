#include <iostream>
#include <string>
using namespace std;

class DayType {
private:
    string currentDay;
    string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int findDayIndex() {
        for (int j = 0; j < 7; j++) {
            if (weekdays[j] == currentDay)
                return j;
        }
        return 0; 
    }

public:
    DayType() {
        currentDay = "Sunday";
    }

    DayType(string dayName) {
        bool found = false;
        for (int i = 0; i < 7; i++) {
            if (weekdays[i] == dayName) {
                currentDay = dayName;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "invalid day, setting to Sunday" << endl;
            currentDay = "Sunday";
        }
    }

    void setDay(string dayName) {
        bool isValid = false;
        for (int k = 0; k < 7; k++) {
            if (weekdays[k] == dayName) {
                currentDay = dayName;
                isValid = true;
                break;
            }
        }
        if (!isValid) {
            cout << "not a valid day" << endl;
            currentDay = "Sunday";
        }
    }

    void printDay() {
        cout << "current day is: " << currentDay << endl;
    }

    string getDay() {
        return currentDay;
    }

    string nextDay() {
        int pos = findDayIndex();
        int nextPos = (pos + 1) % 7;
        return weekdays[nextPos];
    }
    
    string prevDay() {
        int pos = findDayIndex();
        int prevPos = pos - 1;
        if (prevPos < 0) prevPos = 6;
        return weekdays[prevPos];
    }
    
    string addDays(int numDays) {
        int pos = findDayIndex();
        int newPos = (pos + numDays) % 7;
        return weekdays[newPos];
    }
};

int main() {
    DayType today("Monday");
    today.printDay();
    
    cout << "tomorrow will be: " << today.nextDay() << endl;
    cout << "yesterday was: " << today.prevDay() << endl;
    cout << "in 3 days it will be: " << today.addDays(3) << endl;
    cout << "after 25 days: " << today.addDays(25) << endl;
    
    DayType anotherDay;
    anotherDay.setDay("Friday");
    anotherDay.printDay();
    
    return 0;
}