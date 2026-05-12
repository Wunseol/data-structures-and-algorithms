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
void quickSort(SqList &list);
void binarySearch(SqList &list);
void Reverse(SqList &list);
void Orderinser(SqList &list);
void delX_Y(SqList& list);
void merge(SqList& list1, SqList& list2);
void shellsort(SqList& list);



SqList list;
SqList list1;
SqList list2;

int count1=0,count2=0;

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
		printf( "\t\t             9：就地逆置    \n");
		printf( "\t\t             a：有序插入    \n");
		printf( "\t\t             b：删除区间    \n");
		printf( "\t\t             c：合并两有序表   \n");
		printf( "\t\t             d：shell排序    \n");

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
				quickSort(list);
				break;
			case '8':
				binarySearch(list);
				break;
			case '9':
				Reverse(list);
				break;
			case 'a':
				Orderinser(list);
				break;
			case 'b':
				delX_Y(list);
				break;
			case 'c':
				merge(list1,list2);
				break;
			case 'd':
				shellsort(list);
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

//1
//在屏幕上依次显示线性表list中的元素个数和全部元素
//格式应便于观察
//如果需要指定输出的宽度，可以使用 cout << setw(W) << X ，其中 X 是输出的数值，W 是占据的列数
void display(SqList &list)
{
	for(int i=0;i<list.length;i++){
		printf("%d ",list.elem[i]);
	}
	printf("\n");
	system("pause");
}

//2
//屏幕提示后，从键盘输入一个元素值，然后把这个新元素插到线性表list的末尾
//应有溢出判断和报告
void insert(SqList &list)
{
	int e;
	printf("当前长度为%d\n",list.length);
	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);
	
	if(list.length>=10000){
		printf("溢出!\n");
	}else{
		list.elem[list.length]=e;
		printf("插入成功!\n");
		list.length++;
	}
	system("pause");

}

//3
//屏幕提示后，从键盘输入一个元素值，在线性表list中搜索这个元素
//屏幕显示搜索结果和搜索过程中的比较次数
void search(SqList &list)
{
	int e;
	int flag=0;
	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);
	for(int i=0;i<list.length;i++){
        if(list.elem[i]==e){
			printf("输出位序为:%d\n比较次数为:%d\n",i+1,i);
			flag=1;
		}
    }
	if(flag!=1){
		printf("输入错误,请重新输入!\n");
	}
	system("pause");

}

//4
//屏幕提示后，从键盘输入一个元素值，在线性表list中删除这个元素
//屏幕显示删除成功与否的信息，并显示比较次数和移动次数
void del(SqList &list)
{
	while(1){
		int i,e,flag=0,count=1;
		printf("请从键盘输入一个元素值:");
		scanf("%d",&e);
		for(i=0;i<list.length;i++){
			if(list.elem[i]==e){
				printf("%d位序为:%d\n",e,i+1);
				flag=1;
				break;
			}
		}
		if(flag==1){
			for(int k=i+1;k<list.length;k++){
				list.elem[k-1]=list.elem[k];
				count++;
			}
			list.length--;
			printf("%d删除成功!  比较次数为:%d  移动次数为:%d\n",e,i,count);
			break;
		}else{
			printf("输入错误,请重新输入!\n");
		}
	}
	system("pause");
}

//5
//对线性表list进行简单排序
//屏幕显示比较次数和移动次数
void simpleSort(SqList &list)
{
	int i,j,t;
	count1=0,count2=0;
	for(i=list.length;i>0;i--){
		for(j=0;j<list.length-1;j++){
			count1++;
			if(list.elem[j]>list.elem[j+1]){
				t=list.elem[j];
				list.elem[j]=list.elem[j+1];
				list.elem[j+1]=t;
				count2++;
			}
		}
	}
	printf("简单排序完成!\n");
	printf("比较次数为%d,移动次数为%d\n",count1,count2);
	printf("简单排序后的顺序表为：\n");
	display(list);

}

//5
//对顺序表L中的子表L.r[low...high]进行一次划分，并返回枢轴位置
int Partition(SqList &list,int low,int high)
{
	// list.elem[0]=list.elem[low];
	int pivotkey=list.elem[low];
	while(low<high){
		while(low<high && list.elem[high]>=pivotkey)--high;
		list.elem[low]=list.elem[high];
		while(low<high && list.elem[low]<=pivotkey)++low;
		list.elem[high]=list.elem[low];
	}
	list.elem[low]=pivotkey;
	count1++;
	return low;  //代码补充完整后，删除该行
}

//5
//对顺序表L中的子序列L.r[low...high]进行快速排序
void QSort(SqList &list,int low,int high)
{
	if(low<high){
		count2++;
		int pivotloc=Partition(list,low,high);
		QSort(list,low,pivotloc-1);
		QSort(list,pivotloc+1,high);
	}
}

//5
//对线性表list进行快速排序
//屏幕显示比较次数和移动次数
void quickSort(SqList &list)
{
	count1=0,count2=0;
	QSort(list,0,list.length-1);
	printf("快速排序完成!\n");
	printf("比较次数为%d,移动次数为%d\n",count1,count2);
	printf("快速排序后的顺序表为：\n");
	display(list);
	
}

//6
//屏幕提示后，从键盘输入一个元素值，对经过排序的线性表list进行折半查找
//屏幕显示查找结果，并显示比较次数
void binarySearch(SqList &list)
{
	printf("折半查找条件保证要好排序的\n");
	simpleSort(list);// 折半查找条件保证要好排序的
	int low,high,mid,e,flag=0;
	count1=0;
    low=0;    			//定义最低下标为记录首位
    high=list.length;   //记录最高下标为记录末位
	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);
    while(low<=high){
        mid=(low+high)/2;
        if(e<list.elem[mid]){
			count1++;
            high=mid-1;	//最高位下标调小 一位
        }else if(e>list.elem[mid]){
			count1++;
            low=mid+1; 	//最低下标调整到中位下标大一位
        }else{
			if(e==list.elem[mid]){
				flag=1;
				printf("找到元素%d\n",e);
				printf("输出位序为:%d\n比较次数为:%d\n",mid+1,count1+1); 	//代表就是次位置
			}
			break;
        }
    }
	if(low>high&&flag==0){
		printf("输入错误,未找到元素%d\n",e);
	}
	system("pause");

}

//7
// 顺序表的就地逆置,即利用原表的存储空间将顺序表逆置
void Reverse(SqList &list)
{
	int temp,left,right;
	for(left=0,right=list.length-1;left<right;left++,right--)
	{
		temp=list.elem[left];
		list.elem[left]=list.elem[right];
		list.elem[right]=temp;
	}
	printf("顺序表逆置成功!\n");
	printf("逆置后的顺序表为：\n");
	display(list);

}

// *8
// 顺序表有序插入,显示比较次数、移动次数
// 屏幕提示后,从键盘输入一个元素值,在经过排序的线性表中插入这个元素;
// 屏幕显示比较次数和移动次数,应有溢出判断和报告;
void Orderinser(SqList &list)
{
	printf("条件保证要好排序的\n");
	simpleSort(list);// 条件保证要好排序的
	int low,high,mid,e,flag=0;
	count1=0;
	count2=0;
    low=0;    			//定义最低下标为记录首位
    high=list.length-1;   //记录最高下标为记录末位
	printf("请从键盘输入一个元素值:");
	scanf("%d",&e);

	if(list.length>=10000){
		printf("溢出!\n");
	}else{
		while(low<=high){
			mid=(low+high)/2;
			if(e<list.elem[mid]){
				count1++;
				high=mid-1;	//最高位下标调小 一位
			}else if(e>list.elem[mid]){
				count1++;
				low=mid+1; 	//最低下标调整到中位下标大一位
			}
		}
		// if(low>high){
		// 	printf("%d %d",list.elem[low],list.elem[high]);
		// }
		for(int k=list.length-1;k>=low-1;k--){
			list.elem[k+1]=list.elem[k];
			count2++;
		}
		list.elem[low]=e;
		list.length++;
		printf("%d插入成功!  比较次数为:%d  移动次数为:%d\n",e,count1,count2);
		printf("插入后的顺序表为：\n");
		display(list);
	}
}

// *9
// 要求以较高的效率实现删除顺序表中元素值在x到y(x和y自定)之间的所有元素
// [解题思路]
// 在顺序表中设置两个初值为0的下标变量i和j,其中,i为比较元素的下标,j为赋值元素的下标。
// 依次取顺序表中下标为i的元素与x和y比较,假若是x到y之外的元素,则赋值给下标为j的元素。
// 这种算法比删除一个元素后立即移动其后面的元素的效率高得多。
void delX_Y(SqList& list)
{
	int x,y,i=0,j=0;
	display(list);
	printf("输入删除元素的范围（x y)：");
	scanf("%d %d",&x,&y);
	for (i = 0; i < list.length; i++) {
		if (list.elem[i] < x || list.elem[i] > y) {
			list.elem[j] = list.elem[i];
			j++;
		}
	}
	list.length = j;
	printf("删除完成\n");
	printf("删除后的顺序表为：\n");
	display(list);
}

// *10
// 编程实现将两个非递减的顺序表进行合并,要求同样的数据元素只出现一次
// [解题思路]
// 由于两个顺序表中的元素呈有序排列,在进行合并的时候,依次比较,哪个顺序表的元素值小,就先将这个元素复制到新的顺序表中,
// 若两个元素相等,则复制个即可,这样一直到其中的一个顺序表结束,然后将剩余的顺序表复制到新的顺序表中即
void merge(SqList& list1, SqList& list2) 
{
	printf("初始化list1,list2\n");
	init(list1);
	init(list2);
	printf("\n");
	printf("list1,list2排序:\n\n");
	quickSort(list1);
	printf("\n");
	quickSort(list2);
	printf("\n");

	SqList list3;
	list3.length=0;
	int i,j;

	for(j=0,i=0;j < list2.length && i<list1.length;){
		if(list1.elem[i] == list2.elem[j]){
			list3.elem[list3.length] = list1.elem[i];//相等只要一个
			// printf("%d",list3.elem[list3.length]);
			printf("%d\n",list3.length);
			i++,j++,list3.length++;
			
		}else if(list1.elem[i]<list2.elem[j]){//小的放前面
			list3.elem[list3.length] = list1.elem[i];
			// printf("%d",list3.elem[list3.length]);
			printf("%d\n",list3.length);
			i++,list3.length++;
			
		}else{
			list3.elem[list3.length] = list2.elem[j];
			// printf("%d",list3.elem[list3.length]);
			printf("%d\n",list3.length);
			j++,list3.length++;
		}

		// if (list1.elem[i] == list2.elem[i])
		// list3.elem[list3.length++] = list1.elem[i];//相等只要一个

		// else {
		// 	if (list1.elem[i] < list2.elem[i]) {//小的放前面
		// 		list3.elem[list3.length++] = list1.elem[i];
		// 		list3.elem[list3.length++] = list2.elem[i];
		// 	}
		// 	else {
		// 		list3.elem[list3.length++] = list2.elem[i];
		// 		list3.elem[list3.length++] = list1.elem[i];
		// 	}
		// }
	}
	// display(list3);
	// printf("%d %d\n",i,j);
	if (j < list2.length || i<list1.length) {//长的继续输出
		for ( ; j < list2.length; j++) {
			printf("%d\n",list3.length);
			list3.elem[list3.length++] = list2.elem[j];
		}
	}
	else {
		for ( ; i < list1.length; i++) {
			printf("%d\n",list3.length);
			list3.elem[list3.length++] = list1.elem[i];
		}
	}

	// for (i = 0; i < list1.length && i < list2.length; i++) {
	// 	if (list1.elem[i] == list2.elem[j])
	// 		list3.elem[list3.length++] = list1.elem[i];//相等只要一个
	// 	else {
	// 		if (list1.elem[i] < list2.elem[i]) {//小的放前面
	// 			list3.elem[list3.length++] = list1.elem[i];
	// 			list3.elem[list3.length++] = list2.elem[i];
	// 		}
	// 		else {
	// 			list3.elem[list3.length++] = list2.elem[i];
	// 			list3.elem[list3.length++] = list1.elem[i];
	// 		}
	// 	}
	// }

	printf("合并完成!\n合并后的线性表为:");
	display(list3);
}



// *11
// 编程实现顺序表的 shell排序(步长为5,3,1)
void shellsort(SqList& list)
{
	int gap, i, j, temp;
	for (gap = list.length / 2; gap > 0; gap /= 2)
		for (i = gap; i < list.length; i++)
			for (j = i - gap; j >= 0 && list.elem[j] > list.elem[j + gap];  j -= gap) {
				temp = list.elem[j];
				list.elem[j] = list.elem[j + gap];
				list.elem[j + gap] = temp;
			}
	printf("希尔排序完成!\n");
	printf("排序后的顺序表为：\n");
	display(list);

}
