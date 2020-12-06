#include "Slist.h"

void test(SlNode* head,SlNode* tail)//增删测试
{
	
	SlistPushBack(head, tail, 1);
	SlistPushBack(head, tail, 2);
	SlistPushBack(head, tail, 3);
	SlistPrint(head);
}

int main()
{

	SlNode* head=(SlNode*)malloc(sizeof(SlNode));//创造链表，申请一个指向第一个结点的头指针
	head->next = NULL;
	head->data = NULL;
	SlNode* tail = head;
	test(head,tail);//增删测试
	return 0;
}