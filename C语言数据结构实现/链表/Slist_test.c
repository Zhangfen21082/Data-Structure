#include "Slist.h"

void test()//ÔöÉ¾²âÊÔ
{
	SlNode* head=NULL;
	SlNode* tail = head;
	SlistPushBack(&head,&tail, 1);
	SlistPushBack(head,&tail, 2);
	SlistPushBack(head,&tail, 3);
	SlistPushBack(head,&tail, 4);
	SlistPushBack(head,&tail, 5);
	SlistPushBack(head,&tail, 6);
	SlistPushBack(head,&tail, 7);
	SlistPrint(head);

	//SlNode* head = NULL;
	//SlistPushBack(&head, 1);
	//SlistPushBack(&head, 2);
	//SlistPrint(head);
}

int main()
{

	test();//ÔöÉ¾²âÊÔ
	return 0;
}