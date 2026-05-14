#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int size;
    int length;
} SqList;

bool InitList(SqList &L,int s);//初始化
int ListLength(const SqList &L);
int Locate(const SqList &L,const ElemType &e);
bool GetData(const SqList &L,int i,ElemType &e);
bool InsList(SqList &L,int i,const ElemType e);
bool DelList(SqList &L,int i,ElemType &e);
void DestroyList(SqList &L);
void ClearList(SqList &L);
bool EmptyList(const SqList &L);
void DispList(const SqList &L);

int main()
{
    SqList L;
    InitList(L,2);
    // cout<<ListLength(L);
    for(int i=1;i<=5;i++){
        InsList(L,i,i+1);
    }
    // cout<<endl<<L.size;
    DispList(L);
    cout<<endl;
    int x;

    DelList(L,2,x);
    DispList(L);
    cout<<endl;
    cout<<x<<endl;

    return 0;
}

bool InitList(SqList &L,int s)
{
    if(s<=0)s=10;
    L.data=new ElemType[s];
    if(L.data==NULL)return false;
    L.size=s;
    L.length=0;
}
int ListLength(const SqList &L)
{
    return L.length;
}
int Locate(const SqList &L,const ElemType &e)
{
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e)return i+1;
    }
    return -1;
}
bool GetData(const SqList &L,int i,ElemType &e)
{
    if(i>=1&&i<=L.length)
    {
        e=L.data[i-1];
        return true;
    }
    return false;
}
bool InsList(SqList &L,int i,const ElemType e)
{
    if(i<1||i>L.length+1) return false;
    if(L.size==L.length){
        ElemType *temp=new ElemType[2*L.size];
        if(temp==NULL)return false;
        for(int i=0;i<L.length;i++){
            temp[i]=L.data[i];
        }
        delete[] L.data;
        L.data=temp;
        L.size=L.size*2;    
    }
    for(int k=L.length-1;k>=i-1;k--){
        L.data[k+1]=L.data[k];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
bool DelList(SqList &L,int i,ElemType &e)
{
    if(i>=1&&i<=L.length){
        e=L.data[i-1];
        for(int k=i;k<L.length;k++){
            L.data[k-1]=L.data[k];
        }
        L.length--;
        return true;
    }
    return false;
}
void DestroyList(SqList &L)
{
    delete []L.data;
    L.data=NULL;
    L.size=0;
    L.length=0;
}
void ClearList(SqList &L)
{
    L.length=0;
}
bool EmptyList(const SqList &L)
{
    if(L.length==0)return true;
    else return false;
}
void DispList(const SqList &L)
{
    for(int i=0;i<L.length;i++)
    cout<<L.data[i]<<" ";
}