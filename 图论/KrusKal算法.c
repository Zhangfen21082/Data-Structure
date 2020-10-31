#include <stdio.h>
#define maxSize 100

typedef struct//这里定义的结构体保存的是边的信息
{
	int a, b;//这条边连接的两个顶点
	int w;//这条边的权值信息
}Road;//Kruskal算法经常用来求城市最短铺设距离这样的问题，所以这个名字这样写

//Road road[maxSize];//把所有的边全部放入road数组中
void sort(Road arr[],int n)//克鲁斯卡尔算法逐步选取从小到大的权值的边，所以在算法开始前对所有边根据权值排序，这里使用直接插入排序
{
	Road temp;
	int i, j;
	for (i = 1; i < n; i++)
	{ 
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && temp.w < arr[j].w)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
}

int v[maxSize];//定义并查集数组
int getRoot(int p)
{
	while (p != v[p])//只有根节点才会用V[0]=0,V[1]=1这样，如果不是这样，那么就继续向上走，直到走到根节点
		p = v[p];
	return p;
}


//////////////////////Kruskal算法////////////////
void Kruskal(Road road[], int n, int e, int* sum)//road数组存储的是各个相邻顶点边的信息，n和e分别是顶点数和边数
{
	int a, b;//a和b保存一条边所在的两个顶点
	sum = 0;

	for (int i = 0; i < n; ++i)//对并查集数组赋值，开始任何一个节点都可以看做是一个树，也就是自己就是根节点，所以v[0]=0,v[1]=1,v[2]=2.......
		v[i] = i;
	
	sort(road, e);//调用排序函数，所有边按照权值大小从小到大排序

	for (int i = 0; i < e; ++i)
	{
		a = getRoot(road[i].a);//a和b取这条边的两个顶点，传给并查集，查找他们的根节点
		b = getRoot(road[i].b);
		if (a != b);//如果a!=b那就表示他们的根节点不一样，这样就能归并到树内，不然如果根节点一样，并入后就成了环了
		{
			v[a] = b;//如果不相等，那么把a挂在b下，也就是在并查集中，a的父节点是b
			sum = sum + road[i].w;//既然并入了，权值就相应增加即可
		}
	}
}