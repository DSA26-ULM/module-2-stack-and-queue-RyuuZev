#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    if (isEmpty(q)) return false;
    
    const int* next_rear;
    
    if (q->rear == &(q->data[MAX - 1])) {
        next_rear = &(q->data[0]); 
    } else {
        next_rear = q->rear + 1; 
    }
    
    return next_rear == q->front;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("Queue Overflow: Antrean penuh");
    }
    
    if (isEmpty(q)) {
        q->front = &(q->data[0]);
        q->rear = &(q->data[0]);
    } else {
        if (q->rear == &(q->data[MAX - 1])) {
            q->rear = &(q->data[0]);
        } else {
            q->rear++;
        }
    }
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue Underflow: Antrean kosong");
    }
    
    if (q->front == q->rear) {
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        if (q->front == &(q->data[MAX - 1])) {
            q->front = &(q->data[0]);
        } else {
            q->front++;
        }
    }
}
int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue is Empty");
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue is Empty");
    }
    return *(q->rear);
}