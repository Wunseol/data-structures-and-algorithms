#include "circular_queue.h"
#include <stdio.h>

void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

bool QueueEmpty(const SqQueue *Q)
{
    return Q->front == Q->rear;
}

bool QueueFull(const SqQueue *Q)
{
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

int QueueLength(const SqQueue *Q)
{
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

bool EnQueue(SqQueue *Q, QElemType e)
{
    if (QueueFull(Q))
        return false;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue *Q, QElemType *e)
{
    if (QueueEmpty(Q))
        return false;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return true;
}

bool GetHead(const SqQueue *Q, QElemType *e)
{
    if (QueueEmpty(Q))
        return false;
    *e = Q->data[Q->front];
    return true;
}

void QueueTraverse(const SqQueue *Q)
{
    if (QueueEmpty(Q)) {
        printf("队列为空\n");
        return;
    }
    printf("队列元素(从队首到队尾): ");
    int i = Q->front;
    while (i != Q->rear) {
        printf("%d ", Q->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}
