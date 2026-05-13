#include "max_heap.h"
#include <stdio.h>

static void Swap(HeapElemType *a, HeapElemType *b)
{
    HeapElemType tmp = *a;
    *a = *b;
    *b = tmp;
}

static void SiftUp(MaxHeap *H, int i)
{
    while (i > 1 && H->data[i] > H->data[i / 2]) {
        Swap(&H->data[i], &H->data[i / 2]);
        i /= 2;
    }
}

static void SiftDown(MaxHeap *H, int i)
{
    while (2 * i <= H->size) {
        int child = 2 * i;
        if (child + 1 <= H->size && H->data[child + 1] > H->data[child])
            child++;
        if (H->data[i] >= H->data[child])
            break;
        Swap(&H->data[i], &H->data[child]);
        i = child;
    }
}

void InitMaxHeap(MaxHeap *H)
{
    H->size = 0;
}

void BuildMaxHeap(MaxHeap *H, HeapElemType arr[], int n)
{
    if (n > MAXSIZE)
        n = MAXSIZE;
    H->size = n;
    for (int i = 1; i <= n; i++)
        H->data[i] = arr[i - 1];
    for (int i = n / 2; i >= 1; i--)
        SiftDown(H, i);
}

bool MaxHeapInsert(MaxHeap *H, HeapElemType e)
{
    if (H->size >= MAXSIZE)
        return false;
    H->size++;
    H->data[H->size] = e;
    SiftUp(H, H->size);
    return true;
}

bool ExtractMax(MaxHeap *H, HeapElemType *e)
{
    if (H->size == 0)
        return false;
    *e = H->data[1];
    H->data[1] = H->data[H->size];
    H->size--;
    SiftDown(H, 1);
    return true;
}

bool GetMax(const MaxHeap *H, HeapElemType *e)
{
    if (H->size == 0)
        return false;
    *e = H->data[1];
    return true;
}

void MaxHeapSort(HeapElemType arr[], int n)
{
    MaxHeap H;
    H.size = n;
    for (int i = 1; i <= n; i++)
        H.data[i] = arr[i - 1];
    for (int i = n / 2; i >= 1; i--)
        SiftDown(&H, i);
    for (int i = n; i > 1; i--) {
        HeapElemType tmp = H.data[1];
        H.data[1] = H.data[i];
        H.data[i] = tmp;
        H.size--;
        SiftDown(&H, 1);
    }
    for (int i = 0; i < n; i++)
        arr[i] = H.data[i + 1];
}

void HeapTraverse(const MaxHeap *H)
{
    if (H->size == 0) {
        printf("最大堆为空\n");
        return;
    }
    printf("最大堆元素(层序): ");
    for (int i = 1; i <= H->size; i++)
        printf("%d ", H->data[i]);
    printf("\n");
}
