#include "Slist.h"

void test()//增删测试
{
	//完美情况
	/*SlNode* head=NULL;
	SlNode** tail = &head;
	SlistPushBack(head,tail, 1);
	SlistPushBack(head,tail, 2);
	SlistPrint(head);*/

	SlNode* head = NULL;
	SlistPushBack(&head, 1);
	SlistPushBack(&head, 2);
	SlistPrint(head);
}

int main()
{

	test();//增删测试
	return 0;
}