#include <stdio.h>
#include <malloc.h>
#define maxSize 100


//˳���//////////////////////////
typedef struct
{
	int data[maxSize];
	int front;
	int rear;
}SqQueue;
//1:����
int enQueue(SqQueue* qu, int x)
{
	if ((qu->rear + 1) % maxSize == qu->front)//�ж϶���
		return 0;
	qu->rear = (qu->rear + 1) % maxSize;//rear��
	qu->data[qu->rear] = x;//Ȼ����rear���λ������Ԫ��
	return 1;
}
//2:����
int deQueue(SqQueue* qu, int* x)
{
	if (qu->front == qu->rear)//�ж϶ӿ�
		return 0;
	qu->front = (qu->front + 1) % maxSize;
	*x = qu->data[qu->front];//Ҫע��front����һ����Ԫ�أ���rearָ��ľ���Ԫ��
	return 1;
}
//����//////////////////////////////////////////////////
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
//1:��ʼ������
void initQueue(LiQueue* head)
{
	head= (LiQueue*)malloc(sizeof(LiQueue));
	head->front = head->rear = NULL;
}
//2:���
void enQueue(LiQueue* head, int x)
{
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (head->rear==NULL)//���rearָ��գ�˵������Ϊ�գ���ô�����Ԫ����Ϊ���׺Ͷ�β�ڵ�
		head->front = head->rear = p;
	else//�������˵�����в��գ���ô��rearָ��ָ���β�ڵ��nextָ��ָ������ӵĽ�㣬rearָ�����
	{
		head->rear->next = p;
		head->rear = p;
	}

}
//3������
void deQueue(LiQueue* head, int* x)
{
	QNode* p;
	if (head->rear == NULL)//�������Ϊ�գ�����ʧ��
		return 0;
	else
		p = head->front;//��pָ����ӵĽ��
	if (head->front == head->rear)//��������ֻ��һ��Ԫ��ʱ����Ҫ���⴦��Ҳ����front��rearҪͬʱָ��null
		head->front = head->rear = NULL;
	else//��������������front�����ӣ�frontָ����һ��
		head->front = head->front ->next;
	*x = p->data;//����
	free(p);
	return 1;
}