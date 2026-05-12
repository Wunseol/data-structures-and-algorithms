#include "union_find.h"
#include <stdio.h>

static void print_menu(void)
{
    printf("\n========== 并查集操作菜单 ==========\n");
    printf("  1. 创建并查集\n");
    printf("  2. 查找元素根节点\n");
    printf("  3. 合并两个集合\n");
    printf("  4. 判断两个元素是否连通\n");
    printf("  5. 查询连通分量数\n");
    printf("  6. 自测\n");
    printf("  0. 退出\n");
    printf("=====================================\n");
    printf("请选择操作: ");
}

static void self_test(void)
{
    printf("\n----- 并查集自测 -----\n");
    UnionFind *uf = UFCreate(10);
    printf("创建大小为10的并查集, 连通分量数: %d\n", UFCount(uf));

    UFUnion(uf, 1, 2);
    printf("合并 1 和 2, 连通分量数: %d\n", UFCount(uf));
    printf("1 和 2 是否连通: %s\n", UFConnected(uf, 1, 2) ? "是" : "否");

    UFUnion(uf, 3, 4);
    printf("合并 3 和 4, 连通分量数: %d\n", UFCount(uf));

    UFUnion(uf, 1, 3);
    printf("合并 1 和 3, 连通分量数: %d\n", UFCount(uf));
    printf("2 和 4 是否连通: %s\n", UFConnected(uf, 2, 4) ? "是" : "否");
    printf("1 和 5 是否连通: %s\n", UFConnected(uf, 1, 5) ? "是" : "否");

    UFUnion(uf, 5, 6);
    UFUnion(uf, 7, 8);
    UFUnion(uf, 5, 7);
    printf("合并 5-6, 7-8, 5-7, 连通分量数: %d\n", UFCount(uf));
    printf("6 和 8 是否连通: %s\n", UFConnected(uf, 6, 8) ? "是" : "否");

    printf("1 的根节点: %d\n", UFFind(uf, 1));
    printf("5 的根节点: %d\n", UFFind(uf, 5));

    UFDestroy(uf);
    printf("----- 自测完成 -----\n");
}

int main(void)
{
    UnionFind *uf = NULL;
    int choice;
    int n, x, y;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n')
                ;
            printf("输入无效，请重新输入\n");
            continue;
        }

        switch (choice) {
        case 1:
            if (uf != NULL) {
                UFDestroy(uf);
            }
            printf("请输入元素个数: ");
            if (scanf("%d", &n) != 1 || n <= 0) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            uf = UFCreate(n);
            if (uf != NULL)
                printf("并查集创建成功, 大小: %d, 连通分量数: %d\n", n, UFCount(uf));
            break;
        case 2:
            if (uf == NULL) {
                printf("请先创建并查集\n");
                break;
            }
            printf("请输入元素: ");
            if (scanf("%d", &x) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            y = UFFind(uf, x);
            if (y != -1)
                printf("元素 %d 的根节点: %d\n", x, y);
            break;
        case 3:
            if (uf == NULL) {
                printf("请先创建并查集\n");
                break;
            }
            printf("请输入两个元素(用空格分隔): ");
            if (scanf("%d %d", &x, &y) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            UFUnion(uf, x, y);
            printf("合并完成, 连通分量数: %d\n", UFCount(uf));
            break;
        case 4:
            if (uf == NULL) {
                printf("请先创建并查集\n");
                break;
            }
            printf("请输入两个元素(用空格分隔): ");
            if (scanf("%d %d", &x, &y) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("元素 %d 和 %d %s连通\n", x, y, UFConnected(uf, x, y) ? "是" : "不");
            break;
        case 5:
            if (uf == NULL) {
                printf("请先创建并查集\n");
                break;
            }
            printf("当前连通分量数: %d\n", UFCount(uf));
            break;
        case 6:
            self_test();
            break;
        case 0:
            if (uf != NULL)
                UFDestroy(uf);
            printf("程序退出\n");
            return 0;
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    }
}
