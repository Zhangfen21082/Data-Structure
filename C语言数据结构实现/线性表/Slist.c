#include "Slist.h"


void SlistPushBack(SlNode* head, SlNode* tail, SlistDataType x)//β��
{
	SlNode* creat = (SlNode*)malloc(sizeof(SlNode));
	creat->data = x;
	creat->next =tail->next;
	tail->next = creat;
	tail = creat;


}
void SlistPopBack(SlNode* head);//βɾ
void SlistPushFront(SlNode* head, SlistDataType x);//ͷ��
void SlistPopFront(SlNode* head);//ͷɾ

void SlistPrint(SlNode* head)//��ӡ
{
	SlNode* current = head->next;//����һ������ָ�룬��Ϊͷָ�벻������
	while (current!= NULL)
	{
		printf("->%d", current->data);
		current = current->next;//ָ�����
	}
}