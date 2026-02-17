#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string fName, lName, middleName;
    
    public:
        Person(){
            fName = "";
            lName = "";
            middleName = "";
            cout << "person created" << endl;
        }

        void setFirstName(string first){
            fName = first;
        }

        void setMidName(string middle){
            middleName = middle;
        }

        void setLastName(string last){
            lName = last;
        }

        void displayFullName(){
            cout << fName << " " << middleName << " " << lName << endl;
        }

        void checkFirstName(string inputName){
            if(inputName == fName){
                cout << "first name matches" << endl;
            } else {
                cout << "first name does not match" << endl;
            }
        }

        void verifyFullName(string f, string m, string l){
            bool firstMatch = (f == fName);
            bool middleMatch = (m == middleName);
            bool lastMatch = (l == lName);
            
            if(firstMatch && middleMatch && lastMatch){
                cout << "all names are correct" << endl;
            } else {
                cout << "some names are wrong" << endl;
            }
        }
        
        string getFirstName(){
            return fName;
        }
        
        string getLastName(){
            return lName;
        }
};

int main() {
    string userFirst, userMiddle, userLast;
    
    Person student;
    
    student.setFirstName("muhammad");
    student.setMidName("ali");
    student.setLastName("adeel");

    cout << "what is the first name?" << endl;
    cin >> userFirst;
    student.checkFirstName(userFirst);

    cout << "enter middle name:" << endl;
    cin >> userMiddle;

    cout << "what about last name?" << endl;
    cin >> userLast;

    student.verifyFullName(userFirst, userMiddle, userLast);
    
    cout << "\nstored name is: ";
    student.displayFullName();

    return 0;
}