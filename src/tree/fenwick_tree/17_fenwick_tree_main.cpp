#include "17_fenwick_tree.h"
#include <cstdio>
#include <vector>

static void print_menu(void)
{
    printf("\n========== 树状数组操作菜单 ==========\n");
    printf("  1. 单点更新(增量)\n");
    printf("  2. 前缀和查询\n");
    printf("  3. 区间和查询\n");
    printf("  0. 退出\n");
    printf("======================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(data);

    printf("初始数组(1-based): ");
    for (int i = 0; i < (int)data.size(); i++)
        printf("[%d]=%d ", i + 1, data[i]);
    printf("\n");

    printf("query(1) = %d (期望: 1)\n", ft.Query(1));
    printf("query(3) = %d (期望: 9)\n", ft.Query(3));
    printf("query(6) = %d (期望: 36)\n", ft.Query(6));
    printf("range_query(2, 4) = %d (期望: 15)\n", ft.RangeQuery(2, 4));
    printf("range_query(1, 6) = %d (期望: 36)\n", ft.RangeQuery(1, 6));

    ft.Update(2, 7);
    printf("\nUpdate(2, +7) 后:\n");
    printf("query(3) = %d (期望: 16)\n", ft.Query(3));
    printf("range_query(2, 4) = %d (期望: 22)\n", ft.RangeQuery(2, 4));

    ft.Update(5, -4);
    printf("\nUpdate(5, -4) 后:\n");
    printf("query(6) = %d (期望: 39)\n", ft.Query(6));
    printf("range_query(3, 6) = %d (期望: 28)\n", ft.RangeQuery(3, 6));

    int choice;
    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n')
                ;
            printf("输入无效，请重新输入\n");
            continue;
        }

        switch (choice) {
        case 1: {
            int index, delta;
            printf("请输入索引(1-based)和增量: ");
            if (scanf("%d %d", &index, &delta) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            ft.Update(index, delta);
            printf("更新成功\n");
            break;
        }
        case 2: {
            int index;
            printf("请输入索引(1-based): ");
            if (scanf("%d", &index) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("前缀和 [1..%d] = %d\n", index, ft.Query(index));
            break;
        }
        case 3: {
            int left, right;
            printf("请输入区间 [left, right](1-based): ");
            if (scanf("%d %d", &left, &right) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("区间 [%d, %d] 的和 = %d\n", left, right, ft.RangeQuery(left, right));
            break;
        }
        case 0:
            printf("程序退出\n");
            return 0;
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    }
}
