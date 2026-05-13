#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status;
// c语言中status的定义为typedef int status，status为int的一个同义词。
// 数据元（Data element）：又称数据类型，通过定义、标识、表示以及允许值等一系 列属性描述的数据单元。
// 在特定的语义环境中被认为是不可再分的最小数据单元。

#define MAXSIZE 20
typedef int ElemType;

typedef struct
{
    ElemType date[MAXSIZE];
    int length;
}SqList;

Status GetElem(SqList L,int i,ElemType *e)//顺序表
{
    if(L.length==0||i<1||i<L.length)return ERROR;
    *e=L.date[i-1];
    return OK;
}

Status ListInsert(SqList *L,int i,ElemType e)//顺序表
{
    int k;
    if(L->length==MAXSIZE)return ERROR;
    if(i<1||i>L->length+1)return ERROR;
    if(i<=L->length){
        for(k=L->length-1;k>=i-1;k--)L->date[k+1]=L->date[k];
    }
    L->date[i-1]=e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e)//顺序表
{
    int k;
    if(L->length==0)return ERROR;
    if(i<1||i>L->length)return ERROR;
    *e=L->date[i-1];
    if(i<L->length){
        for(k=i;k<L->length;k++)L->date[k-1]=L->date[k];
    }
    L->length--;
    return OK;
}





























