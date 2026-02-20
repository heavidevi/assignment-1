#include<iostream>
using namespace std;

class BankAccount{
    private:
        static int total_accounts;
        int* accountNumber;
        bool isActive;
        
    public:
        BankAccount(){
            total_accounts++;
            accountNumber = new int(total_accounts);
            isActive = true;
            cout << "Account " << *accountNumber << " created successfully!" << endl;
        }
        
        BankAccount(int accNum){
            total_accounts++;
            accountNumber = new int(accNum);
            isActive = true;
            cout << "Account " << *accountNumber << " opened with your chosen number!" << endl;
        }
        
        BankAccount(const BankAccount& other){
            if(other.isActive){
                total_accounts++;
                accountNumber = new int(*other.accountNumber);
                isActive = true;
                cout << "New account " << *accountNumber << " created as a copy!" << endl;
            } else {
                accountNumber = nullptr;
                isActive = false;
                cout << "Sorry, cannot copy from a closed account." << endl;
            }
        }
        
        static int getTotalAccounts(){
            return total_accounts;
        }
        
        int getAccountNumber() const {
            return (isActive && accountNumber) ? *accountNumber : -1;
        }
        
        bool getStatus() const {
            return isActive;
        }
        
        void displayAccount() const {
            if(isActive && accountNumber){
                cout << "Account #" << *accountNumber << " is active and ready to use" << endl;
            } else {
                cout << "This account has been closed" << endl;
            }
        }
        
        void deleteAccount(int accNum){
            if(!isActive){
                cout << "This account is already closed!" << endl;
                return;
            }
            
            if(!accountNumber){
                cout << "Something went wrong with your account data." << endl;
                return;
            }
            
            if(*accountNumber != accNum){
                cout << "Account number doesn't match! You tried to close account " 
                     << accNum << " but this is account " << *accountNumber << "." << endl;
                return;
            }
            
            delete accountNumber;
            accountNumber = nullptr;
            isActive = false;
            total_accounts--;
            cout << "Account " << accNum << " has been successfully closed." << endl;
        }
        
        ~BankAccount(){
            if(isActive && accountNumber){
                delete accountNumber;
                total_accounts--;
                cout << "Account resources cleaned up automatically." << endl;
            }
        }
};

int BankAccount::total_accounts = 0;

int main(){
    cout << "Welcome to the Bank Management System!" << endl << endl;
    
    cout << "Let's create some accounts using different methods:" << endl;
    BankAccount acc1;
    BankAccount acc2;
    cout << "We now have " << BankAccount::getTotalAccounts() << " accounts in our system." << endl;
    
    cout << endl << "Creating an account with a specific number:" << endl;
    BankAccount acc3(100);
    cout << "Total accounts now: " << BankAccount::getTotalAccounts() << endl;
    
    cout << endl << "Making a copy of an existing account:" << endl;
    BankAccount acc4 = acc1;
    cout << "Total accounts after copying: " << BankAccount::getTotalAccounts() << endl;
    
    cout << endl << "Here's what we have in our system:" << endl;
    acc1.displayAccount();
    acc2.displayAccount();
    acc3.displayAccount();
    acc4.displayAccount();
    
    cout << endl << "Now let's try closing some accounts:" << endl;
    
    cout << endl << "Closing account 2..." << endl;
    acc2.deleteAccount(2);
    cout << "Accounts remaining: " << BankAccount::getTotalAccounts() << endl;
    acc2.displayAccount();
    
    cout << endl << "Trying to close account 2 again..." << endl;
    acc2.deleteAccount(2);
    
    cout << endl << "Trying to close account 1 with wrong number..." << endl;
    acc1.deleteAccount(999);
    
    cout << endl << "Closing account 100..." << endl;
    acc3.deleteAccount(100);
    cout << "Accounts remaining: " << BankAccount::getTotalAccounts() << endl;
    
    cout << endl << "Final status of all accounts:" << endl;
    acc1.displayAccount();
    acc2.displayAccount();
    acc3.displayAccount();
    acc4.displayAccount();
    cout << "Total active accounts: " << BankAccount::getTotalAccounts() << endl;
    
    cout << endl << "Program ending - remaining accounts will be cleaned up automatically..." << endl;
    
    return 0;
}