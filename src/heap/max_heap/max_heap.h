#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdbool.h>

#define MAXSIZE 100

typedef int HeapElemType;

typedef struct {
    HeapElemType data[MAXSIZE + 1];
    int size;
} MaxHeap;

void InitMaxHeap(MaxHeap *H);
void BuildMaxHeap(MaxHeap *H, HeapElemType arr[], int n);
bool MaxHeapInsert(MaxHeap *H, HeapElemType e);
bool ExtractMax(MaxHeap *H, HeapElemType *e);
bool GetMax(const MaxHeap *H, HeapElemType *e);
void MaxHeapSort(HeapElemType arr[], int n);
void HeapTraverse(const MaxHeap *H);

#endif
