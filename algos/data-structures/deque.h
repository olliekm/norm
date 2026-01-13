#ifndef DEQUE_H
#define DEQUE_H

#include "linkedlist.h"

struct Deque {
    int size;
    struct LinkedList ll;
};

struct Deque* initDeque();
void pushFront(struct Deque* dq, int data);
void pushBack(struct Deque* dq, int data);
int popFront(struct Deque* dq);
int popBack(struct Deque* dq);
int peekFront(struct Deque* dq);
int peekBack(struct Deque* dq);
int isEmpty(struct Deque* dq);
int getSize(struct Deque* dq);
#endif // DEQUE_H
