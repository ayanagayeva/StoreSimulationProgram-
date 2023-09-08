// Ayan Agayeva
 
#include "LinkedList.h"
#include "Queue.h"
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  // seed the random number generator
  srand(time(0));
  // initialize the checkout lines
  int numLines = 0;
  while (numLines < 1 || numLines > 10) {
    cout << "\nEnter the number of checkout lines (1-10): ";
    cin >> numLines; // store the user's wanted amount for checkoutlines
    if (numLines < 1 || numLines > 10) { // loop this until the input is 1-10
      cout << "\nInvalid input. Please enter a number between 1 and 10.\n";
    }
  }
  vector<queue<Customer>> checkoutLines(numLines); // initialize the vector to hold thr customer's objects
      // initialize the store
      LinkedList shoppers;
  int maxLineLength = 0;
  // assigning and declaring the variables
  int customerCount = 0;
  int totalItemsProcessed = 0;
  int totalWaitTime = 0;
  int totalIdleTime = 0;
  int totalOverTime = 0;
  int numItems = 0;
  int closingTime = 720; // 12 hour shift
  // Run the simulation for each checkout line
  for (int line = 0; line < numLines; line++) {
    // Reset statistics for each checkout line
    customerCount = 0;
    totalItemsProcessed = 0;
    totalWaitTime = 0;
    totalIdleTime = 0;
    totalOverTime = 0;
    maxLineLength = 0;
    // simulate from beginning to end of the store's hours
    for (int time = 0; time <= closingTime; time++) {
      // from instructions
      // generate random number of customers + their items
      int numCustomers = 0;
      int numItems = 0;
      int prob = rand() % 10 + 1;
      if (prob <= 4) {
        numCustomers = 1;
        numItems = rand() % 3 + 1;
      } else if (prob <= 7) {
        numCustomers = 2;
        numItems = rand() % 3 + 1;
      } else if (prob <= 9) {
        numCustomers = 2;
        numItems = rand() % 6 + 1;
      } else {
        numCustomers = 3;
        numItems = rand() % 6 + 1;
      }
      totalItemsProcessed +=
          numItems * numCustomers; // adds the product of num items + num customers
          // add customers to the linked list
          for (int i = 1; i <= numCustomers; i++) {
        Customer customer;
        customer.id = ++customerCount;
        customer.numItems = numItems;
        customer.enterTime = time;
        customer.exitTime =
            time + (rand() % 10 + 10) * numItems; // determines a random time period for each shopper that it takes for them to checkout given their numItems
shoppers.addElement(customer);
      }
      // update the checkout lines
      for (int i = 0; i < numLines; i++) {
        // look if the customer at front of line is ready to leave
        if (!checkoutLines[i].empty() &&
            checkoutLines[i].front().exitTime <= time) {
          Customer customer = checkoutLines[i].front();
          checkoutLines[i].pop();
          totalWaitTime += time - customer.enterTime;
          if (checkoutLines[i].empty()) {
            totalIdleTime++;
          }
        }
        // look if there are customers ready to enter the checkout line
        while (!shoppers.listIsEmpty() && shoppers.peek().enterTime <= time) {
          // find the shortest checkout line
          int shortestLine = 0;
          for (int j = 1; j < numLines; j++) {
            if (checkoutLines[j].size() < checkoutLines[shortestLine].size()) {
              shortestLine = j;
            }
          }
          // add the customer to the shortest checkout line
          Customer customer = shoppers.peek();
          customer.enterTime = time;
          checkoutLines[shortestLine].push(customer);
          shoppers.delElement();
        }
      }
      // check for the max line length
      for (int i = 0; i < numLines; i++) {
        if (checkoutLines[i].size() > maxLineLength) {
          maxLineLength = checkoutLines[i].size();
        }
      }
      // check for overtime in the checkout lines
      if (time >= closingTime) {
        // Process the remaining customers in the shoppers list
        totalOverTime += shoppers.getListCount();
        while (!shoppers.listIsEmpty()) {
          shoppers.delElement();
        }
        // Process the remaining customers in the checkout lines
        for (int i = 0; i < numLines; i++) {
          while (!checkoutLines[i].empty()) {
            totalOverTime++;
            checkoutLines[i].pop();
          }
        }
        // update the checkout lines
        for (int i = 0; i < numLines; i++) {
          bool lineWasEmpty = checkoutLines[i].empty();
          // check if the customer at the front of line is ready to leave
          if (!checkoutLines[i].empty() &&
              checkoutLines[i].front().exitTime <= time) {
            Customer customer = checkoutLines[i].front();
            checkoutLines[i].pop(); // removes the customer at the front of the
                                    // queue after the checkout has been compelted and the customer has left totalWaitTime +=
                time - customer.enterTime;
            if (checkoutLines[i].empty()) {
              totalIdleTime += (time - customer.exitTime);
            }
          }
          // check if there are shoppers ready to enter the checkout line
          while (!shoppers.listIsEmpty() && shoppers.peek().enterTime <= time) {
            // find the shortest checkout line
            int shortestLine = 0;
            for (int j = 1; j < numLines; j++) {
              if (checkoutLines[j].size() <
                  checkoutLines[shortestLine].size()) {
                shortestLine = j;
              }
            }
            // add the shopper to checkout line
            Customer customer = shoppers.peek();
            customer.enterTime =
                time; // records the time the customer entered the checkout line
            checkoutLines[shortestLine].push(customer);
            shoppers.delElement();
          }
          // check for idle time when checkout lines became empty and non empty
          if (lineWasEmpty && !checkoutLines[i].empty()) {
            totalIdleTime += (time - checkoutLines[i].front().enterTime);
          }
        }
        // exit the simulation loop when the day ends
        break;
      }
    }
    // print the stats for the day
    cout << "\n\nCHECKOUT LINE: " << line + 1 << endl;
    cout << "\n\tTotal Customers Helped: " << customerCount << endl;
    cout << "\n\tTotal Number of Items: " << totalItemsProcessed << endl;
    cout << "\n\tMaximum line length: " << maxLineLength << endl;
    cout << "\n\tTotal Idle Time: " << totalIdleTime << " minutes" << endl;
    cout << "\n\tTotal Over Time: " << totalOverTime << " minutes" << endl;
  }
  return 0;
}