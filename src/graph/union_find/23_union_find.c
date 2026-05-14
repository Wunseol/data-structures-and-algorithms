#include "23_union_find.h"
#include <stdio.h>
#include <stdlib.h>

UnionFind *UFCreate(int n)
{
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
    if (uf == NULL) {
        printf("ÄÚ´æ·ÖÅäÊ§°Ü!\n");
        return NULL;
    }
    uf->parent = (int *)malloc(n * sizeof(int));
    uf->rank = (int *)malloc(n * sizeof(int));
    if (uf->parent == NULL || uf->rank == NULL) {
        printf("ÄÚ´æ·ÖÅäÊ§°Ü!\n");
        free(uf->parent);
        free(uf->rank);
        free(uf);
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    uf->count = n;
    uf->capacity = n;
    return uf;
}

int UFFind(UnionFind *uf, int x)
{
    if (x < 0 || x >= uf->capacity) {
        printf("ÔªËØ %d ³¬³ö·¶Î§!\n", x);
        return -1;
    }
    if (uf->parent[x] != x) {
        uf->parent[x] = UFFind(uf, uf->parent[x]);
    }
    return uf->parent[x];
}

void UFUnion(UnionFind *uf, int x, int y)
{
    int rootX = UFFind(uf, x);
    int rootY = UFFind(uf, y);
    if (rootX == -1 || rootY == -1)
        return;
    if (rootX == rootY)
        return;
    if (uf->rank[rootX] < uf->rank[rootY]) {
        uf->parent[rootX] = rootY;
    } else if (uf->rank[rootX] > uf->rank[rootY]) {
        uf->parent[rootY] = rootX;
    } else {
        uf->parent[rootY] = rootX;
        uf->rank[rootX]++;
    }
    uf->count--;
}

bool UFConnected(UnionFind *uf, int x, int y)
{
    int rootX = UFFind(uf, x);
    int rootY = UFFind(uf, y);
    if (rootX == -1 || rootY == -1)
        return false;
    return rootX == rootY;
}

int UFCount(UnionFind *uf)
{
    return uf->count;
}

void UFDestroy(UnionFind *uf)
{
    if (uf != NULL) {
        free(uf->parent);
        free(uf->rank);
        free(uf);
    }
}
