#include "adjacency_list.h"

static int visited[MAXV];

static void DFS(ALGraph *G, int i) {
    visited[i] = 1;
    printf("%c ", G->vertices[i].data);
    ArcNode *p = G->vertices[i].firstarc;
    while (p != NULL) {
        if (!visited[p->adjvex])
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

void CreateALGraph(ALGraph *G) {
    printf("输入顶点数: ");
    scanf("%d", &G->vexnum);
    printf("输入边数: ");
    scanf("%d", &G->arcnum);

    printf("输入%d个顶点(连续字符,如ABCDE): ", G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        scanf(" %c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }

    printf("输入%d条边(起点下标 终点下标 权重):\n", G->arcnum);
    for (int k = 0; k < G->arcnum; k++) {
        int i, j, w;
        scanf("%d %d %d", &i, &j, &w);

        ArcNode *s = (ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex = j;
        s->weight = w;
        s->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = s;

        ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode));
        t->adjvex = i;
        t->weight = w;
        t->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = t;
    }
}

void DFS_AL(ALGraph *G) {
    for (int i = 0; i < G->vexnum; i++)
        visited[i] = 0;
    printf("DFS遍历: ");
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i])
            DFS(G, i);
    }
    printf("\n");
}

void BFS_AL(ALGraph *G) {
    int queue[MAXV];
    int front = 0, rear = 0;

    for (int i = 0; i < G->vexnum; i++)
        visited[i] = 0;

    printf("BFS遍历: ");
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            printf("%c ", G->vertices[i].data);
            queue[rear++] = i;
            while (front != rear) {
                int u = queue[front++];
                ArcNode *p = G->vertices[u].firstarc;
                while (p != NULL) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = 1;
                        printf("%c ", G->vertices[p->adjvex].data);
                        queue[rear++] = p->adjvex;
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    printf("\n");
}

typedef struct {
    int u, v;
    int weight;
} Edge;

static int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

static void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

static int cmpEdge(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void Kruskal(ALGraph *G) {
    Edge edges[MAXV * MAXV];
    int ecnt = 0;

    for (int i = 0; i < G->vexnum; i++) {
        ArcNode *p = G->vertices[i].firstarc;
        while (p != NULL) {
            if (p->adjvex > i) {
                edges[ecnt].u = i;
                edges[ecnt].v = p->adjvex;
                edges[ecnt].weight = p->weight;
                ecnt++;
            }
            p = p->nextarc;
        }
    }

    qsort(edges, ecnt, sizeof(Edge), cmpEdge);

    int parent[MAXV], rank[MAXV];
    for (int i = 0; i < G->vexnum; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Kruskal最小生成树:\n");
    int mstEdges = 0;
    int totalWeight = 0;
    for (int i = 0; i < ecnt && mstEdges < G->vexnum - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int setU = find(parent, u);
        int setV = find(parent, v);
        if (setU != setV) {
            printf("边: %c - %c, 权重: %d\n", G->vertices[u].data, G->vertices[v].data, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSet(parent, rank, setU, setV);
            mstEdges++;
        }
    }

    if (mstEdges < G->vexnum - 1)
        printf("图不连通,无法生成最小生成树!\n");
    else
        printf("最小生成树总权重: %d\n", totalWeight);
}
