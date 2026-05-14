#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[50];
int arr_len = 0;

void menu()
{
	printf("\n\n");
	printf("功能菜单：\n");
	printf(" a.建立顺序表\n b.查找元素\n c.插入元素\n d.删除元素\n e.合并两个非递减顺序表\n f.求两个非递减顺序表的交集\n g.求两个非递减顺序表的并集\n h.逆置线性表\n z.退出\n");
	printf("\n");
}

void SetUp()
{
	printf("建立顺序表：\n");
	int num;
	printf("请输入顺序表表长：");
	scanf("%d",&num);
	if(num>50) num=50;
	printf("请输入顺序表中各元素:\n");
	int i;
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("建立的顺序表为：\n");
	for(i=0;i<num;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	arr[num]=-1;
	arr_len=num;
}

void Check()
{
	int x,count=0;
	printf("请输入要查找的元素：");
	scanf("%d",&x);
	int *p=arr;

	while(*p!=-1&&*p!=x)
	{
		p++;
		count++;
	}
	if(*p==-1)
	{
		printf("该顺序表中没有想要的元素\n");
	}
	else
	{
		printf("位序为%d\n",count);
		printf("比较次数为%d\n",count+1);
	}
}

void Insert()
{
	int i,num,c,count=0;
	for(i=0;arr[i]!=-1;i++)
	{
		count++;
	}
	if(count>=50)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	printf("请输入将元素插入的位序(0-%d):",count);
	scanf("%d",&num);
	printf("请输入插入的元素值：");
	scanf("%d",&c);
	if(num<0||num>count)
	{
		printf("位序错误\n");
		return;
	}
	for(i=count-1;i>=num;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[num]=c;
	arr[count+1]=-1;
	arr_len=count+1;
	printf("插入元素后的顺序表：\n");
	for(i=0;i<=count;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Delete()
{
	int i,count=0,num;
	for(i=0;arr[i]!=-1;i++)
	{
		count++;
	}
	printf("请输入要删除元素的位序(0-%d):",count-1);
	scanf("%d",&num);
	if(num<0||num>=count)
	{
		printf("位序错误\n");
		return;
	}
	for(i=num;i<count-1;i++)
	{
		arr[i]=arr[i+1];
	}
	arr[count-1]=-1;
	arr_len=count-1;
	printf("删除之后的顺序表：");
	for(i=0;i<count-1;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Merge()
{
	int i,count1=0,count2=0,start;
	printf("建立第一个顺序表：\n");
	SetUp();
	int arr1[50];
	for(i=0;arr[i]!=-1;i++)
	{
		arr1[i]=arr[i];
		count1++;
	}
	arr1[count1]=-1;
	start=count1;

	printf("建立第二个顺序表：\n");
	SetUp();
	int arr2[50];
	for(i=0;arr[i]!=-1;i++)
	{
		arr2[i]=arr[i];
		count2++;
	}
	arr2[count2]=-1;

	for(i=start;arr2[i-start]!=-1;i++)
	{
		arr1[i]=arr2[i-start];
	}
	arr1[i]=-1;
	printf("合并后的顺序表：\n");
	for(i=0;arr1[i]!=-1;i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\n");
}

void Intersection()
{
	int i,count1=0,count2=0;
	printf("建立第一个顺序表：\n");
	SetUp();
	int arr1[50];
	for(i=0;arr[i]!=-1;i++)
	{
		arr1[i]=arr[i];
		count1++;
	}
	arr1[count1]=-1;

	printf("建立第二个顺序表：\n");
	SetUp();
	int arr2[50];
	for(i=0;arr[i]!=-1;i++)
	{
		arr2[i]=arr[i];
		count2++;
	}
	arr2[count2]=-1;

	int j=0,k=0;
	int arr3[100];
	for(i=0;i<count1;i++)
	{
		for(j=0;j<count2;j++)
		{
			if(arr1[i]==arr2[j])
			{
				arr3[k]=arr1[i];
				k++;
			}
		}
	}
	if(k==0)
	{
		printf("无交集\n");
	}
	else
	{
		printf("两个顺序表的交集：\n");
		for(i=0;i<k;i++)
		{
			printf("%d ",arr3[i]);
		}
		printf("\n");
	}
}

void Sum()
{
	int i,j,k,count1=0,count2=0;
	printf("建立第一个顺序表：\n");
	SetUp();
	int arr1[50];
	for(i=0;arr[i]!=-1;i++)
	{
		arr1[i]=arr[i];
		count1++;
	}
	arr1[count1]=-1;

	printf("建立第二个顺序表：\n");
	SetUp();
	int arr2[50];
	for(i=0;arr[i]!=-1;i++)
	{
		arr2[i]=arr[i];
		count2++;
	}
	arr2[count2]=-1;

	int arr3[100];
	i=0;j=0;k=0;
	while((i<count1)&&(j<count2))
	{
		if(arr1[i]<arr2[j])
		{
			arr3[k]=arr1[i];
			k++;i++;
		}
		else if(arr1[i]>arr2[j])
		{
			arr3[k]=arr2[j];
			k++;j++;
		}
		else
		{
			arr3[k]=arr1[i];
			k++;i++;j++;
		}
	}
	while(i<count1)
	{
		arr3[k]=arr1[i];
		k++;i++;
	}
	while(j<count2)
	{
		arr3[k]=arr2[j];
		k++;j++;
	}
	arr3[k]=-1;

	printf("两个顺序表的并集：\n");
	for(i=0;i<k;i++)
	{
		printf("%d ",arr3[i]);
	}
	printf("\n");
}

void Reverse()
{
	int i,count=0;
	for(i=0;arr[i]!=-1;i++)
	{
		count++;
	}
	int temp,left,right;
	for(left=0,right=count-1;left<right;left++,right--)
	{
		temp=arr[left];
		arr[left]=arr[right];
		arr[right]=temp;
	}
	printf("逆置后的顺序表为：\n");
	for(i=0;i<count;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void test()
{
	int count=0;
	char ch;
	do{
		menu();
		printf("请选择您的需求：");
		if(count==1)
		{
			getchar();
		}
		else
		{
			count++;
		}
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case 'a':
				SetUp();
				break;
			case 'b':
				Check();
				break;
			case 'c':
				Insert();
				break;
			case 'd':
				Delete();
				break;
			case 'e':
				Merge();
				break;
			case 'f':
				Intersection();
				break;
			case 'g':
				Sum();
				break;
			case 'h':
				Reverse();
				break;
			case 'z':
				break;
			default:
				printf("输入错误，请重新输入!");
				break;
		}
	}while(ch!='z');
}

int main()
{
	test();
	return 0;
}
