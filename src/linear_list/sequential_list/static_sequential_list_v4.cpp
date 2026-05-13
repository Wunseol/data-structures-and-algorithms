/*
	源文件名：P1.cpp
	功能：静态线性表操作
*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max 10000 






struct SqList
{
	int elem[max];         //存放元素的数组
	int length;            //当前长度
};







void init(SqList &list);
void display(SqList &list);
void insert(SqList &list);
void search(SqList &list);
void del(SqList &list);
void simpleSort(SqList &list);
void quickSort(SqList &l,int b,int e);
void binarySearch(SqList &list);





SqList list;






int main()
{
	char choice;

	while (1)
	{
		
		
		
		
		system("cls");
		printf("\n\n\n\n") ;
		printf( "\t\t            静态线性表操作  \n");
		printf( "\t\t======================================");
		printf( "\n\n");
		printf( "\t\t             1：初始化      \n");
		printf( "\t\t             2：显示        \n");
		printf( "\t\t             3：单个插入    \n");
		printf( "\t\t             4：查找        \n");
		printf( "\t\t             5：删除        \n");
		printf( "\t\t             6：简单排序    \n");
		printf( "\t\t             7：快速排序    \n");
		printf( "\t\t             8：折半查找    \n");
		printf( "\n");
		printf( "\t\t             0：退出        \n");
		printf( "\n");
		printf( "\t\t请选择：");

		choice = getch();
		system("cls");
		
		
		
		
		switch(choice)
		{
			case '1':
				init(list);
				break;
			case '2':
				display(list);
				break;
			case '3':
				insert(list);
				break;
			case '4':
				search(list);
				break;
			case '5':
				del(list);
				break;
			case '6':
				simpleSort(list);
				break;
			case '7':
				quickSort(list,0,list.length-1);
				break;
			case '8':
				binarySearch(list);
				break;
			case '0':
				exit(0);
		}
	}
}








//屏幕提示后，从键盘输入线性表长度和随机数种子，生成指定长度的线性表list
void init(SqList &list)
{
	int i;
	while (1)
	{
		
	    printf("输入元素个数（0－ %d ）：" , max);
		scanf("%d",&list.length);
		if (list.length >= 0 && list.length <= max)
			break;
		
	}
	while (1)
	{
	    printf( "输入随机数种子（0－32767）：");
		scanf("%d",&i);
		if (i >= 0 && i <= 32767)
			break;
		
	}
	srand(i);  //指定随机数种子，相同的种子将产生相同的数据序列
	rand();

	for (i = 0; i < list.length; i++)
	{
		list.elem[i] = rand() % 10000;
	}
	for (i = list.length; i < max; i++)
		list.elem[i] = 0;
}





 






//在屏幕上依次显示线性表list中的元素个数和全部元素
//格式应便于观察
//如果需要指定输出的宽度，可以使用 cout << setw(W) << X ，其中 X 是输出的数值，W 是占据的列数
void display(SqList &list)
{
	printf("当前线性表的元素个数为：%d\n",list.length);
	printf("当前线性表元素为：\n");
	for(int k=0;k<list.length;k++){
		printf("%d ",list.elem[k]);
	}
	getch(); 
}








//屏幕提示后，从键盘输入一个元素值，然后把这个新元素插到线性表list的末尾
//应有溢出判断和报告
void insert(SqList &L)
{
	printf("请输入你要插入的元素：\n");
	int e;
	scanf("%d",&e);
	
	
		
	if(L.length>=max){
		printf("线性表已溢出");
	}
	
	L.elem[L.length]=e;
	L.length+=1;
	getch();
	
	
}








//屏幕提示后，从键盘输入一个元素值，在线性表list中搜索这个元素
//屏幕显示搜索结果和搜索过程中的比较次数
void search(SqList &list)
{
	int e,i;
	int flag=0;
	printf("请输入你要查找的元素值：\n");
	scanf("%d",&e);

	for(i=0;i<list.length;i++)
	{
		if(list.elem[i]==e){
			flag=i+1;
		}
	}



	if(flag==0)
	{
		printf("表中无此元素\n");
	}else{
		printf("查找的元素的位序为:%d\n",flag);
		printf("比较次数为:%d\n",flag);
		}
	
	getch();
	
	

}










//屏幕提示后，从键盘输入一个元素值，在线性表list中删除这个元素
//屏幕显示删除成功与否的信息，并显示比较次数和移动次数
void del(SqList &L)
{
	int e,i;
	int flag;
	printf("请输入你要删除的元素：\n");
	scanf("%d",&e);
	
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i]==e){
			flag=i+1;
		}
	}
	
	
	
	for(int j=flag;j<=L.length-1;j++)
	L.elem[j-1]=L.elem[j];
	L.length--;
	printf("比较次数为:%d\n",flag);
	printf("移动次数为%d\n",L.length-flag);
	printf("第%d个元素删除成功\n",flag);
	getch();
		
	
	

}







//对线性表list进行简单排序
//屏幕显示比较次数和移动次数
void simpleSort(SqList &l)
{
	int i,a,A;
	int count1=0;
	int count2=0;
	for(i=1;i<l.length;i++){
		count1++;
	a=i-1;
	A=l.elem[i];
	while(a>=0&&A<l.elem[a])
	{
		l.elem[a+1]=l.elem[a];
		count2++;
		a--;
	}
	l.elem[a+1]=A;
	}
	printf("比较次数为：%d 移动次数为：%d\n",count2,count1);
	printf("排序后的表为:");
	for(i=0;i<l.length;i++){
		printf("%d ",l.elem[i]);
	}
	getch(); 
	
	 
}









//对线性表list进行快速排序
//屏幕显示比较次数和移动次数
void quickSort(SqList &l,int b,int e)
{
	int i=b;
	int j=e;
	int temp,tmp;
	tmp=l.elem[b];
	
	
	if(i>=j)
	{
	
		return;
	
	}

	
	
	
	
	while(i!=j){
		while(l.elem[j]>=tmp&&j>i)
		{
			j--;
		}
		while(l.elem[i]<=tmp&&j>i)
		{
			i++;
		}
		if(j>i)
		{
			temp=l.elem[j];
			l.elem[j]=l.elem[i];
			l.elem[i]=temp;
		}
	}
	
	l.elem[b]=l.elem[i];
	l.elem[i]=tmp;
	quickSort(l,b,i-1);
	quickSort(l,i+1,e);

	



	
	
	
		

}







//屏幕提示后，从键盘输入一个元素值，对经过排序的线性表list进行折半查找
//屏幕显示查找结果，并显示比较次数
void binarySearch(SqList &l)
{
	int low,high,mid,e;
	low=0;
	high=l.length-1;
	int flag=0;
	printf("请输入你要查找的元素值：\n");
	scanf("%d",&e);

	
	
	while(low<=high)
	{
		mid=(low+high)/2;
		if(l.elem[mid]>e)
		{
			high=mid-1;
		}else if(l.elem[mid]<e)
		{
			low=mid+1;
		}
		if(e==l.elem[mid])
		{
			flag=mid+1;
			break;
		}
	}
	
	
	
	if(flag==0)
	{
		printf("表中无此元素\n");
	}else{
		printf("查找的元素的位序为:%d\n",flag);
	
	}
	
	getch();
	
	
	
	

}

