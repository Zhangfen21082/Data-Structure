#include "Slist.h"


//void SlistPushBack(SlNode* head, SlNode** tail, SlistDataType x)//β��
//{
//	SlNode* creat = (SlNode*)malloc(sizeof(SlNode));
//	creat->data = x;
//	creat->next =(*tail)->next;
//	(*tail)->next = creat;
//	(*tail) = creat;
//}
void SlistPushBack(SlNode** tail, SlistDataType x)//β��
{
	SlNode* NewNode = (SlNode*)malloc(sizeof(SlNode));
	NewNode->data = x;
	NewNode->next = NULL;
	(*tail) = NewNode;
	tail = NewNode;
}
void SlistPopBack(SlNode* head);//βɾ
void SlistPushFront(SlNode* head, SlistDataType x);//ͷ��
void SlistPopFront(SlNode* head);//ͷɾ

void SlistPrint(SlNode* head)//��ӡ
{
	SlNode* current = head;//����һ������ָ�룬��Ϊͷָ�벻������
	while (current!= NULL)
	{
		printf("->%d", current->data);
		current = current->next;//ָ�����
	}
}