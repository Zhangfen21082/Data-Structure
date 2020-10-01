#include <stdio.h>
#define maxSize 100

//静态结构体定义
typedef struct
{
	/*
		静态链表不是真正意义上的链表，它既像顺序表（因为它的存储空间是一片连续的）又像
		链表（因为他也依靠“指针”），元素在这片连续的空间是“散布”的，依靠前一个元素的
		索引指向下一个。
	*/
	int data;
	int next;//注意next不是指针型
}SLNode;
//利用数组存储静态链表
SLNode SLink[maxSize];

//静态链表的操作
int p = Ad0;//这里的Ad0是某个元素的下标，我们用一个p“指向它”
SLink[p].data;//这样的操作就是“p->data”
Slink[p].next//这里的操作就是“p->next”

//静态链表插入节点的方法
SLink[q].next = Slink[p].next;
Slink[p].next = q;//类似于：q->next=p->next,p->next=q