#include "16_segment_tree.h"
#include <cstdio>
#include <vector>

static void print_menu(void)
{
    printf("\n========== 线段树操作菜单 ==========\n");
    printf("  1. 更新元素\n");
    printf("  2. 区间查询\n");
    printf("  3. 打印原始数组\n");
    printf("  0. 退出\n");
    printf("====================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree st(data);

    printf("初始数组: ");
    for (int i = 0; i < (int)data.size(); i++)
        printf("%d ", data[i]);
    printf("\n");

    printf("query(0, 5) = %d (期望: 36)\n", st.Query(0, 5));
    printf("query(1, 3) = %d (期望: 15)\n", st.Query(1, 3));
    printf("query(2, 4) = %d (期望: 21)\n", st.Query(2, 4));

    st.Update(1, 10);
    printf("\nUpdate(1, 10) 后:\n");
    printf("query(0, 5) = %d (期望: 43)\n", st.Query(0, 5));
    printf("query(1, 3) = %d (期望: 22)\n", st.Query(1, 3));

    st.Update(3, 0);
    printf("\nUpdate(3, 0) 后:\n");
    printf("query(0, 5) = %d (期望: 36)\n", st.Query(0, 5));
    printf("query(2, 4) = %d (期望: 14)\n", st.Query(2, 4));

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
            int index, value;
            printf("请输入索引和值: ");
            if (scanf("%d %d", &index, &value) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            st.Update(index, value);
            printf("更新成功\n");
            break;
        }
        case 2: {
            int left, right;
            printf("请输入查询区间 [left, right]: ");
            if (scanf("%d %d", &left, &right) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            printf("区间 [%d, %d] 的和 = %d\n", left, right, st.Query(left, right));
            break;
        }
        case 3:
            printf("原始数组: ");
            for (int i = 0; i < (int)data.size(); i++)
                printf("%d ", data[i]);
            printf("\n");
            break;
        case 0:
            printf("程序退出\n");
            return 0;
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    }
}
