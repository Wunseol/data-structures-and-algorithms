#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int *data;
    int  size;
    int length;
} SqList;//定义一个顺序表

    SqList L1;
    SqList L2;
    SqList L3;
int Reverse()
{
    int i,j,n,tp;
    int e,e1,e2;
    while(1){
        printf("请输入:顺序表号数:");
        scanf("%d",&n);
        if(n==1){
            // printf("%d",ListLength(L1));
            for(j=ListLength(L1),i=1;i>=j;j--,i++){
                GetData(L1,j,e);
                GetData(L1,i,e1);
                InsList(L1,j,e1);
                InsList(L1,i,e);
            }
            break;
        }else if(n==2){

            break;
        }else if(n==3){

            break;
        }else{
            printf("输入错误,请重新输入!");
        }
    }
    DispList(L1);
    printf("\n");

}
int main()
{

}

