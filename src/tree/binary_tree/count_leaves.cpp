/*
编写递归算法，计算二叉树叶子结点的数目。 
*/
 
#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;
typedef struct node * blink;
 
blink create_binary();
void FreeTree(blink *T);
 
int preorder(blink a)
{
	if(a == NULL)
	{
		return 0;
	}
	printf("%c ",a->data);
	if(a->lchild == NULL && a->rchild == NULL)
	{
		return 1;
	}
	return preorder(a->lchild) + preorder(a->rchild);
}
 
int main()
{
	blink T;
	T = create_binary();
	int leaf_count = preorder(T);
	printf("\n");
	printf("The number of leaf nodes is %d \n",leaf_count);
	FreeTree(&T);
	return 0;
}
blink create_binary()
{
    blink bt;
    char ch;
    ch = getchar();
    if (ch == '#')
    {
        bt = NULL;
    }
    else
    {
        bt = (blink)malloc(sizeof(bnode));
        
        bt->data = ch;
        bt->lchild = NULL;
        bt->rchild = NULL;
        bt->lchild = create_binary();
        bt->rchild = create_binary();
        
    }
    
    /*   输入abc##d##ef##g## 
    
				    	a
				    b       e
				c     d   f    g
    */
    return bt;
}
void FreeTree(blink *T)
{
	if(*T)
	{
		FreeTree(&(*T)->lchild);
		FreeTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}
