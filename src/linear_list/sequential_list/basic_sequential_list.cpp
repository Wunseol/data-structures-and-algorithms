#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
int newer (struct list *sqlist);//初始化
int insert (struct list *sqlist);//插入
int dele (struct list *sqlist);//删除
int LocateElem (struct list *sqlist);//查找
int  MergeList (struct list *sqlist);//合并
int u (struct list *sqlist);//并集
int n (struct list *sqlist);//交集
void clear(struct list *sqlist);//清空
struct list{
	int a[maxsize];
	int length;
};
int main()
{
    struct list sqlist; 
	sqlist.length=0;
		newer(&sqlist);
		insert(&sqlist);
		dele(&sqlist);
		// LocateElem(&sqlist);
		// MergeList(&sqlist);

        clear(&sqlist);

	return 0; 
}
void clear(struct list *sqlist)
{
	int i,n;
	sqlist->length=0;
	printf("线性表已被清空!\n");
}
int newer(struct list *sqlist)
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d ",sqlist->a[i]=i*i);
		sqlist->length=sqlist->length+1;
	}
	printf("\n");
	return 0;
}
int dele(struct list *sqlist)
{
	int i,x,n;
	printf("你要删除几号元素?\n");
	scanf("%d",&x);
	if(x>sqlist->length||x<1)
		return printf("error!\n");
	if(x<sqlist->length)
	{
		for(i=x;i<sqlist->length;i++)
			sqlist->a[i-1]=sqlist->a[i];
	}
	sqlist->length--;
}
int LocateElem (struct list *sqlist)
{
    int i=1;
    

}



int insert(struct list *sqlist)
{ 
	int i,elem,loc;
	printf("请输入你要插入的元素和位置\n");
	scanf("%d %d",&elem,&loc);
	if(loc<1||loc>sqlist->length+1)
		return printf("error!\n");
	if(sqlist->length==maxsize)
		return printf("error!\n");
	if(loc<=sqlist->length)
	{
		for(i=sqlist->length;i>=loc-1;i--)
		{
			sqlist->a[i+1]=sqlist->a[i];
		}
	}
	sqlist->a[loc-1]=elem;
	sqlist->length=sqlist->length+1;
		for(i=0;i<sqlist->length;i++)
	{
		printf("%d ",sqlist->a[i]);
	}
		printf("\n");
	return 0;
}