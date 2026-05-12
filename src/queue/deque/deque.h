#ifndef DEQUE_H
#define DEQUE_H

#define DEQUE_MAXSIZE 100

typedef int DElemType;

typedef struct {
    DElemType data[DEQUE_MAXSIZE];
    int front;
    int rear;
    int size;
} Deque;

void InitDeque(Deque *D);
bool PushFront(Deque *D, DElemType e);
bool PushBack(Deque *D, DElemType e);
bool PopFront(Deque *D, DElemType *e);
bool PopBack(Deque *D, DElemType *e);
bool GetFront(const Deque *D, DElemType *e);
bool GetBack(const Deque *D, DElemType *e);
bool DequeEmpty(const Deque *D);
int DequeSize(const Deque *D);
void DequeTraverse(const Deque *D);

#endif
