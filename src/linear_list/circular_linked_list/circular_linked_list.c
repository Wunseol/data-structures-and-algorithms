#include "circular_linked_list.h"

CiLinkList InitCiList(void)
{
    CiLinkList L = (CiLinkList)malloc(sizeof(CiLNode));
    if (L == NULL) {
        printf("内存分配失败!\n");
        exit(1);
    }
    L->next = L;
    return L;
}

void CreateCiListTail(CiLinkList L, int n)
{
    CiLNode *tail = L;
    int i;
    for (i = 0; i < n; i++) {
        CiLNode *s = (CiLNode *)malloc(sizeof(CiLNode));
        if (s == NULL) {
            printf("内存分配失败!\n");
            exit(1);
        }
        printf("请输入第%d个元素: ", i + 1);
        scanf("%d", &s->data);
        s->next = L;
        tail->next = s;
        tail = s;
    }
}

int ListInsert(CiLinkList L, int i, ElemType e)
{
    if (i < 1) {
        printf("插入位置不合法!\n");
        return 0;
    }
    CiLNode *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (j < i - 1) {
        printf("插入位置超出链表长度!\n");
        return 0;
    }
    CiLNode *s = (CiLNode *)malloc(sizeof(CiLNode));
    if (s == NULL) {
        printf("内存分配失败!\n");
        return 0;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

int ListDelete(CiLinkList L, int i, ElemType *e)
{
    if (i < 1 || L->next == L) {
        printf("删除位置不合法或链表为空!\n");
        return 0;
    }
    CiLNode *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == L) {
        printf("删除位置超出链表长度!\n");
        return 0;
    }
    CiLNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

int ListEmpty(CiLinkList L)
{
    return L->next == L;
}

int ListLength(CiLinkList L)
{
    int length = 0;
    CiLNode *p = L->next;
    while (p != L) {
        length++;
        p = p->next;
    }
    return length;
}

void ListTraverse(CiLinkList L)
{
    if (L->next == L) {
        printf("链表为空!\n");
        return;
    }
    CiLNode *p = L->next;
    while (p != L) {
        printf("%d", p->data);
        p = p->next;
        if (p != L)
            printf("->");
    }
    printf("->(head)\n");
}

void MergeCiList(CiLinkList La, CiLinkList Lb, CiLinkList Lc)
{
    CiLNode *pa = La->next;
    CiLNode *pb = Lb->next;
    CiLNode *pc = Lc;

    while (pa != La && pb != Lb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    while (pa != La) {
        pc->next = pa;
        pc = pa;
        pa = pa->next;
    }
    while (pb != Lb) {
        pc->next = pb;
        pc = pb;
        pb = pb->next;
    }

    pc->next = Lc;

    La->next = La;
    Lb->next = Lb;
}

void DestroyList(CiLinkList L)
{
    CiLNode *p = L->next;
    CiLNode *q;
    while (p != L) {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
}
