#include "BookType.h"
#include "MemberType.h"

class Bookstore {
    private:
        BookType books[1000];
        MemberType members[500];
        int totalBooks;
        int totalMembers;
        
    public:
        Bookstore();
        
        void addBook();
        void addMember();
        void sellBookToMember();
        void sellBookToGuest();
        void displayAllBooks();
        void displayAllMembers();
        void searchBookByTitle();
        void searchBookByISBN();
        void searchMember();
        void displayMenu();
        void run();
        
        int findBook(string title);
        int findBookByISBN(string isbn);
        int findMember(string memberID);
        void initializeSampleData();
};

Bookstore::Bookstore() {
    totalBooks = 0;
    totalMembers = 0;
}

void Bookstore::addBook() {
    if (totalBooks >= 1000) {
        cout << "bookstore full! cannot add more books" << endl;
        return;
    }
    
    string title, publisher, isbn;
    double price;
    int year, copies, numAuthors;
    
    cout << "book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "number of authors (1-4): ";
    cin >> numAuthors;
    cin.ignore();
    
    books[totalBooks] = BookType(title, numAuthors);
    
    for (int i = 0; i < numAuthors; i++) {
        string authorName;
        cout << "author " << (i + 1) << ": ";
        getline(cin, authorName);
        books[totalBooks].setAuthor(i, authorName);
    }
    
    cout << "publisher: ";
    getline(cin, publisher);
    books[totalBooks].setPublisher(publisher);
    
    cout << "ISBN: ";
    getline(cin, isbn);
    books[totalBooks].setISBN(isbn);
    
    cout << "price: $";
    cin >> price;
    books[totalBooks].setPrice(price);
    
    cout << "year: ";
    cin >> year;
    books[totalBooks].setYear(year);
    
    cout << "copies: ";
    cin >> copies;
    books[totalBooks].setNoOfCopies(copies);
    
    totalBooks++;
    cout << "book added successfully!" << endl;
}

void Bookstore::addMember() {
    if (totalMembers >= 500) {
        cout << "member limit reached!" << endl;
        return;
    }
    
    string name, memberID;
    cout << "member name: ";
    cin.ignore();
    getline(cin, name);
    cout << "member ID: ";
    getline(cin, memberID);
    
    members[totalMembers] = MemberType(name, memberID);
    totalMembers++;
    cout << "member added! please pay $10 membership fee" << endl;
}

int Bookstore::findBook(string title) {
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].isSameTitle(title)) {
            return i;
        }
    }
    return -1;
}

int Bookstore::findBookByISBN(string isbn) {
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].isSameISBN(isbn)) {
            return i;
        }
    }
    return -1;
}

int Bookstore::findMember(string memberID) {
    for (int i = 0; i < totalMembers; i++) {
        if (members[i].isSameMember(memberID)) {
            return i;
        }
    }
    return -1;
}

void Bookstore::sellBookToMember() {
    string memberID, bookTitle;
    cout << "member ID: ";
    cin.ignore();
    getline(cin, memberID);
    
    int memberIndex = findMember(memberID);
    if (memberIndex == -1) {
        cout << "member not found" << endl;
        return;
    }
    
    if (!members[memberIndex].isMembershipPaid()) {
        char payChoice;
        cout << "membership fee not paid. pay now? (y/n): ";
        cin >> payChoice;
        if (payChoice == 'y' || payChoice == 'Y') {
            members[memberIndex].payMembership();
        } else {
            cout << "cannot sell book without membership" << endl;
            return;
        }
    }
    
    cout << "book title: ";
    cin.ignore();
    getline(cin, bookTitle);
    
    int bookIndex = findBook(bookTitle);
    if (bookIndex == -1) {
        cout << "book not found" << endl;
        return;
    }
    
    if (books[bookIndex].getNoOfCopies() <= 0) {
        cout << "book out of stock" << endl;
        return;
    }
    
    double originalPrice = books[bookIndex].getPrice();
    double finalPrice = members[memberIndex].purchaseBook(originalPrice);
    
    if (finalPrice > 0) {
        books[bookIndex].updateNoOfCopies(books[bookIndex].getNoOfCopies() - 1);
        cout << "book sold to " << members[memberIndex].getName() << endl;
        cout << "original price: $" << originalPrice << endl;
        cout << "member price (5% discount): $" << finalPrice << endl;
        cout << "remaining copies: " << books[bookIndex].getNoOfCopies() << endl;
    }
}

void Bookstore::sellBookToGuest() {
    string bookTitle;
    cout << "book title: ";
    cin.ignore();
    getline(cin, bookTitle);
    
    int bookIndex = findBook(bookTitle);
    if (bookIndex == -1) {
        cout << "book not found" << endl;
        return;
    }
    
    if (books[bookIndex].getNoOfCopies() <= 0) {
        cout << "book out of stock" << endl;
        return;
    }
    
    double price = books[bookIndex].getPrice();
    books[bookIndex].updateNoOfCopies(books[bookIndex].getNoOfCopies() - 1);
    
    cout << "book sold to guest" << endl;
    cout << "price: $" << price << endl;
    cout << "remaining copies: " << books[bookIndex].getNoOfCopies() << endl;
}

void Bookstore::displayAllBooks() {
    if (totalBooks == 0) {
        cout << "no books in store" << endl;
        return;
    }
    
    cout << "\nAll Books:" << endl;
    for (int i = 0; i < totalBooks; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        books[i].displayBookInfo();
        cout << "-----" << endl;
    }
}

void Bookstore::displayAllMembers() {
    if (totalMembers == 0) {
        cout << "no members" << endl;
        return;
    }
    
    cout << "\nAll Members:" << endl;
    for (int i = 0; i < totalMembers; i++) {
        cout << "Member " << (i + 1) << ":" << endl;
        members[i].displayMemberInfo();
        cout << "-----" << endl;
    }
}

void Bookstore::searchBookByTitle() {
    string title;
    cout << "book title: ";
    cin.ignore();
    getline(cin, title);
    
    int index = findBook(title);
    if (index != -1) {
        cout << "book found:" << endl;
        books[index].displayBookInfo();
    } else {
        cout << "book not found" << endl;
    }
}

void Bookstore::searchBookByISBN() {
    string isbn;
    cout << "ISBN: ";
    cin.ignore();
    getline(cin, isbn);
    
    int index = findBookByISBN(isbn);
    if (index != -1) {
        cout << "book found:" << endl;
        books[index].displayBookInfo();
    } else {
        cout << "book not found" << endl;
    }
}

void Bookstore::searchMember() {
    string memberID;
    cout << "member ID: ";
    cin.ignore();
    getline(cin, memberID);
    
    int index = findMember(memberID);
    if (index != -1) {
        cout << "member found:" << endl;
        members[index].displayMemberInfo();
    } else {
        cout << "member not found" << endl;
    }
}

void Bookstore::displayMenu() {
    cout << "\nBookstore Menu:" << endl;
    cout << "1. add book" << endl;
    cout << "2. add member" << endl;
    cout << "3. sell book to member" << endl;
    cout << "4. sell book to guest" << endl;
    cout << "5. show all books" << endl;
    cout << "6. show all members" << endl;
    cout << "7. search book by title" << endl;
    cout << "8. search book by ISBN" << endl;
    cout << "9. search member" << endl;
    cout << "10. pay membership fee" << endl;
    cout << "0. exit" << endl;
}

void Bookstore::initializeSampleData() {
    books[0] = BookType("Programming with C++", 1);
    books[0].setAuthor(0, "Bjarne Stroustrup");
    books[0].setPublisher("Addison Wesley");
    books[0].setISBN("978-1234567890");
    books[0].setPrice(45.99);
    books[0].setYear(2020);
    books[0].setNoOfCopies(10);
    
    books[1] = BookType("Data Structures", 2);
    books[1].setAuthor(0, "Michael Goodrich");
    books[1].setAuthor(1, "Roberto Tamassia");
    books[1].setPublisher("Wiley");
    books[1].setISBN("978-9876543210");
    books[1].setPrice(62.50);
    books[1].setYear(2019);
    books[1].setNoOfCopies(8);
    
    books[2] = BookType("Algorithm Design", 1);
    books[2].setAuthor(0, "Jon Kleinberg");
    books[2].setPublisher("Pearson");
    books[2].setISBN("978-5555555555");
    books[2].setPrice(58.99);
    books[2].setYear(2021);
    books[2].setNoOfCopies(12);
    
    totalBooks = 3;
    
    members[0] = MemberType("Ali Ahmed", "M001");
    members[1] = MemberType("Sara Khan", "M002");
    members[2] = MemberType("Omar Hassan", "M003");
    
    totalMembers = 3;
    
    cout << "sample data loaded: " << totalBooks << " books and " << totalMembers << " members" << endl;
}

void Bookstore::run() {
    cout << "Welcome to the Bookstore!" << endl;
    initializeSampleData();
    
    int choice;
    do {
        displayMenu();
        cout << "choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addMember();
                break;
            case 3:
                sellBookToMember();
                break;
            case 4:
                sellBookToGuest();
                break;
            case 5:
                displayAllBooks();
                break;
            case 6:
                displayAllMembers();
                break;
            case 7:
                searchBookByTitle();
                break;
            case 8:
                searchBookByISBN();
                break;
            case 9:
                searchMember();
                break;
            case 10:
                {
                    string memberID;
                    cout << "member ID to pay fee: ";
                    cin.ignore();
                    getline(cin, memberID);
                    int index = findMember(memberID);
                    if (index != -1) {
                        members[index].payMembership();
                    } else {
                        cout << "member not found" << endl;
                    }
                }
                break;
            case 0:
                cout << "thank you for visiting!" << endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }
        
        if (choice != 0) {
            cout << "\npress enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
}

int main() {
    Bookstore store;
    store.run();
    return 0;
}
