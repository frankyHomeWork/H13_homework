#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


typedef struct {
    Node *first;    
    Node *rear;    
    int size;    
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue myCircularQueue;
    myCircularQueue.first = NULL;
    myCircularQueue.rear = NULL;
    myCircularQueue.size = NULL;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  
}

void myCircularQueueFree(MyCircularQueue* obj) {
    
}
int main() {
    
    
    return 0;
}