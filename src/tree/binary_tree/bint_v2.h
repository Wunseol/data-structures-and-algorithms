// void init0(int list[]);

// void getWidth(BiTNode *Tree, int depth, int shift, char map[max*2][max*2]);

// void showBinTree(BiTNode *Tree);

// void release(BiTNode *Tree);

// BiTNode *Generate(int n);

// BiTNode *init1();


//屏幕提示后，从键盘输入个数和随机数种子，在数组elem中生成指定个数的数据，供其他程序使用，0表示数据结束
void init0(int list[])
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

	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 999 +1;
	}
	list[n] = 0;
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

//供init1O调用的释放函数
void release(BiTNode *Tree)
{
	if (Tree==NULL)
		return;
	release(Tree->left);
	release(Tree->right);
	free(Tree);
}

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
