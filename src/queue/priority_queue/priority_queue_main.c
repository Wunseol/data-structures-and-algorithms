#include "priority_queue.h"
#include <stdio.h>

static void print_menu(void)
{
    printf("\n========== 优先队列操作菜单 ==========\n");
    printf("  1. 创建优先队列\n");
    printf("  2. 插入元素\n");
    printf("  3. 取出最大元素\n");
    printf("  4. 查看最大元素\n");
    printf("  5. 判断是否为空\n");
    printf("  6. 查询元素个数\n");
    printf("  7. 自测\n");
    printf("  0. 退出\n");
    printf("======================================\n");
    printf("请选择操作: ");
}

static void self_test(void)
{
    printf("\n----- 优先队列自测 -----\n");
    PriorityQueue *pq = PQCreate(20);
    printf("创建容量为20的优先队列\n");

    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("插入元素: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        PQInsert(pq, arr[i]);
    }
    printf("\n");

    printf("队列大小: %d\n", PQSize(pq));
    printf("是否为空: %s\n", PQIsEmpty(pq) ? "是" : "否");

    PQElemType top;
    if (PQPeek(pq, &top))
        printf("当前最大元素: %d\n", top);

    printf("依次取出最大元素: ");
    while (!PQIsEmpty(pq)) {
        PQElemType item;
        PQExtractMax(pq, &item);
        printf("%d ", item);
    }
    printf("\n");

    printf("取出后是否为空: %s\n", PQIsEmpty(pq) ? "是" : "否");

    PQDestroy(pq);
    printf("----- 自测完成 -----\n");
}

int main(void)
{
    PriorityQueue *pq = NULL;
    int choice;
    int max_size, item;

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
            if (pq != NULL) {
                PQDestroy(pq);
            }
            printf("请输入最大容量: ");
            if (scanf("%d", &max_size) != 1 || max_size <= 0) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            pq = PQCreate(max_size);
            if (pq != NULL)
                printf("优先队列创建成功, 容量: %d\n", max_size);
            break;
        case 2:
            if (pq == NULL) {
                printf("请先创建优先队列\n");
                break;
            }
            printf("请输入要插入的元素: ");
            if (scanf("%d", &item) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            if (PQInsert(pq, item))
                printf("插入成功, 当前大小: %d\n", PQSize(pq));
            break;
        case 3:
            if (pq == NULL) {
                printf("请先创建优先队列\n");
                break;
            }
            if (PQExtractMax(pq, &item))
                printf("取出最大元素: %d, 剩余大小: %d\n", item, PQSize(pq));
            break;
        case 4:
            if (pq == NULL) {
                printf("请先创建优先队列\n");
                break;
            }
            if (PQPeek(pq, &item))
                printf("当前最大元素: %d\n", item);
            break;
        case 5:
            if (pq == NULL) {
                printf("请先创建优先队列\n");
                break;
            }
            printf("优先队列%s空\n", PQIsEmpty(pq) ? "为" : "不");
            break;
        case 6:
            if (pq == NULL) {
                printf("请先创建优先队列\n");
                break;
            }
            printf("当前元素个数: %d\n", PQSize(pq));
            break;
        case 7:
            self_test();
            break;
        case 0:
            if (pq != NULL)
                PQDestroy(pq);
            printf("程序退出\n");
            return 0;
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    }
}
