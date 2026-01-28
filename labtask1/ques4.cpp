#include <iostream>
using namespace std;


int main(){
    int n,max=-9999,min=9999;
    cout<<"enter number of elements: ";
    cin>>n;
    int *ptr= new int[n];
    cout<<"enter elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>ptr[i];
        if(ptr[i]>max){
            max=ptr[i];
        }
        if(ptr[i]<min){
            min=ptr[i];
        }
    }
    cout<<"maximum element is: "<<max<<endl;
    cout<<"minimum element is: "<<min<<endl;
    delete[] ptr;
    return 0;
}