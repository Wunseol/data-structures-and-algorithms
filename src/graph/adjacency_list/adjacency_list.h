#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

typedef char VertexType;
typedef int EdgeType;

typedef struct ArcNode {
    int adjvex;
    EdgeType weight;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAXV];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

void CreateALGraph(ALGraph *G);
void DFS_AL(ALGraph *G);
void BFS_AL(ALGraph *G);
void Kruskal(ALGraph *G);

#endif
