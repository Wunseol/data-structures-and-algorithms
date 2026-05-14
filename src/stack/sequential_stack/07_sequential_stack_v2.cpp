#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100 //存储结构定义
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

Status initstack(Sqstack &st)//初始化栈
{
	st.base=(int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if(!st.base)
	     exit(OVERFLOW);
	st.top=st.base;
	st.stacksize=STACK_INIT_SIZE;
	return OK;	  
}

Status StackEnter(Sqstack st,int &e)//判断栈是否为空
{
	if(st.top==st.base)
		return ERROR;
	else if(e=*(st.top-1))
	    return OK;
}

Status Push(Sqstack &st,int e )//进栈
{
	if(st.top-st.base>=st.stacksize){
		 st.base=(int*)realloc(st.base,(st.stacksize+STACKINCREATEMENT)*sizeof(int));
	if(!st.base)
		 exit(OVERFLOW);
	st.top=st.base+st.stacksize;
	st.stacksize+= STACKINCREATEMENT;} 
	*st.top=e;
	st.top++; 
	return OK;
 }

Status Pop(Sqstack &st,int &e)//出栈
{
	if(st.base==st.top)
		 return ERROR;
	e=*(st.top-1);
	st.top--;
	return OK;
}

Status GetTop(Sqstack &st,int &e)//取栈顶元素
{
    if(st.top==st.base)
		return ERROR;
		e=*(st.top-1);
		return OK;		 
}

Status Printfstack(Sqstack &st)//打印
{
	if(st.base==st.top){
		printf("空栈！\n");
		return ERROR;
	}
	else
		printf("栈为：");
		while(st.base!=st.top){
			printf("%d ",*st.base);
			st.base++;
	}
}

void menu()//菜单
{
    printf("操作菜单：\n");
	printf(" a.初始化栈\n b.判断栈是否为空\n c.进栈\n d.出栈\n e.取栈顶元素\n f.打印观察\n g.退出\n");
	printf("请输入您的操作:");
}

int main()
{
	Sqstack stack1;
	char ch;
	int y,e,s;
	do{
		menu();
		scanf("%c",&ch);//输入的字符
		getchar();
		if(ch=='g')
			break;
		switch(ch)
		{
			case 'a':
			    if(initstack(stack1)){
				printf("Stack初始化成功!\n");
				}
				break;
			case 'b':
			    if(StackEnter(stack1,y))
			    {
			        printf("栈不为空！\n");
			    	printf("栈顶元素为%d\n",y);
				}else{
					printf("栈为空！\n");
				}
				break;
			case 'c':
				printf("请输入要进栈的元素(输入-1结束):");
				while(e!=-1){
					scanf("%d",&e);
				if(Push(stack1,e))
					printf("%d入栈成功!\n",e);
				else
					printf("%d入栈失败!\n",e);
				}
				getchar();
				break;
			case 'd':
			    // scanf("%d",&s);
				if(Pop(stack1,s))
					{
					printf("元素%d出栈\n",s);}
				else
					printf("出栈失败！\n");
				break;
			case 'e':
				if(GetTop(stack1,e))
				printf("栈顶元素为：%d\n",e);
				else
				printf("获得栈顶元素失败！\n");
				getchar();
				break;
			case 'f':
				if(Printfstack(stack1))
				    printf("打印完成！\n"); 
				    break;
			case 'g':break;
			default:
				printf("操作错误！\n");
				break;
		}
	}while(1);
	return 0;
}