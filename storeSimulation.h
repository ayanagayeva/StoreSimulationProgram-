#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "LinkedList.h"
using namespace std;

struct CheckoutLine { // represents a checkout line
    int id;
    int numCustomersServed;
    int totalCheckoutTime;
    int currentCustomerNumItems;
    int currentCustomerEnterTime;
    queue<Customer> customers;
};

// class to simulate the grocery store 
class StoreSimulation { 
private:
    int numCheckoutLines;
    vector<CheckoutLine> checkoutLines;
    LinkedList customers;
    int totalIdleTime;
    int totalOverTime;
    int totalCustomers;
    int totalItems;
    int maxLineLength;

    void addCustomer(); // adding a new customer to the line
    void processCheckoutLines(); // processing the checkout lines
    int chooseCheckoutLine(); // choosing the checkout line with the shortes queue

public:
// constructor
    StoreSimulation(int numCheckoutLines);
// getter methods
    int getIdleTime(); // total idle time
    int getTotalOverTime(); // total over time
    int getTotalCustomers(); // total num customers
    int getTotalItemsProcessed(); // total num items processed
    int getMaxLineLength(); // max length of a checkout line
// simulation methods
    void runSimulation();
    Customer generateNewCustomer();
    int generateNewCustomerArrivalTime();
// printing stats
    void printResults();
};

