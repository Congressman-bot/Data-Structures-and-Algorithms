/*
$ A program to demonstrate the implementation of queues in C 
$ Written by Alex Mwangi
$ BSE 2.1 Data Structures and Algorithms Class
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Enqueue an element
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Peek at the front element
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

// Main function to demonstrate queue operations
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("Dequeued: %d\n", dequeue(q)); // Output: 10
    printf("Front element: %d\n", peek(q)); // Output: 20

    free(q);
    return 0;
}

