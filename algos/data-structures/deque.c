#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "deque.h"

struct Deque* initDeque() {
    struct Deque* newDeque = (struct Deque*)malloc(sizeof(struct Deque));
    newDeque->size = 0;
    initList(&newDeque->ll);
    return newDeque;
}

void pushFront(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (dq->ll.head == NULL) {
        dq->ll.head = newNode;
        dq->ll.tail = newNode;
    } else {
        newNode->next = dq->ll.head;
        dq->ll.head->prev = newNode;
        dq->ll.head = newNode;
    }
    dq->size++;
}

void pushBack(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (dq->ll.head == NULL) {
        dq->ll.head = newNode;
        dq->ll.tail = newNode;
    } else {
        dq->ll.tail->next = newNode;   
        newNode->prev = dq->ll.tail;
        dq->ll.tail = newNode;
    }
    dq->size++;
}

int popFront(struct Deque* dq) {
    if (dq->size == 0) {
        fprintf(stderr, "Error: Cannot pop from empty deque\n");
        return INT_MIN;
    }

    struct Node* popped = dq->ll.head;
    int data = popped->data;

    dq->ll.head = dq->ll.head->next;
    if (dq->ll.head != NULL) {
        dq->ll.head->prev = NULL;
    } else {
        dq->ll.tail = NULL;
    }
    
    free(popped);
    dq->size--;
    return data;
}

int popBack(struct Deque* dq) {
    if (dq->size == 0) {
        fprintf(stderr, "Error: Cannot pop from empty deque\n");
        return INT_MIN;
    }

    struct Node* popped = dq->ll.tail;
    int data = popped->data;

    dq->ll.tail = dq->ll.tail->prev;
    if (dq->ll.tail != NULL) {
        dq->ll.tail->next = NULL;
    } else {
        dq->ll.head = NULL;
    }
    
    free(popped);
    dq->size--;
    return data;
}

int peekFront(struct Deque* dq) {
    if (dq->size == 0) {
        fprintf(stderr, "Error: Empty deque\n");
        return INT_MIN;
    }

    return dq->ll.head->data;
}

int peekBack(struct Deque* dq) {
    if (dq->size == 0) {
        fprintf(stderr, "Error: Empty deque\n");
        return INT_MIN;
    }

    return dq->ll.tail->data;
}

int isEmpty(struct Deque* dq) {
    return dq->size == 0;
}

int getSize(struct Deque* dq) {
    return dq->size;
}
