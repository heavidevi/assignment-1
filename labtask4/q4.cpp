#include <iostream>
using namespace std;

class Employee {
    string name;
public:
    Employee(string n) : name(n) {
        cout << name << " joined the company\n";
    }

    void work() {
        cout << name << " is working\n";
    }

    string getName() const {
        return name;
    }

    ~Employee() {
        cout << name << " left the company\n";
    }
};

class Department {
    string deptName;
    Employee* staff[10];   
    int count;

public:
    Department(string name) : deptName(name), count(0) {}

    void addEmployee(Employee* emp) {
        if (count < 10) {
            staff[count++] = emp;
            cout << emp->getName() << " added to " << deptName << "\n";
        }
    }

    void showStaff() {
        cout << "\n" << deptName << " people:\n";
        for (int i = 0; i < count; i++) {
            staff[i]->work();
        }
    }

    ~Department() {
        cout << "\nDepartment " << deptName << " shut down.\n";
    }
};

int main() {
    
    Employee* e1 = new Employee("Ali");
    Employee* e2 = new Employee("Adeel");

    {
        Department hr("HR");
        hr.addEmployee(e1);
        hr.addEmployee(e2);
        hr.showStaff();
    } 
    delete e1;
    delete e2;

    return 0;
}
