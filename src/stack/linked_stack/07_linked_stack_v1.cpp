#include<stdio.h>
#include<stdlib.h>

//存储结构定义
#define STACK_INIT_SIZE 100 
#define STACKINCREATEMENT 10
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1

typedef int SElemType;
typedef int Status;
typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;


//a.初始化栈
Status initstack(LinkStack &st)
{
	st=NULL;
	return OK;	  
}


//b.判断栈是否为空
Status StackEmpty(LinkStack st)
{
	if(st==NULL)
		 return TRUE;
	else
		 return FALSE;
}

//c.进栈
Status Push(LinkStack &st,int e )
{
	LinkStack p;
    p=new StackNode;

	p->data=e;
	p->next=st;
	st=p;
	return OK;
 }
 
  
//d.出栈
Status Pop(LinkStack &st,int &e)
{
	LinkStack p;
	if(st==NULL)//判断是否栈空 
		 return ERROR;
	e=st->data;
	p=st;
	st=st->next;
	delete p;
	return OK;
}


//e.取栈顶元素
Status GetTop(LinkStack st,int &e) 
{
    if(st==NULL)
		 return ERROR;
	e=st->data;
	return OK;
}


//打印
Status Printfstack(LinkStack &st) {
	if(st==NULL){
		printf("空栈！\n");
		return ERROR;
	}
	else{
		printf("栈的内容为：");
		LinkStack p=st;
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
	return OK;
}


int main(){
	LinkStack st;
	int x;//输入的数字
	if(initstack(st))
		 printf("初始化成功！\n");
		 
	while (1)
	{
		printf("请输入执行的操作：\n");
		printf("1 判断栈是否为空\ 2 入栈\ 3 出栈\ 4 取栈顶元素\ 5 打印\ 0 退出\n");
		
		scanf("%d",&x);
		if(x==0)
			 break;
		switch(x)
		{
			case 0:break;
			case 1:{
				int y;
			  if(!StackEmpty(st))
			     {
			     	printf("栈不为空！\n");
			     	GetTop(st,y);
			     	printf("栈顶元素为%d\n",y);
				 }
				 else{
			     	printf("栈为空！\n");
				 }
			break;}
			case 2:{
				int e;
				printf("请输入要进栈的元素:");
				scanf("%d",&e);
				if(Push(st,e))
					 printf("入栈成功！\n");
				else
					 printf("入栈失败！\n");
				break;}
			case 3:{
				int s;
				if(Pop(st,s))
					{
					 printf("元素%d出栈\n",s);}
				else
					 printf("出栈失败！\n");
				break;}
			case 4:{
				int e;
				if(GetTop(st,e))
				printf("栈顶元素为：%d\n",e);
				else
				printf("获得栈顶元素失败！\n");
				break;}
			case 5:
				if(Printfstack(st))
				   printf("打印完成！\n"); 
				   break;
			default:
				printf("错误操作！\n");
				break;
		}
	}
	return 0;
}