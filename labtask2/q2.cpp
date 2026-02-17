#include <iostream>
using namespace std;

class time{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        void settime(){
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        time(int h, int m, int s){
            hours = h;
            minutes = m;
            seconds = s;
        }
        void setTime(int h, int m, int s){
            hours = h;
            minutes = m;
            seconds = s;
        }
        void displayTime(){
            cout << hours << " : " << minutes << " : " << seconds << endl;
        }
};