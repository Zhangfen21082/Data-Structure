#include <stdio.h>
#include <malloc.h>
#define maxSize 100


//顺序队//////////////////////////
typedef struct
{
	int data[maxSize];
	int front;
	int rear;
}SqQueue;
//1:进队
int enQueue(SqQueue* qu, int x)
{
	if ((qu->rear + 1) % maxSize == qu->front)//判断队满
		return 0;
	qu->rear = (qu->rear + 1) % maxSize;//rear变
	qu->data[qu->rear] = x;//然后在rear变的位置上入元素
	return 1;
}
//2:出队
int deQueue(SqQueue* qu, int* x)
{
	if (qu->front == qu->rear)//判断队空
		return 0;
	qu->front = (qu->front + 1) % maxSize;
	*x = qu->data[qu->front];//要注意front的下一个是元素，而rear指向的就是元素
	return 1;
}
//链队//////////////////////////////////////////////////
typedef struct QNode
{
	int data;
	struct QNode* next
}QNode;
typedef struct
{
	QNode* front;
	QNode* rear;
}LiQueue;
//1:初始化链队
void initQueue(LiQueue* head)
{
	head= (LiQueue*)malloc(sizeof(LiQueue));
	head->front = head->rear = NULL;
}
//2:入队
void enQueue(LiQueue* head, int x)
{
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (head->rear==NULL)//如果rear指向空，说明队列为空，那么让这个元素作为队首和队尾节点
		head->front = head->rear = p;
	else//如果不是说明队列不空，那么让rear指针指向的尾节点的next指针指向新入队的结点，rear指针跟进
	{
		head->rear->next = p;
		head->rear = p;
	}

}
//3：出队
void deQueue(LiQueue* head, int* x)
{
	QNode* p;
	if (head->rear == NULL)//如果队列为空，出队失败
		return 0;
	else
		p = head->front;//用p指向出队的结点
	if (head->front == head->rear)//当队列中只有一个元素时，需要特殊处理，也就是front和rear要同时指向null
		head->front = head->rear = NULL;
	else//否则则按正常处理，front出出队，front指向下一个
		head->front = head->front ->next;
	*x = p->data;//出队
	free(p);
	return 1;
}