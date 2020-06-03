// Leetcode - 622. Design Circular Queue
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
    int count;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    // Edit here...
    MyCircularQueue *myCircularQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    
    myCircularQueue->front = NULL;
    myCircularQueue->rear = NULL;
    myCircularQueue->size = k;
    myCircularQueue->count = 0;
    
    return myCircularQueue;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // Edit here...
    
    if(obj->count == 0) {
        return true;
    } else {
        return false;
    }
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // Edit here...
    if(obj->count == obj->size) {
        return true;
    } else {
        return false;
    }
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // Edit here...
    
    if( myCircularQueueIsFull(obj) ) {
        return false;
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    int count = obj->count;
    if(count == 0) {
        obj->front = newNode;
        
    } else if (count > 0 && obj->front != NULL) {
        Node *current = obj->front;
        
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    obj->count++;
    obj->rear = newNode;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // Edit here...
    
    if( myCircularQueueIsEmpty(obj) ) {
        return false;
    }
    if(obj->front == NULL) {
        return false;
    }
    
    int count = obj->count;
    if(count == 1) {
        
        free(obj->front);
        obj->front = NULL;
        obj->rear = NULL;
        obj->count = 0;
        
    } else if (count > 1) {
        
        Node *current = obj->front;
        Node *next_current = current->next;
        
        obj->front = next_current;
        free(current);
        obj->count--;
    }
    
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    // Edit here...
    
    if( myCircularQueueIsEmpty(obj) ) {
        return -1;
    } else {
        return obj->front->data;
    }
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    // Edit here...
    
    if( myCircularQueueIsEmpty(obj) ) {
        return -1;
    } else {
        return obj->rear->data;
    }
    
    
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free (obj);
}

int main() {
 
	MyCircularQueue* obj = myCircularQueueCreate(3);
	
	bool param_1 = myCircularQueueEnQueue(obj, 1);
	bool param_2 = myCircularQueueEnQueue(obj, 2);
	bool param_3 = myCircularQueueEnQueue(obj, 3);
	bool param_4 = myCircularQueueEnQueue(obj, 4);	
	int  param_5 = myCircularQueueRear(obj);
	bool param_6 = myCircularQueueIsFull(obj);
	bool param_7 = myCircularQueueDeQueue(obj);
	bool param_8 = myCircularQueueEnQueue(obj, 4);
	int  param_9 = myCircularQueueRear(obj);
	
	myCircularQueueFree(obj);
	
	(param_1 && param_2 && param_3 && !param_4 && param_5 == 3 && param_6 && param_7 && param_8 && param_9 == 4) ? printf("Correct\n") : printf("Error\n");
	
	return 0; 
}