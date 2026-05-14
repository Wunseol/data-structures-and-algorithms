#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MaxSize 1024

typedef int TElemType;

typedef struct BstNode
{
    TElemType data;//数据域
    BstNode *Left;//指针域
    BstNode *Right;
}BstNode;

/*创建节点*/
BstNode* CreatBstNode(TElemType data)
{
    BstNode* root = (BstNode *)malloc(sizeof(*root) );
    root->data  = data;
    root->Left  = NULL;
    root->Right = NULL;
    return root;
}

/*在以为root为根的平衡二叉树中插入一个值为x的结点*/
int AddBstNodeToTree(BstNode* root, const TElemType data)
{
    BstNode* p = root;
    BstNode* pnew = CreatBstNode(data);
 
    while (1)
    {
        if ((pnew->data) > (p->data))
        {
            if (NULL == p->Right)
            {
                p->Right = pnew;
                break;
            }
            p = p->Right;
        }
        else if ((pnew->data) < (p->data))
        {
            if (NULL == p->Left)
            {
                p->Left = pnew;
                break;
            }
            p = p->Left;
        }
        else
        {
            printf("Input Error!\n");
            free(pnew);
            return 1;
        }
    }
    return 0;
}

//找到父节点
BstNode* FindFather(BstNode* root, const TElemType key, int& pos)
{
    BstNode* p = root;
    BstNode* backfather = p;
    pos = 0;
    while (p)
    {
        if (key == p->data)
        {
            return backfather;
        }
        else if (key < p->data)
        {
            backfather = p;
            p = p->Left;
            pos = -1;
        }
        else if (p->data < key)
        {
            backfather = p;
            p = p->Right;
            pos = 1;
        }
    }
    return NULL;
}

/*删除节点*/
BstNode* DeleteBstNode(BstNode* &root, const TElemType key)
{
    int pos;
    BstNode *backfather;//父结点指针
    BstNode *ptr;//删除结点指针
    BstNode *next;//子结点指针
    BstNode **fap;//父节点指向删除节点的指针
 
    backfather = FindFather(root, key, pos);
    if (NULL == backfather)
    {
        return root;
    }
    switch (pos)
    {
        case -1:
        {
            ptr = backfather->Left;
            fap = &(backfather->Left);
            break;
        }
        case  1:
        {
            ptr = backfather->Right;
            fap = &(backfather->Right);
            break;
        }
        case  0:
        {
            ptr = backfather;
            fap = &(root);//不能用backfather，操作backfather不会作用到root
            break;
        }
    }
    //第一种情况，没有左子树
    if (NULL == ptr->Left)
    {
        //以当前节点的右子节点替换当前节点
        *fap = ptr->Right;
 
        free(ptr);
        ptr = NULL;
        return root;
    }
    //第二种情况，没有右子树
    if (NULL == ptr->Right)
    {
        //以当前节点的左子节点替换当前节点
        *fap = ptr->Left;
 
        free(ptr);
        ptr = NULL;
        return root;
    }
    //第三种情况，有左子树也有右子树
    backfather = ptr;  //父节点指向当前节点
    next = backfather->Left;   //设置子节点
    while (NULL != next->Right)//找到最接近ptr->data的节点
    {
        backfather = next;
        next = next->Right;
    }
    ptr->data = next->data;  //替换数据
 
    //此时 next->Right == NULL
    if (backfather->Left == next)
    {
        backfather->Left = next->Left;
    }
    else
    {
        backfather->Right = next->Right;//NULL
    }
    free(next);
    return root;
 
}

/*创建一个二叉排序树*/
BstNode* CreatBST(TElemType arr[], const int n)
{
    BstNode *root = NULL;//指向根结点
 
    for (int i=0; i<n; i++)
    {
        if (NULL == root)
        {
            root = CreatBstNode(arr[i]);
        }
        else
        {
            AddBstNodeToTree(root, arr[i]);
        }
    }
    return root;
}

/*查找二叉树中元素*/
BstNode* SearchBstNode(BstNode* T, const TElemType key)
{
    BstNode *p = T;
    if (NULL == p)
    {
        return NULL;
    }
    if (p->data == key)
    {
        p = T;
    }
    else if (p->data > key)
    {
        p = SearchBstNode(T->Left, key);
    }
    else
    {
        p = SearchBstNode(T->Right, key);
    }
    return p;
}

//获取树的深度
int GetDepth(BstNode* T)
{
    if (NULL == T)
    {
        return 0;//空树深度为0
    }
    int ld, rd;
    ld = 1 + GetDepth(T->Left );
    rd = 1 + GetDepth(T->Right);
    return (ld > rd) ? ld : rd;
}

//按树状打印二叉树
void DrawByTree(BstNode *T, int depth)
{
    if (NULL == T)
    {
        return ;
    }
 
    DrawByTree(T->Right, depth+1);//打印右子树，并将层次加1
 
    for (int i = 0; i < depth; i++)//按照递归的层次打印空格
    {
        printf("    ");
    }
 
    printf("%d\n", T->data);//输出根结点
 
    DrawByTree(T->Left, depth+1);//打印左子树，并将层次加1
}

//按层次输出二叉树的结点
void DrawByLevel(BstNode *T)
{
    if (NULL == T)
    {
        return ;
    }
 
    BstNode *queue[MaxSize];
    BstNode *p;
    int front = -1, rear = -1;
 
    rear++;
    queue[rear] = T;
 
    while (front != rear)
    {
        front = (front + 1) % MaxSize;
        p = queue[front];
        printf("%d ", p->data);
 
        if (p->Left)
        {
            rear = (rear + 1) % MaxSize;
            queue[rear] = p->Left;
        }
        if (p->Right)
        {
            rear = (rear + 1) % MaxSize;
            queue[rear] = p->Right;
        }
    }
}

/*用递归的方式，实现二叉树的先序遍历*/
void pre_order(BstNode *T)
{
    if(NULL == T)
    {
        return ;
    }
 
    /*step 1:访问根*/
    printf("%d ",T->data);
 
    /*step 2:用先序的方式去访问左子树*/
    pre_order(T->Left);
 
    /*step 3:用先序的方式去访问右子树*/
    pre_order(T->Right);
}

/*用递归的方式，实现二叉树的中序遍历*/
void mid_order(BstNode *T)
{
    if(NULL == T)
    {
        return ;
    }
 
    /*step 1:用中序的方式去访问左子树*/
    mid_order(T->Left);
 
    /*step 2:访问根*/
    printf("%d ",T->data);
 
    /*step 3:用中序的方式去访问右子树*/
    mid_order(T->Right);
}

/*用递归的方式，实现二叉树的后序遍历*/
void post_order(BstNode *T)
{
    if(NULL == T)
    {
        return ;
    }
 
    /*step 1:用后序的方式去访问左子树*/
    post_order(T->Left);
 
    /*step 2:用后序的方式去访问右子树*/
    post_order(T->Right);
 
    /*step 3:访问根*/
    printf("%d ",T->data);
}

//产生n个不重复的随机数
void CreateArr(TElemType* num, const int n)
{
    bool flag;
    //产生随机数，存储在num数组中
    for (int i=0; i<n; i++)
    {
        flag = true;
        int data = rand() % 100;
 
        //判断生成的数是否重复
        for (int j=0; j<i; j++)
        {
            if(data == num[j])
            {
                flag = false;
                i--;
                break;
            }
        }
 
        if (flag)
        {
            num[i] = data;
        }
    }
}

//将数组中的数输出
void ShowArr(TElemType* num, const int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        TElemType num[128];
        int n = 8;
        printf("----------------------------------\n");
        printf("How many numbers need?\n");
        printf("输入元素个数:");
        scanf("%d", &n);
        if (0 == n)
        {
            return 0;
        }
        srand(time(NULL) );   //设置随机数种子
        CreateArr(num, n);
        ShowArr(num, n);
 
        BstNode *T = CreatBST(num, n);
 
        printf("pre_order:\n");
        pre_order(T);
        printf("\nmid_order:\n");
        mid_order(T);
        printf("\npost_order:\n");
        post_order(T);
        putchar('\n');
 
        printf("\nDrawByLevel:\n");
        DrawByLevel(T);
        printf("\nDrawByTree:\n");
        DrawByTree(T, 0);
 
        printf("----------------------------------\n");
        printf("Delete:\t");
        TElemType key;
        scanf("%d", &key);
        printf("----------------------------------\n");
        T = DeleteBstNode(T, key);
        DrawByTree(T, 0);
    }
}
