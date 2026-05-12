#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef struct sqlist
{
    int data[N];
    int length;

}list;

struct list *create(n)
{
    list *li;
    li=(list*)(malloc)(sizeof(list));
    li->length=0;
    int k=1;
    int i=0;
    printf("加入:");
    for(k=1;k<=n;k++){
        scanf("%d",&li->data[i]);
        i++;
        li->length++;
    }
    return li;

}
int main()
{
    int n=0;
    printf("请输入顺序表表长:");
    scanf("%d",&n);
    list *prt;
    int i=0;
    prt=create(n);
    printf("建立的顺序表为:");
    for(prt->length,i=0;prt->length>=1;prt->length--,i++){
        printf("%d ",prt->data[i]);
    }
}