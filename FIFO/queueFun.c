//
// Created by freepark on 2017/12/6.
//
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * init queue
 * @param pQueue
 */
void InitQueue(Queue * pQueue){
    pQueue->head = NULL;
    pQueue->end = NULL;
    pQueue->hits = 0;
}

/**
 * get the number of queue
 * @param pQueue
 * @return
 */
int GetQueueNum(const Queue * pQueue){
    return pQueue->hits;
}

/**
 * check that the queue is empty
 * @param pQueue
 * @return
 */
bool QueueIsEmpty(const Queue * pQueue){
    if (0 == pQueue->hits){
        return true;
    }

    return false;
}

/**
 * Check that the queue is full
 * @param pQueue
 * @return
 */
bool QueueIsFull(const Queue * pQueue){
    if (QUEUE_LEN == pQueue->hits){
        return true;
    }

    return false;
}

/**
 *
 * @param item
 * @param pQueue
 * @return
 */
bool AddQueue(People item, Queue * pQueue){

    Node * node1 = (Node *) malloc(sizeof(Node));

    if (node1 == NULL){
        fprintf(stderr, "malloc memory fail\n");
        exit(EXIT_FAILURE);
    }

    node1->item = item;
    node1->next = NULL;
    if (QueueIsEmpty(pQueue)){
        pQueue->head = node1;
        pQueue->end = node1;
        pQueue->hits = 1;
        return true;
    }
    RemoveQueue(pQueue);
    pQueue->end->next = node1;
    pQueue->end = node1;
    pQueue->hits++;
    return true;
}

bool RemoveQueue(Queue * pQueue){
    if (!QueueIsFull(pQueue)){
        return false;
    }

    // Move a pointer

    Node * removeNode = pQueue->head;
    pQueue->head = pQueue->head->next;

    free(removeNode);
    pQueue->hits--;
    return true;
}

void EmptyQueue(Queue * pQueue){
    Node * emptyNode;
    while (true){
        emptyNode = pQueue->head;
        pQueue->head = pQueue->head->next;
        free(emptyNode);

        if (pQueue->head == pQueue->end){
            free(pQueue->head);
            break;
        }
    }
}