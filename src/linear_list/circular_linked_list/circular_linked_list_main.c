#include "circular_linked_list.h"

int main(void)
{
    CiLinkList L = NULL;
    CiLinkList La = NULL, Lb = NULL, Lc = NULL;
    int choice;
    int i, n;
    ElemType e;

    while (1) {
        printf("\n\n");
        printf("\t\t              循环链表操作  \n");
        printf("\t\t======================================\n");
        printf("\t\t             1：创建循环链表\n");
        printf("\t\t             2：插入元素\n");
        printf("\t\t             3：删除元素\n");
        printf("\t\t             4：遍历链表\n");
        printf("\t\t             5：求链表长度\n");
        printf("\t\t             6：合并两个有序循环链表\n");
        printf("\t\t             0：退出\n");
        printf("\n");
        printf("\t\t请选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (L != NULL) {
                DestroyList(L);
                L = NULL;
            }
            L = InitCiList();
            printf("请输入元素个数: ");
            scanf("%d", &n);
            CreateCiListTail(L, n);
            printf("创建的循环链表为: ");
            ListTraverse(L);
            break;

        case 2:
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("当前链表: ");
            ListTraverse(L);
            printf("请输入插入位置和元素值(如: 2 10): ");
            scanf("%d %d", &i, &e);
            if (ListInsert(L, i, e)) {
                printf("插入成功! 插入后的链表: ");
                ListTraverse(L);
            }
            break;

        case 3:
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("当前链表: ");
            ListTraverse(L);
            printf("请输入删除位置: ");
            scanf("%d", &i);
            if (ListDelete(L, i, &e)) {
                printf("删除成功! 删除的元素为: %d\n", e);
                printf("删除后的链表: ");
                ListTraverse(L);
            }
            break;

        case 4:
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("循环链表: ");
            ListTraverse(L);
            break;

        case 5:
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("循环链表长度为: %d\n", ListLength(L));
            break;

        case 6:
            if (La != NULL) {
                DestroyList(La);
                La = NULL;
            }
            if (Lb != NULL) {
                DestroyList(Lb);
                Lb = NULL;
            }
            if (Lc != NULL) {
                DestroyList(Lc);
                Lc = NULL;
            }

            La = InitCiList();
            printf("请输入第一个有序链表的元素个数: ");
            scanf("%d", &n);
            CreateCiListTail(La, n);

            Lb = InitCiList();
            printf("请输入第二个有序链表的元素个数: ");
            scanf("%d", &n);
            CreateCiListTail(Lb, n);

            Lc = InitCiList();
            MergeCiList(La, Lb, Lc);

            printf("合并后的有序循环链表: ");
            ListTraverse(Lc);

            DestroyList(La);
            La = NULL;
            DestroyList(Lb);
            Lb = NULL;
            DestroyList(Lc);
            Lc = NULL;
            break;

        case 0:
            if (L != NULL) {
                DestroyList(L);
                L = NULL;
            }
            printf("程序退出!\n");
            return 0;

        default:
            printf("无效选择，请重新输入!\n");
            break;
        }
    }

    return 0;
}
