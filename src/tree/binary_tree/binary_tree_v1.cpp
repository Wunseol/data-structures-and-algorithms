#include<stdio.h>
#include<stdlib.h>
typedef struct BitNode
{
	int data;
	struct BitNode *lchild,*rchild;
}BiTNode,*BiNode;
BiNode SearchBST(BiNode T,int key,BiNode parent,BiNode *p)
//T为根节点时，parent=NULL;其余时候parent指向T的双亲
{
	if(!T)
	{
		*p=parent;
		return 0;
	}
	else
	{
		if(key==T->data)
			return T;
	    else if(key<T->data)
		    return SearchBST(T->lchild,key,T,p);
	    else
		    return SearchBST(T->rchild,key,T,p);
	}
}
BiNode InsertBST(BiNode T,int key)
{
	BiNode p,s;
	if(NULL==T)
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=key;
		T->lchild=T->rchild=NULL;
		return T;
	}
	if(!SearchBST(T,key,NULL,&p))//查找不成功
	{
		s=(BiTNode *)malloc(sizeof(BiTNode));
		s->data=key;
		s->lchild=s->rchild=NULL;
		if(!p)
			T=p;
		else if(key<p->data)
			p->lchild=s;
		else
			p->rchild=s;
		return T;
	}
	else 
		return T;
}
BiNode creat(BiNode T)
{
	int n,i,a;
	i=1;
	scanf("%d",&n);
	while(i<=n)
	{
		scanf("%d",&a);
		T=InsertBST(T,a);
		i++;
	}
	return T;
}
void InOrder(BiNode T)//中序遍历二叉树
{
	
	if(T)
	{
		
		InOrder(T->lchild);
		printf("%-5d",T->data);
		InOrder(T->rchild);
		
	}
 
}
 
 
int main()
{
	BiNode root=NULL;
	root=creat(root);//printf("root=%d\n",root->data);
	InOrder(root);
	printf("\n");
	return 0;
}