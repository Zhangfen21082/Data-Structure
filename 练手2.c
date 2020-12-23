#include <stdio.h>
#define maxsize 100
#include <stdlib.h>
#define INF 1000
/
//typedef struct ArcNode
//{
//	int adjv;
//	struct ArcNode* next;
//}ArcNode;
//
//typedef struct VNode
//{
//	int data
//	ArcNode* first;规划生成树
//
//}VNode;
//
//typedef struct AGraph
//{
//	VNode adjlist[maxsize];
//	int n, e;
//}AGraph;
//
//void convert(int A[][maxsize], int n,AGraph* g)
//{
//	int i, j = 0;
//	int sum;
//	ArcNode* p;
//	for (i = 0; i < n; i++)
//	{
//		for (j = n - 1; j >= 0; j--)
//		{
//			if (A[i][j] != 0)
//			{
//				sum++;
//				p = (ArcNode*)malloc(sizeof(ArcNode));
//				p->adjv = j;
//				p->next = g->adjlist[i].first;
//				g->adjlist[i].first = p;
//			}
//		}
//	}
//	g->n = n;
//	g->e = sum;
//}


//2:编写一个算法，判断无向图G是否连通。若连通，则返回1，否则返回0.设图中顶点标号从0到g.vexnum-1。
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
	VNode adjlist[maxsize];
	int vexnum, edgenum;
}AGraph;

//void BFS(AGraph* G, int v, int visit[maxsize])
//{
//	ArcNode* p;
//	int queue[maxsize], rear = 0, front = 0;
//	int j;
//	visit[v] = 1;
//	rear = (rear + 1) % maxsize;
//	queue[rear] = v;
//	while (rear != front)
//	{
//		front = (front + 1) % maxsize;
//		j = queue[front];
//		p = G->adjlist[j].first;
//		while (p!=NULL)
//		{
//			if (visit[p->adjv] == 0)
//			{
//				visit[p->adjv] = 1;
//				rear = (rear + 1) % maxsize;
//				queue[rear] = p->adjv;
//			}
//			p = p->next;
//		}
//	}
//
//
//}
//int connect(AGraph g)
//{
//	int i, flag = 1;
//	int visited[maxsize];
//	for (i = 0; i < g.vexnum; i++)
//		visited[i] = 0;
//	BFS(&g, 0, visited);
//	
//	for (i = 0; i < g.vexnum; i++)
//	{
//		if (visited[i] == 0)
//		{
//			flag = 0;
//			break;
//		}
//	}
//	return flag;
//
//
//}

//4：编写一个实现连通图G的深度优先遍历（从顶点v开始）的非递归函数

void DSFNoderecursion(AGraph*g, int v)
{
	int i;
	ArcNode* p;
	int visited[maxsize];
	int stack[maxsize], top = -1;
	for (i = 0; i < g->vexnum; i++)
	{
		visited[i] = 0;
	}
	//visit(i);
	stack[++top] = v;
	visited[v] = 1;
	while (top >= 0)
	{
		v = stack[top--];
		p = g->adjlist[v].first;
		while (p != NULL && visited[p->adjv] == 1)
			p = p->next;
		if (p != NULL)
			--top;
		else
		{
			v = p->adjv;
			//visit(v);
			stack[++top] = v;
			visited[v] = 1;
		}
	}

}

//5：找出以t为根的二叉树中各结点中的最大元素的值，
typedef struct BTNode
{
	float data;
	struct BTNode* lchirld;
	struct BTNode* rchirld;
}BTNode;
float findMax(BTNode* t)
{
	float max = t->data;
	BTNode* queue[maxsize];
	int front, rear;
	BTNode* p;
	rear = (rear + 1) % maxsize;
	queue[rear] = t;
	while (front != rear)
	{
		front = (front + 1) % maxsize;
		p = queue[front];
		if (p->data > max)
		{
			max = p->data;
		}
		if (p->lchirld != NULL)
		{
			rear = (rear + 1) % maxsize;
			queue[rear] = p->lchirld;
		}
		if (p->rchirld != NULL)
		{
			rear = (rear + 1) % maxsize;
			queue[rear] = p->rchirld;
		}
	}
	return max;
}


typedef struct
{
	int data[maxsize];
	int top;
}Sqstack;
typedef struct
{
	int data;
	struct Lstack* next;
}Lstack;

typedef struct
{
	int data[maxsize];
	int front;
	int rear;
}SqQueue;

typedef struct
{
	int data;
	struct QNode* next;
}QNode;

typedef struct
{
	QNode* front;
	QNode* rear;
}LiQNode;

void pushstack(Sqstack* st,int x)
{
	if (st->top == maxsize - 1)
	{
		return 0;
	}
	st->data[++st->top]=x;

}
void outstack(Sqstack* st, int* x)
{
	if (st->top == -1)
	{
		return 0;
	}
	*x = st->data[st->top--];

}
void initStack(Lstack* head)
{
	head = (Lstack*)malloc(sizeof(Lstack));
	head->next = NULL;
}
void pushListack(Lstack* head, int x)
{
	Lstack* p = (Lstack*)malloc(sizeof(Lstack));
	p->next = NULL;

	p->data = x;
	p->next = head->next;
	head->next = p;
}
void outListack(Lstack* head, int* x)
{
	if (head->next == NULL)
	{
		return 0;
	}
	Lstack* p;
	p = head->next;
	*x = p->data;
	head->next = p->next;
	free(p);
	return 1;

}

int enQueue(SqQueue* qu, int x)
{
	if ((qu->rear + 1) % maxsize == (qu->front))
	{
		return 0;
	}
	qu->rear = (qu->rear + 1) % maxsize;
	qu->data[qu->rear] = x;
	return 1;
}
int outenQueue(SqQueue* qu, int* x)
{
	if (qu->rear == qu->front)
	{
		return 0;
	}
	qu->front = (qu->front + 1) % maxsize;
	*x = qu->data[qu->front];
	return 1;

}

typedef struct
{
	int data;
	struct Qnode* next;
}Qnode;

typedef struct
{
	Qnode* front;
	Qnode* rear;
}LiQnode;
void initQueue(LiQNode* head)
{
	head = (LiQNode*)malloc(sizeof(LiQNode));
	head->rear = head->front = NULL;
}
int enQueue(LiQNode* head, int x)
{
	QNode* p = (Qnode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;

	if (head->rear == NULL)
	{
		head->rear = head->front = p;
	}
	else
	{
		head->rear->next = p;
		head->rear = p;
	}

}
int outQueue(LiQNode* head, int* x)
{
	QNode* p;
	if (head->rear == NULL)
	{
		return 0;
	}
	else
	{
		p = head->front;
	}
	if (head->front == head->rear)
	{
		head->front = head->rear = NULL;
	}
	else
	{
		head->front = head->front->next;
		*x = p->data;
		free(p);
		return 1;
	}


}

typedef struct
{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

void preOrderNoneRecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* stack[maxsize];
		int top = -1;
		BTNode* p;
		stack[++top] = bt;

		while (top != -1)
		{
			p = stack[top--];
			//visit(p);

			if (p->rchild != NULL)
				stack[++top] = p->rchild;
			if (p->lchild != NULL)
				stack[++top] = p->rchild;
		}

	}


}

void postorderNodeRecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* stack1[maxsize];
		int top1 = -1;
		BTNode* stack2[maxsize];
		int top2 = -1;
		BTNode* p;

		stack1[++top1] = bt;
		while (top1!=-1)
		{
			p = stack1[top1--];
			stack2[++top2] = p;
			if (p->lchild != NULL)
				stack1[++top1] = p->lchild;
			if (p->rchild != NULL)
				stack1[++top1] = p->rchild;
		}

		while (top2 != NULL)
		{
			p = stack2[top2--];
			//visit(p);
		}
	}

}

void inorderNodeRecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* stack[maxsize];
		int top = -1;
		BTNode* p = NULL;

		while (p != NULL || top != -1)
		{
			while (p != NULL)
			{
				stack[++top] = p;
				p = p->lchild;
			}
			if (top != -1)
			{
				p = stack[top--];
				//visit(p);
				p = p->rchild;
			}
		}
	}

}

void level(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* queue[maxsize];
		int front, rear;
		front = rear = 0;
		BTNode* p;

		rear = (rear + 1) % maxsize;
		queue[rear] = bt;

		while (rear != front)
		{
			front = (front + 1) % maxsize;
			p = queue[front];

			if (p->lchild != NULL)
			{
				rear = (rear + 1) % maxsize;
				queue[rear] = p->lchild;
			}
			if (p->rchild != NULL)
			{
				rear = (rear + 1) % maxsize;
				queue[rear]=p->rchild;
			}
		}
	}

}
typedef struct ArcNode
{
	int adjvl;
	struct ArcNode* next;
}ArcNode;
typedef struct VNode
{
	int data;
	ArcNode* first;
}VNode;
typedef struct
{
	VNode adjlistp[maxsize];
	int n,e
}AGraph;

int Visit[];
void Dfs(int v, AGraph* G)
{
	Visit[v] = 1;
	//visit(v);
	ArcNode* q = G->adjlistp[v].first;
	if (q != NULL)
	{
		if (Visit[q->adjvl] = 0)
		{
			Dfs(q->adjvl, G);
		}
		q = q->next;
	}

}

void Bfs(AGraph* g, int v, int Visit[maxsize])
{
	int queue[maxsize], rear = 0, front = 0;
	ArcNode* p;
	Visit[v] = 1;
	//visit();
	rear = (rear + 1) % maxsize;
	queue[rear] = v;
	int j;
	while (rear != front)
	{
		front = (front + 1) % maxsize;
		j = queue[front];
		p = g->adjlistp[j].first;
		while (p != NULL)
		{
			Visit[p->adjvl];
			//visit(p->adj1);
			rear = (rear + 1) % maxsize;
			queue[rear] = p->adjvl;
		}
		p = p->next;




	}

}
void Dfs(int v, AGraph* G)
{
	Visit[v] = 1;
	//visit(v);
	ArcNode* q = G->adjlistp[v].first;

	if (q->adjvl == 0)
	{
		Dfs(q->adjvl, G);
	}
	q = q->next;


}

void Bfs(AGraph* G, int v, int Visit[maxsize])
{
	int queue[maxsize], rear = 0, front = 0;
	ArcNode* p;
	Visit[v] = 1;
	//fangwen'
	rear = (rear + 1) % maxsize;
	queue[rear] = v;
	int j;
	while (rear != front)
	{
		front = (front + 1) % maxsize;
		j = queue[front];
		p = G->adjlistp[j].first;
		while (p != NULL)
		{
			Visit[p->adjvl];
			//fangwen;
			rear = (rear + 1) % maxsize;
			queue[p->adjvl];
		}
		p = p->next; 
	}


}
typedef struct VertexType
{
	int no;
	char info;
}VertexType;

typedef struct
{
	float edges[maxsize][maxsize];
	int n, e;
	VertexType vex[maxsize];
}MGraph;
void Prim(MGraph* G, int v0, float*sum)
{
	int lowCost[maxsize];
	int vSet[maxsize];
	int v, k, min;
	for (int i = 0; i < G->n; i++)
	{
		lowCost[i] = G->edges[v0][i];
		vSet[i] = 0;
	}
	v = v0;
	vSet[v] = 1;
	sum = 0;

	for (int i = 0; i < G->n - 1; i++)
	{
		min = INF;
		for (int j = 0; j < G->n; j++)
		{
			if (vSet[j] == 0 && lowCost[j] < min)
			{
				min = lowCost[j];
				k = j;
			}
		}
		vSet[k] = 1;
		v = k;
		sum += min;
		for (int j = 0; j < G->n;++j)
		{
			if (vSet[j] == 0 && G->edges[v][j] < lowCost[j])
				lowCost[j] = G->edges[v][j];
		}
	}

}

typedef struct VertexType
{
	int io;
	char info;
}VertexType;

typedef struct
{
	float edges[maxsize][maxsize];
	int n, e;
	VertexType vex[maxsize];
}MGraph;

void Prim(MGraph* G, int v0, float* sum)
{
	int lowCost[maxsize];
	int vSet[maxsize];
	int v, min, k;
	for (int i = 0; i < G->n; i++)
	{
		lowCost[i] = G->edges[v0][i];
		vSet[i] = 0;
	}
	v = v0;
	vSet[v] = 1;
	sum = 0;
	for (int i = 0; i < G->n - 1; i++)
	{
		min = INF;
		for (int j = 0; j < G->n; ++j)
		{
			if (vSet[j] == 0 && lowCost[j] < min)
			{
				min = lowCost[j];
				k = j;
			}
		}
		vSet[k] = 1;
		v = k;
		sum = sum + min;

		for (int j = 0; j < G->n; j++)
		{
			if (vSet[j] == 0 && G->edges[v][j] < lowCost[j])
			{
				lowCost[j] = G->edges[v][j];
			}
		}
	}


}

typedef struct
{
	int a, b;
	int w;
}Road;

Road road[maxsize];
void sort(Road arr[], int n)
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
			j--;
		}
		arr[j + 1] = temp;
		
	}
}
int v[maxsize];
int getRoot(int p)
{
	while (p != v[p])
		p = v[p];
	return p;
}

void Kruksal(Road roar[], int n, int e, int* sum)
{
	int a, b;
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		v[i] = i;
	}
	sort(road, e);
	for (int i = 0; i < e; ++i)
	{
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b)
		{
			v[a] = b;
			sum = sum + road[i].w;
		}
	}
}

typedef struct
{
	int a, b;
	int w;
}Road;
Road road[maxsize];
void sort(Road arr[], int n)
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
			j--;
		}
		arr[j + 1] = temp;
	}

}

int v[maxsize];
int getRoot(int p)
{
	while (p != v[p])
	{
		p = v[p];
	}
	return p;
}

void kurksal(Road road[], int n, int e, float* sum)
{
	int a, b;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		v[i] = i;
	}
	sort(road, e);
	for (int i = 0; i < e; i++)
	{
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b)
		{
			v[a] = b;
			sum += road[i].w;
		}
	}
}
typedef struct ArcNode
{
	int adj;
	struct ArcNode* next;

}ArcNode;
typedef struct VNode
{
	int data;
	ArcNode* firs;
}VNode;
typedef struct
{
	int n, e;
	VNode vex[maxsize];
}AGraph;

int Visit[maxsize];
void DFS(AGraph* g, int v)
{
	Visit[v] = 1;
	//fangwe;
	ArcNode* q = g->vex[v].firs;
	if (q != NULL)
	{
		if (Visit[q->adj] == 0)
			DFS(q->adj, g);
		q = q->next;
	}

}
void Bfs(AGraph* G,int v,int Visit[maxsize])
{
	ArcNode* p;
	int queue[maxsize], front = 0, rear = 0;
	Visit[v] = 1;
	//fangwe
	rear = (rear + 1) % maxsize;
	queue[rear] = v;
	int j;
	while (front != rear)
	{
		front = (front + 1) % maxsize;
		j = queue[front];
		p = G->vex[j].firs;
		while (p != NULL)
		{
			if (p->adj == 0)
			{
				Visit[p->adj];
				//fangwe1
				rear = (rear + 1) % maxsize;
				queue[rear] = p->adj;
			}
			p = p->next;
		}
	}

}