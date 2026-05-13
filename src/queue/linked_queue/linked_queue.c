#include "linked_queue.h"
#include <stdio.h>
#include <stdlib.h>

void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
    if (!Q->front) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    Q->front->next = NULL;
}

void DestroyQueue(LinkQueue *Q)
{
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

bool QueueEmpty(const LinkQueue *Q)
{
    return Q->front == Q->rear;
}

bool EnQueue(LinkQueue *Q, QElemType e)
{
    QNode *s = (QNode *)malloc(sizeof(QNode));
    if (!s)
        return false;
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return true;
}

bool DeQueue(LinkQueue *Q, QElemType *e)
{
    if (QueueEmpty(Q))
        return false;
    QNode *p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}

bool GetHead(const LinkQueue *Q, QElemType *e)
{
    if (QueueEmpty(Q))
        return false;
    *e = Q->front->next->data;
    return true;
}

int QueueLength(const LinkQueue *Q)
{
    int len = 0;
    QNode *p = Q->front->next;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

void QueueTraverse(const LinkQueue *Q)
{
    if (QueueEmpty(Q)) {
        printf("队列为空\n");
        return;
    }
    printf("队列元素(从队首到队尾): ");
    QNode *p = Q->front->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
