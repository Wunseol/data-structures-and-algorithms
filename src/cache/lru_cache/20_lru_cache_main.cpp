#include "20_lru_cache.h"
#include <cstdio>

static void print_menu(void)
{
    printf("\n========== LRU缓存操作菜单 ==========\n");
    printf("  1. 查询元素(get)\n");
    printf("  2. 插入/更新元素(put)\n");
    printf("  3. 自测\n");
    printf("  0. 退出\n");
    printf("======================================\n");
    printf("请选择操作: ");
}

static void self_test(void)
{
    printf("\n----- LRU缓存自测 -----\n");
    LRUCache cache(2);

    cache.Put(1, 10);
    printf("put(1, 10)\n");
    cache.Put(2, 20);
    printf("put(2, 20)\n");

    printf("get(1) = %d (期望: 10)\n", cache.Get(1));

    cache.Put(3, 30);
    printf("put(3, 30) -> 淘汰key=2\n");

    printf("get(2) = %d (期望: -1, 已被淘汰)\n", cache.Get(2));

    cache.Put(4, 40);
    printf("put(4, 40) -> 淘汰key=1\n");

    printf("get(1) = %d (期望: -1, 已被淘汰)\n", cache.Get(1));
    printf("get(3) = %d (期望: 30)\n", cache.Get(3));
    printf("get(4) = %d (期望: 40)\n", cache.Get(4));

    cache.Put(3, 300);
    printf("put(3, 300) -> 更新key=3\n");
    printf("get(3) = %d (期望: 300)\n", cache.Get(3));

    printf("----- 自测完成 -----\n");
}

int main(void)
{
    int capacity;
    printf("请输入LRU缓存容量: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("输入无效\n");
        return 1;
    }

    LRUCache cache(capacity);
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
            int key;
            printf("请输入要查询的key: ");
            if (scanf("%d", &key) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            int val = cache.Get(key);
            if (val == -1)
                printf("key=%d 不存在\n", key);
            else
                printf("key=%d -> value=%d\n", key, val);
            break;
        }
        case 2: {
            int key, value;
            printf("请输入key和value(用空格分隔): ");
            if (scanf("%d %d", &key, &value) != 2) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            cache.Put(key, value);
            printf("put(%d, %d) 成功\n", key, value);
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
