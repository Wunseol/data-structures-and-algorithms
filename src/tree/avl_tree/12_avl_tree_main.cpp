#include "12_avl_tree.h"
#include <cstdio>

static void print_menu(void)
{
    printf("\n========== AVL树操作菜单 ==========\n");
    printf("  1. 插入节点\n");
    printf("  2. 删除节点\n");
    printf("  3. 查找节点\n");
    printf("  4. 中序遍历\n");
    printf("  5. 先序遍历\n");
    printf("  6. 后序遍历\n");
    printf("  7. 验证平衡性\n");
    printf("  0. 退出\n");
    printf("===================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    AVLTree tree;
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
            printf("请输入要插入的值: ");
            if (scanf("%d", &key) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            tree.Insert(key);
            printf("插入成功\n");
            tree.InOrder();
            break;
        }
        case 2: {
            int key;
            printf("请输入要删除的值: ");
            if (scanf("%d", &key) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            tree.Delete(key);
            printf("删除完成\n");
            tree.InOrder();
            break;
        }
        case 3: {
            int key;
            printf("请输入要查找的值: ");
            if (scanf("%d", &key) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            AVLNode *result = tree.Search(key);
            if (result)
                printf("找到节点: %d (高度=%d, 平衡因子=%d)\n",
                       result->key, result->height,
                       (result->left ? result->left->height : 0) -
                       (result->right ? result->right->height : 0));
            else
                printf("未找到节点 %d\n", key);
            break;
        }
        case 4:
            tree.InOrder();
            break;
        case 5:
            tree.PreOrder();
            break;
        case 6:
            tree.PostOrder();
            break;
        case 7:
            if (tree.VerifyBalance())
                printf("AVL树平衡性验证通过，所有节点平衡因子在[-1,1]范围内\n");
            else
                printf("AVL树平衡性验证失败，存在不平衡节点\n");
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
