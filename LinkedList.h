#pragma once

// taken from the instructions
// variables are named differently
struct Customer {
  int id;
  int numItems;
  int enterTime;
  int exitTime;
};
struct Node {
  Customer data;
  Node *nextPtr;
};
class LinkedList {
private:
  Node *headPtr;
  static int listCount;

public:
  LinkedList();
  void addElement(Customer data);
  Customer peek();
  void delElement();
  void printList();
  bool listIsEmpty();
  static int getListCount();
};