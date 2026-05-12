#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdbool.h>

typedef struct {
    int *parent;
    int *rank;
    int count;
    int capacity;
} UnionFind;

UnionFind *UFCreate(int n);
int UFFind(UnionFind *uf, int x);
void UFUnion(UnionFind *uf, int x, int y);
bool UFConnected(UnionFind *uf, int x, int y);
int UFCount(UnionFind *uf);
void UFDestroy(UnionFind *uf);

#endif
