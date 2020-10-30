#include <stdio.h>
#define maxSize 100

//带权图的结构类型
typedef struct//先定义顶点类型
{
	int no;//顶点编号
	char info;//顶点其他信息（可以不写）
}VertexType;
typedef struct//再定义图
{
	float edges[maxSize][maxSize];//定义一个邻接矩阵，有权图必须是float类型
	int n, e;//顶点数和边数
	VertexType vex[maxSize];//存放结点信息
}MGraph;


void Floyd(MGraph* g, int path[][maxSize], int A[][maxSize])
/*
	A数组：用来记录当前已经求得的任意两个顶点最短路径的长度
	Path数组：用来记录当前两顶点间最短路径上要经过的中间顶点
*/
{
	int i, j, k;
	for (i = 0; i < g->n; ++i)
	{
		for (j = 0; j < g->n; ++j)
		{
			A[i][j] = g->edges[i][j];
			path[i][j] = -1;
		}
	}

///////////////弗洛伊德核心////////////////////
/*
	第一次以0为中间点，检测所有顶点对：{0,1} {0,2} {0,3}
	{1,0} {1,2} {1,3} {2,0} {2,1} {2,3} {3,0} {3,1} {3,2}
	如果此时检测的顶点对为{i,j}，如果A[i][j]>A[i][0]+A[0][j]，意思
	是开始时A[i][j]存放的就是i到j的最短路径，但是让i到j通过中间点0，如果通过后
	i-0-j的长度小于原先的i-j，那么暂时来说，i-j的最短路径就不是直接i到j了，而是
	i-0-j。并且将Path[i][j]改为0，表示i到j，首先要i到0.

*/
	for (k = 0; k < g->n; ++k)//开始以k为中间点
	{
		for (i = 0; i < g->n; ++i)//以k为中间点，监测i到j距离是否大于i到k和k到j的距离
		{
			for (j = 0; j < g->n; ++j)
			{
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];//若大于说明这是最短路径
					path[i][j] = k;//同时由i找j时，应该先去找k
				}
			}
		}
	}
}
/*
	总结：floyd算法核心从本质上来讲，就是如果A-B是最短路径，B-C是最短路径，
	那么自然A-C是最短路径。所以上述三个for循环就是让所有顶点作为中间点，让其更新为
	最短路径
	举个例子：207页找出了1-3-2-0这样的最短最短路径，弗洛伊德算法在做的时候，让3作为
	中间找出了1到3的最短路径是1-3-2，又让2作为中间点找出了3到0的最短路径是3-2-0，那么最后
	1-0的最短路径就是1-3-2-0了。
*/


//依据弗洛伊德算法生成的数组，找任意两个顶点之间的最短路径
void printPath(int u, int v, int path[][maxSize])
{
	if (path[u][v] == -1)
		printf("输出即可");
	else
	{
		int mid = path[u][v];
		printPath(u, mid, path);
		printPath(mid, v, path);
	}
}