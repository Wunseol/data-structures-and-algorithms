#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct CiLNode {
    ElemType data;
    struct CiLNode *next;
} CiLNode, *CiLinkList;

CiLinkList InitCiList(void);
void CreateCiListTail(CiLinkList L, int n);
int ListInsert(CiLinkList L, int i, ElemType e);
int ListDelete(CiLinkList L, int i, ElemType *e);
int ListEmpty(CiLinkList L);
int ListLength(CiLinkList L);
void ListTraverse(CiLinkList L);
void MergeCiList(CiLinkList La, CiLinkList Lb, CiLinkList Lc);
void DestroyList(CiLinkList L);

#endif
