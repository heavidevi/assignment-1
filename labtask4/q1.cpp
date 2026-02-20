#include <iostream>
// #include <string>
using namespace std;

class Student
{

    const int studentId;
    string studentName;

public:
    Student(int id, string name) : studentId(id), studentName(name) {}

    int getId() const
    {
        return studentId;
    }
    string getStudentName() const
    {
        return studentName;
    }

    void setStudentName(string name)
    {
        studentName = name;
    }
    void display()
    {
        int choice;
        cout << "Student Id: " << getId() << endl;
        cout << "Student name: " << getStudentName() << endl;
    }
};

int main()
{
    Student student1(101, "Ali");
    Student student2(102, "Anas");
    Student student3(103, "ahmed");

    student1.display();
    cout << endl;

    student2.display();
    cout << endl;

    student2.setStudentName("Ahmed");

    student2.display();
    cout << endl;

    student3.display();

    return 0;

}