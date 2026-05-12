#include<stdio.h>
#include<stdlib.h>

//存储结构定义
#define STACK_INIT_SIZE 100 
#define STACKINCREATEMENT 10
#define OVERFLOW -2
#define ERROR 0
#define OK 1


typedef int Status;
typedef struct{
	int *base;
	int *top;
	int stacksize;
}Sqstack;


//a.初始化栈
Status initstack(Sqstack &st)
{
	st.base=(int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if(!st.base)
	     exit(OVERFLOW);
	st.top=st.base;
	st.stacksize=STACK_INIT_SIZE;
	return OK;	  
}


//b.判断栈是否为空
Status StackEmpty(const Sqstack &st)
{
	if(st.top==st.base)
		 return OK;
	else
		 return ERROR;
}

//c.进栈
Status Push(Sqstack &st,int e )
{
	if(st.top-st.base>=st.stacksize){//判断是否栈满 
		 st.base=(int*)realloc(st.base,(st.stacksize+STACKINCREATEMENT)*sizeof(int));//追加存储空间
	if(!st.base)
		 exit(OVERFLOW);
	st.top=st.base+st.stacksize;
	st.stacksize+= STACKINCREATEMENT;} 
	*st.top=e;
	st.top++; 
	return OK;
 }
 
  
//d.出栈
Status Pop(Sqstack &st,int &e)
{
	if(st.base==st.top)//判断是否栈空 
		 return ERROR;
	e=*(st.top-1);
	st.top--;
	return OK;
}


//e.取栈顶元素
Status GetTop(Sqstack &st,int &e) 
{
    if(st.top==st.base){
		 return ERROR;
	}else{
		 e=*(st.top-1);
		 return OK;
	}
}


//打印
Status Printfstack(Sqstack &st) {
	if(st.base==st.top){
		printf("空栈！\n");
		return ERROR;
	}
	else{
		printf("栈的内容为：");
		int *p=st.base;
		while(p!=st.top){
			printf("%d ",*p);
			p++;
		}
	}
	printf("\n");
	return OK;
}


//销毁栈
void DestroyStack(Sqstack &st)
{
	free(st.base);
	st.base=NULL;
	st.top=NULL;
	st.stacksize=0;
}


int main(){
	Sqstack st;
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
			  if(StackEmpty(st))
			     {
			     	printf("栈为空！\n");
				 }
				 else{
			     	printf("栈不为空！\n");
			     	GetTop(st,y);
			     	printf("栈顶元素为%d\n",y);
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
	DestroyStack(st);
	return 0;
}
