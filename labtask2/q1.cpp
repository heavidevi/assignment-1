#include <iostream>
using namespace std;

class rectangle{
    private:
        double length;
        double width;
    public:
        rectangle(double l, double w){
            length = l;
            width = w;
        }
        double area(){
            return length * width;
        }
        void setLength(double l){
            length = l;
        }
        void setWidth(double w){
            width = w;
        }
        void setDimensions(double l, double w){
            length = l;
            width = w;
        }
        double setarea(){
            return length * width;
        }
        double setperimeter(){
            return 2 * (length + width);
        }
        double getlength(){
            return length;
        }
        double getwidth(){
            return width;
        }
    
       
        int isSquare(){
            if(getlength() == getwidth()){
                return 1;
            }
            else{
                return 0;
            }
            
        }
};


int main(){
    rectangle r1(4, 5);
    rectangle r2(6, 6);
    cout << "Area of r1: " << r1.area() << endl;
    cout << "Area of r2: " << r2.area() << endl;
    cout << "Perimeter of r1: " << r1.setperimeter() << endl;
    cout << "Perimeter of r2: " << r2.setperimeter() << endl;
    if(r1.isSquare()){
        cout << "r1 is a square" << endl;
    }
    else{
        cout << "r1 is not a square" << endl;
    }
    if(r2.isSquare()){
        cout << "r2 is a square" << endl;
    }
    else{
        cout << "r2 is not a square" << endl;
    }
    
}