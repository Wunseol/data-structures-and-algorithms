#include "min_heap.h"
#include <stdio.h>

static void print_menu(void)
{
    printf("\n========== 最小堆操作菜单 ==========\n");
    printf("  1. 初始化最小堆\n");
    printf("  2. 从数组构建最小堆\n");
    printf("  3. 插入元素\n");
    printf("  4. 提取最小值\n");
    printf("  5. 获取最小值\n");
    printf("  6. 堆排序\n");
    printf("  7. 遍历堆\n");
    printf("  0. 退出\n");
    printf("====================================\n");
    printf("请选择操作: ");
}

int main(void)
{
    MinHeap H;
    HeapElemType e;
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
            InitMinHeap(&H);
            initialized = true;
            printf("最小堆初始化成功\n");
            break;
        case 2: {
            if (!initialized) {
                printf("请先初始化最小堆\n");
                break;
            }
            int n;
            printf("请输入元素个数: ");
            if (scanf("%d", &n) != 1 || n < 1 || n > MAXSIZE) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            HeapElemType arr[MAXSIZE];
            printf("请输入%d个整数: ", n);
            for (int i = 0; i < n; i++) {
                if (scanf("%d", &arr[i]) != 1) {
                    while (getchar() != '\n')
                        ;
                    printf("输入无效\n");
                    n = i;
                    break;
                }
            }
            BuildMinHeap(&H, arr, n);
            printf("构建最小堆成功\n");
            HeapTraverse(&H);
            break;
        }
        case 3:
            if (!initialized) {
                printf("请先初始化最小堆\n");
                break;
            }
            printf("请输入要插入的元素: ");
            if (scanf("%d", &e) != 1) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            if (MinHeapInsert(&H, e))
                printf("插入成功\n");
            else
                printf("插入失败，堆已满\n");
            break;
        case 4:
            if (!initialized) {
                printf("请先初始化最小堆\n");
                break;
            }
            if (ExtractMin(&H, &e))
                printf("提取成功，最小值: %d\n", e);
            else
                printf("提取失败，堆为空\n");
            break;
        case 5:
            if (!initialized) {
                printf("请先初始化最小堆\n");
                break;
            }
            if (GetMin(&H, &e))
                printf("当前最小值: %d\n", e);
            else
                printf("获取失败，堆为空\n");
            break;
        case 6: {
            int n;
            printf("请输入排序元素个数: ");
            if (scanf("%d", &n) != 1 || n < 1 || n > MAXSIZE) {
                while (getchar() != '\n')
                    ;
                printf("输入无效\n");
                break;
            }
            HeapElemType arr[MAXSIZE];
            printf("请输入%d个整数: ", n);
            for (int i = 0; i < n; i++) {
                if (scanf("%d", &arr[i]) != 1) {
                    while (getchar() != '\n')
                        ;
                    printf("输入无效\n");
                    n = i;
                    break;
                }
            }
            MinHeapSort(arr, n);
            printf("排序结果(降序): ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            break;
        }
        case 7:
            if (!initialized) {
                printf("请先初始化最小堆\n");
                break;
            }
            HeapTraverse(&H);
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
