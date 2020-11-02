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

void BFS(AGraph* G, int v, int visit[Maxsize])//���ȴ���v=0Ҳ���Ǵӵ�һ��Ԫ�ؿ�ʼ��visit��һ�������ı������
{
	ArcNode* p;
	int que[Maxsize], front = 0, rear = 0;//����һ�����������Ҫ�õ�����
	int j;
	Visit(v);
	visit[v] = 1;//�ս��뺯��ʱ���ȰѸ��ڵ���ʣ����
	rear = (rear + 1) % Maxsize;
	que[rear] = v;
	while (front != rear)//���Ӳ���ʱ��ִ�г��Ӳ���
	{
		front = (front + 1) % Maxsize;//��Ҫע����ǣ��������ֻ�Ǵ洢��ͼ��Ԫ�ص���ţ�ÿ���ڶ���whileѭ������ʱ����ʾ����ڵ�����нڵ㱻��Ѱ����ˣ�Ȼ�����һ������ѭ��������һ��while
		j = que[front];
		p = G->adjlist[j].first;//pָ���˴˴γ��ӵ�j�ıߣ���������ڵ��first�߿�ʼ�����������whileѭ��ȥ���������еĽ��
		while (p != NULL)
		{
			if (visit[p->adjv] == 0)//���������ָ���Ԫ��û�б����ʹ����Ǿͽ������
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