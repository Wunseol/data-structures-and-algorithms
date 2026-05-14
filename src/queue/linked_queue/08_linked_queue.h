#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdbool.h>

typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} LinkQueue;

void InitQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);
bool QueueEmpty(const LinkQueue *Q);
bool EnQueue(LinkQueue *Q, QElemType e);
bool DeQueue(LinkQueue *Q, QElemType *e);
bool GetHead(const LinkQueue *Q, QElemType *e);
int QueueLength(const LinkQueue *Q);
void QueueTraverse(const LinkQueue *Q);

#endif
