#include "Slist.h"

void test(SlNode* head,SlNode** tail)//��ɾ����
{
	
	SlistPushBack(tail, 1);
	/*SlistPushBack(head, &tail, 2);
	SlistPushBack(head, &tail, 3);
	SlistPushBack(head, &tail, 3);
	SlistPushBack(head, &tail, 3);
	SlistPushBack(head, &tail, 3);
	SlistPushBack(head, &tail, 3);*/
	SlistPrint(head);
}

int main()
{

	//SlNode* head=(SlNode*)malloc(sizeof(SlNode));//������������һ��ָ���һ������ͷָ��
	SlNode* head=NULL;
	SlNode* firstNode = (SlNode*)malloc(sizeof(SlNode));
	head = firstNode;
	//head->next = NULL;
	//head->data = NULL;
	SlNode** tail = head;
	test(head,tail);//��ɾ����
	return 0;
}