#include "linked_queue.h"
#include <stdio.h>

static void print_menu(void)
{
    printf("\n========== 链式队列操作菜单 ==========\n");
    printf("  1. 初始化队列\n");
    printf("  2. 销毁队列\n");
    printf("  3. 判断队列是否为空\n");
    printf("  4. 入队\n");
    printf("  5. 出队\n");
    printf("  6. 获取队头元素\n");
    printf("  7. 求队列长度\n");
    printf("  8. 遍历队列\n");
    printf("  0. 退出\n");
    printf("======================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    LinkQueue Q;
    QElemType e;
    int choice;
    bool initialized = false;

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
            if (initialized)
                DestroyQueue(&Q);
            InitQueue(&Q);
            initialized = true;
            printf("队列初始化成功\n");
            break;
        case 2:
            if (!initialized) {
                printf("请先初始化队列\n");
                break;
            }
            DestroyQueue(&Q);
            initialized = false;
            printf("队列已销毁\n");
            break;
        case 3:
            if (!initialized) {
                printf("请先初始化队列\n");
                break;
            }
            printf("队列%s空\n", QueueEmpty(&Q) ? "为" : "不");
            break;
        case 4:
            if (!initialized) {
                printf("请先初始化队列\n");
                break;
            }
            printf("请输入入队元素: ");
            if (scanf("%d", &e) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            if (EnQueue(&Q, e))
                printf("入队成功\n");
            else
                printf("入队失败，内存分配失败\n");
            break;
        case 5:
            if (!initialized) {
                printf("请先初始化队列\n");
                break;
            }
            if (DeQueue(&Q, &e))
                printf("出队成功，出队元素: %d\n", e);
            else
                printf("出队失败，队列为空\n");
            break;
        case 6:
            if (!initialized) {
                printf("请先初始化队列\n");
                break;
            }
            if (GetHead(&Q, &e))
                printf("队头元素: %d\n", e);
            else
                printf("获取失败，队列为空\n");
            break;
        case 7:
            if (!initialized) {
                printf("请先初始化队列\n");
                break;
            }
            printf("队列长度为: %d\n", QueueLength(&Q));
            break;
        case 8:
            if (!initialized) {
                printf("请先初始化队列\n");
                break;
            }
            QueueTraverse(&Q);
            break;
        case 0:
            if (initialized)
                DestroyQueue(&Q);
            printf("程序退出\n");
            return 0;
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    }
}
