#include <stdio.h>
#include <malloc.h>
#define maxSize 100

typedef struct Lstack
{
	int data;
	struct Lstack* next;

}Lstack;

//顺序栈/////////////////////////////////////
//1：入栈
void pushstack()
{
	int stack[maxSize];
	int top = -1;
	if (top == maxSize - 1)//入栈可能导致栈满
		printf("栈满");
	int x;//待入栈元素
	
	stack[++top] = x;
}
//2：出栈
void outstack()
{
	int x;//x用来接受出栈元素
	int stack[maxSize];
	int top;
	if (top == -1)//出栈可能导致栈空
		printf("栈空");	
	x = stack[top--];
}
//链栈///////////////////////////////////////////////////
//1:初始化
void initstack(Lstack* head)
{
	head = (Lstack*)malloc(sizeof(Lstack));//制造头结点
	head->next = NULL;
}
//2:入栈
void push(Lstack* head, int x)
{
	Lstack* p = (Lstack*)malloc(sizeof(Lstack));//为新节点申请空间
	p->next = NULL;

	p->data = x;//头插法
	p->next = head->next;
	head->next = p;
}
//2：出栈
int pop(Lstack* head, int* x)
{
	Lstack* p;
	if (head->next == NULL)
		return 0;//栈空返回失败

	p = head->next;
	x = p->data;
	head->next = p->next;
	free(p);
	return 1;
}
