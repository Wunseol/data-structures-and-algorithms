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

#define NULLKEY  65535
#define max 100

typedef struct BiTNode        //二叉树结点类型
{
	int data;         //数据
	int tem1,tem2;    //辅助数据（实习题不用）
	BiTNode *left;    //左子树指针
	BiTNode *right;   //右子树指针
}BiTNode,* BSTree;



BiTNode* Parent;
BSTree bst;
// BiTNode *p;
BiTNode *Tree;      //本程序操作的二叉树根指针

int elem[max];       	//存放原始数据
int count = 0;			//叶子结点个数 
int key;

//从键盘输入个数和随机数种子，在数组elem中生成指定个数的数据，供其他程序使用，0表示数据结束
void init0(int list[]);

//在本程序所在的位置生成文本文件Map.txt，其中显示以Tree为根指针的二叉树      
void showBinTree(BiTNode *Tree);

//从键盘输入个数和随机数种子，以Tree为根指针，生成指定结点个数的二叉树，供其他程序使用
BiTNode *init1();   

void display(BiTNode *Tree);
void pre_order(BiTNode *Tree);
void mid_order(BiTNode *Tree);
void post_order(BiTNode *Tree);
void preorder(BiTNode *Tree);
int GetDepth(BiTNode *Tree);
void ReChange(BiTNode *Tree);

void CreatBST(BSTree* bst);
void InsertBST(BSTree* bst, int data);
void SearchBST(BiTNode *Tree);
void BST_Deletion(BiTNode *Tree, int key );

void DrawByLevel(BiTNode *Tree);

//主函数，显示功能菜单（包括生成二叉树、显示二叉树），键盘选择后执行对应功能
int main()
{
	char choice;
	while (1)
	{
		system("cls");
		printf( "\n\n\n\n");
		printf( "\t\t              二叉树操作  \n");
		printf( "\t\t======================================");
		printf( "\n\n");
		printf( "\t\t             1：初始化      							\n");
		printf( "\t\t             2：显示(map.txt)      					\n");
		printf( "\t\t             3：先序遍历(递归法)    					\n");
		printf( "\t\t             4：中序遍历(递归法)        				\n");
		printf( "\t\t             5：后序遍历(递归法)        				\n");
		printf( "\t\t             6：统计叶子结点数 	     				\n");
		printf( "\t\t             7：二叉树深度        						\n");
		printf( "\t\t             8：左右子树交换    	 					\n");
		printf( "\t\t             9：生成二叉排序树    	 					\n");
		printf( "\t\t             a：二叉排序树中查找结点       			\n");
		printf( "\t\t             b：二叉排序树中删除结点       			\n");
		printf( "\t\t             c：先序遍历				       			\n");
		printf( "\t\t             d：按层次输出二叉树结点(逐层从左到右输出)	  \n");
		printf( "\t\t             0：退出        	 					   \n");
		printf( "\n");
		printf( "\t\t请选择：");

		choice = getch();
		system("cls");

		switch(choice)
		{
			case '1':
				Tree = init1();
				printf("二叉树创建成功\n");
				showBinTree(Tree);
				break;
			case '2':
				display(Tree);
				printf("(图在上面)\n");
				system("pause");
				break;
			case '3':
				display(Tree);
				printf("\npre_order:\n");
				pre_order(Tree);
				printf("\n");
				system("pause");
				break;
			case '4':
				display(Tree);
				printf("\nmid_order:\n");
				mid_order(Tree);
				printf("\n");
				system("pause");
				break;
			case '5':
				display(Tree);
				printf("\npost_order:\n");
				post_order(Tree);
				printf("\n");
				system("pause");
				break;
			case '6':
				preorder(Tree);
				printf("统计叶子结点数为:%d\n",count);
				system("pause");
				break;
			case '7':
				printf("二叉树深度为:%d\n",GetDepth(Tree));
				system("pause");
				break;
			case '8':
				display(Tree);
				ReChange(Tree);
				showBinTree(Tree);
				display(Tree);
				printf("左右子树交换完成!(图在上面)\n");
				system("pause");
				break;
			case '9':
				CreatBST(&Tree);
				showBinTree(Tree);
				display(Tree);
				printf("生成二叉排序树完成!(图在上面)\n");
				system("pause");
				break;
			case 'a':
				display(Tree);
				printf("请输入你要查找的节点值:");
            	SearchBST(Tree);
				system("pause");
				break;
			case 'b':
				display(Tree);
				printf("请输入你要删除的节点值:");
				scanf("%d",&key);
				BST_Deletion(Tree,key);
				showBinTree(Tree);
				printf("\n");
				display(Tree);
				printf("删除的节点完成!(图在上面)\n");
				system("pause");
				break;
			case 'c':
				display(Tree);
				printf("\npre_order:\n");
				pre_order(Tree);
				printf("\n");
				system("pause");
				break;
			case 'd':
				DrawByLevel(Tree);
				break;
			case '0':
				exit(0);
		}
	}
}

#include "BinT.h"

//1
// 按树状打印二叉树
void display(BiTNode *Tree)
{
	char map[max*2];
	FILE *f;
	f=fopen("Map.txt","r");
	fseek(f,0L,SEEK_SET);			/*定位指针到文件开始位置*/
	fread(map,198,1,f);
	printf("%s",map);
	fclose(f);

}

//2
//先序、中序、后序遍历以Tree为根指针的二叉树

//2
// 用递归的方式，实现二叉树的先序遍历
void pre_order(BiTNode *Tree)
{
    if(NULL == Tree)
    {
        return ;
    }
    printf("%d ",Tree->data);
    pre_order(Tree->left);
    pre_order(Tree->right);
}

//2
// 用递归的方式，实现二叉树的中序遍历
void mid_order(BiTNode *Tree)
{
    if(NULL == Tree)
    {
        return ;
    }
    mid_order(Tree->left);
    printf("%d ",Tree->data);
    mid_order(Tree->right);
}

//2
// 用递归的方式，实现二叉树的后序遍历
void post_order(BiTNode *Tree)
{
    if(NULL == Tree)
    {
        return ;
    }
    post_order(Tree->left);
    post_order(Tree->right);
    printf("%d ",Tree->data);
}

//3
//递归，先序遍历 树 同时统计叶子结点 
void preorder(BiTNode *Tree)
{
	//递归出口 
	if(Tree == NULL)
	{
		return;
	}
	//先序遍历树 
    preorder(Tree->left);
    preorder(Tree->right);
	//统计叶子 结点 
	if(Tree->left == NULL && Tree->right == NULL)
	{
		count ++;
	}
	return;
}

//4
//获取树的深度
int GetDepth(BiTNode *Tree)
{
    if (Tree == NULL)//递归出口
    {
        return 0;//空树深度为0
    }
    int ld, rd;
    ld = 1 + GetDepth(Tree->left );
    rd = 1 + GetDepth(Tree->right);
    return (ld > rd) ? ld : rd;
}

//5
//递归实现交换左右子树
void ReChange(BiTNode *Tree)
{
    if (Tree == NULL)//递归出口
    {
        return ;//空树深度为0
    }
	BiTNode *temp=Tree->left;
	Tree->left=Tree->right;
	Tree->right=temp;
	ReChange(Tree->left);
	ReChange(Tree->right);
}

//6
//生成二叉排序树
//使用数组elem中的随机数序列（以0表示结束，不包括0），生成以Tree为根指针的二叉排序树
//二叉排序树的插入算法（递归）
void InsertBST(BSTree* bst,int elem) 
{
	BSTree s;
	if (*bst == NULL) {
		s = (BSTree)malloc(sizeof(BiTNode));
		s->data = elem;
		s->left = NULL;
		s->right = NULL;
		*bst = s;
	}
	else if (elem < (*bst)->data)
		InsertBST(&((*bst)->left),elem);		//将s插入左子树
	else if (elem >= (*bst)->data)
		InsertBST(&((*bst)->right),elem);		//将s插入左子树
}

//传入数组 一次性插入 创建二叉排序树
void CreatBST(BSTree* bst)
{
	init0(elem);
	*bst = NULL;
	for(int i=0;elem[i]!=0;i++){
		InsertBST(bst,elem[i]);
	}
}

//在以Tree为根指针的二叉排序树中查找结点
void SearchBST(BiTNode *Tree)
{
	int key;
	int row=1;
	int flag=1;
	scanf("%d",&key);
	if (Tree == NULL)//递归出口
    {
		printf("空树\n");
        return ;//空树
    }
	while(Tree!=NULL)
	{
		if (Tree->data==key) 
		{
			printf("find!\n");
			printf("row=%d",row);
			flag=0;
			break;
		}
		else if(Tree->data>key){
			Tree=Tree->left; 
			row++;
		}
		else{
			Tree=Tree->right;
			row++;
		}
	}
	if(flag){
		printf("没找到!\n");
	}
}

//从以Tree为根指针的二叉排序树中删除结点（适用各种位置的结点）
//二叉排序树中删除结点p，并重新连接它的左子树或右子树
//在BST树上删除值为key的结点 
void BST_Deletion(BiTNode *Tree, int key )
{
	int flag = 1;//删除成功失败的标志，初始化为成功。
	BiTNode *p, *q, *s, *sq;//p指向待删除的结点，q指向p的双亲, s指向左右非空时的左子树最右侧的树叶 
	p = q = Tree;
	
	while( p != NULL )//找值为key的结点，即BST查找 
	{
		if( key == p->data )
		{
			break;
		}
		else if( key < p->data )
		{
			q = p;
			p = p->left;
		}
		else
		{
			q = p;
			p = p->right;
		}
	}

	if( p == NULL ) //此时在二叉排序树上没有找到目标结点 
	{
		flag = 0;
		printf("没找到!\n");
	}

	else//找到目标结点 
	{
		//1）如果是目标结点是树叶，则删除树叶
		if( p->left == NULL && p->right == NULL )
		{
			if( p->data == Tree->data )
			{
				Tree->data = NULLKEY;
			}
			else
			{
				if( p->data < q->data )
				{
					q->left = NULL;
				}
				else
				{
					q->right = NULL;
				}
				free( p );	
			} 
		}
		
		//2）删除只有左子树的结点
		else if( p->left != NULL && p->right == NULL )
		{
			//树根是待删除的结点 
			if( p->data == Tree->data ) //当前的参数T在函数内部不可以改变地址 ，只能改变T地址中的值
			{
				q = Tree->left;
				Tree->data = q->data;
				Tree->left = q->left;
				free(q);
			}
			else
			{
				if( p->data < q->data )
				{
					q-> left= p->left;
				}
				else
				{
					q->right = p->left;
				}
				free( p );
			}
		}
		//3）删除只有右子树的结点
		else if( p->left == NULL && p->right != NULL )
		{
			//树根是待删除的结点
			if( p->data == Tree->data )//当前的参数T在函数内部不可以改变地址 ，只能改变T地址中的值 
			{
				q = Tree->right;
				Tree->data = q->data;
				Tree->right = q->right;
				free(q);
			}
			else
			{
				if( p->data < q->data )
				{
					q->left = p->right;
				}
				else
				{
					q->right = p->right;
				}
				free(p);
			}
		}
		//4）删除左右均非空的结点，需要看左子树的最右侧结点是树叶或者非树叶 
		//   此时处理不同于前面处理单分支的结点，只需要用目标结点s的值替换待删除结点p的值即可 
		else 
		{
			//首先找p的左子树的最右侧的结点 
			sq = p;
			s  = p->left;
			while( s->right != NULL ) 
			{
				sq = s;
				s  = s->right;
			}
			// 41）如果最右侧结点是树叶,将s的值赋值给p即可 
			if( s->left == NULL ) 
			{
				sq->right = NULL;//把s的双亲结点sq的右子树置空 
				p->data = s->data;
				free( s );//释放最右侧的树叶结点所占的空间 
			}
			else//42）最右侧结点不是树叶
			{
				// 421）s=p->LChild 没有右子树,此时sq还是指向了p,则只需要将s的左子树链接到p的左子树即可 
				if( sq->data == p->data )
				{
					p->left = s->left;
				}
				// 422）p->LChild 有右子树
				else
				{
					sq->right = s->left;	
				}
				p->data = s->data;
				free(s); 
			} 
		}
	}
}//BST_Deletion


//对以Tree为根指针的二叉树,从根结点开始，逐层从左到右输出各结点的数据
//提示：用数组 BiTNode *queue[max] 构成队列，利用这个队列实现功能
//按层次输出二叉树的结点
void DrawByLevel(BiTNode *Tree)
{
    if (NULL == Tree)
    {
        return ;
    }
    BiTNode *queue[max];
    BiTNode *p;
    int front = -1, rear = -1;
    rear++;
    queue[rear] = Tree;
 
    while (front != rear)
    {
        front = (front + 1) % max;
        p = queue[front];
        printf("%d ", p->data);
 
        if (p->left)
        {
            rear = (rear + 1) % max;
            queue[rear] = p->left;
        }
        if (p->right)
        {
            rear = (rear + 1) % max;
            queue[rear] = p->right;
        }
    }
}


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

