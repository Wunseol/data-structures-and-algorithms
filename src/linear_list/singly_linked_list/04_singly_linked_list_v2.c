#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
typedef int Status;
// c语言中status的定义为typedef int status，status为int的一个同义词。
// 数据元（Data element）：又称数据类型，通过定义、标识、表示以及允许值等一系 列属性描述的数据单元。
// 在特定的语义环境中被认为是不可再分的最小数据单元。

#define MAXSIZE 20
typedef int ElemType;

typedef struct Node//单链表
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

void menu(LinkList *L1);
LinkList InitList();
Status LengthList(LinkList L);
Status Locate(LinkList L,int i,ElemType *e);
Status GetElem(LinkList L,ElemType e);
Status ListInsert(LinkList *L,int i,ElemType e);
Status ListDelete(LinkList *L,int i,ElemType *e);
void CreateListHead(LinkList *L,int n);
void CreateListTail(LinkList *L,int n);
Status ClearList(LinkList *L);
void Reverse(LinkList L);
void DisplayList(LinkList L);



int main()
{
    LinkList L1=NULL;
    menu(&L1);
}

LinkList InitList()
{
    LinkList L;
    L=(Node*)malloc(sizeof(Node));
    L->data=0;
    L->next=NULL;
    printf("初始化成功!\n");
    return L;
}

//求表长 
Status LengthList(LinkList L)
{
	LinkList p=L->next;
	int j=0;
	while(p!=NULL){
		p=p->next;
		j++;
	}
	printf("链表head长度为%d",j);
}

//用e返回L中第i个元素的值,按位置查找
Status Locate(LinkList L,int i,ElemType *e)//单链表查找
{
    int j;
    LinkList p;
    p=L->next;
    j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)return ERROR;
    *e=p->data;
    return OK;
}

//按值查找
Status GetElem(LinkList L,ElemType e)
{
    int j=1;
    LinkList p;
    p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
        j++;
    }
    if(p!=NULL){
		printf("在表的第%d位置找到值为%d的结点!",j,e);
	}else{
		printf("未找到值为%d的结点!",e);
	}
}

//在L中的第i个位置前插入新的数据e
Status ListInsert(LinkList *L,int i,ElemType e)//单链表插入值
{
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)return ERROR;
    s=(LinkList)malloc(sizeof(Node));//生成新结点;malloc() 函数用来动态地分配内存空间
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

//删除L的第i个元素，并用e返回其值，L的长度减一
Status ListDelete(LinkList *L,int i,ElemType *e)//单链表删除元素
{//
    int j;
    LinkList p,q;
    p=*L;
    j=1;
    while(p->next&&j<i){
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i)return ERROR;
    q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);//free()是C语言中释放内存空间的函数，通常与申请内存空间的函数malloc()结合使用，可以释放由 malloc()、calloc()、realloc() 等函数申请的内存空间。
    return OK;
}

//随机产生n个元素的值，建立带表头结点的单链表L（头插法
void CreateListHead(LinkList *L,int n)//单链表头插法建表
{
    LinkList p;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=(*L)->next;
        (*L)->next=p;
    }
}

//随机产生n个元素的值，建立带表头结点的单链表L（尾插法
void CreateListTail(LinkList *L,int n)//单链表尾插法建表
{
    LinkList p,r;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    r=*L;
    for(i=0;i<n;i++){
        p=(Node *)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

//将L置空,释放单链表
Status ClearList(LinkList *L)//清空单链表
{
    LinkList p,q;
    p=(*L)->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return OK;
}

//逆置单链表
void Reverse(LinkList L)
{ 
	LinkList prev,curr,next;
	prev=NULL;
	curr=L->next;
	while(curr){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	L->next=prev;
	printf("链表head逆置成功!"); 
} 

//输出链表 
void DisplayList(LinkList L)
{
	LinkList p;
	p=L->next;
	while(p!=NULL){
		printf("%5d",p->data);
		p=p->next;
	}
}

void menu(LinkList *L1)
{
    int n,x,i;
    ElemType e;
    char ch;
    printf("\n================================");
    printf("\n");
    printf("功能菜单:\n");
    printf(" a.初始化单链表\n b.头插法建表\n c.尾插法建表\n d.求表长\n e.单链表删除元素\n f.单链表插入元素\n g.单链表查找元素\n h.逆置单链表\n i.释放单链表\n z.退出\n");
    printf("================================\n");
    do{
        printf("请输入您的需求:");
        scanf(" %c",&ch);
        switch (ch)
        {
        case 'a':
            *L1=InitList();
            break;
        case 'b':
            printf("头插法建立带表头结点的单链表L,随机产生n个元素的值,n为:");
            scanf("%d",&n);
            CreateListHead(L1,n);
            DisplayList(*L1);
            break;
        case 'c':
            printf("尾插法建立带表头结点的单链表L,随机产生n个元素的值,n为:");
            scanf("%d",&n);
            CreateListTail(L1,n);
            DisplayList(*L1);
            break;
        case 'd':
            LengthList(*L1);
            break;
        case 'e':
            printf("请输入要删除的位置:");
            scanf("%d",&i);
            if(ListDelete(L1,i,&e))
                printf("删除的元素为:%d\n",e);
            DisplayList(*L1);
            break;
        case 'f':
            printf("请输入要插入的位置:");
            scanf("%d",&i);
            printf("请输入要插入的元素值:");
            scanf("%d",&x);
            ListInsert(L1,i,x);
            DisplayList(*L1);
            break;
        case 'g':
            printf("请输入要查找的元素值:");
            scanf("%d",&x);
            GetElem(*L1,x);
            break;
        case 'h':
            Reverse(*L1);
            DisplayList(*L1);
            break;
        case 'i':
            ClearList(L1);
            DisplayList(*L1);
            break;
        case 'z':
            break;
        default:
            printf("请重新输入!");
            printf("\n");
            break;
        }
    }while(ch!='z');
}
