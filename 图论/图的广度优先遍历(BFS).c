#include <stdio.h>
#define Maxsize 100

typedef struct ArcNode
{
	int adjv;
	struct ArcNode* next;
}ArcNode;

typedef struct
{
	int data;
	ArcNode* first;
}VNode;


typedef struct
{
	VNode adjlist[Maxsize];
	int n, e;
}AGraph;

void BFS(AGraph* G, int v, int visit[Maxsize])//首先传入v=0也就是从第一个元素开始，visit是一个辅助的标记数组
{
	ArcNode* p;
	int que[Maxsize], front = 0, rear = 0;//和树一样广度优先需要用到队列
	int j;
	Visit(v);
	visit[v] = 1;//刚进入函数时，先把根节点访问，入队
	rear = (rear + 1) % Maxsize;
	que[rear] = v;
	while (front != rear)//当队不空时，执行出队操作
	{
		front = (front + 1) % Maxsize;//需要注意的是，这个队列只是存储的图的元素的序号，每当第二个while循环结束时，表示这个节点的所有节点被搜寻完毕了，然后出下一个结点的循环进行下一个while
		j = que[front];
		p = G->adjlist[j].first;//p指向了此次出队的j的边，并从这个节点的first边开始，进入下面的while循环去遍历，所有的结点
		while (p != NULL)
		{
			if (visit[p->adjv] == 0)//如果这条边指向的元素没有被访问过，那就进入访问
			{
				Visit(p->adjv);
				visit[p->adjv] = 1;
				rear = (rear + 1) % Maxsize;
				que[rear] = p->adjv;
			}
			p = p->next;
		}
	}


}