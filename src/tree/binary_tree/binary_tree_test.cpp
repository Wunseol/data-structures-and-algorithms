#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_SIZE 128
#define STR_SIZE 1024

typedef struct node{
	struct node *lchild;						//指向左孩子节点
	char data;									//数据元素
	struct node *rchild;						//指向右孩子节点 
}BTNode;

typedef struct Quene {      // 定义顺序队
    int     front;          // 队头指针
    int     rear;           // 队尾指针
    BTNode* data[MAX_SIZE]; // 存放队中元素
} SqQueue;                  // struct Queue 的别名

//菜单
void menu();
//创建二叉树 
int createBTNode(BTNode * &BT,char *str,int n);
//销毁二叉树
void destroyBTNode(BTNode * &BT);
//查找结点存在
BTNode *findBTNode(BTNode * &BT,char ch);
//求高度
int BTHeight(BTNode * &BT);
//输出二叉树
void displayBTNode(BTNode * &BT);
//先序遍历
void preOrder(BTNode * &BT);
//中序遍历
void inOrder(BTNode * &BT);
//后序遍历
void postOrder(BTNode * &BT);
//先序非递归遍历
void preOrderNonRecursive(BTNode *BT);
//中序非递归遍历
void inOrderNonRecursive(BTNode *BT);
//后序非递归遍历
void postOrderNonRecursive(BTNode *BT);
// 初始化队列
void initQueue(SqQueue** q); 
// 判断队列空            
bool emptyQueue(SqQueue* q);     
// 入队        
bool enQueue(SqQueue* q, BTNode* node);  
// 出队
bool deQueue(SqQueue* q, BTNode** node); 
// 层次遍历
void levelOrder(BTNode* BT);                      





// A. 创建一棵二叉树 CreateBTNode(*b,*str)
int createBTNode(BTNode * &BT,char *str,int n){	
	printf("%d ",n);
	char ch=str[n];								//把第 n 个字符赋给ch,方便后面判断 
	printf("%c \n",ch);
	n=n+1;
	if(ch!='\0'){								//如果 ch 不等于结束符就继续创建，否则就结束 
		if( ch=='#'){							//以 # 号代表 NULL，下面没有了 
			BT = NULL;
		}
		else{
			BT = new BTNode;					//新建一个二叉链 
			BT->data=ch;						//把字符存入二叉链 
			n=createBTNode(BT->lchild,str,n); 	//左递归创建 
			n=createBTNode(BT->rchild,str,n);	//右递归创建 
		}
	}
	return n;									//返回 n,记录字符串使用到哪里了 
}

// B. 查找结点FindNode(*b,x)
BTNode *findBTNode(BTNode * &BT,char ch){
	if(BT==NULL){								//空，返回为空　NULL 
		return NULL;
	}
	else if(BT->data==ch){						//存在，提示存在并返回数据 
		printf("存在该节点：%c\n",ch); 
		return BT;
	}
	else{
		BTNode *p;								//定义一个链表指针 
		p=findBTNode(BT->lchild,ch);			//递归查询左子树 
		if(p!=NULL){
			return p;							//左子树已经找到 
		}
		else{
			return findBTNode(BT->rchild,ch);	//递归查询右子树 
		}
	}
}

// C. 销毁二叉树DestroyBTree(&b)
void destroyBTNode(BTNode * &BT){
	if(BT!=NULL){
		destroyBTNode(BT->lchild);				//左递归释放内存 
		destroyBTNode(BT->rchild);				//右递归释放内存 
		
		/*
			free()释放的是指针指向的内存！注意！释放的是内存，不是指针！这点非常非常重要！
			指针是一个变量，只有程序结束时才被销毁。释放内存空间。 
			原来指向这块空间的指针还是存在！只不过现在指针指向的内容是未定义的。
			因此，释放内存后把指针指向NULL，防止指针在后面不小心又被引用了。非常重要啊这一点！
		*/
		delete BT;
		BT=NULL; 
	}
}

// D. 求高度BTNodeDepth(*b)
int BTHeight(BTNode * &BT){
	int lchildh;//左孩子
	int rchildh;//右孩子
	int h;
	if(BT==NULL){
		return 0;										//空树高度为0 
	}
	else{
		lchildh=BTHeight(BT->lchild);					//求左子树的高度 
		rchildh=BTHeight(BT->rchild);					//求右子树的高度 
		h=(lchildh>rchildh)?(lchildh+1):(rchildh+1);	//比较左子树和右子树，高度高的再 +1（根节点） 就是树的高度 
		return h;
	}
}

// E. 输出二叉树DispBTNode(*b)
void displayBTNode(BTNode * &BT){
	if(BT!=NULL){
		printf("%c",BT->data);
		displayBTNode(BT->lchild);
		displayBTNode(BT->rchild);
	}
	else{
		printf("#");
	}
}

// F. 先序递归遍历二叉树PreOrder(BTNode *b)
// G. 先序非递归遍历二叉树PreOrder1(BTNode *b)
void preOrder(BTNode * &BT){
    if(BT!=NULL){					//判断不为空 
        printf("%c",BT->data);		//访问根节点
        preOrder(BT->lchild);		//递归，先序遍历左子树 
        preOrder(BT->rchild);		//递归，先序遍历右子树 
    }
}

// H. 中序递归遍历二叉树InOrder(BTNode *b)
// I. 中序非递归遍历二叉树InOrder(BTNode *b)
void inOrder(BTNode * &BT){
        if(BT!=NULL){
            inOrder(BT->lchild);
            printf("%c",BT->data);
            inOrder(BT->rchild);
        }
    }

// J. 后序递归遍历二叉树PostOrder(BTNode *b)
// K. 后序非递归遍历二叉树PostOrder(BTNode *b)
void postOrder(BTNode * &BT){
    if(BT!=NULL){
        postOrder(BT->lchild);
        postOrder(BT->rchild);
        printf("%c",BT->data);
    }
}

void preOrderNonRecursive(BTNode *BT){
    if(BT==NULL) return;
    BTNode* stack[MAX_SIZE];
    int top=-1;
    stack[++top]=BT;
    while(top!=-1){
        BTNode* p=stack[top--];
        printf("%c",p->data);
        if(p->rchild!=NULL) stack[++top]=p->rchild;
        if(p->lchild!=NULL) stack[++top]=p->lchild;
    }
}

void inOrderNonRecursive(BTNode *BT){
    BTNode* stack[MAX_SIZE];
    int top=-1;
    BTNode* p=BT;
    while(top!=-1 || p!=NULL){
        while(p!=NULL){
            stack[++top]=p;
            p=p->lchild;
        }
        if(top!=-1){
            p=stack[top--];
            printf("%c",p->data);
            p=p->rchild;
        }
    }
}

void postOrderNonRecursive(BTNode *BT){
    if(BT==NULL) return;
    BTNode* stack1[MAX_SIZE];
    BTNode* stack2[MAX_SIZE];
    int top1=-1,top2=-1;
    stack1[++top1]=BT;
    while(top1!=-1){
        BTNode* p=stack1[top1--];
        stack2[++top2]=p;
        if(p->lchild!=NULL) stack1[++top1]=p->lchild;
        if(p->rchild!=NULL) stack1[++top1]=p->rchild;
    }
    while(top2!=-1){
        printf("%c",stack2[top2--]->data);
    }
}

// 初始化队列
void initQueue(SqQueue** q) {
    if (!((*q) = (SqQueue*)malloc(sizeof(SqQueue)))) {
        printf("内存分配失败！");
        exit(-1);
    }
    (*q)->front = (*q)->rear = 0;
}

// 进队列
bool enQueue(SqQueue* q, BTNode* node) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        return false;
    }
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % MAX_SIZE;
    return true;
}

// 判断队列是否为空
bool emptyQueue(SqQueue* q) {
    if (q->front == q->rear) {
        return true;
    }
    return false;
}

// 出队列
bool deQueue(SqQueue* q, BTNode** node) {
    if (q->front == q->rear) {
        return false;
    }
    *node = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return true;
}

void levelOrder(BTNode* BT) {
    SqQueue* q;       // 定义队列
    initQueue(&q);    // 初始化队列
    if (BT != NULL) { // 根节点指针进队列
        enQueue(q, BT);
    }
    // 一层一层的把节点存入队列，当没有孩子节点时就不再循环
    while (!emptyQueue(q)) {      // 队不为空循环
        deQueue(q, &BT);          // 出队时的节点
        printf("%c", BT->data);   // 输出节点存储的值
        if (BT->lchild != NULL) { // 有左孩子时将该节点进队列
            enQueue(q, BT->lchild);
        }
        if (BT->rchild != NULL) { // 有右孩子时将该节点进队列
            enQueue(q, BT->rchild);
        }
    }
}

int main()
{
	BTNode *BT;
	int num=-1;
    int count=0;
    char flag;
    char ch;
    int flag2=1;
	do{
        if(flag2==0){
            system("pause");
        }
        flag2=0;
        menu();    
        printf("请输入您的需求:");
        scanf("%c",&flag);
        getchar();
        switch (flag)
        {
        case 'A':{			
	        printf("输入字符串(例:ABC###D##):");
	        char *str=(char *)malloc(sizeof(char) * 1024);
	        scanf("%s",str);
            getchar();
            createBTNode(BT,str,0);
            free(str);
			printf("二叉树建立成功\n");
            break;
			}
        case 'B':{
		    char c;
			printf("请输入要查找的节点：");
	        scanf("%c",&c);
            getchar();
	        printf("%c\n",c); 
	        if(findBTNode(BT,c)==NULL){
		        printf("没有此节点\n");
	            }
			break;
			}
		case 'C':{
		    destroyBTNode(BT);
			if(BT==NULL){
		        printf("销毁成功\n");
	        }
			break;
			}
		case 'D':{
		    int h=BTHeight(BT); 
	        printf("树的高度为：%d",h);
	        printf("\n");
			break;
            }
		case 'E':{
            printf("二叉树为："); 
	        displayBTNode(BT);
	        printf("\n");
			break;
            }
		case 'F':{
            printf("先序遍历结果：");
	        preOrder(BT);
	        printf("\n");
			break;
            }
        case 'G':{
            printf("先序非递归遍历结果：");
	        preOrderNonRecursive(BT);
	        printf("\n");
			break;
            }
		case 'H':{
            printf("中序遍历结果：");
	        inOrder(BT);
	        printf("\n");
			break;
            }
        case 'I':{
            printf("中序非递归遍历结果：");
	        inOrderNonRecursive(BT);
	        printf("\n");
			break;
            }
		case 'J':{
        	printf("后序遍历结果：");
	        postOrder(BT);
	        printf("\n");
			break;
            }
        case 'K':{
        	printf("后序非递归遍历结果：");
	        postOrderNonRecursive(BT);
	        printf("\n");
			break;
            }
		case 'L':{
            printf("层序遍历结果:");
            levelOrder(BT);
            printf("\n");
			break;
            }
        case 'M':{
// M.（递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码
            break;
        }
        case 'N':{
// N.（非递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码
            break;
        }
        case 'Z':{
            printf("再见!\n");
            break;
        }
        default:
            printf("请重新输入!");
            printf("\n");
            getchar();
            break;
        }
    }while(flag!='Z');
	return 0;
}



// L. 层次遍历二叉树LevelOrder(BTNode *b)
// M. （递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码
// N.（非递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码

//菜单
void menu()
{ 
    printf("\n================================");
    printf("\n");
    printf("功能菜单:\n");
    printf("A. 创建一棵二叉树\n");
    printf("B. 查找结点\n");
    printf("C. 销毁二叉树\n");
    printf("D. 求高度\n");
    printf("E. 输出二叉树\n");
    printf("F. 先序递归遍历二叉树\n");
    printf("G. 先序非递归遍历二叉树\n");
    printf("H. 中序递归遍历二叉树\n");
    printf("I. 中序非递归遍历二叉树\n");
    printf("J. 后序递归遍历二叉树\n");
    printf("K. 后序非递归遍历二叉树\n");
    printf("L. 层次遍历二叉树\n");
    printf("M.（递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码\n");
    printf("N.（非递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码\n");
    printf("Z. 退出");    
    printf("================================\n");
}

