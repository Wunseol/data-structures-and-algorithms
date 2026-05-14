#include "09_skip_list.h"
#include <cstdio>

static void print_menu(void)
{
    printf("\n========== 跳表操作菜单 ==========\n");
    printf("  1. 插入元素\n");
    printf("  2. 查找元素\n");
    printf("  3. 删除元素\n");
    printf("  4. 显示跳表\n");
    printf("  5. 自测\n");
    printf("  0. 退出\n");
    printf("==================================\n");
    printf("请选择操作: ");
}

static void self_test(void)
{
    printf("\n----- 跳表自测 -----\n");
    SkipList sl;

    printf("插入元素: ");
    int keys[] = {3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        printf("%d ", keys[i]);
        sl.Insert(keys[i], keys[i] * 10);
    }
    printf("\n");

    printf("\n跳表结构:\n");
    sl.Display();

    int value;
    printf("\n查找 19: ");
    if (sl.Search(19, value))
        printf("找到, key=19, value=%d\n", value);
    else
        printf("未找到\n");

    printf("查找 15: ");
    if (sl.Search(15, value))
        printf("找到, key=15, value=%d\n", value);
    else
        printf("未找到\n");

    printf("\n删除 19: %s\n", sl.Delete(19) ? "成功" : "失败");
    printf("删除后跳表结构:\n");
    sl.Display();

    printf("\n查找 19: ");
    if (sl.Search(19, value))
        printf("找到, key=19, value=%d\n", value);
    else
        printf("未找到\n");

    printf("----- 自测完成 -----\n");
}

int main(void)
{
    SkipList sl;
    int choice;
    int key, value;

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
            printf("请输入key和value(用空格分隔): ");
            if (scanf("%d %d", &key, &value) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            sl.Insert(key, value);
            printf("插入成功\n");
            break;
        case 2:
            printf("请输入要查找的key: ");
            if (scanf("%d", &key) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            if (sl.Search(key, value))
                printf("找到, key=%d, value=%d\n", key, value);
            else
                printf("未找到 key=%d\n", key);
            break;
        case 3:
            printf("请输入要删除的key: ");
            if (scanf("%d", &key) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            if (sl.Delete(key))
                printf("删除成功\n");
            else
                printf("删除失败, key=%d 不存在\n", key);
            break;
        case 4:
            sl.Display();
            break;
        case 5:
            self_test();
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
