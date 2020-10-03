#include <stdio.h>
#define maxSize 100


//顺序表取最值
typedef struct
{
	int data[maxSize];
	int length;
}Sqlist;
Sqlist L;
//取最大值
int main(void)
{
	int max = L.data[0];
	int maxIdx = 0;
	for (int i = 0; i < L.length; ++i)
	{
		if (max < L.data[i])
		{
			max = L.data[i];
			maxIdx = i;
		}
	}
}
//取最小值
int main(void)
{
	int min = L.data[0];
	int minIdx = 0;
	for (int i = 0; i < L.length; ++i)
	{
		if (min > L.data[i])
		{
			min = L.data[i];
			minIdx = i;
		}
	}
}



//链表取最值
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
//最大值
int main(void)
{
	LNode* head;
	LNode* p;
	LNode* q;

	int max = head->next->data;//首先认为第一个元素是最大的
	q = p = head->next;//让q和p都指向它
	while (p != NULL)//让p去扫描链表
	{
		if (max < p->data)//某一时刻p所指结点要大于max
		{
			max = p->data;//那么就把这个节点定义为max
			q = p;//q用来实时跟踪最大结点的位置
		}
		p = p->next;//一直扫描直到结束
	}
}
//最小值
int main(void)
{
	LNode* head;
	LNode* p;
	LNode* q;

	int min = head->next->data;//变化
	q = p = head->next;
	while (p != NULL)
	{
		if (min > p->data)//变化
		{
			min = p->data;//变化
			q = p;
		}
		p = p->next;
	}
}
