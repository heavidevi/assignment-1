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


void BookType::setTitle(string t) {
    title = t;
}

string BookType::getTitle() const {
    return title;
}

void BookType::showTitle() const {
    cout << "Title: " << title << endl;
}

bool BookType::isSameTitle(string t) const {
    return title == t;
}


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

int BookType::getNumAuthors() const {
    return numAuthors;
}

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

void BookType::setPublisher(string pub) {
    publisher = pub;
}

string BookType::getPublisher() const {
    return publisher;
}

void BookType::showPublisher() const {
    cout << "Publisher: " << publisher << endl;
}

bool BookType::isSamePublisher(string pub) const {
    return publisher == pub;
}

void BookType::setISBN(string isbnCode) {
    isbn = isbnCode;
}

string BookType::getISBN() const {
    return isbn;
}

void BookType::showISBN() const {
    cout << "ISBN: " << isbn << endl;
}

bool BookType::isSameISBN(string isbnCode) const {
    return isbn == isbnCode;
}

void BookType::setPrice(double p) {
    if (p >= 0) {
        price = p;
    } else {
        cout << "price cannot be negative" << endl;
    }
}

double BookType::getPrice() const {
    return price;
}

void BookType::showPrice() const {
    cout << "Price: $" << price << endl;
}

void BookType::updatePrice(double newPrice) {
    setPrice(newPrice);
}

void BookType::setYear(int y) {
    if (y > 0) {
        year = y;
    } else {
        cout << "year must be positive" << endl;
    }
}

int BookType::getYear() const {
    return year;
}

void BookType::showYear() const {
    cout << "Year: " << year << endl;
}

void BookType::setNoOfCopies(int copies) {
    if (copies >= 0) {
        noOfCopies = copies;
    } else {
        cout << "copies cannot be negative" << endl;
    }
}

int BookType::getNoOfCopies() const {
    return noOfCopies;
}

void BookType::showNoOfCopies() const {
    cout << "Copies: " << noOfCopies << endl;
}

void BookType::updateNoOfCopies(int copies) {
    setNoOfCopies(copies);
}

int BookType::returnNoOfCopies() const {
    return noOfCopies;
}


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

int searchByTitle(BookType books[], int size, string title);
int searchByISBN(BookType books[], int size, string isbn);
void updateCopies(BookType books[], int size, string isbn, int newCopies);
void displayAllBooks(BookType books[], int size);
void addSampleBooks(BookType books[], int& count);
void displayMenu();

int main() {
    const int MAX_BOOKS = 100;
    BookType library[MAX_BOOKS];
    int bookCount = 0;
    
    cout << "Book Library System" << endl;
    
    addSampleBooks(library, bookCount);
    
    int choice;
    string searchTitle, searchISBN;
    int newCopies, bookIndex;
    
    do {
        displayMenu();
        cout << "choice: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1:
                cout << "\nAll Books:" << endl;
                displayAllBooks(library, bookCount);
                break;
                
            case 2:
                cout << "book title: ";
                getline(cin, searchTitle);
                bookIndex = searchByTitle(library, bookCount, searchTitle);
                if (bookIndex != -1) {
                    cout << "\nfound at " << bookIndex << ":" << endl;
                    library[bookIndex].displayBookInfo();
                } else {
                    cout << "book '" << searchTitle << "' not found" << endl;
                }
                break;
                
            case 3:
                cout << "ISBN: ";
                getline(cin, searchISBN);
                bookIndex = searchByISBN(library, bookCount, searchISBN);
                if (bookIndex != -1) {
                    cout << "\nfound at " << bookIndex << ":" << endl;
                    library[bookIndex].displayBookInfo();
                } else {
                    cout << "ISBN '" << searchISBN << "' not found" << endl;
                }
                break;
                
            case 4:
                cout << "ISBN to update: ";
                getline(cin, searchISBN);
                cout << "new copies: ";
                cin >> newCopies;
                updateCopies(library, bookCount, searchISBN, newCopies);
                break;
                
            case 5:
                if (bookCount < MAX_BOOKS) {
                    string title, publisher, isbn;
                    double price;
                    int year, copies, numAuthors;
                    
                    cout << "book title: ";
                    getline(cin, title);
                    cout << "authors (1-4): ";
                    cin >> numAuthors;
                    cin.ignore();
                    
                    library[bookCount] = BookType(title, numAuthors);
                    
                    for (int i = 0; i < numAuthors; i++) {
                        string authorName;
                        cout << "author " << (i + 1) << ": ";
                        getline(cin, authorName);
                        library[bookCount].setAuthor(i, authorName);
                    }
                    
                    cout << "publisher: ";
                    getline(cin, publisher);
                    library[bookCount].setPublisher(publisher);
                    
                    cout << "ISBN: ";
                    getline(cin, isbn);
                    library[bookCount].setISBN(isbn);
                    
                    cout << "price: $";
                    cin >> price;
                    library[bookCount].setPrice(price);
                    
                    cout << "year: ";
                    cin >> year;
                    library[bookCount].setYear(year);
                    
                    cout << "copies: ";
                    cin >> copies;
                    library[bookCount].setNoOfCopies(copies);
                    
                    bookCount++;
                    cout << "book added!" << endl;
                } else {
                    cout << "library full!" << endl;
                }
                break;
                
            case 6:
                cout << "\nTesting operations:" << endl;
                
                cout << "first book title test:" << endl;
                cout << "is 'Introduction to Algorithms'? " << 
                        (library[0].isSameTitle("Introduction to Algorithms") ? "yes" : "no") << endl;
                
                cout << "second book ISBN test:" << endl;
                cout << "is '978-0134685991'? " << 
                        (library[1].isSameISBN("978-0134685991") ? "yes" : "no") << endl;
                
                cout << "third book publisher test:" << endl;
                cout << "is 'O'Reilly Media'? " << 
                        (library[2].isSamePublisher("O'Reilly Media") ? "yes" : "no") << endl;
                
                cout << "\ncopy update test:" << endl;
                cout << "book 1 copies before: " << library[0].returnNoOfCopies() << endl;
                library[0].updateNoOfCopies(library[0].returnNoOfCopies() + 5);
                cout << "book 1 copies after adding 5: " << library[0].returnNoOfCopies() << endl;
                break;
                
            case 0:
                cout << "bye!" << endl;
                break;
                
            default:
                cout << "invalid choice" << endl;
        }
        
        if (choice != 0) {
            cout << "\npress enter...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. show all books" << endl;
    cout << "2. search by title" << endl;
    cout << "3. search by ISBN" << endl;
    cout << "4. update copies" << endl;
    cout << "5. add book" << endl;
    cout << "6. test operations" << endl;
    cout << "0. exit" << endl;
}

int searchByTitle(BookType books[], int size, string title) {
    for (int i = 0; i < size; i++) {
        if (books[i].isSameTitle(title)) {
            return i;
        }
    }
    return -1;
}

int searchByISBN(BookType books[], int size, string isbn) {
    for (int i = 0; i < size; i++) {
        if (books[i].isSameISBN(isbn)) {
            return i;
        }
    }
    return -1;
}

void updateCopies(BookType books[], int size, string isbn, int newCopies) {
    int index = searchByISBN(books, size, isbn);
    if (index != -1) {
        int oldCopies = books[index].returnNoOfCopies();
        books[index].updateNoOfCopies(newCopies);
        cout << "updated '" << books[index].getTitle() 
             << "' from " << oldCopies << " to " << newCopies << endl;
    } else {
        cout << "ISBN '" << isbn << "' not found" << endl;
    }
}

void displayAllBooks(BookType books[], int size) {
    if (size == 0) {
        cout << "no books" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        books[i].displayBookInfo();
        cout << "-----" << endl;
    }
}

void addSampleBooks(BookType books[], int& count) {
    books[0] = BookType("Introduction to Algorithms", 4);
    books[0].setAuthor(0, "Thomas H. Cormen");
    books[0].setAuthor(1, "Charles E. Leiserson");
    books[0].setAuthor(2, "Ronald L. Rivest");
    books[0].setAuthor(3, "Clifford Stein");
    books[0].setPublisher("MIT Press");
    books[0].setISBN("978-0262033848");
    books[0].setPrice(89.99);
    books[0].setYear(2009);
    books[0].setNoOfCopies(15);
    
    books[1] = BookType("Effective C++", 1);
    books[1].setAuthor(0, "Scott Meyers");
    books[1].setPublisher("Addison-Wesley");
    books[1].setISBN("978-0134685991");
    books[1].setPrice(54.99);
    books[1].setYear(2005);
    books[1].setNoOfCopies(25);
    
    books[2] = BookType("Clean Code", 1);
    books[2].setAuthor(0, "Robert C. Martin");
    books[2].setPublisher("Prentice Hall");
    books[2].setISBN("978-0132350884");
    books[2].setPrice(47.99);
    books[2].setYear(2008);
    books[2].setNoOfCopies(30);
    
    books[3] = BookType("Design Patterns", 4);
    books[3].setAuthor(0, "Erich Gamma");
    books[3].setAuthor(1, "Richard Helm");
    books[3].setAuthor(2, "Ralph Johnson");
    books[3].setAuthor(3, "John Vlissides");
    books[3].setPublisher("Addison-Wesley");
    books[3].setISBN("978-0201633612");
    books[3].setPrice(64.99);
    books[3].setYear(1994);
    books[3].setNoOfCopies(20);
    
    books[4] = BookType("The Art of Computer Programming", 1);
    books[4].setAuthor(0, "Donald E. Knuth");
    books[4].setPublisher("Addison-Wesley");
    books[4].setISBN("978-0321751041");
    books[4].setPrice(199.99);
    books[4].setYear(2011);
    books[4].setNoOfCopies(10);
    
    count = 5;
    
    cout << "loaded " << count << " books" << endl;
}