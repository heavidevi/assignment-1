#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <iostream>
#include <string>
using namespace std;

class BookType {
    private:
        string title;
        string* authors;        
        int numAuthors;        
        string publisher;
        string isbn;
        double price;          
        int year;
        int noOfCopies;
    
    public:
        BookType();
        BookType(string t, int numAuth);
        BookType(const BookType& other);
        ~BookType();
        BookType& operator=(const BookType& other);
        
        void setTitle(string t);
        string getTitle() const;
        void showTitle() const;
        bool isSameTitle(string t) const;
        
        void setNumAuthors(int num);
        int getNumAuthors() const;
        void setAuthor(int index, string authorName);
        string getAuthor(int index) const;
        void showAuthors() const;
        void setAllAuthors(string* authorArray, int num);

        void setPublisher(string pub);
        string getPublisher() const;
        void showPublisher() const;
        bool isSamePublisher(string pub) const;
        
        void setISBN(string isbnCode);
        string getISBN() const;
        void showISBN() const;
        bool isSameISBN(string isbnCode) const;
        
        void setPrice(double p);
        double getPrice() const;
        void showPrice() const;
        void updatePrice(double newPrice);
        
        void setYear(int y);
        int getYear() const;
        void showYear() const;
        
        void setNoOfCopies(int copies);
        int getNoOfCopies() const;
        void showNoOfCopies() const;
        void updateNoOfCopies(int copies);
        int returnNoOfCopies() const;
        
        void displayBookInfo() const;
};

#endif
