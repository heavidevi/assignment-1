#include "BookType.h"

BookType::BookType() {
    title = "";
    authors = nullptr;
    numAuthors = 0;
    publisher = "";
    isbn = "";
    price = 0.0;
    year = 0;
    noOfCopies = 0;
}

BookType::BookType(string t, int numAuth) {
    title = t;
    numAuthors = numAuth;
    if (numAuth > 0 && numAuth <= 4) {
        authors = new string[numAuth];
        for (int i = 0; i < numAuth; i++) {
            authors[i] = "";
        }
    } else {
        authors = nullptr;
        numAuthors = 0;
    }
    publisher = "";
    isbn = "";
    price = 0.0;
    year = 0;
    noOfCopies = 0;
}

BookType::BookType(const BookType& other) {
    title = other.title;
    numAuthors = other.numAuthors;
    publisher = other.publisher;
    isbn = other.isbn;
    price = other.price;
    year = other.year;
    noOfCopies = other.noOfCopies;
    
    if (other.authors != nullptr && numAuthors > 0) {
        authors = new string[numAuthors];
        for (int i = 0; i < numAuthors; i++) {
            authors[i] = other.authors[i];
        }
    } else {
        authors = nullptr;
    }
}

BookType::~BookType() {
    delete[] authors;
}

BookType& BookType::operator=(const BookType& other) {
    if (this != &other) {
        delete[] authors;
        
        title = other.title;
        numAuthors = other.numAuthors;
        publisher = other.publisher;
        isbn = other.isbn;
        price = other.price;
        year = other.year;
        noOfCopies = other.noOfCopies;
        
        if (other.authors != nullptr && numAuthors > 0) {
            authors = new string[numAuthors];
            for (int i = 0; i < numAuthors; i++) {
                authors[i] = other.authors[i];
            }
        } else {
            authors = nullptr;
        }
    }
    return *this;
}

void BookType::setTitle(string t) { title = t; }
string BookType::getTitle() const { return title; }
void BookType::showTitle() const { cout << "Title: " << title << endl; }
bool BookType::isSameTitle(string t) const { return title == t; }

void BookType::setNumAuthors(int num) {
    if (num <= 0 || num > 4) {
        cout << "authors must be between 1 and 4" << endl;
        return;
    }
    delete[] authors;
    numAuthors = num;
    authors = new string[numAuthors];
    for (int i = 0; i < numAuthors; i++) {
        authors[i] = "";
    }
}

int BookType::getNumAuthors() const { return numAuthors; }

void BookType::setAuthor(int index, string authorName) {
    if (index >= 0 && index < numAuthors && authors != nullptr) {
        authors[index] = authorName;
    } else {
        cout << "invalid author index" << endl;
    }
}

string BookType::getAuthor(int index) const {
    if (index >= 0 && index < numAuthors && authors != nullptr) {
        return authors[index];
    }
    return "";
}

void BookType::showAuthors() const {
    cout << "Authors: ";
    if (authors != nullptr && numAuthors > 0) {
        for (int i = 0; i < numAuthors; i++) {
            cout << authors[i];
            if (i < numAuthors - 1) cout << ", ";
        }
    }
    cout << endl;
}

void BookType::setAllAuthors(string* authorArray, int num) {
    if (num <= 0 || num > 4) {
        cout << "authors must be between 1 and 4" << endl;
        return;
    }
    delete[] authors;
    numAuthors = num;
    authors = new string[numAuthors];
    for (int i = 0; i < numAuthors; i++) {
        authors[i] = authorArray[i];
    }
}

void BookType::setPublisher(string pub) { publisher = pub; }
string BookType::getPublisher() const { return publisher; }
void BookType::showPublisher() const { cout << "Publisher: " << publisher << endl; }
bool BookType::isSamePublisher(string pub) const { return publisher == pub; }

void BookType::setISBN(string isbnCode) { isbn = isbnCode; }
string BookType::getISBN() const { return isbn; }
void BookType::showISBN() const { cout << "ISBN: " << isbn << endl; }
bool BookType::isSameISBN(string isbnCode) const { return isbn == isbnCode; }

void BookType::setPrice(double p) {
    if (p >= 0) {
        price = p;
    } else {
        cout << "price cannot be negative" << endl;
    }
}

double BookType::getPrice() const { return price; }
void BookType::showPrice() const { cout << "Price: $" << price << endl; }
void BookType::updatePrice(double newPrice) { setPrice(newPrice); }

void BookType::setYear(int y) {
    if (y > 0) {
        year = y;
    } else {
        cout << "year must be positive" << endl;
    }
}

int BookType::getYear() const { return year; }
void BookType::showYear() const { cout << "Year: " << year << endl; }

void BookType::setNoOfCopies(int copies) {
    if (copies >= 0) {
        noOfCopies = copies;
    } else {
        cout << "copies cannot be negative" << endl;
    }
}

int BookType::getNoOfCopies() const { return noOfCopies; }
void BookType::showNoOfCopies() const { cout << "Copies: " << noOfCopies << endl; }
void BookType::updateNoOfCopies(int copies) { setNoOfCopies(copies); }
int BookType::returnNoOfCopies() const { return noOfCopies; }

void BookType::displayBookInfo() const {
    showTitle();
    showAuthors();
    showPublisher();
    showISBN();
    showPrice();
    showYear();
    showNoOfCopies();
    cout << endl;
}
