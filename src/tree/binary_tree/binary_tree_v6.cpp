#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**************************/
/*一元稀疏多项式简单计算器*/
/**************************/


typedef struct polynomial{
	double coefficient;
	double index;
}ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LinkList;


int x;


//----------------------------------------------------------------------------

//                     【P4.cpp中的函数】
//
//
/*init:分配内存空间，建立一个空链表*/
LinkList* init();
/*createList:创建单链表List并返回头节点指针*/
LinkList* createList();
/*destroy:销毁单链表并返回NULL*/
LinkList* destroy(LinkList* const List);
/*absoluteValue:返回绝对值*/
double absoluteValue(const double number);
/*display:按照预定格式输出多项式*/
void display(LinkList* const List);
/*getNegative:把list2每个项的系数变成负数并把新多项式储存在list1中*/
void getNegative(LinkList* &list1, LinkList* &list2);
/*将list2按指数降序的形式插入到list1中，并合并同类项*/
void sortAndCombine(LinkList* &list1, LinkList* &list2);
/*getOperation:显示提示信息并读取用户的操作*/
int getMyOperationChoice();
// display1:按照预定格式输出含X的多项式
void display1(LinkList* const List);
//求解X
void add(LinkList* const List);


//
//
//----------------------------------------------------------------------------

bool createListFlag = false;
const int ERROR_CHOICE = 99;


/*init:分配内存空间，建立一个空链表*/
LinkList* init(){
	LinkList *List = (LinkList*)malloc(sizeof(LinkList));
	List->next = NULL;
	return List;
}


/*createList:创建单链表List并返回头节点指针*/
LinkList* createList(){
	LinkList* List = init();
	
	LinkList* pTailNode = List;  //pTailNode初始时指向头指针
	LinkList* pNewNode = NULL;
	
	
	printf("进行多项式输入，若系数输入0则结束输入\n");
	ElemType elem  = {0,0};
	int nodeCount = 1;
	while(1){
		printf("%dth项\n",nodeCount);
		printf("请输入当前项的系数:");
		scanf("%lf",&elem.coefficient);
		printf("请输入当前项的指数:");
		scanf("%lf",&elem.index);
		
		if(elem.coefficient == 0){
			break;
		}
		
		pNewNode = (LinkList*)malloc(sizeof(LinkList));
		pNewNode->data = elem;
		pNewNode->next = NULL;
		pTailNode->next = pNewNode;
		pTailNode = pNewNode;
		
		nodeCount++;
	}
	
	return List;
}


/*destroy:销毁单链表并返回NULL*/
LinkList* destroy(LinkList* const List){

	LinkList *pNode = List->next;
	while(pNode != NULL){
		List->next = pNode->next;
		free(pNode);
		pNode = List->next;
	}
	free(List);
	return NULL;
}


/*absoluteValue:返回绝对值*/
double absoluteValue(const double number){
	if(number >= 0){
		return number;
	}
	else{
		return (-number);
	}
}


/*display:按照预定格式输出多项式*/
void display(LinkList* const List){
	LinkList *pNode = List->next;  //初始时指向第一个数据节点
	bool firstNodeFlag = true;
	printf("(");
	while(pNode != NULL){
		
		if(firstNodeFlag != true && pNode->data.coefficient > 0){
			printf("+");
		}

		if(firstNodeFlag == true){
			firstNodeFlag = false;
		}
		
		if(pNode->data.coefficient == 1){
			;
		}
		else if(pNode->data.coefficient == -1){
			printf("-");
		}
		else{
			if( (absoluteValue(pNode->data.coefficient) - (int)absoluteValue(pNode->data.coefficient) ) > 0){
				printf("%.1lf",pNode->data.coefficient);
			}
			else{//只有整数部分
				printf("%d",(int)pNode->data.coefficient);
			}
		}

		if(pNode->data.index == 0){
			if(pNode->data.coefficient == 1);
			if(firstNodeFlag != true){
				printf("*");
			}
			printf("1");
		}
		else if(pNode->data.index == 1){
			printf("X");
		}
		else{
		    printf("X",x);
		    printf("^");
		    if(pNode->data.index < 0){
			    printf("(");
			    if( (absoluteValue(pNode->data.index) - (int)absoluteValue(pNode->data.index) ) > 0 ){
			    	printf("%.1lf",pNode->data.index);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index);			
			    }
			    printf(")");
		    }
	    	else{
			    if( (pNode->data.index - (int)pNode->data.index > 0) ){
			    	printf("%.1lf",pNode->data.index);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index);			
			    }
		    }
		}
		pNode = pNode->next;
	}
	printf(")");
}


/*getNegative:把list2每个项的系数变成负数并把新多项式储存在list1中*/
void getNegative(LinkList* &list1, LinkList* &list2){
	LinkList *pTailNode = list1;
	LinkList *pNode = list2->next;
	LinkList *pNewNode = NULL;
	
	while(pNode != NULL){
		pNewNode = (LinkList*)malloc(sizeof(LinkList));
		pNewNode->data.coefficient = -(pNode->data.coefficient);
		pNewNode->data.index = pNode->data.index;
		pNewNode->next = NULL;
		pTailNode->next = pNewNode;
		pTailNode = pNewNode;
		pNode = pNode->next;
	}
}


/*将list2按指数降序的形式插入到list1中，并合并同类项*/
void sortAndCombine(LinkList* &list1, LinkList* &list2){
	LinkList* pNodeInList2 = list2->next;
	LinkList* pPreNodeInList1 = list1;
	LinkList* pNewNode = NULL;
	
	while(pNodeInList2 != NULL){
		pPreNodeInList1 = list1;
		while( pPreNodeInList1->next != NULL && (pPreNodeInList1->next->data.index > pNodeInList2->data.index) ){
			pPreNodeInList1 = pPreNodeInList1->next;
		}
		
		if(pPreNodeInList1->next != NULL && (pPreNodeInList1->next->data.index == pNodeInList2->data.index) ){
			pPreNodeInList1->next->data.coefficient += pNodeInList2->data.coefficient;
		}
		else{
			pNewNode = (LinkList*)malloc(sizeof(LinkList));
		    pNewNode->data = pNodeInList2->data;
			pNewNode->next = pPreNodeInList1->next;
			pPreNodeInList1->next = pNewNode;
		}
		pNodeInList2 = pNodeInList2->next;
	}
	
	LinkList* delNode = NULL;
	pPreNodeInList1 = list1;
	while(pPreNodeInList1->next != NULL){
		if(pPreNodeInList1->next->data.coefficient == 0){
			delNode = pPreNodeInList1->next;  //系数为0的项删去
			pPreNodeInList1->next = pPreNodeInList1->next->next;
			free(delNode);
			continue;
		}
		pPreNodeInList1 = pPreNodeInList1->next;
		if(pPreNodeInList1 == NULL){
			break;
		}
	}
}


// display1:按照预定格式输出含X的多项式
void display1(LinkList* const List)
{
	LinkList *pNode = List->next;  //初始时指向第一个数据节点
	bool firstNodeFlag = true;
	printf("(");
	while(pNode != NULL){
		
		if(firstNodeFlag != true && pNode->data.coefficient > 0){
			printf("+");
		}

		if(firstNodeFlag == true){
			firstNodeFlag = false;
		}
		
		if(pNode->data.coefficient == 1){
			;
		}
		else if(pNode->data.coefficient == -1){
			printf("-");
		}
		else{
			if( (absoluteValue(pNode->data.coefficient) - (int)absoluteValue(pNode->data.coefficient) ) > 0){
				printf("%.1lf",pNode->data.coefficient);
			}
			else{//只有整数部分
				printf("%d",(int)pNode->data.coefficient);
			}
		}

		if(pNode->data.index == 0){
			if(pNode->data.coefficient == 1);
			if(firstNodeFlag != true){
				printf("*");
			}
			printf("1");
		}
		else if(pNode->data.index == 1){
			printf("*%d",x);
		}
		else{
		    printf("*%d",x);
		    printf("^");
		    if(pNode->data.index < 0){
			    printf("(");
			    if( (absoluteValue(pNode->data.index) - (int)absoluteValue(pNode->data.index) ) > 0 ){
			    	printf("%.1lf",pNode->data.index);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index);			
			    }
			    printf(")");
		    }
	    	else{
			    if( (pNode->data.index - (int)pNode->data.index > 0) ){
			    	printf("%.1lf",pNode->data.index);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index);			
			    }
		    }
		}
		pNode = pNode->next;
	}
	printf(")");
}


//求解X
void add(LinkList* const List)
{
	int i=0;
	int xishu;
	double sum=0;
	bool firstNodeFlag = true;
	LinkList *pNode = List->next;  //初始时指向第一个数据节点
	while(pNode != NULL){
		if(firstNodeFlag != true && pNode->data.coefficient > 0){
			printf("+");
		}

		if(firstNodeFlag == true){
			firstNodeFlag = false;
		}

		if(pNode->data.coefficient == 1){
			xishu=1;
		}else if(pNode->data.coefficient == -1){
			printf("-");
			xishu=-1;
		}else{
			if( (absoluteValue(pNode->data.coefficient) - (int)absoluteValue(pNode->data.coefficient) ) > 0){//panduanxiaoshu
				printf("%.1lf",pNode->data.coefficient);
			}
			else{//只有整数部分
				printf("%d",(int)pNode->data.coefficient);
			}
			xishu=pNode->data.coefficient;
		}

		if(pNode->data.index == 0){
			if(pNode->data.coefficient == 1);
			if(firstNodeFlag != true){
				printf("*");
			}
			sum=sum+xishu*1;
			printf("1");
		}else if(pNode->data.index == 1){
			sum=sum+xishu*x;
			printf("*%d",x);
		}else{
		    printf("*%d",x);
		    printf("^");
			//指数
		    if(pNode->data.index < 0){
			    printf("(");
			    if( (absoluteValue(pNode->data.index) - (int)absoluteValue(pNode->data.index) ) > 0 ){
			    	printf("%.1lf",pNode->data.index);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index);			
			    }
			    printf(")");
		    }
	    	else{
			    if( (pNode->data.index - (int)pNode->data.index > 0) ){
			    	printf("%.1lf",pNode->data.index);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index);			
			    }
		    }
			sum=sum+xishu*pow(x,pNode->data.index);
		}
		pNode = pNode->next;
	}
	printf("\n多项式L3在X处的运算结果为------\n%lf\n",sum);
}


void qiudao(LinkList* const List)
{
	LinkList *pNode = List->next;  //初始时指向第一个数据节点
	bool firstNodeFlag = true;
	printf("(");
	while(pNode != NULL){
		
		if(firstNodeFlag != true && pNode->data.coefficient > 0){
			printf("+");
		}

		if(firstNodeFlag == true){
			firstNodeFlag = false;
		}
		
		if(pNode->data.coefficient == 1){
			;
		}
		else if(pNode->data.coefficient == -1){
			printf("-");
		}
		else{
			if( (absoluteValue(pNode->data.coefficient*pNode->data.index) - (int)absoluteValue(pNode->data.coefficient*pNode->data.index) ) > 0){
				printf("%.1lf",pNode->data.coefficient*pNode->data.index);
			}
			else{//只有整数部分
				printf("%d",(int)pNode->data.coefficient*pNode->data.index);
			}
		}
		
		if(pNode->data.index-1 == 0){
			if(pNode->data.coefficient == 1);
			if(firstNodeFlag != true){
				printf("*");
			}
			printf("1");
		}
		else if(pNode->data.index-1 == 1){
			printf("X");
		}
		else{
		    printf("X");
		    printf("^");
		    if(pNode->data.index-1 < 0){
			    printf("(");
			    if( (absoluteValue(pNode->data.index-1) - (int)absoluteValue(pNode->data.index-1) ) > 0 ){
			    	printf("%.1lf",pNode->data.index-1);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index-1);			
			    }
			    printf(")");
		    }
	    	else{
			    if( (pNode->data.index-1 - (int)pNode->data.index-1 > 0) ){
			    	printf("%.1lf",pNode->data.index-1);
			    }
			    else{//只有整数部分
                    printf("%d",(int)pNode->data.index-1);			
			    }
		    }
		}
		pNode = pNode->next;
	}
	printf(")");

	// int i=0;
	// int xishu;
	// double sum=0;
	// bool firstNodeFlag = true;
	// LinkList *pNode = List->next;  //初始时指向第一个数据节点
	// while(pNode != NULL){
	// 	if(firstNodeFlag != true && pNode->data.coefficient > 0){
	// 		printf("+");
	// 	}

	// 	if(firstNodeFlag == true){
	// 		firstNodeFlag = false;
	// 	}

	// 	if(pNode->data.coefficient == 1){
	// 		xishu=1;
	// 	}else if(pNode->data.coefficient == -1){
	// 		printf("-");
	// 		xishu=-1;
	// 	}else{
	// 		if( (absoluteValue(pNode->data.coefficient) - (int)absoluteValue(pNode->data.coefficient) ) > 0){//panduanxiaoshu
	// 			printf("%.1lf",pNode->data.coefficient);
	// 		}
	// 		else{//只有整数部分
	// 			printf("%d",(int)pNode->data.coefficient);
	// 		}
	// 		xishu=pNode->data.coefficient;
	// 	}

	// 	if(pNode->data.index == 0){
	// 		if(pNode->data.coefficient == 1);
	// 		if(firstNodeFlag != true){
	// 			printf("*");
	// 		}
	// 		sum=sum+xishu*1;
	// 		printf("1");
	// 	}else if(pNode->data.index == 1){
	// 		sum=sum+xishu*x;
	// 		printf("*%d",x);
	// 	}else{
	// 	    printf("*%d",x);
	// 	    printf("^");
	// 		//指数
	// 	    if(pNode->data.index < 0){
	// 		    printf("(");
	// 		    if( (absoluteValue(pNode->data.index) - (int)absoluteValue(pNode->data.index) ) > 0 ){
	// 		    	printf("%.1lf",pNode->data.index);
	// 		    }
	// 		    else{//只有整数部分
    //                 printf("%d",(int)pNode->data.index);			
	// 		    }
	// 		    printf(")");
	// 	    }
	//     	else{
	// 		    if( (pNode->data.index - (int)pNode->data.index > 0) ){
	// 		    	printf("%.1lf",pNode->data.index);
	// 		    }
	// 		    else{//只有整数部分
    //                 printf("%d",(int)pNode->data.index);			
	// 		    }
	// 	    }
	// 		sum=sum+xishu*pow(x,pNode->data.index);
	// 	}
	// 	pNode = pNode->next;
	// }
	// printf("\n多项式L3在X处的运算结果为------\n%lf\n",sum);

}



/*getOperation:显示提示信息并读取用户的操作*/
int getMyOperationChoice(){
	int myChoice;
	system("cls");
	if(createListFlag == false){
		printf("\t\t多项式尚未输入，请输入1进行多项式输入\n");
		printf( "\n\n\n\n");
		printf( "\t\t              一元稀疏多项式简单计算器  \n");
		printf( "\t\t======================================\n");
		printf( "\t\t             1：多项式输入      \n");
		printf( "\t\t             0：退出        \n");
		printf( "\t\t请选择：");
	}
	else{
	    printf("已输入多项式L1、L2\n");
		printf( "\n\n\n\n");
		printf( "\t\t              一元稀疏多项式简单计算器  \n");
		printf( "\t\t======================================");
		printf( "\n\n");
		printf( "\t\t             1：重新输入多项式      \n");
		printf( "\t\t             2：输出多项式L1、L2    \n");
		printf( "\t\t             3：进行多项式加法并显示运算结果(L1+L2)          \n");
		printf( "\t\t             4：进行多项式减法并显示运算结果(L1-L2)          \n");
		printf( "\t\t             5：计算多项式L3在X处的值并显示运算结果          \n");
		printf( "\t\t             6：计算多项式a的导函数a'          			 \n");
		printf( "\t\t             0：退出        \n");
		printf( "\n");
		printf( "\t\t请选择：");
	}
	scanf("%d",&myChoice);
	
	if(myChoice != 1 && myChoice != 0 && createListFlag == false ){
		return ERROR_CHOICE;
	}
	return myChoice;
}


int main(){
    LinkList *L1 = NULL;
	LinkList *L2 = NULL;
	LinkList *L3 = NULL;
	LinkList *temp = NULL;

	// system("pause");
	
	int myOperationChoice;
	while((myOperationChoice = getMyOperationChoice()) != 0){
		switch(myOperationChoice){//读取除0以外的指令
			case 1:{
				if(createListFlag == true){
					L1 = destroy(L1);
					L2 = destroy(L2);
				}
				printf("进行多项式L1的输入\n");
				L1 = createList();
				printf("\n\n进行多项式L2的输入\n");
				L2 = createList();
				createListFlag = true;
				if(createListFlag == false){
					createListFlag = true;
				}
				
				//指数降序排序并合并同类项
				temp = init();
				sortAndCombine(temp,L1);
				L1 = destroy(L1);
				L1 = temp;
				temp = NULL;
				
				temp = init();
				sortAndCombine(temp,L2);
				L2 = destroy(L2);
				L2 = temp;
				temp = NULL;
				
				break;
			}
			case 2:{
	            printf("L1:");
				display(L1);
				printf("\n");
				printf("L2:");
				display(L2);
				printf("\n");
				break;
			}
			case 3:{
				if(L3 != NULL){
					L3 = destroy(L3);
				}
				L3 = init();
				sortAndCombine(L3,L1);
				sortAndCombine(L3,L2);
				
				display(L1);
				printf(" + ");
				display(L2);
				printf(" = ");
				display(L3);
				printf("\n");
				
				break;
			}
			case 4:{
				temp = init();
				getNegative(temp,L2);
				
				if(L3 != NULL){
					L3 = destroy(L3);
				}
				L3 = init();
				sortAndCombine(L3,L1);
				sortAndCombine(L3,temp);
				temp = destroy(temp);
				
				display(L1);
				printf(" - ");
				display(L2);
				printf(" = ");
				display(L3);
				printf("\n");
				
				break;
			}
			case 5:{
				if(L3 != NULL){
					L3 = destroy(L3);
				}
				L3 = init();
				printf("进行多项式L3的输入\n");
				L3 = createList();
				//指数降序排序并合并同类项
				temp = init();
				sortAndCombine(temp,L3);
				L3 = destroy(L3);
				L3 = temp;
				temp = NULL;

				printf("多项式L3的输入完成:");
				display(L3);
				printf("\n");
				printf("进行X的输入:");
				scanf("%d",&x);
				printf("当X=%d时,多项式L3=",x);
				display(L3);
				printf(" = ");
				display1(L3);
				printf("\n");
				add(L3);
				printf("\n");
				
				break;
			}
			case 6:{
				if(L3 != NULL){
					L3 = destroy(L3);
				}
				L3 = init();
				printf("进行多项式L3的输入\n");
				L3 = createList();
				//指数降序排序并合并同类项
				temp = init();
				sortAndCombine(temp,L3);
				L3 = destroy(L3);
				L3 = temp;
				temp = NULL;

				printf("多项式L3的输入完成:");
				display(L3);
				printf("\n");;

				display1(L3);
				printf("\n");
				qiudao(L3);
				printf("\n");
				
				break;
			}


			default:{
				printf("无效操作，请重试\n");
				break;
			}
		}
		system("pause");
	}
	return 0;
}


