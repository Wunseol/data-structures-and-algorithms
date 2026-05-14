#include "21_adjacency_matrix.h"

static int visited[MAXV];

static void DFS(MGraph *G, int i) {
    visited[i] = 1;
    printf("%c ", G->vexs[i]);
    for (int j = 0; j < G->vexnum; j++) {
        if (G->edges[i][j] != 0 && G->edges[i][j] != INF && !visited[j]) {
            DFS(G, j);
        }
    }
}

void CreateMGraph(MGraph *G) {
    printf("输入顶点数: ");
    scanf("%d", &G->vexnum);
    printf("输入边数: ");
    scanf("%d", &G->arcnum);

    printf("输入%d个顶点(连续字符,如ABCDE): ", G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        scanf(" %c", &G->vexs[i]);
    }

    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            if (i == j)
                G->edges[i][j] = 0;
            else
                G->edges[i][j] = INF;
        }
    }

    printf("输入%d条边(起点下标 终点下标 权重):\n", G->arcnum);
    for (int k = 0; k < G->arcnum; k++) {
        int i, j, w;
        scanf("%d %d %d", &i, &j, &w);
        G->edges[i][j] = w;
        G->edges[j][i] = w;
    }
}

void DFSTraverse(MGraph *G) {
    for (int i = 0; i < G->vexnum; i++)
        visited[i] = 0;
    printf("DFS遍历: ");
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i])
            DFS(G, i);
    }
    printf("\n");
}

void BFSTraverse(MGraph *G) {
    int queue[MAXV];
    int front = 0, rear = 0;

    for (int i = 0; i < G->vexnum; i++)
        visited[i] = 0;

    printf("BFS遍历: ");
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            printf("%c ", G->vexs[i]);
            queue[rear++] = i;
            while (front != rear) {
                int u = queue[front++];
                for (int j = 0; j < G->vexnum; j++) {
                    if (G->edges[u][j] != 0 && G->edges[u][j] != INF && !visited[j]) {
                        visited[j] = 1;
                        printf("%c ", G->vexs[j]);
                        queue[rear++] = j;
                    }
                }
            }
        }
    }
    printf("\n");
}

void Prim(MGraph *G, int start) {
    int lowcost[MAXV];
    int closest[MAXV];
    int inMST[MAXV];

    for (int i = 0; i < G->vexnum; i++) {
        lowcost[i] = G->edges[start][i];
        closest[i] = start;
        inMST[i] = 0;
    }
    inMST[start] = 1;

    printf("Prim最小生成树(从顶点%c开始):\n", G->vexs[start]);
    for (int i = 1; i < G->vexnum; i++) {
        int min = INF;
        int minIdx = -1;
        for (int j = 0; j < G->vexnum; j++) {
            if (!inMST[j] && lowcost[j] < min) {
                min = lowcost[j];
                minIdx = j;
            }
        }

        if (minIdx == -1) {
            printf("图不连通,无法生成最小生成树!\n");
            return;
        }

        inMST[minIdx] = 1;
        printf("边: %c - %c, 权重: %d\n", G->vexs[closest[minIdx]], G->vexs[minIdx], min);

        for (int j = 0; j < G->vexnum; j++) {
            if (!inMST[j] && G->edges[minIdx][j] < lowcost[j]) {
                lowcost[j] = G->edges[minIdx][j];
                closest[j] = minIdx;
            }
        }
    }
}

void Dijkstra(MGraph *G, int start, int dist[], int path[]) {
    int finalized[MAXV];

    for (int i = 0; i < G->vexnum; i++) {
        dist[i] = G->edges[start][i];
        finalized[i] = 0;
        if (G->edges[start][i] != 0 && G->edges[start][i] != INF)
            path[i] = start;
        else
            path[i] = -1;
    }
    finalized[start] = 1;
    path[start] = -1;

    for (int i = 1; i < G->vexnum; i++) {
        int min = INF;
        int minIdx = -1;
        for (int j = 0; j < G->vexnum; j++) {
            if (!finalized[j] && dist[j] < min) {
                min = dist[j];
                minIdx = j;
            }
        }

        if (minIdx == -1) break;
        finalized[minIdx] = 1;

        for (int j = 0; j < G->vexnum; j++) {
            if (!finalized[j] && G->edges[minIdx][j] != INF) {
                if (dist[minIdx] + G->edges[minIdx][j] < dist[j]) {
                    dist[j] = dist[minIdx] + G->edges[minIdx][j];
                    path[j] = minIdx;
                }
            }
        }
    }

    printf("Dijkstra最短路径(源点: %c):\n", G->vexs[start]);
    for (int i = 0; i < G->vexnum; i++) {
        if (i == start) continue;
        printf("  到%c的最短距离: ", G->vexs[i]);
        if (dist[i] == INF)
            printf("不可达\n");
        else {
            printf("%d, 路径: ", dist[i]);
            int stack[MAXV], top = 0;
            int k = i;
            while (k != -1) {
                stack[top++] = k;
                k = path[k];
            }
            while (top > 0) {
                printf("%c", G->vexs[stack[--top]]);
                if (top > 0) printf(" -> ");
            }
            printf("\n");
        }
    }
}

void Floyd(MGraph *G, int dist[][MAXV], int path[][MAXV]) {
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            dist[i][j] = G->edges[i][j];
            if (i != j && G->edges[i][j] != INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }

    for (int k = 0; k < G->vexnum; k++) {
        for (int i = 0; i < G->vexnum; i++) {
            for (int j = 0; j < G->vexnum; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = path[k][j];
                    }
                }
            }
        }
    }

    printf("Floyd各顶点对最短路径:\n");
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            if (i == j) continue;
            printf("  %c -> %c: ", G->vexs[i], G->vexs[j]);
            if (dist[i][j] == INF) {
                printf("不可达\n");
            } else {
                printf("距离=%d, 路径: ", dist[i][j]);
                int stack[MAXV], top = 0;
                int k = j;
                while (k != -1) {
                    stack[top++] = k;
                    if (k == i) break;
                    k = path[i][k];
                }
                while (top > 0) {
                    printf("%c", G->vexs[stack[--top]]);
                    if (top > 0) printf(" -> ");
                }
                printf("\n");
            }
        }
    }
}

void TopologicalSort(MGraph *G) {
    int indegree[MAXV] = {0};
    int queue[MAXV];
    int front = 0, rear = 0;
    int count = 0;

    for (int j = 0; j < G->vexnum; j++) {
        for (int i = 0; i < G->vexnum; i++) {
            if (G->edges[i][j] != 0 && G->edges[i][j] != INF)
                indegree[j]++;
        }
    }

    for (int i = 0; i < G->vexnum; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("拓扑排序: ");
    while (front != rear) {
        int u = queue[front++];
        printf("%c ", G->vexs[u]);
        count++;
        for (int j = 0; j < G->vexnum; j++) {
            if (G->edges[u][j] != 0 && G->edges[u][j] != INF) {
                indegree[j]--;
                if (indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }

    if (count < G->vexnum)
        printf("\n图中存在环,拓扑排序不完整!");
    printf("\n");
}
