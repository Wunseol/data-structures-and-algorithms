#include "doubly_linked_list.h"

int main(void)
{
    DuLinkList L = NULL;
    char ch;
    int i, n;
    ElemType e;

    while (1) {
        printf("\n");
        printf("\t\t              双向链表操作  \n");
        printf("\t\t======================================\n");
        printf("\t\t             1：创建链表(头插法)       \n");
        printf("\t\t             2：创建链表(尾插法)       \n");
        printf("\t\t             3：插入元素              \n");
        printf("\t\t             4：删除元素              \n");
        printf("\t\t             5：查找元素位置          \n");
        printf("\t\t             6：获取指定位置元素      \n");
        printf("\t\t             7：正向遍历              \n");
        printf("\t\t             8：反向遍历              \n");
        printf("\t\t             9：链表长度              \n");
        printf("\t\t             0：退出                  \n");
        printf("\t\t======================================\n");
        printf("\t\t请选择: ");

        scanf(" %c", &ch);

        switch (ch) {
        case '1':
            if (L != NULL) {
                DestroyList(L);
                L = NULL;
            }
            L = InitDuList();
            printf("输入元素个数: ");
            scanf("%d", &n);
            CreateDuListHead(L, n);
            printf("头插法创建的链表: ");
            ListTraverse(L);
            break;
        case '2':
            if (L != NULL) {
                DestroyList(L);
                L = NULL;
            }
            L = InitDuList();
            printf("输入元素个数: ");
            scanf("%d", &n);
            CreateDuListTail(L, n);
            printf("尾插法创建的链表: ");
            ListTraverse(L);
            break;
        case '3':
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("输入插入位置和元素值(位置 元素): ");
            scanf("%d %d", &i, &e);
            if (ListInsert(L, i, e)) {
                printf("插入成功! 链表: ");
                ListTraverse(L);
            }
            break;
        case '4':
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("输入删除位置: ");
            scanf("%d", &i);
            if (ListDelete(L, i, &e)) {
                printf("删除成功! 删除的元素为: %d\n", e);
                printf("链表: ");
                ListTraverse(L);
            }
            break;
        case '5':
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("输入要查找的元素: ");
            scanf("%d", &e);
            i = LocateElem(L, e);
            if (i == 0) {
                printf("元素 %d 不在链表中!\n", e);
            } else {
                printf("元素 %d 的位置为: %d\n", e, i);
            }
            break;
        case '6':
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("输入要获取的位置: ");
            scanf("%d", &i);
            if (GetElem(L, i, &e)) {
                printf("位置 %d 的元素为: %d\n", i, e);
            }
            break;
        case '7':
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("正向遍历: ");
            ListTraverse(L);
            break;
        case '8':
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("反向遍历: ");
            ListTraverseBack(L);
            break;
        case '9':
            if (L == NULL) {
                printf("链表未创建，请先创建链表!\n");
                break;
            }
            printf("链表长度为: %d\n", ListLength(L));
            break;
        case '0':
            if (L != NULL) {
                DestroyList(L);
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
