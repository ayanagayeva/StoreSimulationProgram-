#include "storeSimulation.h"
#include "LinkedList.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int StoreSimulation::chooseCheckoutLine() {
    // choosing the checkout line with the shortest queue
    int shortestLineIndex = 0;
    int shortestLineLength = checkoutLines[0].customers.size(); // setting shortest line to he size of the customer in the queue
    for (int i = 1; i < numCheckoutLines; i++) {
        int currentLineLength = checkoutLines[i].customers.size(); // get the size of he customers in the current checkout line
        if (currentLineLength < shortestLineLength) {
            shortestLineIndex = i;
            shortestLineLength = currentLineLength; // assign to the shortest line
        }
    }
    return shortestLineIndex;
} 

 


 