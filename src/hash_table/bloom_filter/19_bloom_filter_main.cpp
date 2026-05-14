#include "19_bloom_filter.h"
#include <cstdio>
#include <cstring>

static void print_menu(void)
{
    printf("\n========== 布隆过滤器操作菜单 ==========\n");
    printf("  1. 添加元素(add)\n");
    printf("  2. 查询元素(contains)\n");
    printf("  3. 自测\n");
    printf("  0. 退出\n");
    printf("========================================\n");
    printf("请选择操作: ");
}

static void self_test(void)
{
    printf("\n----- 布隆过滤器自测 -----\n");
    BloomFilter bf(1000, 3);

    const char *items[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int n = sizeof(items) / sizeof(items[0]);

    printf("添加元素: ");
    for (int i = 0; i < n; i++) {
        printf("\"%s\" ", items[i]);
        bf.Add(items[i]);
    }
    printf("\n");

    printf("\n查询已添加的元素:\n");
    for (int i = 0; i < n; i++) {
        printf("  contains(\"%s\") = %s\n", items[i],
               bf.Contains(items[i]) ? "true" : "false");
    }

    printf("\n查询未添加的元素:\n");
    const char *absent[] = {"fig", "grape", "kiwi"};
    int m = sizeof(absent) / sizeof(absent[0]);
    for (int i = 0; i < m; i++) {
        printf("  contains(\"%s\") = %s\n", absent[i],
               bf.Contains(absent[i]) ? "true (误判)" : "false");
    }

    printf("----- 自测完成 -----\n");
}

int main(void)
{
    BloomFilter bf(1000, 3);
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
            char buf[256];
            printf("请输入要添加的字符串: ");
            scanf("%s", buf);
            bf.Add(std::string(buf));
            printf("添加成功\n");
            break;
        }
        case 2: {
            char buf[256];
            printf("请输入要查询的字符串: ");
            scanf("%s", buf);
            if (bf.Contains(std::string(buf)))
                printf("\"%s\" 可能在集合中\n", buf);
            else
                printf("\"%s\" 一定不在集合中\n", buf);
            break;
        }
        case 3:
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
