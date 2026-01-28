#include <iostream>
using namespace std;

typedef struct book {
    string title;
    string author;
    int pages;
    float price;
} book;

int main(){
    int cheapest=9999,expensive=0;
    string cheapesttitle,expensivetitle;
    book *ptr = new book[5];
    for(int i=0;i<5;i++){
        cout<<"enter details of book "<<i+1<<":"<<endl;
        cout<<"title: ";
        cin>>ptr[i].title;
        cout<<"author: ";
        cin>>ptr[i].author;
        cout<<"number of pages: ";
        cin>>ptr[i].pages;
        cout<<"price: ";
        cin>>ptr[i].price;
        if(ptr[i].price<cheapest){
            cheapest=ptr[i].price;
            cheapesttitle=ptr[i].title;
        }
        if(ptr[i].price>expensive){
            expensive=ptr[i].price;
            expensivetitle=ptr[i].title;
        }
    }
    cout<<"cheapest book is: "<<cheapesttitle<<" with price "<<cheapest<<endl;
    cout<<"most expensive book is: "<<expensivetitle<<" with price "<<expensive<<endl;
    delete[] ptr;
    return 0;
}