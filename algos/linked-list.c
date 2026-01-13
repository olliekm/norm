// This is my implementation of a linked list in C

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(struct LinkedList* ll) {
    struct Node* current = ll->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void initList(struct LinkedList* ll) {
    ll->head = NULL;
    ll->tail = NULL;
}

void appendNode(struct LinkedList* ll, int data) {
    struct Node* newNode = createNode(data);
    if (ll->head == NULL) {
        ll->head = newNode;
        ll->tail = newNode;
    } else {
        ll->tail->next = newNode;
        ll->tail = newNode;
    }
}

void freeList(struct LinkedList* ll) {
    struct Node* current = ll->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    ll->head = NULL;
    ll->tail = NULL;
}
