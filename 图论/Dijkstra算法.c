#include <stdio.h>
#define maxSize 100
#define INF 10000000
/*
	迪杰斯特拉算法需要用到三个数组
*
//带权图
typedef struct
{
	int no;
	char info;
}VertexType;
typedef struct
{
	float edges[maxSize][maxSize];
	int n, e;
	VertexType vex[maxSize];
}MGraph;

void Dijkstra(MGraph g, int v, int dist[], int path[])
/*
	dist[]数组存储了当前起点到其余顶点最短路径的长度
	path[]数组存储了起点到其余顶点的最短路径（通过查询该数组，可获得路径信息）
	set[]数组中标记为1表示被选入最短路径
*/
{
	int set[maxSize];//初始化set数组
	int min, i, h, u;
	for (i = 0; i < g.n; ++i)
	{
		dist[i] = g.edges[v][i];//初始化dist数组，根据edges数组的信息，录入根结点到其余结点距离信息
		set[i] = 0;//开始时所有结点均为被并入，故设为0
		if (g.edges[v][i] < INF)
		/*
		  举例 如果path[0][3]不是无穷大(置于无穷大会大于这个很大的数)
		   那么path[3]=0，表示3这个节点之前是0，0-3是一个最短路径
		*/
			path[i] = v;
		else
			path[i] = -1;//如果path[3]=-1，表示之前没有元素
	}
	set[v] = 1;//根节点被并入
	path[v] = -1;//根节点前没有结点
///////////////迪杰斯特拉算法核心//////////////
	for (i = 0; i < g.n-1; ++i)
	{
		min = INF;
		for (int j = 0; j < g.n; ++j)
		/*
			此for循环每次从剩余结点中选出一个一个结点，通过往这个
			顶点的路径在通往所有剩余顶点的路径中是最短的
		*/
		{
			if (set[j] == 0 & dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		set[u] = 1;
		for (int j = 0; j < g.n; ++j)
		/*
			此for循环以刚并入的结点作为中间点，对所有通往剩余顶点的路径进行监测
		*/
		{
			if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j])
			{
				/*
				如果顶点u的加入会出现通往顶点j的更短的路径，那么就更新信息
				*/
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}
	}
}
/*
	总结：总的来说迪杰斯特拉算法和普利姆算法其实还是挺相似的。普利姆算法第一个小for循环时在找权值最小的边并并入其中，地杰斯特拉算法第一个小for循环
	也是在剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有顶点的路径中长度是最短的。普利姆算法第二个for循环是在更新lowcost数组，如果剩余的结点距离
	树的距离小于之前状况就更新，而地杰斯特拉算法第二个for循环用于判断刚并入路径中的顶点u的加入是否会出现通往顶点u更短的路径（他在判断时，是以新加入的那个结点
	为起点从未被并入的结点中逐个比较。比如上一状态的最短路径为0-1-4，其权值为11，然后新加入的结点是5，此时发现0-1-2-5这样的路径权值为10那么将其更新为10）

	也就是说地杰斯特拉算法的核心如果新加入的这个节点其产生的路径到某一点要比原先路径到某一点的距离要小，那么其
	dist数组就更新为它
	*/