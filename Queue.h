#pragma once
#include <vector>

// taken from the instructions
struct queueNodeData {
    int timeAvailable;
    int itemCount;
};

struct queueNode {
    queueNodeData data;
    queueNode* nextPtr;
};

struct queueData {
    int queueCount = 0;            // current queue length (set to 0)
    int totalIdleTime = 0;        // if queueCount == 0, this is incremented
    int totalOverTime = 0;        // increment if current time > 720 & there are people in line
    int maxQueueLength = 0;       // if current queueCount > maxQueueLength then set to 0  
    int currItems = 0;            // update as shoppers are added + removed from queue
    int totalItems = 0;           // storing purchased
};

class Queue {
public:
    Queue();
    void enQueue(queueNodeData);
    queueNodeData deQueue();
    queueNodeData peek();
    bool queueEmpty();
    void printQueue();

private:
    queueNode* front;
    queueNode* rear;
    queueData queueStats;   // queue data statistics
};


