#include "08_deque.h"
#include <cstdio>

void InitDeque(Deque *D)
{
    D->front = 0;
    D->rear = 0;
    D->size = 0;
}

bool PushFront(Deque *D, DElemType e)
{
    if (D->size >= DEQUE_MAXSIZE)
        return false;
    D->front = (D->front - 1 + DEQUE_MAXSIZE) % DEQUE_MAXSIZE;
    D->data[D->front] = e;
    D->size++;
    return true;
}

bool PushBack(Deque *D, DElemType e)
{
    if (D->size >= DEQUE_MAXSIZE)
        return false;
    D->data[D->rear] = e;
    D->rear = (D->rear + 1) % DEQUE_MAXSIZE;
    D->size++;
    return true;
}

bool PopFront(Deque *D, DElemType *e)
{
    if (D->size == 0)
        return false;
    *e = D->data[D->front];
    D->front = (D->front + 1) % DEQUE_MAXSIZE;
    D->size--;
    return true;
}

bool PopBack(Deque *D, DElemType *e)
{
    if (D->size == 0)
        return false;
    D->rear = (D->rear - 1 + DEQUE_MAXSIZE) % DEQUE_MAXSIZE;
    *e = D->data[D->rear];
    D->size--;
    return true;
}

bool GetFront(const Deque *D, DElemType *e)
{
    if (D->size == 0)
        return false;
    *e = D->data[D->front];
    return true;
}

bool GetBack(const Deque *D, DElemType *e)
{
    if (D->size == 0)
        return false;
    *e = D->data[(D->rear - 1 + DEQUE_MAXSIZE) % DEQUE_MAXSIZE];
    return true;
}

bool DequeEmpty(const Deque *D)
{
    return D->size == 0;
}

int DequeSize(const Deque *D)
{
    return D->size;
}

void DequeTraverse(const Deque *D)
{
    if (D->size == 0) {
        printf("双端队列为空\n");
        return;
    }
    printf("双端队列元素(从前到后): ");
    int idx = D->front;
    for (int i = 0; i < D->size; i++) {
        printf("%d ", D->data[idx]);
        idx = (idx + 1) % DEQUE_MAXSIZE;
    }
    printf("\n");
}
