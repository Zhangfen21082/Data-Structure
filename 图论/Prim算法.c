#include <stdio.h>
#define maxsize 100
#define INF 10000 //一个很大的数

//需要使用带权图节点类型
typedef struct//顶点类型
{
	int no;//顶点编号
	char info;//顶点其他信息
}VertexType;
typedef struct
{
	float edges[maxsize][maxsize];//使用邻接矩阵来存储图
	int n, e;//顶点数和边数
	VertexType vex[maxsize];//以数组方式存放所有结点
}MGraph;
//////////////////Prim算法////////////////////////
//1:算法流程
/*  
	从树中某一个顶点v0开始，构造生成树：
	1：将v0到其他顶点的边作为候选边；
	2：重复以下步骤n-1次，使得其他n-1个顶点并入生成树中
	  a:从候选边中挑选出权值最小边输出，并将与该边另一端相接的顶点v并入生成树中
	  b:考察所有剩余顶点vi，如果(v,vi)权值要比lowcost[vi]小，则用(v,vi)的权值更新lowcost[vi]。
*/
void Prim(MGraph g, int v0, float* sum)//v0是起始节点，sum是权值之和
{
	int lowCost[g.n];////lowCost[]存放当前生成树到剩余各顶点最短边的权值，比如lowCost[0]的值就表示当前的生成树到顶点0权值最小的那条边的权值
	int vSet[g.m];//vSet[]表示当数组某一位置上的值被设置为1的时候，就代表其所指顶点已经被并入生成树中了，如vSet[0]=1，就代表0已经被并入生成树中了
	int v;//指向刚并入的结点
	int k;
	int min;
	for (int i = 0; i < g.n; ++i)//初始化操作
	{
		lowCost[i] = g.edges[v0][i];//lowCost进行初始化，表示了其余各顶点到v0的权值信息
		vSet[i] = 0;//最开始时所有结点都没有并入，自然设为0
	}
	v = v0;//使用v始终指向刚并入的结点，先并入根节点
	vSet[v] = 1;
	sum = 0;

	/*
	这个for循环用于将已经更新好的lowcost数组中最小的权值找出来，也就是那个
	到这个树最小的距离的点
	*/
	for (int i = 0; i < g.n - 1; ++i)//开始已经把根节点处理了，所以这里是n-1
	{
		min = INF;//我们要选出最小的边，开始把它设置为很大的数
		for (int j = 0; j < g.n; ++j)
		{
			if (vSet[j] == 0 && lowCost[j] < min)
			{
				min = lowCost[j];
				k = j;//找出最小的后用k指向他 
			}

		}
		vSet[k] = 1;//把它标记为已访问
		v = k;
		sum += min;
		/*
		下面这个for循环用于更新lowcost数组，第一次，lowcost再没有更新的时候，存储的是v0结点到其他结点权值信息，
		看起来好像是点与点之间的距离，但是实际本质上是树去其他结点之间距离，只不过只有一个结点
		当某一个结点并入之后，树会长大，此时我们应该要以这个刚并入的结点v为依据与之前的lowcost数组去比较，更新
		这棵树去其他节点之间的权值信息
		*/
		for (int j = 0; j < g.n; ++j)
		{
			if (vSet[j] == 0 && g.edges[v][j] < lowCost[j]])//如果这个节点还没有并入并且刚并入的这个节点到其他结点之间的距离小于原来的lowCost数组
				lowCost[j] = g.edges[v][j];//那么更新lowCost
		}
		
	}
}

//****总结下来就是第一次的时候lostcowst数组初始化，储存的就是0到1,2,3这几个结点之间的距离，分别为1,2,3,然后0到4的距离为无穷大，也就是说
	//此时4距离这个的树距离无穷大。然后进入总的for循环，每两次for循环结束后，min总会被设置为最大值，用于寻找当前的最小边。这里进入第一个for循环
	//可以发现0到1的距离是最小的，所以把0到1结点之间的权值给min，然后标记1这个节点为1，然后用v指向k，那么此时这个树由于1的加入就增加了规模，那么
	//此时4与这个树的距离也就是此时lowcost[4]不应该是无穷大了，而应该是4了，那么就以1这个结点为媒介，遍历所有的结点，看其余结点与新生成的这个
	//这个节点之间的距离（或者说与这个树的距离）是否小于原先的距离(也就是现在的lowcost[4]=4小于之前的无穷大)一旦小于，那么就把这个数值赋值给他
	//（也就是lowcost[4]=4）,那么这样lowcost数组更新完毕，它所储存的就是当前未被并入树中的结点与树的权值关系。两个小循环结束，跑到大循环，然后
