#include <stdio.h>
void menu()
{
    int count=0;
    char ch;
    do{
        printf("\n================================\n");
        printf("\n");
        printf("功能菜单:\n");
        printf(" a.建立顺序表\n b.查找元素\n c.插入元素\n d.删除元素\n e.合并两个非递减顺序表\n f.求两个非递减顺序表的交集\n g.求两个非递减顺序表的并集\n h.逆置线性表\n z.退出\n");
        printf("\n================================\n");
        printf("请输入您的需求:");
        scanf("%c",&ch);
        getchar();
        switch (ch)
        {
        case 'a':
            // Setuplist();
            break;
        default:
            printf("请重新输入");
            break;
        }
    }while(ch!='z');
}

int main()
{
    menu();
    return 0;
}