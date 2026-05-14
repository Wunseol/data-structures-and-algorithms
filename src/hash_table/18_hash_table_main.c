#include <stdio.h>
#include <stdlib.h>
#include "18_hash_table_chaining.h"
#include "18_hash_table_open_addressing.h"

static void chaining_menu() {
    HashTableChaining *ht = NULL;
    int choice, key, size;
    while (1) {
        printf("\n===== 链地址法哈希表 =====\n");
        printf("1. 创建哈希表\n");
        printf("2. 插入关键字\n");
        printf("3. 查找关键字\n");
        printf("4. 删除关键字\n");
        printf("5. 遍历哈希表\n");
        printf("6. 查看装载因子\n");
        printf("0. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (ht) {
                htc_destroy(ht);
                ht = NULL;
            }
            printf("请输入哈希表大小: ");
            scanf("%d", &size);
            ht = htc_create(size);
            if (ht)
                printf("哈希表创建成功，大小为 %d\n", size);
            else
                printf("创建失败！\n");
            break;
        case 2:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("请输入要插入的关键字: ");
            scanf("%d", &key);
            if (htc_insert(ht, key))
                printf("插入成功！\n");
            else
                printf("插入失败（关键字已存在）！\n");
            break;
        case 3:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("请输入要查找的关键字: ");
            scanf("%d", &key);
            if (htc_search(ht, key))
                printf("找到关键字 %d！\n", key);
            else
                printf("未找到关键字 %d！\n", key);
            break;
        case 4:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("请输入要删除的关键字: ");
            scanf("%d", &key);
            if (htc_delete(ht, key))
                printf("删除成功！\n");
            else
                printf("删除失败（关键字不存在）！\n");
            break;
        case 5:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            htc_traverse(ht);
            break;
        case 6:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("装载因子: %.2f\n", htc_load_factor(ht));
            break;
        case 0:
            if (ht) { htc_destroy(ht); ht = NULL; }
            return;
        default:
            printf("无效选择！\n");
        }
    }
}

static void open_addressing_menu() {
    HashTableOA *ht = NULL;
    int choice, key, size;
    while (1) {
        printf("\n===== 开放地址法哈希表（线性探测）=====\n");
        printf("1. 创建哈希表\n");
        printf("2. 插入关键字\n");
        printf("3. 查找关键字\n");
        printf("4. 删除关键字\n");
        printf("5. 遍历哈希表\n");
        printf("6. 查看装载因子\n");
        printf("0. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (ht) {
                htoa_destroy(ht);
                ht = NULL;
            }
            printf("请输入哈希表大小: ");
            scanf("%d", &size);
            ht = htoa_create(size);
            if (ht)
                printf("哈希表创建成功，大小为 %d\n", size);
            else
                printf("创建失败！\n");
            break;
        case 2:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("请输入要插入的关键字: ");
            scanf("%d", &key);
            if (htoa_insert(ht, key))
                printf("插入成功！\n");
            else
                printf("插入失败（表满或关键字已存在）！\n");
            break;
        case 3:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("请输入要查找的关键字: ");
            scanf("%d", &key);
            {
                int pos = htoa_search(ht, key);
                if (pos != -1)
                    printf("找到关键字 %d，位于槽位 %d！\n", key, pos);
                else
                    printf("未找到关键字 %d！\n", key);
            }
            break;
        case 4:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("请输入要删除的关键字: ");
            scanf("%d", &key);
            if (htoa_delete(ht, key))
                printf("删除成功（懒删除）！\n");
            else
                printf("删除失败（关键字不存在）！\n");
            break;
        case 5:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            htoa_traverse(ht);
            break;
        case 6:
            if (!ht) { printf("请先创建哈希表！\n"); break; }
            printf("装载因子: %.2f\n", htoa_load_factor(ht));
            break;
        case 0:
            if (ht) { htoa_destroy(ht); ht = NULL; }
            return;
        default:
            printf("无效选择！\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n========== 哈希表演示 ==========\n");
        printf("1. 链地址法（Separate Chaining）\n");
        printf("2. 开放地址法（Open Addressing - 线性探测）\n");
        printf("0. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            chaining_menu();
            break;
        case 2:
            open_addressing_menu();
            break;
        case 0:
            printf("再见！\n");
            return 0;
        default:
            printf("无效选择！\n");
        }
    }
    return 0;
}
