#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdbool.h>

#define MAXSIZE 100

typedef int HeapElemType;

typedef struct {
    HeapElemType data[MAXSIZE + 1];
    int size;
} MinHeap;

void InitMinHeap(MinHeap *H);
void BuildMinHeap(MinHeap *H, HeapElemType arr[], int n);
bool MinHeapInsert(MinHeap *H, HeapElemType e);
bool ExtractMin(MinHeap *H, HeapElemType *e);
bool GetMin(const MinHeap *H, HeapElemType *e);
void MinHeapSort(HeapElemType arr[], int n);
void HeapTraverse(const MinHeap *H);

#endif
