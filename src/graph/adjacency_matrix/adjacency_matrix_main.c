#include "adjacency_matrix.c"

int main() {
    MGraph G;
    int choice;
    int dist[MAXV], path[MAXV];
    int fdist[MAXV][MAXV], fpath[MAXV][MAXV];
    int created = 0;

    while (1) {
        printf("\n========== 邻接矩阵图操作 ==========\n");
        printf("1. 创建图\n");
        printf("2. DFS遍历\n");
        printf("3. BFS遍历\n");
        printf("4. Prim最小生成树\n");
        printf("5. Dijkstra最短路径\n");
        printf("6. Floyd所有顶点对最短路径\n");
        printf("7. 拓扑排序\n");
        printf("0. 退出\n");
        printf("=====================================\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            CreateMGraph(&G);
            created = 1;
            break;
        case 2:
            if (!created) { printf("请先创建图!\n"); break; }
            DFSTraverse(&G);
            break;
        case 3:
            if (!created) { printf("请先创建图!\n"); break; }
            BFSTraverse(&G);
            break;
        case 4:
            if (!created) { printf("请先创建图!\n"); break; }
            {
                int start;
                printf("输入起始顶点下标(0~%d): ", G.vexnum - 1);
                scanf("%d", &start);
                Prim(&G, start);
            }
            break;
        case 5:
            if (!created) { printf("请先创建图!\n"); break; }
            {
                int start;
                printf("输入源点下标(0~%d): ", G.vexnum - 1);
                scanf("%d", &start);
                Dijkstra(&G, start, dist, path);
            }
            break;
        case 6:
            if (!created) { printf("请先创建图!\n"); break; }
            Floyd(&G, fdist, fpath);
            break;
        case 7:
            if (!created) { printf("请先创建图!\n"); break; }
            TopologicalSort(&G);
            break;
        case 0:
            printf("退出程序。\n");
            return 0;
        default:
            printf("无效选择!\n");
        }
    }
    return 0;
}
