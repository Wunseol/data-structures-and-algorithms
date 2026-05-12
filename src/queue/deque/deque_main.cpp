#include "deque.h"
#include <cstdio>

static void print_menu(void)
{
    printf("\n========== 双端队列操作菜单 ==========\n");
    printf("  1. 初始化双端队列\n");
    printf("  2. 前端入队 (PushFront)\n");
    printf("  3. 后端入队 (PushBack)\n");
    printf("  4. 前端出队 (PopFront)\n");
    printf("  5. 后端出队 (PopBack)\n");
    printf("  6. 获取前端元素 (GetFront)\n");
    printf("  7. 获取后端元素 (GetBack)\n");
    printf("  8. 判断是否为空\n");
    printf("  9. 求队列大小\n");
    printf("  10. 遍历双端队列\n");
    printf("  0. 退出\n");
    printf("======================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    Deque D;
    DElemType e;
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
            InitDeque(&D);
            initialized = true;
            printf("双端队列初始化成功\n");
            break;
        case 2:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            printf("请输入前端入队元素: ");
            if (scanf("%d", &e) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            if (PushFront(&D, e))
                printf("前端入队成功\n");
            else
                printf("前端入队失败，双端队列已满\n");
            break;
        case 3:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            printf("请输入后端入队元素: ");
            if (scanf("%d", &e) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            if (PushBack(&D, e))
                printf("后端入队成功\n");
            else
                printf("后端入队失败，双端队列已满\n");
            break;
        case 4:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            if (PopFront(&D, &e))
                printf("前端出队成功，出队元素: %d\n", e);
            else
                printf("前端出队失败，双端队列为空\n");
            break;
        case 5:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            if (PopBack(&D, &e))
                printf("后端出队成功，出队元素: %d\n", e);
            else
                printf("后端出队失败，双端队列为空\n");
            break;
        case 6:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            if (GetFront(&D, &e))
                printf("前端元素: %d\n", e);
            else
                printf("获取失败，双端队列为空\n");
            break;
        case 7:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            if (GetBack(&D, &e))
                printf("后端元素: %d\n", e);
            else
                printf("获取失败，双端队列为空\n");
            break;
        case 8:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            printf("双端队列%s空\n", DequeEmpty(&D) ? "为" : "不");
            break;
        case 9:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            printf("双端队列大小: %d\n", DequeSize(&D));
            break;
        case 10:
            if (!initialized) {
                printf("请先初始化双端队列\n");
                break;
            }
            DequeTraverse(&D);
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
