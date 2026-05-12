#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define MAXV 100
#define INF 99999

typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vexs[MAXV];
    EdgeType edges[MAXV][MAXV];
    int vexnum, arcnum;
} MGraph;

void CreateMGraph(MGraph *G);
void DFSTraverse(MGraph *G);
void BFSTraverse(MGraph *G);
void Prim(MGraph *G, int start);
void Dijkstra(MGraph *G, int start, int dist[], int path[]);
void Floyd(MGraph *G, int dist[][MAXV], int path[][MAXV]);
void TopologicalSort(MGraph *G);

#endif
