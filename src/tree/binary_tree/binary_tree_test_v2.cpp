#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct node{
	struct node *lchild;						//指向左孩子节点
	char data;									//数据元素
	struct node *rchild;						//指向右孩子节点 
}BTNode;

void menu();
int createBTNode(BTNode * &BT,char *str,int n);
BTNode *findBTNode(BTNode * &BT,char ch);
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


void menu()
{
    printf("\n================================");
    printf("\n");
    printf("功能菜单:\n");
    printf(" 1.创建二叉树\n 2.查找结点\n 3.销毁二叉树\n 4.求高度\n 5.输出二叉树\n 6.先序遍历\n 7.中序遍历\n 8.后序遍历\n 9.退出\n");
    printf("================================\n");
    printf("请输入您的需求:");

}



// A. 创建一棵二叉树 CreateBTNode(*b,*str)
//创建二叉树
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



int BTHeight(BTNode * &BT){
	int lchildh;
	int rchildh;
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

void displayBTNode(BTNode * &BT){
	if(BT!=NULL){
		printf("%c",BT->data);
		if(BT->lchild!=NULL || BT->rchild!=NULL){
			printf("(");
			displayBTNode(BT->lchild);
			printf(",");
			displayBTNode(BT->rchild);
			printf(")");
		}
	}
}
void displayBTNode1(BTNode * &BT){
	if(BT!=NULL){
		printf("%c",BT->data);
		displayBTNode1(BT->lchild);
		displayBTNode1(BT->rchild);
	}
	else{
		printf("#");
	}
}

void preOrder(BTNode * &BT){
    if(BT!=NULL){					//判断不为空 
        printf("%c",BT->data);		//访问根节点
        preOrder(BT->lchild);		//递归，先序遍历左子树 
        preOrder(BT->rchild);		//递归，先序遍历右子树 
    }
}

 void inOrder(BTNode * &BT){
        if(BT!=NULL){
            inOrder(BT->lchild);
            printf("%c",BT->data);
            inOrder(BT->rchild);
        }
    }

void postOrder(BTNode * &BT){
    if(BT!=NULL){
        postOrder(BT->lchild);
        postOrder(BT->rchild);
        printf("%c",BT->data);
    }
}

int main()
{
	BTNode *BT;
	int num=-1;
    int count=0;
    char ch;
    menu();
	do{
    printf("请输入您的需求:");
        scanf("%d",&num);
        getchar();
        switch (num)
        {
        case 1:{
		    //例子：ABC###D##
			
	        printf("输入字符串：");
	        char *str=(char *)malloc(sizeof(char) * 1024);
	        scanf("%s",str);
            createBTNode(BT,str,0);
            free(str);
			printf("二叉树建立成功\n");
            break;
			}
        case 2:{
		    char c;
			printf("请输入要查找的节点：");
	        scanf("%c",&c);
	        printf("%c\n",c); 
	        if(findBTNode(BT,c)==NULL){
		        printf("没有此节点\n");
	            }
			break;
			}
		case 3:{
		    destroyBTNode(BT);
			if(BT==NULL){
		        printf("销毁成功\n");
	        }
			break;
			}
		case 4:{
		    int h=BTHeight(BT);
		    printf("树的高度为：%d\n",h);
			break;
            }
		case 5:{
		    printf("二叉树为：");
		    displayBTNode(BT);
		    printf("\n");
			break;
            }
		case 6:{
		    printf("先序遍历结果：");
		    preOrder(BT);
		    printf("\n");
			break;
            }
		case 7:{
		    printf("中序遍历结果：");
		    inOrder(BT);
		    printf("\n");
			break;
            }
		case 8:{
		    printf("后序遍历结果：");
		    postOrder(BT);
		    printf("\n");
			break;
            }
		case 9:{
		    printf("再见!\n");
			break;
            }
        default:
            printf("请重新输入!");
            printf("\n");
            getchar();
            break;
        }
    }while(num!=9);
	

//	int h=BTHeight(BT); 
//	printf("树的高度为：%d",h);
//	printf("\n");
//	
//	printf("二叉树为："); 
//	displayBTNode(BT);
//	printf("\n");
//	printf("二叉树为："); 
//	displayBTNode1(BT);
//	printf("\n");
//	
//	printf("先序遍历结果：");
//	preOrder(BT);
//	printf("\n");
//    
//	printf("中序遍历结果：");
//	inOrder(BT);
//	printf("\n");
//    
//	printf("后序遍历结果：");
//	postOrder(BT);
//	printf("\n");
	
	return 0;
}




// D. 求高度BTNodeDepth(*b)
// E. 输出二叉树DispBTNode(*b)
// F. 先序递归遍历二叉树PreOrder(BTNode *b)
// G. 先序非递归遍历二叉树PreOrder1(BTNode *b)
// H. 中序递归遍历二叉树InOrder(BTNode *b)
// I. 中序非递归遍历二叉树InOrder(BTNode *b)
// J. 后序递归遍历二叉树PostOrder(BTNode *b)
// K. 后序非递归遍历二叉树PostOrder(BTNode *b)
// L. 层次遍历二叉树LevelOrder(BTNode *b)
// M. （递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码
// N.（非递归）构造一棵哈夫曼树并求给出元素的哈夫曼编码