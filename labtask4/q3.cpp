#include <iostream>
using namespace std;

class Engine
{
    string engineName;

public:
    Engine(string n) : engineName(n)
    {
        cout <<"EntEngine ("<< engineName << ") constructed"<<endl;
    }
    string getName()
    {
        return engineName;
    }
    void start()
    {
        cout<<engineName<<" engine starting up...\n"<<endl;
    }
    ~Engine(){}
};
class Car
{
    string carName;
    Engine e;

public:
    Car(string n, string engName) : carName(n), e(engName) {
         cout << "Car (" << carName << ") assembled\n"<<endl;
    }
    string getCarName()
    {
        return carName;
    }
    void drive()
    {
        cout<<"Starting "<<carName<<" drive"<<endl;
        e.start();
       
    }
    ~Car(){
        cout<<endl;
    }
};
int main()
{
   
    {
        Car c1("SedanX","V6");
        c1.drive();

        cout<<"End of main scope."<<endl;
    }
}