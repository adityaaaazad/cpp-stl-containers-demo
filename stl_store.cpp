#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Product{
    int productId;
    string name;
    string category;
};

struct Order{
    int orderId;
    int productId;
    int quantity;
    string customerId;
    time_t orderDate;
};

int main(){

    vector<Product> products = {
        {2, "SmartPhone", "Electronics"},
        {1, "Laptop", "Electronics"},
        {3, "Coffee Maker", "Kitchen"},
        {4, "Blender", "Kitchen"},
        {5, "Study Lamp", "Home"},
    };

    deque<string> recentCustomers = {"C01", "C02", "C03"};

    recentCustomers.push_back("C04");
    recentCustomers.push_front("C05");

    list<Order> orderHistory;

    orderHistory.push_back({1, 1, 1, "C01", time(0)});
    orderHistory.push_back({2, 3, 3, "C02", time(0)});
    orderHistory.push_back({3, 3, 1, "C03", time(0)});

    set<string> categories;
    for(const auto &product: products){
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {1, 10},
        {2, 5},
        {3, 24},
        {4, 55},
        {5, 15},
    };

    multimap<string, Order> customerOrders;
    for(const auto &order: orderHistory){
        customerOrders.insert({order.customerId,order});
    }

    unordered_map<string, string> customerData = {
        {"C01", "Luffy"},
        {"C02", "Ronny"},
        {"C03", "Eddie"},
        {"C04", "Max"},
        {"C05", "Alice"},
    };

    unordered_set<int> uniqueProductIds; 
    for(const auto &product: products){
        uniqueProductIds.insert(product.productId);
    }



    //Displaying-----

    cout << "Product Stock: " << endl;
    for(const auto &item : productStock){
        cout << "Product ID: " << item.first << ", Stock : " << item.second << endl;
    }

    cout << "\nUnique Product IDs: ";
    for(const auto &id : uniqueProductIds){
        cout << id << " ";
    }

    cout << "\nRecent Customers: ";
    for(const auto &customer : recentCustomers){
        cout << customer << " ";
    }

    cout << "\nCustomer Orders: " << endl;
    for(const auto &entry : customerOrders){
        cout << "Customer ID: " << entry.first << ", Order ID: " << entry.second.orderId << ", Product ID: " << entry.second.productId << ", Quantity: " << entry.second.quantity << ", Order Date: " << ctime(&entry.second.orderDate);
    }




    return 0;
}