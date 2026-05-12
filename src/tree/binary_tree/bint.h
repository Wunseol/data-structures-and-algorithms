#include <limits.h>
#include <queue>
using namespace std;





//供init1调用的生成函数
BiTNode *Generate(int n)
{
	int nl;
	if (n==0)
		return NULL;

	BiTNode *P = new BiTNode;
	P->data = rand() % 999 +1;
	nl=rand() % (n);
	P->left = Generate(nl);
	P->right = Generate(n-1-nl);
	return P;
}
//供init1O调用的释放函数
void release(BiTNode *Tree)
{
	if (Tree==NULL)
		return;
	release(Tree->left);
	release(Tree->right);
	free(Tree);
}

//屏幕提示后，从键盘输入个数和随机数种子，以Tree为根指针，生成指定结点个数的二叉树，供其他程序使用，同时生成文件Map.txt，显示这课二叉树
BiTNode *init1()
{
	int i,n;

	while (1)
	{
	    int max_1=max-1;
		printf("输入数据个数（0－ %d ）：" , max_1);
		scanf("%d",&n);
		if (n >= 0 && n <= max-1)
			break;
		
	}
	
	while (1)
	{
	    printf( "输入随机数种子（0－32767）：" );
		scanf("%d",&i);
		if (i >= 0 && i <= 32767)
			break;
		
	}
	srand(i);  //指定随机数种子，相同的种子将产生相同的数据序列
	rand();

//	release(Tree);
	return Generate (n);
}

void getWidth(BiTNode *Tree, int depth, int shift, char map[max*2][max*2])
{
	int i;

	if (Tree->left != NULL)
	{
		getWidth(Tree->left, depth+1, shift, map);
		Tree->tem1 = Tree->left->tem1 + Tree->left->tem2 + 1;
		for (i=(Tree->left->tem1+shift)*2; i<shift*2; i=i+2)
		{
			map[depth*2+1][i]='-';
			map[depth*2+1][i+1]='-';
		}
	}
	else Tree->tem1 = 0;
	if (Tree->right != NULL)
	{
		getWidth(Tree->right, depth+1, shift+Tree->tem1+1, map);
		Tree->tem2 = Tree->right->tem1 + Tree->right->tem2 + 1;
	}
	else Tree->tem2 = 0;

	for (i=shift*2; i<(Tree->tem1+shift)*2; i++)
		map[depth*2][i]=' ';
	
	map[depth*2][(Tree->tem1+shift)*2]=(char)(Tree->data / 1000 +48);
	map[depth*2][(Tree->tem1+shift)*2+1]=(char)(Tree->data / 100 % 10 +48);
	map[depth*2][(Tree->tem1+shift)*2+2]=(char)(Tree->data / 10 % 10 +48);
	map[depth*2][(Tree->tem1+shift)*2+3]=(char)(Tree->data %10 +48);
	if (Tree->data<1000)
	{
		map[depth*2][(Tree->tem1+shift)*2]=' ';
		if (Tree->data<100)
		{
			map[depth*2][(Tree->tem1+shift)*2+1]=map[depth*2][(Tree->tem1+shift)*2+2];
			map[depth*2][(Tree->tem1+shift)*2+2]=map[depth*2][(Tree->tem1+shift)*2+3];
			map[depth*2][(Tree->tem1+shift)*2+3]=' ';
			if (Tree->data<10)
				map[depth*2][(Tree->tem1+shift)*2+1]=' ';
		}
	}

	if (Tree->left != NULL)
	{
		map[depth*2+1][(Tree->left->tem1+shift)*2+1]=(char)0xa9;
		map[depth*2+1][(Tree->left->tem1+shift)*2+2]=(char)0xb0;
		map[depth*2+1][(Tree->tem1+shift)*2+1]=(char)0xa9;
		map[depth*2+1][(Tree->tem1+shift)*2+2]=(char)0xbc;
		for (i=(Tree->left->tem1+shift)*2+3; i<(Tree->tem1+shift)*2; i=i+2)
		{
			map[depth*2+1][i]=(char)0xa9;
			map[depth*2+1][i+1]=(char)0xa4;
		}
	}
	if (Tree->right != NULL)
	{
		map[depth*2+1][(Tree->tem1+shift)*2+1]=(char)0xa9;
		map[depth*2+1][(Tree->tem1+shift)*2+2]=(char)0xb8;
		map[depth*2+1][(Tree->tem1+Tree->right->tem1+shift)*2+3]=(char)0xa9;
		map[depth*2+1][(Tree->tem1+Tree->right->tem1+shift)*2+4]=(char)0xb4;
		for (i=(Tree->tem1+shift)*2+3; i<(Tree->tem1+Tree->right->tem1+shift)*2+2; i=i+2)
		{
			map[depth*2+1][i]=(char)0xa9;
			map[depth*2+1][i+1]=(char)0xa4;
		}
	}
	if (Tree->left != NULL && Tree->right != NULL)
	{
		map[depth*2+1][(Tree->tem1+shift)*2+1]=(char)0xa9;
		map[depth*2+1][(Tree->tem1+shift)*2+2]=(char)0xd8;
	}

}

//生成文件Map.txt，显示以Tree为根指针的二叉树
void showBinTree(BiTNode *Tree)
{
	char map[max*2][max*2];
	FILE *f;
	int i,j,k;

	f=fopen("Map.txt","w");
	if (Tree == NULL)
	{
		fprintf(f,"空树");
		fclose(f);
		return;
	}
	for (i=0; i<max*2; i++)
		for (j=0; j<max*2; j++)
			map[i][j]=' ';
	getWidth(Tree,0,0,map);
	for (i=0; i<max*2; i++)
	{
		k=max*2-1; 
		while (k>=0 && map[i][k]==' ')
			k--;

		for (j=0; j<=k; j++)
			fprintf(f,"%c",map[i][j]);
		fprintf(f,"\n");
//		if (k<0)
//			break;
	}
	fclose(f);
}

//先序遍历（递归） 
void PreOrde(BiTNode *T)
{
	
	
	if (T==NULL)
	{
		return;
	}
	
	printf("%d ", T->data);
	PreOrde(T->left);
	PreOrde(T->right);
}
//中序遍历
void InOrder(BiTNode *T)
{
	if (!T)
	{
		return;
	}
	
	InOrder(T->left);
	printf("%d ", T->data);
	InOrder(T->right);
}
//后序遍历
void PostOrde(BiTNode *T)
{
	if (!T)
	{
		return;
	}
	
	PostOrde(T->left);
	PostOrde(T->right);
	printf("%d ", T->data);
}

int GetNodeNumber(BiTNode *T)
{

    int count1,count2;
    if(T==NULL)return 0;   //数空
    else
        if(T->left==NULL&&T->right==NULL)return 1;//为叶子结点
        else
        {
            count1=GetNodeNumber(T->left);//左子树叶子结点数
            count2=GetNodeNumber(T->right);//右子树叶子结点数
            return count1+count2;//返回叶子结点数
        }
}

//两数较大值
int MaxOfTwo(int a, int b)
{
	if (a >= b)
	{
		return a;
	} 
	else
	{
		return b;
	}
}

//求高度
int BTNodeDepth(BiTNode *T)
{
	if (T)
	{
		return MaxOfTwo(BTNodeDepth(T->left), BTNodeDepth(T->right)) + 1;
	} 
	else
	{
		return 0;
	}
}

//将结点的左右子树交换
void swap(BiTNode* T)
{
	BiTNode* tmp;
	tmp = T->left;
	T->left = T->right;
	T->right = tmp;
}
 
void TreeSwap(BiTNode* T)
{
	if (T == NULL)
		return;
	else
	{
		TreeSwap(T->left);
		TreeSwap(T->right);
		swap(T);
	}
}

void find(BiTNode* Tree, int x)
{
	if (Tree == NULL)
	{
		printf("未找到%d\n", x);
		return;
	}
	if (Tree->data == x)
	{
		printf("%d\n", x);
	}
	else if (x < Tree->data)
	{
		find(Tree->left, x);
	}
	else
	{
		find(Tree->right, x);
	}
}

BiTNode* search(BiTNode* Tree, int x, BiTNode** parent)
{
	if (!Tree || Tree->data == x)
	{
		return Tree;
	}
	*parent = Tree;
	if (x < Tree->data)
	{
		return search(Tree->left, x, parent);
	}
	else
	{
		return search(Tree->right, x, parent);
	}
}

int findMin(BiTNode* Tree)
{
	if (Tree == NULL) return INT_MAX;
	while (Tree->left != NULL)
		Tree = Tree->left;
	return Tree->data;
}

void del(BSTree* root, int x)
{
	BiTNode* parent = NULL;
	BiTNode* temp = search(*root, x, &parent);
	if (!temp)
	{
		printf("你要删除的结点不存在\n");
		return;
	}
	if (!temp->left && !temp->right)
	{
		if (parent)
		{
			if (x < parent->data) parent->left = NULL;
			else parent->right = NULL;
		}
		else
		{
			*root = NULL;
		}
		free(temp);
	}
	else if (!temp->left && temp->right)
	{
		if (parent)
		{
			if (x < parent->data) parent->left = temp->right;
			else parent->right = temp->right;
		}
		else
		{
			*root = temp->right;
		}
		free(temp);
	}
	else if (temp->left && !temp->right)
	{
		if (parent)
		{
			if (x < parent->data) parent->left = temp->left;
			else parent->right = temp->left;
		}
		else
		{
			*root = temp->left;
		}
		free(temp);
	}
	else
	{
		int minVal = findMin(temp->right);
		del(&(temp->right), minVal);
		temp->data = minVal;
	}
}

queue<BiTNode*>q; //用队列保存结点
//层序遍历
void Level_order(BiTNode* Tree)
{


	if (Tree == NULL) return;
	q.push(Tree);
	while (!q.empty())//当队列非空
	{
		BiTNode* node = q.front(); q.pop();
		printf("%d ", node->data);
		if (node->left != NULL) q.push(node->left); 
		if (node->right != NULL) q.push(node->right);

	}
}

/*二叉排序树的插入算法（递归）*/
void InsertBST(BSTree* bst, int data) {
	BSTree s;
	if (*bst == NULL) {
		s = (BSTree)malloc(sizeof(BiTNode));
		s->data = data;
		s->left = NULL;
		s->right = NULL;
		*bst = s;
	}
	else if (data < (*bst)->data)
		InsertBST(&((*bst)->left), data);		//将s插入左子树
	else if (data >= (*bst)->data)
		InsertBST(&((*bst)->right), data);		//将s插入左子树
}

/*创建二叉排序树*/
void CreatBST(BSTree* bst) {
	int data;
	*bst = NULL;
	printf("请输入元素:");
	scanf("%d", &data);
	while (data != 0) {
		InsertBST(bst, data);
		scanf("%d", &data);
	}
}
