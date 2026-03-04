#include<iostream>
#include<string>
#include "vehicle.h"
#include "account.h"
#include "admin.h"
#include "audit.h"
#include "buyer.h"
#include "car.h"
#include "finance.h"
#include "marketplace.h"
#include "seller.h"
#include "user.h"
#include "inspector.h"
#include "message.h"
#include "autoparts.h"
#include "company.h"

using namespace std;

// Global system objects
Marketplace* marketplace;
Finance* pakwheelsFinance;
Admin* systemAdmin;
Inspector* systemInspector;

// Sample data
User* users[10];
int userCount = 0;
AutoParts* autoparts[10];
int partsCount = 0;

// Vehicle approval system
bool vehicleApprovalStatus[100];
int totalVehicles = 0;

// Vehicle ownership system
string vehicleOwners[100];
Vehicle* allVehicles[100];

// User favorites system
string userFavorites[10][50];
int favoriteCount[10] = {0};

void initializeSystem() {
    cout << "=== PAKWHEELS SYSTEM INITIALIZATION ===" << endl;
    
    marketplace = new Marketplace(20);
    pakwheelsFinance = new Finance();
    systemAdmin = nullptr;  // Skip admin creation for now
    systemInspector = new Inspector("inspector1", "inspect123", 2001);
    
    // Create sample users
    users[0] = new User("ahmed123", "pass123", "03001234567");
    users[1] = new User("sara456", "pass456", "03009876543");
    users[2] = new User("ali789", "pass789", "03007654321");
    userCount = 3;
    
    // Create sample auto parts
    autoparts[0] = new AutoParts("Michelin Tire", "Tires", 15000.0, 50);
    autoparts[1] = new AutoParts("Air Filter", "Engine", 2500.0, 100);
    autoparts[2] = new AutoParts("Bumper", "Body", 8000.0, 25);
    partsCount = 3;
    
    // Create sample vehicles
    Vehicle* car1 = new Vehicle(VehicleCategory::PASSENGER_CAR, "Toyota Corolla", 2500000, 2020, "Lahore", "Toyota", "TYT-123");
    Vehicle* car2 = new Vehicle(VehicleCategory::PASSENGER_CAR, "Honda Civic", 3200000, 2019, "Karachi", "Honda", "HND-456");
    Vehicle* car3 = new Vehicle(VehicleCategory::PASSENGER_CAR, "Suzuki Alto", 1800000, 2021, "Islamabad", "Suzuki", "SZK-789");
    
    marketplace->addVehicle(car1);
    marketplace->addVehicle(car2);
    marketplace->addVehicle(car3);
    
    // Store vehicles for detailed viewing
    allVehicles[0] = car1;
    allVehicles[1] = car2;
    allVehicles[2] = car3;
    
    // Initialize vehicle ownership
    vehicleOwners[0] = "admin_default";
    vehicleOwners[1] = "admin_default";
    vehicleOwners[2] = "admin_default";
    
    // Initialize vehicle approval status
    vehicleApprovalStatus[0] = true;  // Toyota approved
    vehicleApprovalStatus[1] = true;  // Honda approved
    vehicleApprovalStatus[2] = true;  // Suzuki approved
    totalVehicles = 3;
    
    cout << "System initialized with sample data!" << endl;
}

void showMainMenu() {
    cout << "\n=== PAKWHEELS MARKETPLACE ===" << endl;
    cout << "1. User Login" << endl;
    cout << "2. Admin Login" << endl;
    cout << "3. Inspector Login" << endl;
    cout << "4. Register New User" << endl;
    cout << "5. View System Statistics" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayAllVehicles() {
    cout << "\n=== ALL VEHICLES ===" << endl;
    for(int i = 0; i < totalVehicles; i++) {
        if(vehicleApprovalStatus[i]) {
            cout << "\n" << (i+1) << ". " << allVehicles[i]->getSpecificType() << endl;
            cout << "   Brand: " << allVehicles[i]->getManufacturer() << endl;
            cout << "   Price: PKR " << allVehicles[i]->getPrice() << endl;
            cout << "   Year: " << allVehicles[i]->getModelYear() << endl;
            cout << "   Location: " << allVehicles[i]->getLocation() << endl;
            cout << "   Owner: " << vehicleOwners[i] << endl;
            cout << "   Status: APPROVED" << endl;
            cout << "   -------------------------" << endl;
        }
    }
}

void displayVehicleDetails(int vehicleIndex) {
    if(vehicleIndex >= 0 && vehicleIndex < totalVehicles && vehicleApprovalStatus[vehicleIndex]) {
        Vehicle* vehicle = allVehicles[vehicleIndex];
        cout << "\n=== VEHICLE DETAILS ===" << endl;
        cout << "Vehicle ID: " << (vehicleIndex + 1) << endl;
        cout << "Name: " << vehicle->getSpecificType() << endl;
        cout << "Brand: " << vehicle->getManufacturer() << endl;
        cout << "Model: " << vehicle->getSpecificType() << endl;
        cout << "Price: PKR " << vehicle->getPrice() << endl;
        cout << "Year: " << vehicle->getModelYear() << endl;
        cout << "Location: " << vehicle->getLocation() << endl;
        cout << "Vehicle Number: " << vehicle->getVehicleNumber() << endl;
        cout << "Owner: " << vehicleOwners[vehicleIndex] << endl;
        cout << "Status: APPROVED" << endl;
        cout << "==========================" << endl;
    }
}

void searchAndFilterVehicles() {
    cout << "\n=== VEHICLE SEARCH & FILTER ===" << endl;
    cout << "1. View All Approved Vehicles" << endl;
    cout << "2. Filter by Brand" << endl;
    cout << "3. Filter by Price Range" << endl;
    cout << "4. Filter by Year Range" << endl;
    cout << "5. Filter by Location" << endl;
    cout << "6. Advanced Multi-Filter Search" << endl;
    cout << "7. Back to Main Menu" << endl;
    cout << "Enter choice: ";
    
    int filterChoice;
    cin >> filterChoice;
    
    switch(filterChoice) {
        case 1: {
            cout << "\n=== APPROVED VEHICLES ===" << endl;
            for(int i = 0; i < totalVehicles; i++) {
                if(vehicleApprovalStatus[i]) {
                    cout << (i+1) << ". " << allVehicles[i]->getSpecificType() 
                         << " - PKR " << allVehicles[i]->getPrice() 
                         << " (" << allVehicles[i]->getModelYear() << ")" << endl;
                }
            }
            break;
        }
        case 2: {
            string brand;
            cout << "Available brands: Toyota, Honda, Suzuki, etc." << endl;
            cout << "Enter brand to search: ";
            cin >> brand;
            cout << "\n=== " << brand << " VEHICLES ===" << endl;
            
            bool found = false;
            for(int i = 0; i < totalVehicles; i++) {
                if(vehicleApprovalStatus[i] && allVehicles[i]->getManufacturer() == brand) {
                    displayVehicleDetails(i);
                    found = true;
                }
            }
            if(!found) cout << "No " << brand << " vehicles found." << endl;
            break;
        }
        case 3: {
            double minPrice, maxPrice;
            cout << "Enter minimum price (PKR): ";
            cin >> minPrice;
            cout << "Enter maximum price (PKR): ";
            cin >> maxPrice;
            
            cout << "\n=== VEHICLES IN PRICE RANGE PKR " << minPrice << " - " << maxPrice << " ===" << endl;
            bool found = false;
            for(int i = 0; i < totalVehicles; i++) {
                if(vehicleApprovalStatus[i] && allVehicles[i]->getPrice() >= minPrice && 
                   allVehicles[i]->getPrice() <= maxPrice) {
                    displayVehicleDetails(i);
                    found = true;
                }
            }
            if(!found) cout << "No vehicles found in this price range." << endl;
            break;
        }
        case 4: {
            int minYear, maxYear;
            cout << "Enter minimum year: ";
            cin >> minYear;
            cout << "Enter maximum year: ";
            cin >> maxYear;
            
            cout << "\n=== VEHICLES FROM " << minYear << " - " << maxYear << " ===" << endl;
            bool found = false;
            for(int i = 0; i < totalVehicles; i++) {
                if(vehicleApprovalStatus[i] && allVehicles[i]->getModelYear() >= minYear && 
                   allVehicles[i]->getModelYear() <= maxYear) {
                    displayVehicleDetails(i);
                    found = true;
                }
            }
            if(!found) cout << "No vehicles found in this year range." << endl;
            break;
        }
        case 5: {
            string location;
            cout << "Available locations: Lahore, Karachi, Islamabad, etc." << endl;
            cout << "Enter location: ";
            cin >> location;
            
            cout << "\n=== VEHICLES IN " << location << " ===" << endl;
            bool found = false;
            for(int i = 0; i < totalVehicles; i++) {
                if(vehicleApprovalStatus[i] && allVehicles[i]->getLocation() == location) {
                    displayVehicleDetails(i);
                    found = true;
                }
            }
            if(!found) cout << "No vehicles found in " << location << "." << endl;
            break;
        }
        case 6: {
            cout << "\n=== ADVANCED MULTI-FILTER SEARCH ===" << endl;
            string brand, location;
            double minPrice = 0, maxPrice = 999999999;
            int minYear = 1990, maxYear = 2030;
            
            cout << "Enter brand (or 'any' for all): ";
            cin >> brand;
            cout << "Enter location (or 'any' for all): ";
            cin >> location;
            cout << "Enter minimum price (0 for no limit): ";
            cin >> minPrice;
            cout << "Enter maximum price (0 for no limit): ";
            cin >> maxPrice;
            if(maxPrice == 0) maxPrice = 999999999;
            cout << "Enter minimum year: ";
            cin >> minYear;
            cout << "Enter maximum year: ";
            cin >> maxYear;
            
            cout << "\n=== FILTERED RESULTS ===" << endl;
            bool found = false;
            for(int i = 0; i < totalVehicles; i++) {
                if(vehicleApprovalStatus[i] &&
                   (brand == "any" || allVehicles[i]->getManufacturer() == brand) &&
                   (location == "any" || allVehicles[i]->getLocation() == location) &&
                   allVehicles[i]->getPrice() >= minPrice &&
                   allVehicles[i]->getPrice() <= maxPrice &&
                   allVehicles[i]->getModelYear() >= minYear &&
                   allVehicles[i]->getModelYear() <= maxYear) {
                    displayVehicleDetails(i);
                    found = true;
                }
            }
            if(!found) cout << "No vehicles match your criteria." << endl;
            break;
        }
        case 7:
            return;
        default:
            cout << "Invalid choice!" << endl;
    }
}

void contactVehicleOwner(int vehicleIndex) {
    if(vehicleIndex >= 0 && vehicleIndex < totalVehicles) {
        cout << "\n=== CONTACT VEHICLE OWNER ===" << endl;
        cout << "Vehicle: " << allVehicles[vehicleIndex]->getSpecificType() << endl;
        cout << "Owner: " << vehicleOwners[vehicleIndex] << endl;
        cout << "Price: PKR " << allVehicles[vehicleIndex]->getPrice() << endl;
        
        cout << "\n1. Send Message to Owner" << endl;
        cout << "2. Request Phone Contact" << endl;
        cout << "3. Schedule Test Drive" << endl;
        cout << "4. Make Offer" << endl;
        cout << "5. Back" << endl;
        cout << "Enter choice: ";
        
        int contactChoice;
        cin >> contactChoice;
        
        switch(contactChoice) {
            case 1: {
                string message;
                cout << "Enter your message: ";
                cin.ignore();
                getline(cin, message);
                cout << "Message sent to " << vehicleOwners[vehicleIndex] << ": " << message << endl;
                break;
            }
            case 2: {
                cout << "Phone contact request sent to " << vehicleOwners[vehicleIndex] << endl;
                cout << "Owner will contact you soon." << endl;
                break;
            }
            case 3: {
                cout << "Test drive scheduled with " << vehicleOwners[vehicleIndex] << endl;
                cout << "You will receive confirmation details." << endl;
                break;
            }
            case 4: {
                double offerPrice;
                cout << "Enter your offer (PKR): ";
                cin >> offerPrice;
                cout << "Offer of PKR " << offerPrice << " sent to " << vehicleOwners[vehicleIndex] << endl;
                break;
            }
            case 5:
                return;
        }
    }
}

void addToFavorites(int userIndex, string vehicleId) {
    if(favoriteCount[userIndex] < 50) {
        userFavorites[userIndex][favoriteCount[userIndex]] = vehicleId;
        favoriteCount[userIndex]++;
        cout << "Vehicle added to favorites!" << endl;
    } else {
        cout << "Favorites list is full!" << endl;
    }
}

void showFavorites(int userIndex) {
    cout << "\n=== YOUR FAVORITES ===" << endl;
    if(favoriteCount[userIndex] == 0) {
        cout << "No favorites added yet." << endl;
        return;
    }
    
    for(int i = 0; i < favoriteCount[userIndex]; i++) {
        cout << (i+1) << ". Vehicle ID: " << userFavorites[userIndex][i] << endl;
    }
}

int findUserIndex(User* currentUser) {
    for(int i = 0; i < userCount; i++) {
        if(users[i] == currentUser) {
            return i;
        }
    }
    return -1;
}

User* authenticateUser(string username, string password) {
    for(int i = 0; i < userCount; i++) {
        if(users[i]->getName() == username) {
            cout << "User found: " << username << endl;
            return users[i];
        }
    }
    return nullptr;
}

bool authenticateAdmin(string username, string password) {
    if(username == "admin" && password == "admin123") {
        return true;
    }
    return false;
}

bool authenticateInspector(string username, string password) {
    if(username == "inspector1" && password == "inspect123") {
        return true;
    }
    return false;
}

void showUserMenu(User* currentUser) {
    int choice;
    int userIndex = findUserIndex(currentUser);
    
    do {
        cout << "\n=== USER DASHBOARD - Welcome " << currentUser->getName() << " ===" << endl;
        cout << "1. Browse & Search Vehicles" << endl;
        cout << "2. Sell Vehicle (Post Ad)" << endl;
        cout << "3. Buy Auto Parts" << endl;
        cout << "4. View My Profile" << endl;
        cout << "5. View My Listings" << endl;
        cout << "6. Send Message" << endl;
        cout << "7. View Vehicle Valuation" << endl;
        cout << "8. My Favorites" << endl;
        cout << "9. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                cout << "\n=== VEHICLE MARKETPLACE ===" << endl;
                cout << "1. View All Available Vehicles" << endl;
                cout << "2. Search & Filter Vehicles" << endl;
                cout << "3. Back to Dashboard" << endl;
                cout << "Enter choice: ";
                
                int browseChoice;
                cin >> browseChoice;
                
                if(browseChoice == 1) {
                    displayAllVehicles();
                    cout << "\nEnter vehicle number to view details (or -1 to go back): ";
                    int vehicleChoice;
                    cin >> vehicleChoice;
                    
                    if(vehicleChoice == -1) {
                        break;
                    }
                    
                    if(vehicleChoice > 0 && vehicleChoice <= totalVehicles) {
                        int vehicleIndex = vehicleChoice - 1;
                        if(vehicleApprovalStatus[vehicleIndex]) {
                            displayVehicleDetails(vehicleIndex);
                            
                            cout << "\n1. Add to Favorites" << endl;
                            cout << "2. Contact Owner" << endl;
                            cout << "3. Back" << endl;
                            cout << "Choice: ";
                            
                            int actionChoice;
                            cin >> actionChoice;
                            
                            if(actionChoice == 1) {
                                addToFavorites(userIndex, "VEH-" + to_string(vehicleChoice));
                            } else if(actionChoice == 2) {
                                contactVehicleOwner(vehicleIndex);
                            }
                        } else {
                            cout << "Vehicle pending approval!" << endl;
                        }
                    } else {
                        cout << "Invalid vehicle number!" << endl;
                    }
                } else if(browseChoice == 2) {
                    searchAndFilterVehicles();
                    
                    cout << "\nWould you like to view details of any vehicle? (y/n): ";
                    char viewDetails;
                    cin >> viewDetails;
                    
                    if(viewDetails == 'y' || viewDetails == 'Y') {
                        cout << "Enter vehicle number: ";
                        int vehicleChoice;
                        cin >> vehicleChoice;
                        
                        if(vehicleChoice > 0 && vehicleChoice <= totalVehicles) {
                            int vehicleIndex = vehicleChoice - 1;
                            if(vehicleApprovalStatus[vehicleIndex]) {
                                displayVehicleDetails(vehicleIndex);
                                
                                cout << "\n1. Add to Favorites" << endl;
                                cout << "2. Contact Owner" << endl;
                                cout << "3. Back" << endl;
                                cout << "Choice: ";
                                
                                int actionChoice;
                                cin >> actionChoice;
                                
                                if(actionChoice == 1) {
                                    addToFavorites(userIndex, "VEH-" + to_string(vehicleChoice));
                                } else if(actionChoice == 2) {
                                    contactVehicleOwner(vehicleIndex);
                                }
                            }
                        }
                    }
                }
                break;
            }
            case 2: {
                cout << "\n=== POST VEHICLE FOR SALE ===" << endl;
                string brand, model, location, vehicleNum;
                double price;
                int year;
                
                cout << "Enter vehicle brand: ";
                cin >> brand;
                cout << "Enter model: ";
                cin >> model;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter price (PKR): ";
                cin >> price;
                cout << "Enter location: ";
                cin >> location;
                cout << "Enter vehicle number: ";
                cin >> vehicleNum;
                
                Vehicle* newVehicle = new Vehicle(VehicleCategory::PASSENGER_CAR, brand + " " + model, price, year, location, brand, vehicleNum);
                marketplace->addVehicle(newVehicle);
                
                // Store vehicle and ownership info
                allVehicles[totalVehicles] = newVehicle;
                vehicleOwners[totalVehicles] = currentUser->getName();
                
                // Add to approval system
                vehicleApprovalStatus[totalVehicles] = false;  // Pending approval
                totalVehicles++;
                
                Seller* userSeller = new Seller();
                userSeller->postAd(newVehicle);
                
                cout << "Vehicle posted successfully! Pending admin approval." << endl;
                break;
            }
            case 3: {
                cout << "\n=== AUTO PARTS STORE ===" << endl;
                for(int i = 0; i < partsCount; i++) {
                    cout << (i+1) << ". ";
                    autoparts[i]->displayPartInfo();
                    cout << "---" << endl;
                }
                
                cout << "Enter part number to buy (1-" << partsCount << ") or -1 to go back: ";
                int partChoice;
                cin >> partChoice;
                
                if(partChoice == -1) {
                    break;
                }
                
                if(partChoice >= 1 && partChoice <= partsCount) {
                    cout << "Enter quantity: ";
                    int quantity;
                    cin >> quantity;
                    
                    pakwheelsFinance->processAutoPartsSale(autoparts[partChoice-1], quantity);
                }
                break;
            }
            case 4: {
                cout << "\n=== USER PROFILE ===" << endl;
                currentUser->showDashboard();
                break;
            }
            case 5: {
                cout << "\n=== MY VEHICLE LISTINGS ===" << endl;
                cout << "Displaying vehicles posted by " << currentUser->getName() << endl;
                break;
            }
            case 6: {
                cout << "\n=== SEND MESSAGE ===" << endl;
                string recipient, messageText;
                cout << "Enter recipient username: ";
                cin >> recipient;
                cout << "Enter message: ";
                cin.ignore();
                getline(cin, messageText);
                
                Message* newMsg = new Message(currentUser->getName(), recipient, messageText);
                newMsg->displayMessage();
                cout << "Message sent successfully!" << endl;
                break;
            }
            case 7: {
                cout << "\n=== VEHICLE VALUATION ===" << endl;
                string brand, model;
                int year;
                cout << "Enter brand: ";
                cin >> brand;
                cout << "Enter model: ";
                cin >> model;
                cout << "Enter year: ";
                cin >> year;
                
                cout << "Estimated market value calculation..." << endl;
                cout << "Based on " << brand << " " << model << " " << year << endl;
                cout << "Estimated value: PKR 2,200,000 (sample calculation)" << endl;
                break;
            }
            case 8: {
                showFavorites(userIndex);
                if(favoriteCount[userIndex] > 0) {
                    cout << "Enter favorite number to view details (or -1 to go back): ";
                    int favChoice;
                    cin >> favChoice;
                    
                    if(favChoice > 0 && favChoice <= favoriteCount[userIndex]) {
                        cout << "Viewing details for: " << userFavorites[userIndex][favChoice-1] << endl;
                    }
                }
                break;
            }
            case 9:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 9);
}

void showAdminMenu() {
    int choice;
    do {
        cout << "\n=== ADMIN DASHBOARD ===" << endl;
        cout << "1. View All Vehicles (Approve/Reject)" << endl;
        cout << "2. View All Users" << endl;
        cout << "3. View Revenue Report" << endl;
        cout << "4. Manage Auto Parts Inventory" << endl;
        cout << "5. System Statistics" << endl;
        cout << "6. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                cout << "\n=== VEHICLE APPROVAL SYSTEM ===" << endl;
                cout << "Pending Vehicles for Approval:" << endl;
                
                bool hasPending = false;
                for(int i = 0; i < totalVehicles; i++) {
                    if(!vehicleApprovalStatus[i]) {
                        cout << "\n" << (i+1) << ". " << allVehicles[i]->getSpecificType() << endl;
                        cout << "   Brand: " << allVehicles[i]->getManufacturer() << endl;
                        cout << "   Price: PKR " << allVehicles[i]->getPrice() << endl;
                        cout << "   Year: " << allVehicles[i]->getModelYear() << endl;
                        cout << "   Owner: " << vehicleOwners[i] << endl;
                        cout << "   Status: PENDING APPROVAL" << endl;
                        cout << "   -------------------------" << endl;
                        hasPending = true;
                    }
                }
                
                if(!hasPending) {
                    cout << "No vehicles pending approval." << endl;
                    break;
                }
                
                cout << "\nEnter vehicle number to approve/reject (or -1 to go back): ";
                int vehicleChoice;
                cin >> vehicleChoice;
                
                if(vehicleChoice == -1) {
                    break;
                }
                
                if(vehicleChoice >= 1 && vehicleChoice <= totalVehicles) {
                    if(!vehicleApprovalStatus[vehicleChoice-1]) {
                        displayVehicleDetails(vehicleChoice-1);
                        cout << "\n1. APPROVE Vehicle" << endl;
                        cout << "2. REJECT Vehicle" << endl;
                        cout << "3. Back" << endl;
                        cout << "Enter choice: ";
                        
                        int approvalChoice;
                        cin >> approvalChoice;
                        
                        if(approvalChoice == 1) {
                            vehicleApprovalStatus[vehicleChoice-1] = true;
                            cout << "Vehicle #" << vehicleChoice << " APPROVED successfully!" << endl;
                        } else if(approvalChoice == 2) {
                            cout << "Vehicle #" << vehicleChoice << " REJECTED!" << endl;
                        }
                    } else {
                        cout << "Vehicle already approved!" << endl;
                    }
                }
                break;
            }
            case 2: {
                cout << "\n=== USER MANAGEMENT ===" << endl;
                for(int i = 0; i < userCount; i++) {
                    cout << (i+1) << ". " << users[i]->getName() << " - User ID: " << (i+1) << endl;
                }
                break;
            }
            case 3: {
                cout << "\n=== REVENUE REPORT ===" << endl;
                pakwheelsFinance->generateRevenueReport();
                break;
            }
            case 4: {
                cout << "\n=== INVENTORY MANAGEMENT ===" << endl;
                for(int i = 0; i < partsCount; i++) {
                    autoparts[i]->displayPartInfo();
                    cout << "---" << endl;
                }
                
                cout << "Enter part number to restock (1-" << partsCount << ") or -1 to view only: ";
                int partChoice;
                cin >> partChoice;
                
                if(partChoice == -1) {
                    cout << "Viewing inventory only - no changes made." << endl;
                    break;
                }
                
                if(partChoice >= 1 && partChoice <= partsCount) {
                    cout << "Enter restock quantity: ";
                    int quantity;
                    cin >> quantity;
                    autoparts[partChoice-1]->restockPart(quantity);
                }
                break;
            }
            case 5: {
                cout << "\n=== SYSTEM STATISTICS ===" << endl;
                marketplace->displayStatistics();
                cout << "Total Users: " << userCount << endl;
                cout << "Total Auto Parts: " << partsCount << endl;
                
                // Show approval statistics
                int approvedCount = 0, pendingCount = 0;
                for(int i = 0; i < totalVehicles; i++) {
                    if(vehicleApprovalStatus[i]) approvedCount++;
                    else pendingCount++;
                }
                cout << "Approved Vehicles: " << approvedCount << endl;
                cout << "Pending Approval: " << pendingCount << endl;
                break;
            }
            case 6:
                cout << "Admin logging out..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 6);
}

void showInspectorMenu() {
    int choice;
    do {
        cout << "\n=== INSPECTOR DASHBOARD ===" << endl;
        cout << "1. View Pending Inspections" << endl;
        cout << "2. Inspect Vehicle" << endl;
        cout << "3. View Inspection History" << endl;
        cout << "4. Generate Inspection Report" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                cout << "\n=== PENDING INSPECTIONS ===" << endl;
                cout << "Vehicles pending inspection displayed." << endl;
                break;
            }
            case 2: {
                cout << "\n=== VEHICLE INSPECTION ===" << endl;
                string vehicleNum;
                cout << "Enter vehicle number to inspect: ";
                cin >> vehicleNum;
                cout << "Inspecting vehicle: " << vehicleNum << endl;
                cout << "Inspection completed successfully!" << endl;
                
                pakwheelsFinance->addInspectionRevenue(3000.0);
                break;
            }
            case 3: {
                cout << "\n=== INSPECTION HISTORY ===" << endl;
                systemInspector->showDashboard();
                break;
            }
            case 4: {
                cout << "\n=== GENERATE INSPECTION REPORT ===" << endl;
                cout << "Comprehensive inspection report generated." << endl;
                cout << "Total inspections completed: 15" << endl;
                cout << "Revenue generated: PKR 45,000" << endl;
                break;
            }
            case 5:
                cout << "Inspector logging out..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 5);
}

void registerNewUser() {
    cout << "\n=== USER REGISTRATION ===" << endl;
    string username, password, phone;
    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter phone number: ";
    cin >> phone;
    
    if(userCount < 10) {
        users[userCount] = new User(username, password, phone);
        userCount++;
        cout << "Registration successful! You can now login." << endl;
    } else {
        cout << "Maximum user limit reached!" << endl;
    }
}

void cleanupSystem() {
    cout << "\n=== SYSTEM CLEANUP ===" << endl;
    
    for(int i = 0; i < userCount; i++) {
        delete users[i];
    }
    
    for(int i = 0; i < partsCount; i++) {
        delete autoparts[i];
    }
    
    delete marketplace;
    delete pakwheelsFinance;
    if(systemAdmin) delete systemAdmin;
    delete systemInspector;
    
    cout << "System cleanup completed!" << endl;
}

int main() {
    cout << "=== WELCOME TO PAKWHEELS MARKETPLACE ===" << endl;
    
    initializeSystem();
    
    int mainChoice;
    do {
        showMainMenu();
        cin >> mainChoice;
        
        switch(mainChoice) {
            case 1: {
                cout << "\n=== USER LOGIN ===" << endl;
                string username, password;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                
                User* currentUser = authenticateUser(username, password);
                if(currentUser != nullptr) {
                    cout << "Login successful! Welcome " << username << endl;
                    showUserMenu(currentUser);
                } else {
                    cout << "Invalid credentials! Please try again." << endl;
                }
                break;
            }
            case 2: {
                cout << "\n=== ADMIN LOGIN ===" << endl;
                string username, password;
                cout << "Admin Username: ";
                cin >> username;
                cout << "Admin Password: ";
                cin >> password;
                
                if(authenticateAdmin(username, password)) {
                    cout << "Admin login successful!" << endl;
                    showAdminMenu();
                } else {
                    cout << "Invalid admin credentials!" << endl;
                }
                break;
            }
            case 3: {
                cout << "\n=== INSPECTOR LOGIN ===" << endl;
                string username, password;
                cout << "Inspector Username: ";
                cin >> username;
                cout << "Inspector Password: ";
                cin >> password;
                
                if(authenticateInspector(username, password)) {
                    cout << "Inspector login successful!" << endl;
                    showInspectorMenu();
                } else {
                    cout << "Invalid inspector credentials!" << endl;
                }
                break;
            }
            case 4: {
                registerNewUser();
                break;
            }
            case 5: {
                cout << "\n=== SYSTEM STATISTICS ===" << endl;
                marketplace->displayStatistics();
                pakwheelsFinance->generateRevenueReport();
                break;
            }
            case 6: {
                cout << "\nThank you for using PakWheels Marketplace!" << endl;
                cout << "Exiting system..." << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(mainChoice != 6);
    
    cleanupSystem();
    return 0;
}