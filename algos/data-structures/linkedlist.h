#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

struct Node* createNode(int data);
void printList(struct LinkedList* ll);
void initList(struct LinkedList* ll);
void appendNode(struct LinkedList* ll, int data);
void freeList(struct LinkedList* ll);
#endif // LINKEDLIST_H
