#include "LinkedList.h"
#include <iostream>

using namespace std;

int LinkedList::listCount = 0;
// constructor initializes an empty list
LinkedList::LinkedList() { headPtr = nullptr; }
// adds element to the list in sorted order by enterTime
void LinkedList::addElement(Customer newCart) {
  Node *newNode = new Node;
  newNode->data = newCart;
  newNode->nextPtr = nullptr;
  // set the new node as the head IF the list is empty
  if (headPtr == nullptr) {
    headPtr = newNode;
  } else {
    // find the next position of the new node
    Node *currentPtr = headPtr;
    Node *prevPtr = nullptr;
    while (currentPtr != nullptr &&
           currentPtr->data.enterTime < newNode->data.enterTime) {
      prevPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }
    if (prevPtr == nullptr) {
      // update headPtr if new node is the head
      newNode->nextPtr = headPtr;
      headPtr = newNode;
    } else {
      // insert the new node between the previous and current nodes
      prevPtr->nextPtr = newNode;
      newNode->nextPtr = currentPtr;
    }
  }
  listCount++; // +1 the count of nodes in the list
}
// return the data of the first element in the list (without removing it)
Customer LinkedList::peek() { return headPtr->data; }
// remove the first element from the list
void LinkedList::delElement() {
  if (headPtr != nullptr) {
    Node *tempPtr = headPtr;
    headPtr = headPtr->nextPtr;
    delete tempPtr;
    listCount--; // -1 the count of nodes in the list
  }
}

// check if the list is empty
bool LinkedList::listIsEmpty() { return headPtr == nullptr; }
int LinkedList::getListCount() { return listCount; }