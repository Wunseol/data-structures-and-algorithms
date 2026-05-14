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
    SqList L4;

void menu();//建立功能菜单
int SetupList();//建立顺序表
int CheckLocate();//按值查找
int Insert();
int Delete();
int MergeList();
int Merge(SqList L1,SqList L2,SqList L3);
int Intersection();
int Union();
int Reverse();


int InitList(SqList &L,int s);//初始化顺序表
int ListLength(const SqList &L);//求顺序表长度
int Locate(const SqList &L,const int &e);//按值查找
int GetData(const SqList &L,int i,int &e);//获得顺序表第i个元素
int InsList(SqList &L,int i,const int e);//在顺序表第i个元素前插入一个元素
int DelList(SqList &L,int i,int &e);//删除顺序表第i个元素
void DestroyList(SqList &L);//销毁顺序表
void ClearList(SqList &L);//清空顺序表
int EmptyList(const SqList &L);//判断空表
void DispList(const SqList &L);//输出顺序表

int main()
{
    menu();
    printf("再见!!!");
    return 0;
}
void menu()
{
    int count=0;
    char ch;
    printf("\n================================");
    printf("\n");
    printf("功能菜单:\n");
    printf(" a.建立顺序表\n b.查找元素\n c.插入元素\n d.删除元素\n e.合并两个非递减顺序表\n f.求两个非递减顺序表的交集\n g.求两个非递减顺序表的并集\n h.逆置线性表\n z.退出\n");
    printf("================================\n");
    printf("请输入您的需求:");
    do{
        printf("请输入您的需求:");
        scanf("%c",&ch);
        getchar();
        switch (ch)
        {
        case 'a':
            SetupList();
            break;
        case 'b':
			CheckLocate();
			break;
		case 'c':
			Insert();
			break;
		case 'd':
			Delete();
			break;
		case 'e':
			MergeList();
			break;
		case 'f':
			Intersection();
			break;
		case 'g':
			Union();
			break;
		case 'h':
			Reverse();
			break;
		case 'z':
			break;
        default:
            printf("请重新输入!");
            printf("\n");
            getchar();
            break;
        }
    }while(ch!='z');

}

int SetupList()
{

    int n;
    InitList(L1,2);
    InitList(L2,2);
    InitList(L3,2);
    InitList(L4,2);
    for(int i=1;i<=5;i++){
        InsList(L1,i,i+1);
    }
    for(int i=1;i<=5;i++){
        InsList(L2,i,i);
    }
    printf("顺序表L1的元素:"); 
    DispList(L1);
    printf("\n");
    printf("顺序表L2的元素:"); 
    DispList(L2);
    printf("\n");
}
int CheckLocate()
{
    int n,e;
    while(1){
        printf("请输入所查找的顺序表的号数和所查找的元素:");
        scanf("%d %d",&n,&e);
        if(n==1){
            printf("输出位序为:%d\n比较次数为:%d\n",Locate(L1,e),Locate(L1,e)-1);
            break;
        }else if(n==2){
            printf("输出位序为:%d\n比较次数为:%d\n",Locate(L2,e),Locate(L2,e)-1);
            break;
        }else{
            printf("输入错误,请重新输入!");
        }
        break;
    }
}
int Insert()
{
    int locate,n,e;
    while(1){
        printf("在顺序表第i个元素前插入一个元素\n");
        printf("请输入:顺序表号数 插入元素的位置 插入元素:");
        scanf("%d %d %d",&n,&locate,&e);
        if(n==1){
            InsList(L1,locate,e);
            break;
        }else if(n==2){
            InsList(L2,locate,e);
            break;
        }else{
            printf("输入错误,请重新输入!");
        }
    }
    printf("OK!");
    printf("\n");
    printf("顺序表L1的元素:"); 
    DispList(L1);
    printf("\n");
    printf("顺序表L2的元素:"); 
    DispList(L2);
    printf("\n");

}
int Delete()
{
    int n,locate;
    int x;
    while(1){
        printf("删除顺序表第i个元素\n");
        printf("请输入:顺序表号数 删除元素的位置:");
        scanf("%d %d",&n,&locate);
        if(n==1){
            DelList(L1,locate,x);
            break;
        }else if(n==2){
            DelList(L2,locate,x);
            break;
        }else{
            printf("输入错误,请重新输入!");
        }
    }
    printf("OK!");
    printf("\n");
    printf("顺序表L1的元素:"); 
    DispList(L1);
    printf("\n");
    printf("顺序表L2的元素:"); 
    DispList(L2);
    printf("\n");
}
int MergeList()
{
    DispList(L3);
    Merge(L1,L2,L3);
}

int Merge(SqList L1,SqList L2,SqList L3)
{
    int i=1;
    int j=1;
    int k=0;
    int ai,aj;
    while((L1.length>=i)&&(L2.length>=j)){
        GetData(L1,i,ai);GetData(L2,j,aj);
        if(ai<=aj){InsList(L3,k++,ai);++i;}
        else{InsList(L3,++k,aj);++j;}
    }
    while(i<=L1.length)
    {
        GetData(L1,i++,ai);
        InsList(L3,++k,ai);
    }
    while (j<=L2.length)
    {
        GetData(L2,j++,aj);
        InsList(L3,++k,aj);
    }
    DispList(L3);
    printf("\n");
}

int Intersection()
{
    InitList(L3,4);
    int i,j,k=1;
    int ai,aj;
    for(i=1;i<=L1.length;i++){
        for(j=1;j<=L2.length;j++){
            GetData(L1,i,ai);GetData(L2,j,aj);
            if(ai==aj){
                InsList(L3,k++,ai);
            }
        }
    }
    if(k==0){
        printf("无交集\n");
    }
    DispList(L3);
    printf("\n");
}
int Union()
{
    int L1_len,L2_len;
    int e;
    L1_len=ListLength(L1);
    L2_len=ListLength(L2);
    for(int i=1;i<=L2_len;i++){
        GetData(L2,i,e);
        if(!Locate(L1,e)){
            InsList(L1,++L1_len,e);
        }
    }
    DispList(L1);
    printf("\n");
}
int Reverse()
{
    int i,j,n,tp;
    int e,e1,e2;
    
    while(1){
        printf("请输入:顺序表号数:");
        scanf("%d",&n);
        if(n==1){
            ClearList(L4);
            j=ListLength(L1);
            // j=ListLength(L1);
            // printf("%d\n",ListLength(L1));
            // printf("%d\n",GetData(L1,j,e));
            // GetData(L1,j,e);
            // printf("%d\n",e);
            for(i=1;i<=L1.length;i++,j--){
                GetData(L1,j,e);
                InsList(L4,i,e);
            }
            break;
        }else if(n==2){
            ClearList(L4);
            j=ListLength(L2);
            for(i=1;i<=L2.length;i++,j--){
                GetData(L2,j,e);
                InsList(L4,i,e);
            }
            break;
        }else if(n==3){
            ClearList(L4);
            j=ListLength(L3);
            for(i=1;i<=L3.length;i++,j--){
                GetData(L3,j,e);
                InsList(L4,i,e);
            }
            break;
        }else{
            printf("输入错误,请重新输入!");
        }
    }
    DispList(L4);
    printf("\n");
}

int InitList(SqList &L,int s)//初始化顺序表
{
    if(s<=0)s=10;
    L.data=new int [s];
    if(L.data==NULL)return false;
    L.size=s;
    L.length=0;
}
int ListLength(const SqList &L)//求顺序表长度
{
    return L.length;
}
int Locate(const SqList &L,const int &e)//按值查找,输出位序和比较次数
{
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e)return i+1;
    }
    return false;
}
int GetData(const SqList &L,int i,int &e)//获得顺序表第i个元素
{
    if(i>=1&&i<=L.length)
    {
        e=L.data[i-1];
        return true;
    }
    return false;
}
int InsList(SqList &L,int i,const int e)//在顺序表第i个元素前插入一个元素
{
    if(i<1||i>L.length+1) return false;
    if(L.size==L.length){
        int *temp=new int [2*L.size];
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
int DelList(SqList &L,int i,int &e)//删除顺序表第i个元素
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
void DestroyList(SqList &L)//销毁顺序表
{
    delete []L.data;
    L.data=NULL;
    L.size=0;
    L.length=0;
}
void ClearList(SqList &L)//清空顺序表
{
    L.length=0;
}
int EmptyList(const SqList &L)//判断空表
{
    if(L.length==0)return true;
    else return false;
}
void DispList(const SqList &L)//输出顺序表
{
    for(int i=0;i<L.length;i++)
    printf("%d ",L.data[i]);
}


