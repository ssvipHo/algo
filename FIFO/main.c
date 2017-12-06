//
// Created by freepark on 2017/12/6.
//

#include <stdio.h>
#include <string.h>
#include "queue.h"

char * u_gets(char * st, int size);
int main(){
    People item;
    Queue pQueue;
    InitQueue(&pQueue);

    if (!QueueIsFull(&pQueue)){
        while (u_gets(item.name, NAME_LEN) != NULL && item.name[0] != '\0'){
            puts("Enter the id:");
            scanf("%d", &item.id);
            while (getchar() != '\n'){
                continue;
            }
            if (AddQueue(item, &pQueue)){
                puts("Element inserted");
            }
        }
    }

    int count = 1;
    Node * pNode;
    pNode = pQueue.head;
    while (true){
        printf("%d name: %s\n", count, pNode->item.name);
        pNode = pNode->next;
        count++;
        if (pNode == NULL){
            break;
        }
    }

    EmptyQueue(&pQueue);

    return 0;
}

char * u_gets(char * st, int size){
    puts("Enter the name of people:");
    char * cItem;
    cItem = fgets(st, size, stdin);

    if (cItem) {
        char * find;
        find = strchr(st, '\n');
        if (find){
            *find = '\0';
        }else{
            while (getchar() != '\n'){
                continue;
            }
        }
    }

    return cItem;
}