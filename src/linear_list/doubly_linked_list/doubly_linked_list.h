#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

DuLinkList InitDuList(void);
void CreateDuListHead(DuLinkList L, int n);
void CreateDuListTail(DuLinkList L, int n);
int ListInsert(DuLinkList L, int i, ElemType e);
int ListDelete(DuLinkList L, int i, ElemType *e);
int LocateElem(DuLinkList L, ElemType e);
int GetElem(DuLinkList L, int i, ElemType *e);
int ListLength(DuLinkList L);
void ListTraverse(DuLinkList L);
void ListTraverseBack(DuLinkList L);
void DestroyList(DuLinkList L);

#endif
