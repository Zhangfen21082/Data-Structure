#include <stdio.h>
#include <malloc.h>
#define maxSize 100

typedef struct Lstack
{
	int data;
	struct Lstack* next;

}Lstack;

//˳��ջ/////////////////////////////////////
//1����ջ
void pushstack()
{
	int stack[maxSize];
	int top = -1;
	if (top == maxSize - 1)//��ջ���ܵ���ջ��
		printf("ջ��");
	int x;//����ջԪ��
	
	stack[++top] = x;
}
//2����ջ
void outstack()
{
	int x;//x�������ܳ�ջԪ��
	int stack[maxSize];
	int top;
	if (top == -1)//��ջ���ܵ���ջ��
		printf("ջ��");	
	x = stack[top--];
}
//��ջ///////////////////////////////////////////////////
//1:��ʼ��
void initstack(Lstack* head)
{
	head = (Lstack*)malloc(sizeof(Lstack));//����ͷ���
	head->next = NULL;
}
//2:��ջ
void push(Lstack* head, int x)
{
	Lstack* p = (Lstack*)malloc(sizeof(Lstack));//Ϊ�½ڵ�����ռ�
	p->next = NULL;

	p->data = x;//ͷ�巨
	p->next = head->next;
	head->next = p;
}
//2����ջ
int pop(Lstack* head, int* x)
{
	Lstack* p;
	if (head->next == NULL)
		return 0;//ջ�շ���ʧ��

	p = head->next;
	x = p->data;
	head->next = p->next;
	free(p);
	return 1;
}
