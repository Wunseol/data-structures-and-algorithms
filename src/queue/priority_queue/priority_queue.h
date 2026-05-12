#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

typedef int PQElemType;

typedef struct {
    PQElemType *data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue *PQCreate(int max_size);
bool PQInsert(PriorityQueue *pq, PQElemType item);
bool PQExtractMax(PriorityQueue *pq, PQElemType *item);
bool PQPeek(PriorityQueue *pq, PQElemType *item);
bool PQIsEmpty(PriorityQueue *pq);
int PQSize(PriorityQueue *pq);
void PQDestroy(PriorityQueue *pq);

#endif
