#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int DataType;

typedef struct linknode{
	DataType data;
	struct linknode *next;
}LinkList;

//初始化
LinkList *InitList()
{
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head;
}

//头插法建表 
void CreateListH(LinkList *head,int n)
{
	LinkList *s;
	int i;
	printf("请输入%d个整数:",n);
	for(i=0;i<n;i++){
		s=(LinkList *)malloc(sizeof(LinkList)) ;
		scanf("%d",&s->data);
		s->next=head->next;
		head->next=s;
	}
	printf("创建链表head操作成功！"); 
}

//尾插法建表 
void CreateListL(LinkList *head ,int n)
{ 
	LinkList *s,*last;
	int i;
	last=head;
	printf("请输入%d整数:",n);
	for(i=0;i<n;i++){
		s=(LinkList *)malloc(sizeof(LinkList)) ;
		scanf("%d",&s->data);
		s->next=NULL;
		last->next=s;
		last=s;
	}
    printf("创建链表head操作成功！"); 
} 

//求表长 
int LengthList(LinkList *head)
{
	LinkList *p=head->next;
	int j=0;
	while(p!=NULL){
		p=p->next;
		j++;
	}
	printf("链表head长度为%d",j);
}

//按值查找 
void Locate(LinkList *head,DataType x)
{
	int j=1;
	LinkList *p;
	p=head->next;
	while(p!=NULL&&p->data!=x){
		p=p->next;
		j++;
	}
	if(p!=NULL){
		printf("在表的第%d位置找到值为%d的结点！",j,x);
	}else{
		printf("未找到值为%d的结点!",x);
	}
}

//插入值 
void InsList(LinkList *head,int i,DataType x)
{ 
	int j=0;
	LinkList *p,*s;
	p=head;
	while(p->next!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p!=NULL){
		s=(LinkList *)malloc(sizeof(LinkList)) ;
		s->data=x;
		s->next=p->next;
		p->next=s;
		printf("成功在第%d个位置插入%d元素",i,x);
		 
	}
	else{
		printf("插入失败！"); 
	}
}

//删除元素
void DelList(LinkList *head,int i)
{ 
	int j=0;
	DataType x;
	LinkList *p=head,*s;
	while(p->next!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p->next!=NULL&&j==i-1){
		s=p->next;
		x=s->data;
		p->next=s->next;
		free(s);
		printf("删除第%d位置上的元素%d成功！",i,x);
	} else{
		printf("删除失败！");
	}
}

//输出链表 
void Displist(LinkList *head)
{
	LinkList *p;
	p=head->next;
	while(p!=NULL){
		printf("%5d",p->data);
		p=p->next;
	}
}

//逆置链表
void ReverseList(LinkList *head)
{ 
	LinkList *prev,*curr,*next;
	prev=NULL;
	curr=head->next;
	while(curr){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head->next=prev;
	printf("链表head逆置成功！"); 
} 

//释放链表
void DestroyList(LinkList *head)
{ 
	LinkList *p;
	while(head){
		p=head;
		head=head->next;
		free(p);
	}
	printf("链表head成功销毁!"); 
}

void Menu()
{
	printf("\n        单链表序表操作顺序    ");
	printf("\n         1.--建立单链表       "); 
	printf("\n         2--查看单链表长度    "); 
	printf("\n         3--插入元素          ");  
	printf("\n         4--删除元素          ");
	printf("\n         5--按值查找元素      ");
	printf("\n         6--逆置单链表        ");  
	printf("\n         7--释放单链表        ");
	printf("\n         0--返回              ");   
	printf("\n请输入菜单号0~7："); 
}

int main()
{
	LinkList *head;
	DataType x;
	int n,i,loc;
	char ch1,ch2,a;
	ch1='y';
		while(ch1=='y'||ch1=='Y'){
		Menu();
		scanf(" %c",&ch2);
		getchar();
		switch(ch2){
			case '1':
				head=InitList();
				printf("要建立多少个元素的线性表："); 
				scanf("%d",&n);
				CreateListL(head,n);
				printf("\n");
				Displist(head);
				break;
			case '2':
			    LengthList(head);
				break;
			case '3':
				printf("插入前的链表head："); 
				Displist(head);
				printf("\n输入要插入元素的位置i:");
				scanf("%d",&i);
				printf("输入要插入的整数x:");
				scanf("%d",&x);
				InsList(head,i,x);
				printf("\n插入后的链表head：");
				Displist(head); 
				break; 
			case '4':
				printf("删除前的链表head："); 
				Displist(head);
				printf("\n输入要删除元素的位置i:");
				scanf("%d",&i);
				DelList(head,i); 
				printf("\n删除后的链表head：");
				Displist(head);
				break; 
			case '5':
				printf("链表head:");
				Displist(head);
				printf("\n输入要查找元素的数值：");
				scanf("%d",&x);
			    Locate(head,x);
				break;
            case '6':
				printf("逆置前的链表："); 
			    ReverseList(head);
			    printf("\n逆置后的链表head：");
				Displist(head); 
				break;
			case '7':
			    DestroyList(head);
			    break;
			case '0':
				ch1='n';
				break;
			default:
				printf("输入错误！！请输入0~9进行选择！");
		}
		if(ch2!='0'){
			printf("\n按回车键继续，按任意键返回主菜单！\n");
			a=getchar();
			if(a!='\xA'){
				getchar();
				ch1='n';
			}
		}
	}
}
