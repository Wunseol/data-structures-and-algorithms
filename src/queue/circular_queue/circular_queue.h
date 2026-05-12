#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

#define MAXSIZE 100

typedef int QElemType;

typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue *Q);
bool QueueEmpty(const SqQueue *Q);
bool QueueFull(const SqQueue *Q);
int QueueLength(const SqQueue *Q);
bool EnQueue(SqQueue *Q, QElemType e);
bool DeQueue(SqQueue *Q, QElemType *e);
bool GetHead(const SqQueue *Q, QElemType *e);
void QueueTraverse(const SqQueue *Q);

#endif
