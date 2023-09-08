#include "Queue.h"
#include <iostream>

using namespace std;
// taken from the instrucions
Queue::Queue() { // constructor that initializes the front and rear pointers to
  // null.
  front = nullptr;
  rear = nullptr;
}
void Queue::enQueue(queueNodeData newData) {
  queueNode *newNode = new queueNode; // create a new node
  newNode->data = newData;            // add new node to the back of the queue
  newNode->nextPtr = nullptr;
  if (front == nullptr) {
    front = newNode;
    rear = newNode;
  } else {
    rear->nextPtr = newNode;
    rear = newNode;
  }
}