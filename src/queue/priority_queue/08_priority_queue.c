#include "08_priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

static void swap(PQElemType *a, PQElemType *b)
{
    PQElemType temp = *a;
    *a = *b;
    *b = temp;
}

static void sift_up(PriorityQueue *pq, int i)
{
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->data[parent] < pq->data[i]) {
            swap(&pq->data[parent], &pq->data[i]);
            i = parent;
        } else {
            break;
        }
    }
}

static void sift_down(PriorityQueue *pq, int i)
{
    int n = pq->size;
    while (2 * i + 1 < n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < n && pq->data[left] > pq->data[largest])
            largest = left;
        if (right < n && pq->data[right] > pq->data[largest])
            largest = right;
        if (largest != i) {
            swap(&pq->data[i], &pq->data[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

PriorityQueue *PQCreate(int max_size)
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (pq == NULL) {
        printf("内存分配失败!\n");
        return NULL;
    }
    pq->data = (PQElemType *)malloc(max_size * sizeof(PQElemType));
    if (pq->data == NULL) {
        printf("内存分配失败!\n");
        free(pq);
        return NULL;
    }
    pq->size = 0;
    pq->capacity = max_size;
    return pq;
}

bool PQInsert(PriorityQueue *pq, PQElemType item)
{
    if (pq->size >= pq->capacity) {
        printf("优先队列已满!\n");
        return false;
    }
    pq->data[pq->size] = item;
    sift_up(pq, pq->size);
    pq->size++;
    return true;
}

bool PQExtractMax(PriorityQueue *pq, PQElemType *item)
{
    if (pq->size <= 0) {
        printf("优先队列为空!\n");
        return false;
    }
    *item = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    sift_down(pq, 0);
    return true;
}

bool PQPeek(PriorityQueue *pq, PQElemType *item)
{
    if (pq->size <= 0) {
        printf("优先队列为空!\n");
        return false;
    }
    *item = pq->data[0];
    return true;
}

bool PQIsEmpty(PriorityQueue *pq)
{
    return pq->size == 0;
}

int PQSize(PriorityQueue *pq)
{
    return pq->size;
}

void PQDestroy(PriorityQueue *pq)
{
    if (pq != NULL) {
        free(pq->data);
        free(pq);
    }
}
