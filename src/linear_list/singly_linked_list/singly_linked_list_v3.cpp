#include <stdio.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max 10000

//定义结点类型
struct Node{
	int data;
	Node *next;
};

Node Head;       	//头结点
Node *DLList;		//头指针

Node Head1;   
Node *DLList1;

Node Head2;   
Node *DLList2;




void init(Node *DLList);//initialization初始化
void display(Node *DLList);
void insert(Node *DLList);
void search(Node *DLList);
void del(Node *DLList);
void ListInsert(Node *DLList);
void sort(Node *DLList);
void reverse(Node *DLList);
void MergeList(Node *DLList1,Node *DLList2);
void split(Node *DLList1,Node *DLList2);

int GetLengthList(Node *DLList);//Get表长 
void LengthList(Node *DLList);//求表长 


int main()
{
	char choice;

	DLList=&Head;     //使头指针指向头结点
	Head.next=NULL; 

	DLList1=&Head1;     //使头指针指向头结点
	Head1.next=NULL; 

	DLList2=&Head2;     //使头指针指向头结点
	Head2.next=NULL; 

	while (1)
	{
		system("cls");
		printf( "\n\n\n\n");
		printf( "\t\t              单链表操作  \n");
		printf( "\t\t======================================");
		printf( "\n\n");
		printf( "\t\t             1：初始化      	\n");
		printf( "\t\t             2：显示        	\n");
		printf( "\t\t             3：单个插入    	\n");
		printf( "\t\t             4：查找        	\n");
		printf( "\t\t             5：删除        	\n");
		printf( "\t\t             6：选择法排序      \n");
		printf( "\t\t             7：逆置链表        \n");
		printf( "\t\t             8：合并两链表    	 \n");
		printf( "\t\t             9：拆分链表    	 \n");
		printf( "\t\t             a：求表长        	 \n");
		printf( "\t\t             b：直接插入    	 \n");
		printf( "\t\t             0：退出        	 \n");
		printf( "\n");
		printf( "\t\t请选择：");

		choice = getch();
		system("cls");
		
		switch(choice)
		{
			case '1':
				init(DLList);
				init(DLList1);
				init(DLList2);
				break;
			case '2':
				display(DLList);
				printf("\n");
				display(DLList1);
				printf("\n");
				display(DLList2);
				system("pause");
				break;
			case '3':
				insert(DLList);
				break;
			case '4':
				search(DLList);
				break;
			case '5':
				del(DLList);
				break;
			case '6':
				sort(DLList);
				break;
			case '7':
				reverse(DLList);
				break;
			case '8':
				init(DLList1);
				init(DLList2);
				display(DLList1);
				printf("\n");
				display(DLList2);
				MergeList(DLList1,DLList2);
				break;
			case '9':
				init(DLList1);
				display(DLList1);
				printf("\n");
				split(DLList1,DLList2);
				break;
			case 'a':
				LengthList(DLList);
				printf("\n");
				LengthList(DLList1);
				printf("\n");
				LengthList(DLList2);
				break;
			case 'b':
				ListInsert(DLList);
				break;	
			case '0':
				exit(0);
		}
	}
}


//公用的等待函数
void wait()
{
	printf( "\n\n请按任意键继续");
	getch();
}

//1
//屏幕提示后，从键盘输入线性表长度和随机数种子，生成以DLList为头指针的指定长度的线性表
void init(Node *DLList)
{
	int length;
	Node *p,*q;
	while (1)
	{
	    printf("输入元素个数（0－ %d ）：" , max);
		scanf("%d",&length);
		if (length >= 0 && length <= 10000)
			break;
		
	}

    int i;
	while (1)
	{
	    printf( "输入随机数种子（0－32767）：" );
		scanf("%d",&i);
		if (i >= 0 && i <= 32767)
			break;
	
	}

    //从线性表中删除并释放原有的结点，使其成为空表
	p=DLList;
	while (p->next!=NULL)
	{
		q=p->next;
		p->next=q->next;
		free(q);
	}

	srand(i);  //指定随机数种子，相同的种子将产生相同的数据序列
	rand();  

	//向线性表插入length个新结点
    for (int j=1;j<=length;j++)    
    {
		p=new Node;
		p->next=DLList->next;
		DLList->next=p;
		p->data=rand() % 10000;
    }
}

//2
//在屏幕上依次显示以DLList为头指针的线性表中的全部元素和元素个数
//格式应便于观察
//如果需要指定输出的宽度，可以使用 cout << setw(W) << X ，其中 X 是输出的数值，W 是占据的列数
void display(Node *DLList)
{
	Node *p;
	p=DLList->next;

	while(p!=NULL){		//只要p指针指向的结点的next不是Null，就执行输出语句。
		printf("%d ",p->data);
		p=p->next;
	}
    printf("\n");

}

//4
//屏幕提示后，从键盘输入一个元素值，然后把这个新元素插到以DLList为头指针的线性表的末尾
void insert(Node *DLList)
{
	Node *p,*s;
	p=DLList->next;
	
	int e;
	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);
	while(p->next!=NULL){
		p=p->next;
	}
	if(p!=NULL){
		s=(Node *)malloc(sizeof(Node));
		s->data=e;
		s->next=p->next;
		p->next=s;
		printf("成功在末尾位置插入元素%d\n",e);
		display(DLList);
		wait();
	}else{
		printf("插入失败!\n"); 
		wait();
	}

}

//3
//屏幕提示后，从键盘输入一个元素值，在以DLList为头指针的线性表中搜索这个元素
void search(Node *DLList)
{
	Node *p;
	p=DLList->next;

	int count=0;
	int e;
	int j=1;
	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);
	while(p!=NULL&&p->data!=e){
		p=p->next;
		j++;
		count++;
	}
	if(p!=NULL){
		printf("在表的第%d位置找到值为%d的结点!\n",j,e);
		printf("比较次数为:%d\n",count);

	}else{
		printf("未找到值为%d的结点!\n",e);
	}
	wait();
}

//5
//屏幕提示后，从键盘输入一个元素值，在以DLList为头指针的线性表中删除这个元素
//屏幕显示删除成功与否的信息
void del(Node *DLList)
{
	Node *p,*s;
	p=DLList->next;

	int count=1;
	int j=0;
	int i=0,e;

	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);
	while(p!=NULL&&p->data!=e){
		p=p->next;
		i++;
	}
	
	p=DLList->next;

	while(p->next!=NULL&&j<i-1){
		p=p->next;
		j++;
		count++;
	}

	if(p->next!=NULL&&j==i-1){
		s=p->next;
		e=s->data;
		p->next=s->next;
		free(s);
		printf("删除第%d位置上的元素%d成功!\n",i+1,e);
		printf("比较次数为:%d\n",count);
		display(DLList);
		wait();
	}else{
		printf("删除失败！\n");
		wait();
	}
}

//6插入排序
//对已创建的链表(数据不限)进行直接插入排序
void sort(Node *DLList)
{
	Node *p,*pre,*q;
	// DLList=&Head;     	//使头指针指向头结点_将指针重新指向头结点
	p=DLList->next;
	p = DLList->next->next;		// 先保存下L的第二个元素，因为下一步要将L变成只有一个元素的有序表。  
	DLList->next->next = NULL;	// 将L变成只有一个元素的有序表
	// 从L的第二个元素开始遍历整个L直至表尾 
	while(p != NULL){
		q = p->next;
		pre = DLList;	// 先用pre来保存L。
		while(pre->next !=NULL && pre->next->data < p->data) // 遍历pre所指向的有序表L，直至找到比p大的节点 
			pre = pre->next; 
		p->next = pre->next;
		pre->next = p;
		p = q;	
	}
	printf("插入排序成功!\n");
	printf("插入排序后序列为:\n");
	display(DLList);
	wait();

}

//应用题

//7
// 6、将链接存储线性表逆置，即最后一个结点变成第1个结点，原来倒数第2个结点变成第2个结点，如此等等。
void reverse(Node *DLList)
{
	Node *p,*pre,*q;
	p=DLList->next;
    DLList->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        q->next=DLList->next;
        DLList->next=q;
    }
	printf("逆置成功!\n");
	printf("逆置后序列为:\n");
	display(DLList);
	wait();

}    
	

	
// 	7、生成有序的两个单链表A和B（链表的数据和个数自定），其首结点指针分别为a和b，要求将两
// 个单链表合并为一个有序的单链表C，其首结点指针为c，并且合并后的单链表的数据不重复。   

void MergeList(Node *DLList1,Node *DLList2)
{
	Node *p,*q,*r;
	p=DLList1->next;q=DLList2->next;
	r=DLList1;//
	while(1)
	{
		if(p!=NULL&&q!=NULL)
		{
			if(p->data<q->data) 
			{
				r->next=p;
				r=p;
				p=p->next;
			}
			else if(p->data>q->data)
			{
				r->next=q;
				r=q;
				q=q->next;
			}
			else
			{
				r->next=p;
				r=p;
				p=p->next;
				Node *temp=q;
				q=q->next;
				free(temp);
			}
		}
		else if(p==NULL)//任何一个单链表为null，就可以退出循环了
		{
			r->next=q;
			break;
		}
		else if(q==NULL)
		{
			r->next=p;
			break;
		}
	}
	sort(DLList1);
	system("cls");
	printf("合并完成!\n");
	printf("合并后的序列为:");
	display(DLList1);
	wait();
}

//     8、将一个首结点指针为a的单链表A分解成两个单链表A和B，其首结点指针分别为a和b，使得链表A中含有原链表A中序号为奇数的元素，而链表B中含有原链表A中序号为偶数的元素，且保持原来的相对顺序。

void split(Node *DLList1,Node *DLList2) 
{
	Node *p = DLList1;
	DLList2 = (Node*)malloc(sizeof(Node));
	DLList2->next = NULL;
	Node *q = DLList2;
	Node *r;
	int pos = 1;
	while(p->next != NULL){
		if(pos % 2 == 0){
			r = p->next;
			p->next = p->next->next;
			q->next = r;
			r->next = NULL;
			q = q->next;
		}else{
			p = p->next;		
		}
		pos++;
	}
	display(DLList1);
	printf("\n");
	display(DLList2);
	wait();
}


//附加功能

//Get表长 
int GetLengthList(Node *DLList)
{
	Node *p,*s;
	p=DLList->next;

	int j=0;
	while(p!=NULL){
		p=p->next;
		j++;
	}
	return j;
}

//求表长
void LengthList(Node *DLList)
{
	Node *p;
	p=DLList->next;

	int j=0;
	while(p!=NULL){
		p=p->next;
		j++;
	}
	printf("链表长度为%d",j);
	wait();
}

//单链表插入值
//在L中的第i个位置前插入新的数据e
void ListInsert(Node *DLList)
{
	Node *p,*s;
	p=DLList->next;

	int i,e;
    int j=1;
	printf("在L中的第i个位置插入新的数据e\n");
	printf("请输入所需插入的位置:");
	scanf("%d",&i);
	i=i-1;
	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);
	if(i>GetLengthList(DLList) || i<0){
		printf("输入位置错误！\n");
		printf("请重新输入!\n");
		wait();
	}else{
		while(p&&j<i){
			p=p->next;
			++j;
		}
		
		s=(Node *)malloc(sizeof(Node));//生成新结点;malloc() 函数用来动态地分配内存空间
		s->data=e;
		s->next=p->next;
		p->next=s;
		printf("插入成功!\n");
		display(DLList);
		wait();
	}

}
