/*
	源文件名：P5.cpp
	功能：二叉树操作
*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
using namespace std;

#define max 100

typedef struct BiTNode        //二叉树结点类型
{
	int data;         //数据
	int tem1,tem2;    //辅助数据（实习题不用）
	BiTNode *left;    //左子树指针
	BiTNode *right;   //右子树指针
}BiTNode, * BSTree;

BiTNode *Tree;      //本程序操作的二叉树根指针

BSTree bst;

int val=0;

int elem[max];        //存放原始数据



//从键盘输入个数和随机数种子，在数组elem中生成指定个数的数据，供其他程序使用，0表示数据结束
int* init0();

//从键盘输入个数和随机数种子，以Tree为根指针，生成指定结点个数的二叉树，供其他程序使用
BiTNode *init1();   

//在本程序所在的位置生成文本文件Map.txt，其中显示以Tree为根指针的二叉树      
void showBinTree(BiTNode *Tree);



void PreOrde(BiTNode *T);
void InOrder(BiTNode *T);
void PostOrde(BiTNode *T);

int GetNodeNumber(BiTNode *T);
int BTNodeDepth(BiTNode *T); 
void TreeSwap(BiTNode* T);


void find(BiTNode* Tree, int x);
void del(BSTree* root, int x);
void Level_order(BiTNode* Tree);

void CreatBST(BSTree* bst);



//主函数，显示功能菜单（包括生成二叉树、显示二叉树），键盘选择后执行对应功能
int main()
{
	char choice;

	while (1)
	{
		system("cls");
		printf("\n\n\n\n") ;
		printf( "\t\t            二叉树操作  \n");
		printf( "\t\t======================================");
		printf( "\n\n");
		printf( "\t\t             1：初始化               \n");
		printf( "\t\t             2：显示（Map.txt)       \n");
		printf( "\t\t             3：先序遍历(递归法)     \n");
		printf( "\t\t             4：中序遍历(递归法)     \n");
		printf( "\t\t             5：后序遍历(递归法)     \n");
		printf( "\t\t             6：统计叶子结点数目     \n");
		printf( "\t\t             7：二叉树深度    		  \n");
		printf( "\t\t             8：左右子树交换    	  \n");
		printf( "\t\t             9: 生成二叉排序树 	  \n");
		printf( "\t\t             a：查找排序树中的结点   \n");
		printf( "\t\t             b：删除二叉树中的结点   \n");
		printf( "\t\t             c：先序遍历    	  	  \n");
		printf( "\t\t             d：层次遍历    	      \n");
		
		printf( "\n");
		printf( "\t\t             0：退出        \n");
		printf( "\n");
		printf( "\t\t请选择：");

		choice = getch();
		system("cls");
		
		int val;
		switch(choice)
		{
			case '1':
				Tree = init1();
				printf("二叉树创建成功\n");
				break;
			case '2':
				printf("结果已存入Map.txt中\n");
				showBinTree(Tree);
				break;
			case '3':
				printf("先序遍历的结果如下：\n");
				PreOrde(Tree);
				break;
			case '4':
				printf("中序遍历的结果如下：\n");
				InOrder(Tree);
				break;
			case '5':
				printf("后序遍历的结果如下：\n");
				PostOrde(Tree);
				break;
			case '6':
				printf("统计的叶子结点数目为：%d\n",GetNodeNumber(Tree));
				break;
			case '7':
				printf("二叉树深度为：%d\n",BTNodeDepth(Tree));
				break;
			case '8':
				TreeSwap(Tree);
				printf("左右子树已交换\n");
				break;
			case '9':
				CreatBST(&bst);
				printf("二叉排序树已生成\n");
				break;	
			case 'a':
				printf("请输入查找的结点:");
				scanf("%d", &val);
				find(bst, val);
				break;
			case 'b': 
			    printf("请输入要删除的值:>");
				scanf("%d", &val);
				del(&bst, val);
				PreOrde(bst);
				break;
			case 'c':
				printf("先序遍历的结果如下：\n");
				PreOrde(bst);
				break;
			case 'd':
				printf("层次遍历的结果如下：\n");
				Level_order(bst);
				break;
			case '0':
				exit(0);
		}
	getch();
	}
}




#include  "BinT.h"


//先序、中序、后序遍历以Tree为根指针的二叉树

//使用数组elem中的随机数序列（以0表示结束，不包括0），生成以Tree为根指针的二叉排序树

//在以Tree为根指针的二叉排序树中查找结点

//从以Tree为根指针的二叉排序树中删除结点（适用各种位置的结点）

//对以Tree为根指针的二叉树,从根结点开始，逐层从左到右输出各结点的数据
//提示：用数组 BiTNode *queue[max] 构成队列，利用这个队列实现功能



//*1、随机生成二叉树。 2、生成并保存先（后）序、中序输出序列。 3、按照保存的一对输出序列恢复出二叉树。 4、生成先（后）序、中序输出序列。 5、比较两对输出序列。

//*不用递归，先序、中序、后序遍历以Tree为根指针的二叉树
//提示：用数组 BiTNode *stack[max] 构成堆栈，利用这个堆栈实现功能

//*用缩入格式的多行文本表示以Tree为根指针的二叉树，例如：
//  324
//     123
//      746
//      690
//     567

//*用广义表表示以Tree为根指针的二叉树，例如
// (324(123(746()())(690()()))(567()()))

//*使用数组elem中的随机数序列（以0表示结束，不包括0），生成赫夫曼树，计算平均带权路径长度
