#include <iostream>
#include <string>
using namespace std;


class Restaurant;
class Order;

class Customer {
private:
    string name;

public:
    Customer(string customerName) : name(customerName) {}
    
    string getName() const {
        return name;
    }
    
    Order* placeOrder(Restaurant* restaurant, string food);
};

class Restaurant {
private:
    string name;

public:
    Restaurant(string restaurantName) : name(restaurantName) {}
    
    string getName() const {
        return name;
    }
    
    void takeOrder(Order* order) {
        cout << "restaurant " << name << " received an order!" << endl;
    }
};

class Order {
private:
    static int nextId;
    int id;
    string customer;
    string restaurant;
    string foodItem;

public:
    Order(Customer* c, Restaurant* r, string food) {
        id = ++nextId;
        customer = c->getName();
        restaurant = r->getName();
        foodItem = food;
    }
    
    void show() const {
        cout << "details:" << endl;
        cout << "id: " << id << endl;
        cout << "customer: " << customer << endl;
        cout << "restaurant: " << restaurant << endl;
        cout << "food: " << foodItem << endl;
       
    }
    
    int getId() const {
        return id;
    }
};


int Order::nextId = 0;


Order* Customer::placeOrder(Restaurant* restaurant, string food) {
    cout << name << " is place for " << food << " from " << restaurant->getName() << endl;
    Order* order = new Order(this, restaurant, food);
    restaurant->takeOrder(order);
    return order;
}

int main() {

    Customer customer1("Ali");
    Customer customer2("Adeel");
    
    Restaurant restaurant1("Pizza Palace");
    Restaurant restaurant2("Burger Barn");
    
   
    cout << "Customers: " << customer1.getName() << ", " << customer2.getName() << endl;
    cout << "Restaurants: " << restaurant1.getName() << ", " << restaurant2.getName() << endl;
    cout << endl;
    
    Order* order1 = customer1.placeOrder(&restaurant1, "Margherita Pizza");
    order1->show();
    
    Order* order2 = customer2.placeOrder(&restaurant2, "Cheeseburger");
    order2->show();
    
    Order* order3 = customer1.placeOrder(&restaurant2, "French Fries");
    order3->show();
    
    
    delete order1;
    delete order2;
    delete order3;
    
    return 0;
}