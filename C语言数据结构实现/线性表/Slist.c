#include "Slist.h"


//void SlistPushBack(SlNode* head, SlNode** tail, SlistDataType x)//尾插
//{
//	SlNode* creat = (SlNode*)malloc(sizeof(SlNode));
//	creat->data = x;
//	creat->next =(*tail)->next;
//	(*tail)->next = creat;
//	(*tail) = creat;
//}
void SlistPushBack(SlNode** tail, SlistDataType x)//尾插
{
	SlNode* NewNode = (SlNode*)malloc(sizeof(SlNode));
	NewNode->data = x;
	NewNode->next = NULL;
	(*tail) = NewNode;
	tail = NewNode;
}
void SlistPopBack(SlNode* head);//尾删
void SlistPushFront(SlNode* head, SlistDataType x);//头插
void SlistPopFront(SlNode* head);//头删

void SlistPrint(SlNode* head)//打印
{
	SlNode* current = head;//申请一个遍历指针，因为头指针不能乱跑
	while (current!= NULL)
	{
		printf("->%d", current->data);
		current = current->next;//指针后移
	}
}