//
// Created by freepark on 2017/12/6.
//

#ifndef _QUEUE_H
#define _QUEUE_H
// Define the relevant data types and function prototypes

#include <stdbool.h>

#define QUEUE_LEN 3 // The queue can only have 10 elements
#define NAME_LEN 10

typedef struct people{
    unsigned int id;
    char name[NAME_LEN];
} People;

typedef struct node {
    People item;
    struct node * next;
} Node;

struct queue{
    Node * head;
    Node * end;
    int hits;
};

typedef struct queue Queue;

// Define func
void InitQueue(Queue * pQueue); // initialize the queue
bool AddQueue(People item, Queue * pQueue);  // insert a new node
bool RemoveQueue(Queue * pQueue); // del a old node
int GetQueueNum(const Queue * pQueue); // get the number of queue
void EmptyQueue(Queue * pQueue); // empty queue
bool QueueIsFull(const Queue * pQueue);
bool QueueIsEmpty(const Queue * pQueue);

#endif