/*
	源文件名：P1.cpp
	功能：静态线性表操作
*/
#define _CRT_SECURE_NO_WARNINGS 0；
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<algorithm>
#include<Windows.h>

#define max 10000 
using namespace std;


struct SqList
{
	int elem[max];         //存放元素的数组
	int length;            //当前长度
};

void init(SqList& list);
void display(SqList& list);
void insert(SqList& list);
void search(SqList& list);
void del(SqList& list);
void simpleSort(SqList& list);
void quickSort(SqList& list);
void binarySearch(SqList& list);

void reverse(SqList& list);//逆置
void insertInOrder(SqList& list);//有序插入
void delX_Y(SqList & list);//删除（x-y）的元素
void merge(SqList& list, SqList& list1);//合并线性表
void shellsort(SqList& list);//shell排序
SqList list;
SqList list1;
SqList list2;

int main()
{
	char choice;

	
	while (1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t            静态线性表操作  \n");
		printf("\t\t======================================");
		printf("\n\n");
		printf("\t\t             1：初始化      \n");
		printf("\t\t             2：显示        \n");
		printf("\t\t             3：单个插入    \n");
		printf("\t\t             4：查找        \n");
		printf("\t\t             5：删除        \n");
		printf("\t\t             6：简单排序    \n");
		printf("\t\t             7：快速排序    \n");
		printf("\t\t             8：折半查找    \n");
		printf("\t\t             9: 就地逆置    \n");
		printf("\t\t             a: 有序插入    \n");
		printf("\t\t             b: 删除x-y的元素    \n");
		printf("\t\t             c: 合并线性表    \n");
		printf("\t\t             d: shell排序    \n");
		printf("\n");
		printf("\t\t             0：退出        \n");
		printf("\n");
		printf("\t\t请选择：");

		choice = _getch();


		system("cls");

		switch (choice)
		{
		case '1':
			init(list);
			cout << "初始化list1" << endl;
			init(list1);
			cout << "初始化list2" << endl;
			init(list2);
			break;
		case '2':
			display(list);
			display(list1);
			display(list2);
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
			reverse(list);
			break;
		case 'a':
			insertInOrder(list);
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
		choice = _getch();
	}
}



//屏幕提示后，从键盘输入线性表长度和随机数种子，生成指定长度的线性表list
void init(SqList& list)
{
	int i;
	while (1)
	{

		printf("输入元素个数（0－ %d ）：", max);
		scanf("%d", &list.length);
		if (list.length >= 0 && list.length <= max)
			break;

	}
	while (1)
	{
		printf("输入随机数种子（0－32767）：");
		scanf("%d", &i);
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
void display(SqList& list)
{
	int n;
	cout << "输入指定输出的宽度:";
	cin >> n;
	cout << "元素个数：" << list.length<<endl;
	cout << "全部元素：";
	for (int i = 0; i < list.length; i++) {
		cout <<setw(n)<< list.elem[i]<<" ";
	}
	cout << endl;
}

//屏幕提示后，从键盘输入一个元素值，然后把这个新元素插到线性表list的末尾
//应有溢出判断和报告
void insert(SqList& list)
{
	int n;
	cout << "输入插入的元素：";
	cin >> n;
	if (list.length + 1 > max) {
		cout << "线性表溢出" << endl;
	}
	else {
		list.elem[list.length++] = n;
	}
}

//屏幕提示后，从键盘输入一个元素值，在线性表list中搜索这个元素
//屏幕显示搜索结果和搜索过程中的比较次数
void search(SqList& list)
{
	int n,count=1;
	cout << "输入搜索元素：";
	cin >> n;
	int i;
	for (i = 0; i < list.length; i++,count++) {
		if (list.elem[i] == n) {
			cout << "找到了该元素，比较次数为："<<count<< endl;
			break;
		}
	}
	if (i >= list.length)
		cout << "未找到该元素" << endl;
}

//屏幕提示后，从键盘输入一个元素值，在线性表list中删除这个元素
//屏幕显示删除成功与否的信息，并显示比较次数和移动次数
void del(SqList& list)
{
	int n, count1 =0,count2= 0;
	cout << "输入删除元素：";
	cin >> n;
	int i;
	for (i = 0; i < list.length; i++, count1++) {
		if (list.elem[i] == n) {
			for (int j = i,k=i+1; k< list.length; j++,k++,count2++) {
				list.elem[j] = list.elem[k];
			}
			list.length--;
			i--;
		}
	}
	if (i >list.length)
		cout << "未找到该元素" << endl;
	else
		cout << "删除成功,比较次数为："<<count1 <<"移动次数为：" <<count2<< endl;
}

//对线性表list进行简单排序
//屏幕显示比较次数和移动次数
void simpleSort(SqList& list)
{
	int count1 = 0, count2 = 0;
	for (int i = 0; i < list.length; i++) {
		int index = i;
		for (int j = i + 1; j < list.length; j++,count1++) {
			if (list.elem[j] < list.elem[index]) {
				index = j;
			}
		}
		if (index != i) {
			int temp;
			temp = list.elem[i];
			list.elem[i] = list.elem[index];
			list.elem[index] = temp;
			count2++;
		}
	}
	cout << "简单排序成功,比较次数为：" << count1 << "移动次数为：" << count2 << endl;
}

//对线性表list进行快速排序
//屏幕显示比较次数和移动次数
int Partition(SqList& list, int s, int t, int* p1, int* p2) {
	int i = s, j = t;
	int tmp = list.elem[s];
	while (i != j) {
		(*p1)++;
		while (j >i && list.elem[j] >= tmp) {
			(*p1)++;
			j--;
		}
		list.elem[i] = list.elem[j];
		(*p1)++;
		while (i <j && list.elem[i] <= tmp) {
			(*p1)++;
			i++;
		}
		list.elem[j] = list.elem[i];
		//*p2 += 2;
	}
	list.elem[i] = tmp;
	(*p2)++;
	return i;
}
void QuickSort(SqList& list, int s, int t,int *p1,int *p2) {
	if (s < t) {
		int i = Partition(list, s, t,p1,p2);
		QuickSort(list, s, i-1,p1,p2);
		QuickSort(list, i + 1, t,p1,p2);
	}
}
void quickSort(SqList& list)
{
	int count1 = 0, count2 = 0;
	int* p1, * p2;
	p1 = &count1;
	p2 = &count2;
	QuickSort(list, 0, list.length-1,p1,p2);
	cout << "快速排序成功,比较次数为：" << count1 << "移动次数为：" << count2 << endl;
}

//屏幕提示后，从键盘输入一个元素值，对经过排序的线性表list进行折半查找
//屏幕显示查找结果，并显示比较次数
void binarySearch(SqList& list)
{
	int n, count=0,flag=1;
	cout << "输入查找的元素：";
	cin >> n;
	int left = 0, right = list.length - 1, mid;
	while (left <= right) {
		mid = ( right-left) / 2+left;
		count++;
		if (list.elem[mid] == n) {
			flag = 0;
			cout << "找到了该元素,比较次数为："<<count << endl;
			break;
		}
		if (list.elem[mid] < n)
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (flag)
		cout << "未找到该元素" << endl;
}

//线性表的就地逆置
void reverse(SqList& list) {
	int i = 0, j = list.length - 1;
	while (i < j) {
		int temp = list.elem[i];
		list.elem[i] = list.elem[j];
		list.elem[j] = temp;
		i++;
		j--;
	}
	cout << "逆置完成" << endl;
}

//在已排序的线性表中插入元素
void insertInOrder(SqList& list) {
	int n ,count1=0,count2=0;
	cout << "输入插入的元素：";
	cin >> n;
	for (int i = 0; i < list.length-1; i++) {
		count1++;
		if (n<list.elem[i]) {
			if (list.length + 1 > max) {
				cout << "线性表溢出" << endl;
				break; //溢出判断
			}
			list.length++;
			int j;
			for (j = list.length - 1; j > i; j--) {
				list.elem[j] = list.elem[j-1];
				count2++;
			}
			list.elem[j] = n;
			break;
		}
	}
	cout << "插入完成，比较次数为：" << count1 <<" 移动次数为："<<count2<< endl;
}

//删除x-y的元素
void delX_Y(SqList& list) {
	int x,y,i=0,j=0;
	cout << "输入删除元素的范围（x y)：";
	cin >> x >> y;
	for (i = 0; i < list.length; i++) {
		if (list.elem[i]<x || list.elem[i]>y) {
			list.elem[j] = list.elem[i];
			j++;
		}
	}
	list.length = j;
	cout << "删除完成" << endl;
}

//合并线性表
void merge(SqList& list1, SqList& list2) {
	quickSort(list1);
	quickSort(list2);
	SqList list3;
	list3.length = 0;
	int i;
	for (i = 0; i < list1.length && i < list2.length; i++) {
		if (list1.elem[i] == list2.elem[i])
			list3.elem[list3.length++] = list1.elem[i];
		else {
			if (list1.elem[i] < list2.elem[i]) {
				list3.elem[list3.length++] = list1.elem[i];
				list3.elem[list3.length++] = list2.elem[i];
			}
			else {
				list3.elem[list3.length++] = list2.elem[i];
				list3.elem[list3.length++] = list1.elem[i];
			}
		}
	}
	if (list1.length < list2.length) {
		for (int j = i; j < list2.length; j++) {
			list3.elem[list3.length++] = list2.elem[j];
		}
	}
	else {
		for (int j = i; j < list1.length; j++) {
			list3.elem[list3.length++] = list1.elem[j];
		}
	}
	cout << "合并完成，合并后的线性表为：" << endl;
	display(list3);
}

//shell排序
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
	cout << "排序完成" << endl;
}
