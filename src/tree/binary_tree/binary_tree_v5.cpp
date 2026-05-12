#include"stdio.h" 
#include"malloc.h"

#define NULLKEY  65535

//BST树的结点结构 
typedef struct node
{
	int data;
	struct node *LChild;
	struct node *RChild;
}BST;
void CreateBST( BST *T, int arr[], int n );
void InorderSearch( BST *T );
int SearchBST( BST *T, int key );
int BST_Deletion( BST *T, int key );

int main()
{
	
	int arr[] = { 18, 6, 20, 4, 7, 19, 27, 1, 5, 3, 14 };
	BST *T = ( BST * )malloc( sizeof( BST ) );
	CreateBST( T, arr, 11 );
	InorderSearch( T );
	printf( "\n" );
	
	int flag, key;
	key = 27;
	flag = BST_Deletion( T, key );//删除树叶 
	InorderSearch( T );
	printf( "\n" );
	
	key = 20;
	flag = BST_Deletion( T, key );//删除只有左子树的结点 
	InorderSearch( T );
	printf( "\n" );
	
	key = 7;
	flag = BST_Deletion( T, key );//删除只有右子树的结点
	InorderSearch( T );
	printf( "\n" );
	
	key = 6;
	flag = BST_Deletion( T, key );//删除左右子树均非空的结点（情形一） 
	InorderSearch( T );
	printf( "\n" );
	
	key = 18;
	flag = BST_Deletion( T, key );//删除左右子树均非空的树根 
	InorderSearch( T );
	printf( "\n" );
	
	key = 5;
	flag = BST_Deletion( T, key );//删除左右子树均非空的结点（情形二） 
	InorderSearch( T );
	printf( "\n" );
	
	
	printf( "\n" );
	int arr1[] = { 10 };
	BST *T1 = ( BST * )malloc( sizeof( BST ) );
	CreateBST( T1, arr1, 1 );
	InorderSearch( T1 );
	printf( "\n" );
	
	key = 10;
	flag = BST_Deletion( T1, key );//删除只有一个树根的BST树 
	if( T1->data == NULLKEY )//这个处理是和当前删除算法的参数有关。
	{
		printf( "the tree is empty.\n" );
	}
	printf( "\n" );
	
	int arr2[] = { 10 , 11, 12, 13, 14 };
	BST *T2 = ( BST * )malloc( sizeof( BST ) );
	CreateBST( T2, arr2, 5 );//只有左子树
	InorderSearch( T2 );
	printf( "\n" );
	
	key = 10;
	flag = BST_Deletion( T2, key );
	InorderSearch( T2 );
	printf( "\n" );
	
	int arr3[] = { 14 , 13, 12, 11, 10 };
	BST *T3 = ( BST * )malloc( sizeof( BST ) );
	CreateBST( T3, arr3, 5 );//只有右子树 
	InorderSearch( T3 );
	printf( "\n" );
	
	key = 14;
	flag = BST_Deletion( T3, key );
	InorderSearch( T3 );
	printf( "\n" );
	
	key = 15;
	flag = BST_Deletion( T3, key );
	if( flag == 0 ) 
	{
		printf( "%d is not on the BST\n", key );
	}
	return 0;
}//main

//根据已知的数组arr创建二叉排序树 
void CreateBST( BST *T, int arr[], int n ) 
{
	BST *s, *p, *q; 
	int i; 
	T->data = arr[0]; 
	T->LChild = NULL; 
	T->RChild = NULL; 
	for( i = 1; i < n; i++ ) 
	{
		s = (BST *)malloc( sizeof(BST) ); 
		s->data   = arr[i];
		s->LChild = NULL;
		s->RChild = NULL;
		p = T;
		while( p != NULL )
		{
			if( s->data == p->data )
			{
				printf( "%d existed.\n", s->data );
				q = NULL;
				break; 
			}
			q = p;
			if( s->data < p->data )
			{
				p = p->LChild;
			}
			else if( s->data > p->data )
			{
				p = p->RChild;			
			}
		} 
		if( q != NULL && s->data < q->data )
		{
			q->LChild = s;
		}
		else if( q != NULL && s->data > q->data )
		{
			q->RChild = s;
		}	
	}
}//CreateBST

//在BST树上查找元素key，返回查找成功与失败的标志 
int SearchBST( BST *T, int key )
{
	int flag = 0; //查找成功标志，初始化为失败 
	BST *p = T; 
	while( p != NULL )
	{
		if ( p->data == key )
		{
			flag = 1;
			break;
		}
		else if( key < p->data )
		{
			p = p->LChild;
		}
		else
		{
			p = p->RChild;
		}
	}
	return( flag );
}//SearchBST

//在BST树上删除值为key的结点 
int BST_Deletion( BST *T, int key )
{
	int flag = 1;//删除成功失败的标志，初始化为成功。
	BST *p, *q, *s, *sq;//p指向待删除的结点，q指向p的双亲, s指向左右非空时的左子树最右侧的树叶 
	p = q = T;
	//找值为key的结点，即BST查找 
	while( p != NULL )
	{
		if( key == p->data )
		{
			break;
		}
		else if( key < p->data )
		{
			q = p;
			p = p->LChild;
		}
		else
		{
			q = p;
			p = p->RChild;
		}
	}
	if( p == NULL ) //此时在二叉排序树上没有找到目标结点 
	{
		flag = 0;
	}
	else//找到目标结点 
	{
		//1）如果是目标结点是树叶，则删除树叶
		if( p->LChild == NULL && p->RChild == NULL )
		{
			if( p->data == T->data )
			{
				T->data = NULLKEY;
			}
			else
			{
				if( p->data < q->data )
				{
					q->LChild = NULL;
				}
				else
				{
					q->RChild = NULL;
				}
				free( p );	
			} 
		}
		
		//2）删除只有左子树的结点
		else if( p->LChild != NULL && p->RChild == NULL )
		{
			//树根是待删除的结点 
			if( p->data == T->data ) //当前的参数T在函数内部不可以改变地址 ，只能改变T地址中的值
			{
				q = T->LChild;
				T->data = q->data;
				T->LChild = q->LChild;
				free(q);
			}
			else
			{
				if( p->data < q->data )
				{
					q->LChild = p->LChild;
				}
				else
				{
					q->RChild = p->LChild;
				}
				free( p );
			}
		}
		//3）删除只有右子树的结点
		else if( p->LChild == NULL && p->RChild != NULL )
		{
			//树根是待删除的结点
			if( p->data == T->data )//当前的参数T在函数内部不可以改变地址 ，只能改变T地址中的值 
			{
				q = T->RChild;
				T->data = q->data;
				T->RChild = q->RChild;
				free(q);
			}
			else
			{
				if( p->data < q->data )
				{
					q->LChild = p->RChild;
				}
				else
				{
					q->RChild = p->RChild;
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
			s  = p->LChild;
			while( s->RChild != NULL ) 
			{
				sq = s;
				s  = s->RChild;
			}
			// 41）如果最右侧结点是树叶,将s的值赋值给p即可 
			if( s->LChild == NULL ) 
			{
				sq->RChild = NULL;//把s的双亲结点sq的右子树置空 
				p->data = s->data;
				free( s );//释放最右侧的树叶结点所占的空间 
			}
			else//42）最右侧结点不是树叶
			{
				// 421）s=p->LChild 没有右子树,此时sq还是指向了p,则只需要将s的左子树链接到p的左子树即可 
				if( sq->data == p->data )
				{
					p->LChild = s->LChild;
				}
				// 422）p->LChild 有右子树
				else
				{
					sq->RChild = s->LChild;	
				}
				p->data = s->data;
				free(s); 
			} 
		}
	}
	return flag; 
}//BST_Deletion

//中序遍历二叉树-递归算法 
void InorderSearch( BST *T )
{
	if( T != NULL )
	{
		InorderSearch( T->LChild );
		if( T->LChild != NULL && T->RChild != NULL ) 
		{
			printf( "%5d/", T->data );//子树树根加个标识符/ 
		}
		else
		{
			printf( "%5d", T->data );
		}
		InorderSearch( T->RChild );
	} 
}//InorderSearch
