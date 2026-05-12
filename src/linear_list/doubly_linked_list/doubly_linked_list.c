#include "doubly_linked_list.h"

DuLinkList InitDuList(void)
{
    DuLinkList L = (DuLinkList)malloc(sizeof(DuLNode));
    if (L == NULL) {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }
    L->prior = NULL;
    L->next = NULL;
    return L;
}

void CreateDuListHead(DuLinkList L, int n)
{
    for (int i = 0; i < n; i++) {
        DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
        if (s == NULL) {
            printf("内存分配失败!\n");
            return;
        }
        printf("输入第%d个元素: ", i + 1);
        scanf("%d", &s->data);
        s->next = L->next;
        s->prior = L;
        if (L->next != NULL) {
            L->next->prior = s;
        }
        L->next = s;
    }
}

void CreateDuListTail(DuLinkList L, int n)
{
    DuLNode *tail = L;
    for (int i = 0; i < n; i++) {
        DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
        if (s == NULL) {
            printf("内存分配失败!\n");
            return;
        }
        printf("输入第%d个元素: ", i + 1);
        scanf("%d", &s->data);
        s->next = NULL;
        s->prior = tail;
        tail->next = s;
        tail = s;
    }
}

int ListInsert(DuLinkList L, int i, ElemType e)
{
    if (i < 1) {
        printf("插入位置不合法!\n");
        return 0;
    }
    DuLNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        printf("插入位置超出范围!\n");
        return 0;
    }
    DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
    if (s == NULL) {
        printf("内存分配失败!\n");
        return 0;
    }
    s->data = e;
    s->next = p->next;
    s->prior = p;
    if (p->next != NULL) {
        p->next->prior = s;
    }
    p->next = s;
    return 1;
}

int ListDelete(DuLinkList L, int i, ElemType *e)
{
    if (i < 1) {
        printf("删除位置不合法!\n");
        return 0;
    }
    DuLNode *p = L->next;
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        printf("删除位置超出范围!\n");
        return 0;
    }
    *e = p->data;
    p->prior->next = p->next;
    if (p->next != NULL) {
        p->next->prior = p->prior;
    }
    free(p);
    return 1;
}

int LocateElem(DuLinkList L, ElemType e)
{
    DuLNode *p = L->next;
    int j = 1;
    while (p != NULL) {
        if (p->data == e) {
            return j;
        }
        p = p->next;
        j++;
    }
    return 0;
}

int GetElem(DuLinkList L, int i, ElemType *e)
{
    if (i < 1) {
        printf("位置不合法!\n");
        return 0;
    }
    DuLNode *p = L->next;
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        printf("位置超出范围!\n");
        return 0;
    }
    *e = p->data;
    return 1;
}

int ListLength(DuLinkList L)
{
    int length = 0;
    DuLNode *p = L->next;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

void ListTraverse(DuLinkList L)
{
    DuLNode *p = L->next;
    if (p == NULL) {
        printf("链表为空!\n");
        return;
    }
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf("<->");
        }
        p = p->next;
    }
    printf("\n");
}

void ListTraverseBack(DuLinkList L)
{
    DuLNode *p = L->next;
    if (p == NULL) {
        printf("链表为空!\n");
        return;
    }
    while (p->next != NULL) {
        p = p->next;
    }
    while (p != L) {
        printf("%d", p->data);
        if (p->prior != L) {
            printf("<->");
        }
        p = p->prior;
    }
    printf("\n");
}

void DestroyList(DuLinkList L)
{
    DuLNode *p = L;
    DuLNode *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
}
