#include "22_adjacency_list.c"

int main() {
    ALGraph G;
    int choice;
    int created = 0;

    while (1) {
        printf("\n========== 邻接表图操作 ==========\n");
        printf("1. 创建图\n");
        printf("2. DFS遍历\n");
        printf("3. BFS遍历\n");
        printf("4. Kruskal最小生成树\n");
        printf("0. 退出\n");
        printf("===================================\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            CreateALGraph(&G);
            created = 1;
            break;
        case 2:
            if (!created) { printf("请先创建图!\n"); break; }
            DFS_AL(&G);
            break;
        case 3:
            if (!created) { printf("请先创建图!\n"); break; }
            BFS_AL(&G);
            break;
        case 4:
            if (!created) { printf("请先创建图!\n"); break; }
            Kruskal(&G);
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
