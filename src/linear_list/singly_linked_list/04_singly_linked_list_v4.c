//readme
//

// 1.首先包含头文件，定义链表结构体，产生随即链表的范围，定义全局头尾节点。

// 2.准备工作

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>//getch()

#define MAX 100

/*定义链表*/
typedef struct Node 
{
    int data;
    struct Node *next;  
}Node;
/*定义全局头尾节点*/
Node *head = NULL;
Node *end = NULL;

void InitializeList();//initialization初始化链表
int CreatList(int a);/*根据传入的参数添加链表节点*/
void PrintList(Node *temp);/*打印链表*/
int InsertListEnd(int index,int a);/*根据传入的数，在其后面增加元素*/
int InsertListHead(int index,int a);/*根据传入的数，在其前面增加元素*/
void DeleteListHead();/*删除链表头*/
void DeleteListTail();/*尾删除————删*/
void DeleteList(int a);/*删除链表任意元素*/
Node *FindList(int a);/*根据传入的数值，查询链表*/
void ModifyList(Node *phead,int element,int modify);/*修改链表元素,element为要修改的元素，modify为修改后的值*/
int LengthList(Node *temp);/*求链表长度并返回*/
Node *FindPreNode(Node *p);/*寻找p的前驱节点*/
Node *FindNextNode(Node *p);/*寻找p的后继节点*/
Node *InvertList(Node *phead);/*方法一：倒置链表*/
Node *ReverseList(Node *phead);/*方法二：倒置链表*/
int Is_Circular(Node *phead);/*判断链表有环*/


// 单链表的冒泡，快排，选择，插入，归并5种排序算法


Node *BubbleSort(Node *phead);// 1.冒泡排序

int *QuickSort(Node* pBegin, Node* pEnd);// 2.快速排序

Node *InsertSort(Node *phead);// 3.插入排序

Node* SelectSort(Node* phead);// 4.选择排序

void Swanext(Node *p,Node *q);/*交换相邻节点*/

void SwapHeadAnother(Node *tmphead,Node *p);/*交换头结点和任意节点(除尾节点外)*/

void SwapEndAnother(Node *tmpend,Node *p);/*交换尾结点和任意节点(除头节点外)*/

void SwapHeadEnd(Node *tmphead,Node *tmpend);/*交换头结点和尾节点*/

void SwapRandom(Node *p,Node *q);/*除了首尾节点，中间不相邻的两个节点*/

void SwapNode(Node*p, Node*q);/*交换任意两个节点*/

Node *MergeSort(Node *pList);// 5.归并排序

Node *getMiddleNode(Node *pList);/*获取链表中间元素*/

Node *MergeList(Node *p1, Node *p2);/*合并有序链表，合并之后升序排列*/



void wait();//公用的等待函数


// 3.创建链表

/*根据传入的参数添加链表节点*/
int CreatList(int a)
{
    /*定义临时结构体并分配空间*/
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp ==NULL)
    {
        printf("malloc error!");
        return -1;
    }
    else
	{
		/*给数据类型赋值*/
		temp->data = a;
		temp->next = NULL;
		/*如果链表长度为0*/
		if (head == NULL)
		{
			head = temp; 
			end = temp;    
		}
		else
		{
			end->next = temp;
			end = temp;
		}
    }  
}

// 4.打印链表

/*打印链表*/
void PrintList(Node *temp)
{
    if(temp == NULL)
    {
        printf("Empty List！\r\n");
    }
    while (temp)
    {
       printf("%d",temp->data);
       temp = temp->next;
	   if(temp)
	   printf("->");
    }
    printf("\r\n");
}

// 5.在节点后面插入元素

/*根据传入的数，在其后面增加元素*/
int InsertListEnd(int index,int a)
{
    if (head == NULL)
    {
        printf("Empty List！\r\n");
        return 0;
    }
	if (FindList(index)->next == FindList(a))
		return 0;
	else
	{
	  /*找到传入值的位置并保存*/
		Node *temp = FindList(index);
		/*分配空间存放新的传入的值*/
		Node *pt = (Node *)malloc(sizeof(Node));
		pt->data = a;
		/*是否是最后一个元素*/
		if (temp == end)
		{
			//尾巴的下一个指向新插入的节点
			end->next = pt;
			//新的尾巴
			end = pt;
			end->next = NULL;
		}
		else
		{
			// 先连后面 （先将要插入的节点指针指向原来找到节点的下一个）
			pt->next = temp->next;
			//后连前面
			temp->next = pt;
			printf("The list after insert %d is \r\n",a);
			PrintList(head);
		}
	}

}

// 6.在元素前面插入元素

/*根据传入的数，在其前面增加元素*/
int InsertListHead(int index,int a)
{
    if (head == NULL)
    {
        printf("Empty List！\r\n");
        return 0;
    }

	   /*找到传入值的位置并保存*/
		Node *temp = FindList(index);
		/*分配空间存放新的传入的值*/
		Node *pt = (Node *)malloc(sizeof(Node));
		pt->data = a;
		/*是否是第一个元素*/
		if (temp == head)
		{
			//尾巴的下一个指向新插入的节点
			pt->next = head;
			//新的头
			head = pt;
		}
		else
		{
			/*寻找到要插入位置的前驱节点*/
			Node *pre = FindPreNode(temp);
			pre->next = pt;
			pt->next = temp;
			printf("The list after insert %d is \r\n",a);
			PrintList(head);
		}


}

// 7.删除链表元素，要注意删除链表尾还是链表头

/*删除链表头*/
void DeleteListHead()
{ //记住旧头
	Node *temp = head;
	//链表检测
	if (NULL == head)
	{
		printf("Empty list!\n");
		return;
	}

	head = head->next; //头的第二个节点变成新的头
	free(temp);
}
/*尾删除————删*/
void DeleteListTail()
{
	if (NULL == end)
	{
		printf("链表为空，无需删除\n");
		return;
	}
	//链表不为空
	//链表有一个节点
	if (head == end)
	{
		free(head);
		head = NULL;
		end = NULL;
	}
	else
	{
		//找到尾巴前一个节点
		Node *temp = head;
		while (temp->next != end)
		{
			temp = temp->next;
		}
		//找到了，删尾巴
		//释放尾巴
		free(end);
		//尾巴迁移
		end = temp;
		//尾巴指针为NULL
		end->next = NULL;
	}
}
/*删除链表任意元素*/
void DeleteList(int a)
{
   //链表判断 是不是没有东西
	if (NULL == head)
	{
		printf("Empty list!\n");
		return;
	}
	//链表有东西，找这个节点
	 Node *temp = FindList(a);
	if (NULL == temp)
	{
		printf("%d not find\r\n",a);
		return;
	}
	//找到了,且只有一个节点
	if (head == end)
	{
		free(head);
		head = NULL;
		end = NULL;
        printf("The list after delete %d is empty!\r\n",a);
       
	}
	else if (head->next == end) //有两个节点
	{
		//看是删除头还是删除尾
		if (end == temp)
		{
			DeleteListTail();
            printf("The list after delete %d is \r\n",a);
            PrintList(head);
		}
		else if (temp == head)
		{
			DeleteListHead();
            printf("The list after delete %d is \r\n",a);
            PrintList(head);
		}
	}
	else //多个节点
	{
		//看是删除头还是删除尾
		if (end == temp)
			DeleteListTail();
		else if (temp == head)
			DeleteListHead();
		else //删除中间某个节点
		{	//找要删除temp前一个，遍历
			Node *pt = head;
			while (pt->next != temp)
			{
				pt = pt->next;
			}
			//找到了
			//让前一个直接连接后一个 跳过指定的即可
			pt->next = temp->next;
			free(temp);
            printf("The list after delete %d is \r\n",a);
            PrintList(head);
		}
	}
    
}

// 8.根据传入的数值查询链表

/*根据传入的数值，查询链表*/
Node *FindList(int a)
{
    Node *temp = head;
    if(head == NULL)
    {
        printf("Empty List！\r\n");
        return NULL;
    }
  
    else
    {
       while (temp)
       {
           if (temp->data == a)
           {
                printf("%d find!\r\n",a);
                return temp;
           }
           temp = temp->next;
       }
            printf("%d not find!\r\n",a);
            return 0;
    }
    
}

// 9.修改链表元素

/*修改链表元素,element为要修改的元素，modify为修改后的值*/
void ModifyList(Node *phead,int element,int modify)
{
	Node *temp = phead;
	while((temp!= NULL))
	{
		
		if(temp->data == element)
		{
			temp->data	= modify;
			
		}	
		temp = temp->next;
	}
}

// 10.求链表长度

/*求链表长度并返回*/
int LengthList(Node *temp)
{
    int length = 0;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
    
}

// 11.前驱，后继节点的查找

Node *FindPreNode(Node *p)
{
	Node *temp = head;
	/*寻找p的前驱节点*/
	if(p == head)
	{
		printf("%d is head node\r\n",p->data);
		return NULL;
	}
	else
	{
		while((temp->next != p) && (temp !=NULL))
		{
			
			temp = temp->next;

		}
		return temp;		
	}

}
Node *FindNextNode(Node *p)
{
	Node *temp = head;
	/*寻找p的后继节点*/
	while(temp &&(temp != p))
	{
		temp = temp->next;

	}
	/*先不判断是否为尾节点，尾节点NULL也可以赋值*/
	temp = temp->next;
	return temp;
	 
}

// 12.倒置链表

/*方法一：倒置链表*/
Node *InvertList(Node *phead)
{
        if(phead == NULL || phead->next == NULL)
		{
                return phead;
        }
		else
		{
                Node *p = phead;
                Node *q = NULL;
                Node *r = NULL;
                while(p != NULL)
				{
						/*保存下一个节点*/
                        q = p->next;
						/*让该节点指向上一个节点*/
                        p->next = r;
						/*上一个节点走到当前节点*/
                        r = p;
						/*当前节点走到下一个节点*/
                        p = q;
                }
				head = r;
                return head;
        }
}
/*方法二：倒置链表*/
Node *ReverseList(Node *phead)
    {
		/*创建一个新链*/
		/*两个指针，一个指向新的链表，一个指向单个断开的节点元素。连接起来*/
        Node *ptmp = NULL;
        Node *tmp = NULL;
		/*处理链表为空*/
        if(NULL == phead)
		{
                printf("link is empty\n");
                return NULL;
        }else
		{
				/*将旧链上的结点链到新链上*/
                while(phead != NULL)
				{
                        tmp = phead;
                        phead = phead->next;
						/*连接到上一次存下来的连表上。第一次时，ptmp为空，整个链表赋值给tmp后只剩下第一个元素*/
                        tmp->next = ptmp;
						/*新的链表赋值给ptmp*/
                        ptmp = tmp;
                }
        }
		head = ptmp;
        return ptmp;
}

// 13.判断链表是否有环

/*判断链表有环*/
int Is_Circular(Node *phead)
{
        if(phead == NULL || phead->next == NULL){
                return 0;       
        }
		/*快慢指针，当二者相等时，一定有环*/
        Node *p1 = phead;
        Node *p2 = phead;
        while(p1 != NULL && p2 != NULL){
                p2 = p2->next; 
                if(p1 == p2)
                        return 1;
                p2 = p2->next;
                p1 = p1->next;
        }
        return 0;
}

// 14.单链表的冒泡，快排，选择，插入，归并5种排序算法

// 1.冒泡排序
Node *BubbleSort(Node *phead)
{

	Node * p = phead;
	Node * q = phead->next;
	/*有几个数据就-1；比如x 个i<x-1*/
	for(int i=0;i<5;i++)
	{ 
		while((q!=NULL)&&(p!=NULL))
		{ 
			if(p->data>q->data)
			{
				/*头结点和下一节点的交换，要特殊处理，更新新的头head*/
				if (p == phead)
				{
					p->next = q->next;
					q->next = p;
					head = q;
					phead = q;
					/*这里切记要把p,q换回来，正常的话q应该在p的前面，进行的是p,q的比较
					*但是经过指针域交换之后就变成q,p.再次进行下一次比较时，
					*就会变成q,p的数据域比较。假如原本p->data > q->data,则进行交换。变成q->data和p->data比较，
					*不会进行交换，所以排序就会错误。有兴趣的可以调试下。
					*/	
					Node*temp=p; 
					p=q;
					q=temp;		
				}
				/*处理中间过程，其他数据的交换情况，要寻找前驱节点if (p != phead)*/
				else 
				{
					/*p，q的那个在前，那个在后。指针域的连接画图好理解一点*/
					if (p->next == q)
					{
						/*寻找p的前驱节点*/
						Node *ppre = FindPreNode(p);
						/*将p的下一个指向q的下一个*/
						p->next = q->next;
						/*此时q为头结点，让q的下一个指向p，连接起来*/
						q->next = p;
						/*将原来p的前驱节点指向现在的q，现在的q为头结点*/
						ppre->next = q;
						Node*temp=p; 
						p=q; 
						q=temp;
					}
					else if (q->next == p)
					{
						Node *qpre = FindPreNode(q);
						q->next = p->next;
						p->next = q;
						qpre->next = p;
						Node*temp=p;
						p=q; 
						q=temp;
						}									
				}		
			}
			/*地址移动*/
			p = p->next;
			q = q->next;
		}
		/*进行完一轮比较后，从头开始进行第二轮*/
		p = phead;
		q = phead->next;	
	}
	
	head = phead;
	return head;
}

// 2.快速排序
int *QuickSort(Node* pBegin, Node* pEnd)
{
    if(pBegin == NULL || pEnd == NULL || pBegin == pEnd)
        return 0;
 
    //定义两个指针
    Node* p1 = pBegin;
    Node* p2 = pBegin->next;
    int pivot = pBegin->data;

	int temp;//

	//每次只比较小的，把小的放在前面。经过一轮比较后，被分成左右两部分。其中p1指向中值处，pbegin为pivot。
    while(p2 != NULL)/* && p2 != pEnd->next */
	{
        if(p2->data < pivot)
		{
            p1 = p1->next;
            if(p1 != p2)
			{
                // SwapNode(&p1->data, &p2->data);
				// SwapData(&p1->data, &p2->data);
				temp=p2->data;
				p2->data=p1->data;
				p1->data=temp;

        	}
      	}
        p2 = p2->next;
   }
   /*此时pivot并不在中间，我们要把他放到中间，以他为基准，把数据分为左右两边*/
    // SwapNode(&p1->data, &pBegin->data);
	// SwapData(&p1->data, &pBegin->data);
	temp=pBegin->data;
	pBegin->data=p1->data;
	p1->data=temp;

    //此时p1是中值节点
	//if(p1->data >pBegin->data)
    QuickSort(pBegin, p1);
	//if(p1->data < pEnd->data)
    QuickSort(p1->next, pEnd);

}

// 3.插入排序
Node *InsertSort(Node *phead)  
{  
	/*不好理解可以调试下看下具体过程*/
	/*为原链表剩下用于直接插入排序的节点头指针*/  
    Node *unsort; 
	/*临时指针变量：插入节点*/
    Node *t;  
	/*临时指针变量*/  
    Node *p; 
	/*临时指针变量*/  
    Node *sort; 
	/*原链表剩下用于直接插入排序的节点链表：可根据图12来理解。*/  
    unsort = phead->next; 
	/*只含有一个节点的链表的有序链表：可根据图11来理解。*/  
    head->next = NULL; 
  	/*遍历剩下无序的链表*/ 
    while (unsort != NULL)  
    {  
        /*注意：这里for语句就是体现直接插入排序思想的地方*/
		/*无序节点在有序链表中找插入的位置*/  
		/*跳出for循环的条件：
		*1.sort为空，此时，sort->data < t->data，p存下位置，应该放在有序链表的后面
		*2.sort->data > t->data ，跳出循环时，t->data放在有序链表sort的前面
		*3.sort为空 sort->data > t->data，也插入在sort前面的位置
		*/  
		/*q为有序链表*/
        for (t = unsort, sort = phead; ((sort != NULL) && (sort->data < t->data)); p = sort, sort = sort->next); 
      
   		 /*退出for循环，就是找到了插入的位置插入位置要么在前面，要么在后面*/  
    	/*注意：按道理来说，这句话可以放到下面注释了的那个位置也应该对的，但是就是不能。原因：你若理解了上面的第3条，就知道了。*/  
       /*无序链表中的第一个节点离开，以便它插入到有序链表中。*/
	    unsort = unsort->next;    
		/*插在第一个节点之前*/ 
		/*sort->data > t->data*/
		/*sort为空 sort->data > t->data*/
        if (sort == phead)  
        {  
			/*整个无序链表给phead*/
            phead = t;  
        }  
		/*p是sort的前驱，这样说不太确切，当sort到最后时，for里面有个sort = sort->next，
		*就会把sort置空，所以要用p暂存上一次sort的值。而且执行判断sort->data < t->data时，用的也是上一次的sort
		*/
		/*sort后面插入*/
		/*sort遍历到了最后，此时，sort->data < t->data,sort和p都为最后一个元素。*/ 
        else  
        {  
            p->next = t;  
        }  
		/*if处理之后，t为无序链表，因为要在phead前插入。这里先把t赋值给phead，再把t的next指向sort，
		*就完成了在sort之前插入小的元素，很巧妙的一种方法
		*else处理完之后，sort存放的是sort的下一次，真正的sort存放在p中。不满足条件跳出循环时，判断的是下一次的sort，
		但是我们要用的插入的位置为上一次的sort，所以要记录下sort上一次的位置
		*/
		/*完成插入动作*/
		/*当sort遍历完成为空时，t->next就是断开后面的元素（sort为空）*/
		/*当sort不为空时，sort->data > t->data，sort存放的元素比t要大，放在后面，t->next就是再链接起来sort*/
        t->next = sort;   
        /*unsort = unsort->next;*/  
    }  
	head = phead;
    return phead;  
}

// 4.选择排序
Node* SelectSort(Node* phead)                                                
{                                                                                                             
	Node *temp;
	Node *temphead = phead;
	/*将第一次的最大值设置为头结点*/
	int max = phead->data;
	/*交换变量*/
	 for(int i = 0;i<LengthList(phead);i++)
	 {
		 /*每次遍历开始前都要把最大值设置为头结点*/
		  max = phead->data;
		while (temphead->next !=NULL)
		{
			/*寻找最大值*/
			if(max < temphead->next->data)
			{
				max =  temphead->next->data;
			}
			/*移动指针位置*/
			temphead = temphead->next;
		}	
		/*找到最大值的位置*/
		temp = FindList(max);
		/*判断最大值是否和头节点相同*/
		if(phead != temp)
		{
			SwapNode(phead,temp);		
		}
		/*更新下一次遍历的头结点*/
		temphead = temp->next;
		phead = temphead;
	}

} 

// SwapNode相关代码如下。当时考虑只需要理解排序思想就好了，就没有把这个函数的代码放出来。这个代码写的太长太复杂了，有时间我会重新精简下。

/*交换相邻节点*/
void Swanext(Node *p,Node *q)
{
	
	/*中间相邻节点*/
	if ((p != head)&&(q != head))
	{
		// /*p为前一个节点，q的前驱为p*/
		// /*寻找p的前驱结点*/
		// Node *ppre = FindPreNode(p);
		// Node *temp;
		
		// /*暂存p节点的后继结点，指向q*/
		// temp = p->next;
		// /*将q节点的后继节点赋值给p的后继结点，即将p节点放到了q位置（此时q的前驱节点的next指针还指向的是q）*/
		// p->next = q->next;
		// /*将p节点给q的next，即将完成了q与p的重新连接*/
		// q->next =p;
		// /*找到原来p的前驱节点，指向q，即完成了原来p的前驱结点和q节点的连接*/
		// ppre->next =q;
			if (p->next == q)
			{
				Node *ppre = FindPreNode(p);
				p->next = q->next;
				q->next = p;
				ppre->next = q;
				// PrintList(head);

			}
			else if (q->next == p)
			{
				Node *qpre = FindPreNode(q);
				q->next = p->next;
				p->next = q;
				qpre->next = p;

			}			

	}
	/*头结点相邻的交换*/	
	else
	{
		if(p == head)
		{
			p->next = q->next;
			q->next = p;
			head = q;
		}
		else 
		{
			q->next = p->next;
			p->next = q;	
			 head = p;		
		}
	}
	

	


}
/*交换头结点和任意节点(除尾节点外)*/
void SwapHeadAnother(Node *tmphead,Node *p)
{
	/*寻找p的前驱节点*/
	Node *ppre = FindPreNode(p);
	
	Node *temp;
	if(p!=tmphead->next)
	{
		/*暂存p节点*/
		temp = p->next;
		/*将tmphead节点的后继节点赋值给p的后继结点，即将tmphead节点放到了p位置（此时p的前驱节点的next指针还未断开）*/
		p->next = tmphead->next;
		/*将p的后继结点赋值给tmphead的后继结点，同时连接p的前驱和tmphead*/
		tmphead->next = temp;
		ppre->next =tmphead;
		/*新的头结点返回给全局head*/
		head = p;
	}

	else
	{
		/*头结点和下一节点*/
		 tmphead->next = p->next;
		 p->next = tmphead;
		 head = p;
	}


	

}
/*交换尾结点和任意节点(除头节点外)*/
void SwapEndAnother(Node *tmpend,Node *p)
{
	/*寻找p的前驱节点*/
	Node *ppre = FindPreNode(p);
	Node *endpre = FindPreNode(tmpend);
	Node *temp;
	if((tmpend==end)&&(p!=tmpend))
	{
		/*暂存p节点*/
		temp = p->next;
		/*将tmpend节点的后继节点赋值给p的后继结点，即将tmpend节点放到了p位置（此时p的前驱节点的next指针还未断开）*/
		p->next = tmpend->next;
		endpre->next = p;
		/*将p的后继结点赋值给tmpend的后继结点，同时连接p的前驱和tmpend（断开了之前的连接）*/
		tmpend->next = temp;
		ppre->next =tmpend;
		/*新的头结点返回给全局head*/
		end = p;
	}
	else
	{
		p->next = tmpend->next;
		tmpend->next = p;
		end = p;
	}

	

}
/*交换头结点和尾节点*/
void SwapHeadEnd(Node *tmphead,Node *tmpend)
{
	/*寻找tmpend的前驱节点*/
	Node *endpre = FindPreNode(tmpend);
	Node *temp;
	/*暂存tmpend节点*/
	temp = tmpend->next;
	/*将tmphead节点的后继节点赋值给tmpend的后继结点，即将tmpend节点放到了tmphead位置（此时tmpend的前驱节点的next指针还未断开）*/
	tmpend->next = tmphead->next;
	/*将p的后继结点赋值给tmpend的后继结点，同时连接p的前驱和tmpend（断开了之前的连接）*/
	tmphead->next = temp;
	endpre->next =tmphead;
	/*新的头结点返回给全局head*/
	head = tmpend;
	end = tmphead;
	// PrintList(tmpend);
}
/*除了首尾节点，中间不相邻的两个节点*/
void SwapRandom(Node *p,Node *q)
{
	
	
	if((p->next != q)||(q->next != p))
	{
		/*寻找前驱结点*/
		Node *ppre = FindPreNode(p);
		Node *qpre = FindPreNode(q);
		/*借助一个中间节点传递数据域*/
		Node *temp;
		temp = p->next;
		/*交换p和q*/
		/*2、p的新后继结点要变成q的原后继结点*/
		p->next = q->next;
		/*3、q的原前趋结点（qpre）的新后继结点要变成p*/
		qpre->next = p;
		/*4、q的新后继结点要变成p的原后继结点（p->next）*/
		q->next = temp;
		/*1、p的原前趋结点（ppre）的新后继结点要变成q*/
		ppre->next = q;
	}
	/*中间相邻节点的处理*/
	else if (p->next == q)
	{
		Node *ppre = FindPreNode(p);
		p->next = q->next;
		q->next = p;
		ppre->next = q;

	}
	else if (q->next == p)
	{
		Node *qpre = FindPreNode(q);
		q->next = p->next;
		p->next = q;
		qpre->next = p;

	}
	
}

/*交换任意两个节点*/
void SwapNode(Node*p, Node*q)
{
	// if(LengthList(head)<2)
	// printf("Can not swap!The Length of list is:%d\r\n ",LengthList(head));
	/*检查是否是头尾节点*/
	/*对于头尾节点有四种情况
	*1.p头节点和q为中间节点
	*2.p尾节点和q为中间节点
	*3.q头节点和p为中间节点
	*4.q尾节点和p为中间节点
	*5.p头结点和q尾节点
	*6.q头结点和p尾节点
	*7.其他中间交换的情况
	*/
	/*2.两个节点是否相邻 除去头结点和下一节点相邻的情况，放在headanother处理*/
	if((p->next == q)&&(p !=head)&&(q !=head))
	Swanext(p,q);
	else if((q->next == p)&&(p !=head)&&(q !=head))
	Swanext(q,p);
	/*1.p头节点和q为中间节点*/
	else if((p == head)&&(q != end))
	SwapHeadAnother(p,q);
	/*2.p尾节点和q为中间节点*/
	else if ((p == end)&&(q != head))
	SwapEndAnother(p,q);
	/*3.q头节点和p为中间节点*/
	else if((q == head)&&(p != end))
	SwapHeadAnother(q,p);
	/*4.q尾节点和p为中间节点*/
	else if((q == end)&&(p != head))
	SwapEndAnother(q,p);
	/*5.p头结点和q尾节点*/
	else if((p == head)&&(q == end))
	SwapHeadEnd(p,q);
	/*6.q头结点和p尾节点*/
	else if((q == head)&&(p == end))
	SwapHeadEnd(q,p);	
	/*7.其他中间交换的情况*/
	else 
	SwapRandom(p,q);	
}

// 5.归并排序
Node *MergeSort(Node *pList)
{
    if (pList == NULL || pList->next == NULL)
    {
        return pList;
    }
	/*获取中间结点*/
    Node *pMiddle = getMiddleNode(pList); 
	/*链表前半部分，包括中间结点*/
    Node *pBegin = pList; 
	/*链表后半部分*/
    Node *pEnd = pMiddle->next;
	/*必须赋值为空 相当于断开操作。pBegin--pMiddle pEnd---最后 */
    pMiddle->next = NULL; 
	/*排序前半部分数据，只有一个元素的时候停止，即有序*/
    pBegin = MergeSort(pBegin); 
	/*排序后半部分数据 递归理解可以参考PrintListRecursion;*/
    pEnd = MergeSort(pEnd); 
	/*合并有序链表*/
    return MergeList(pBegin, pEnd); 
}

/*获取链表中间元素*/
Node *getMiddleNode(Node *pList)
{
    if (pList == NULL)
    {
        return NULL;
    }
    Node *pfast = pList->next;
    Node *pslow = pList;
    while (pfast != NULL)
    {
         pfast = pfast->next;
         if (pfast != NULL)
         {
             pfast = pfast->next;
             pslow = pslow->next;
         }
 
    }
 
    return pslow;
}
/*合并有序链表，合并之后升序排列*/
Node *MergeList(Node *p1, Node *p2) 
{
    if (NULL == p1)
    {
        return p2;
    }
    if (NULL == p2)
    {
        return p1;
    }
 
    Node *pLinkA = p1;
    Node *pLinkB = p2;
    Node *pTemp = NULL;
	/*较小的为头结点，pTemp存下头结点*/
    if (pLinkA->data <= pLinkB->data)
    {
        pTemp = pLinkA;
        pLinkA = pLinkA->next;
    }
    else
    {
        pTemp = pLinkB;
        pLinkB = pLinkB->next;
    }
	/*初始化头结点，即头结点指向不为空的结点*/
    Node *pHead = pTemp; 
    while (pLinkA && pLinkB)
    {
        /*合并先放小的元素*/
		if (pLinkA->data <= pLinkB->data)
        {
            pTemp->next = pLinkA;
			/*保存下上一次节点。如果下一次为NULL，保存的上一次的节点就是链表最后一个元素*/
            pTemp = pLinkA;
            pLinkA = pLinkA->next;
        }
        else
        {
            pTemp->next = pLinkB;
            pTemp = pLinkB;
            pLinkB = pLinkB->next;
        }
 
    }
	/*跳出循环时，有一个为空。把不为空的剩下的部分插入链表中*/
    pTemp->next = pLinkA ? pLinkA:pLinkB; 
	head = pHead;
    return pHead;
	
}

// 测试函数

void InitializeList()//initialization初始化链表
{
    int i;
    printf("输入链表元素个数:");
    scanf("%d",&i);  
    /*设置获得随机数的种子（固定代码，没有这句，随机数是固定不变的）测试可以不加*/
	srand((int)time(0)); 

    for (;i>0;i--){
        CreatList(rand()%MAX);
    }
	
	// CreatList(i);
	printf("新创建的的链表为:");
	PrintList(head);  
	wait(); 

}

//公用的等待函数
void wait()
{
	printf( "\n\n请按任意键继续");
	getch();
}


int main ()
{
    char choice;
	int i,e;
	// DLList=&Head;     //使头指针指向头结点
	// Head.next=NULL; 

	while (1)
	{
		system("cls");
		printf( "\n\n\n\n");
		printf( "\t\t              单链表操作  \n");
		printf( "\t\t======================================");
		printf( "\n\n");
		printf( "\t\t             1：添加链表元素个数(初始化) \n");
		printf( "\t\t             2：显示        			\n");
		printf( "\t\t             3：在元素i前插入元素e   	 \n");
		printf( "\t\t             4：在元素i后插入元素e      \n");
		printf( "\t\t             5：删除        			\n");
		printf( "\t\t             6：查找    				\n");
		printf( "\t\t             7：修改元素i为元素e        \n");
		printf( "\t\t             8：将链接存储线性表逆置    \n");
		printf( "\t\t             9：链表长度      			\n");
		printf( "\t\t             a：1.冒泡排序        		\n");
		printf( "\t\t             b：2.快速排序   	 		\n");
		printf( "\t\t             c：3.插入排序      		\n");
		printf( "\t\t             d：4.选择排序      		\n");
		printf( "\t\t             e：5.归并排序      		\n");

		printf( "\t\t             0：退出        \n");
		printf( "\n");
		printf( "\t\t请选择：");

		choice = getch();
		system("cls");
		
		switch(choice)
		{
			case '1':
				InitializeList();
				break;
			case '2':
				PrintList(head);
				wait();
				printf("\n");
				break;
			case '3':
				PrintList(head);
				printf("在元素i前插入元素e\n");
				scanf("%d %d",&i,&e);
				InsertListHead(i,e);
				printf("在%d前插入%d后的链表为:\n",i,e);
				PrintList(head);
				wait();
				printf("\n");
				break;
			case '4':
				PrintList(head);
				printf("在元素i后插入元素e\n");
				scanf("%d %d",&i,&e);
				InsertListEnd(i,e);
				printf("在%d后插入%d后的链表为:\n",i,e);
				PrintList(head);
				wait();
				printf("\n");
				break;
			case '5':
				PrintList(head);
				printf("输入要删除的元素e:");
				scanf("%d",&e);
				DeleteList(e);
				printf("删除%d后的链表为:\n",e);
				PrintList(head);
				wait();
				printf("\n");
				break;
			case '6':
				PrintList(head);
				printf("输入要找的元素e:");
				scanf("%d",&e);
				Node *p = FindList(e);
				// Node *q = FindList(e);
				break;
			case '7':
				PrintList(head);
				printf("修改元素i为元素e\n");
				scanf("%d %d",&i,&e);
				ModifyList(head,i,e);
				printf("修改%d为%d后的链表为:",i,e);
				PrintList(head);
				wait();
				printf("\n");
				break;
			case '8':
				PrintList(head);
				printf("将链接存储线性表逆置");
				ReverseList(head);
				printf("反转后的链表为:");
				PrintList(head);
				wait();
				printf("\n");
				break;
			case '9':
				PrintList(head);
				printf("链表长度为:%d",LengthList(head));
				wait();
				printf("\n");
				break;
			case 'a':
				PrintList(head);
				printf("1.冒泡排序:");
				BubbleSort(head);
				PrintList(head);
				wait();
				printf("\n");
				break;
			case 'b':
				PrintList(head);
				printf("2.快速排序:");
				QuickSort(head,end);
				PrintList(head);
				wait();
				printf("\n");
				break;
			case 'c':
				PrintList(head);
				printf("3.插入排序:");
				InsertSort(head);
				PrintList(head);
				wait();
				printf("\n");
				break;
			case 'd':
				PrintList(head);
				printf("4.选择排序:\n");
				SelectSort(head);
				printf("排序完成:\n");
				PrintList(head);
				wait();
				printf("\n");
				break;
			case 'e':
				PrintList(head);
				printf("5.归并排序:");
				MergeSort(head);
				PrintList(head);
				wait();
				printf("\n");
				break;
			// case '2':
			// 	PrintList(head);
			// 	break;

			case '0':
				exit(0);
		}
	}


    // InitializeList();//initialization初始化链表

	// printf("\n");


	// printf("5.归并排序:");
	// MergeSort(head);
	// PrintList(head);
	// wait();

	// printf("\n");


	// printf("4.选择排序:");
	// SelectSort(head);
	// PrintList(head);
	// wait();

	// printf("\n");


	// printf("3.插入排序:");
	// InsertSort(head);
	// PrintList(head);
	// wait();

	// printf("\n");
	


	// printf("2.快速排序:");
	// QuickSort(head,end);
	// PrintList(head);
	// wait();

	// printf("\n");


	// printf("1.冒泡排序:");
	// BubbleSort(head);
	// PrintList(head);
	// wait();

	// printf("\n");
	

	// int i,e;
	// printf("在元素i前插入元素e\n");
	// scanf("%d %d",&i,&e);
	// InsertListHead(i,e);
	// printf("在%d前插入%d后的链表为:\n",i,e);
	// PrintList(head);
	// wait();

	// printf("\n");


	// printf("在元素i后插入元素e\n");
	// scanf("%d %d",&i,&e);
	// InsertListEnd(i,e);
	// printf("在%d后插入%d后的链表为:\n",i,e);
	// PrintList(head);
	// wait();

	// printf("\n");


	// printf("输入要删除的元素e:");
	// scanf("%d",&e);
	// DeleteList(e);
	// printf("删除%d后的链表为:\n",e);
	// PrintList(head);
	// wait();

	// printf("\n");
	

	// printf("输入要找的元素e:");
	// scanf("%d",&e);
	// Node *p = FindList(e);
	// Node *q = FindList(e);


	// printf("修改元素i为元素e\n");
	// scanf("%d %d",&i,&e);
	// ModifyList(head,i,e);
	// printf("修改%d为%d后的链表为:",i,e);
	// PrintList(head);
	// wait();

	// printf("\n");


	// printf("将链接存储线性表逆置");
	// ReverseList(head);
	// printf("反转后的链表为:");
	// PrintList(head);
	// wait();

	// printf("\n");


	// printf("链表长度为:%d",LengthList(head));
	// wait();

	// printf("\n");

    return 0;

}
