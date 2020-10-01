#include <stdio.h>
#include <malloc.h>

typedef struct LNnode
{
	int data;
	struct LNonde* next;
}LNode;

//尾插法建立单链表

void createlinklistR(LNode* head)//C语言不能引用型，实际为LNode* &head
{
	head = (LNode*)malloc(sizeof(LNode));//为头结点申请内存空间
	head->next = NULL;//好习惯，申请好结点后，就将它指向NULL
	LNode* p = NULL;//p指针用循环生成新节点
	LNode* r = head;//由于是尾插法，所以需要一个指针标记出末尾结点的位置，新插入的结点就是末尾
	int n;//用于接收要多少个数
	scanf("%d", &n);//用用户输入接收
	for (int i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));//为每个新节点申请空间
		p->next = NULL;
		scanf("%d", &(p->data));//用输入的数据返回到指针的data域内
		//尾插法建表核心代码/////
		p->next = r->next;
		r->next = p;
		r = p;
	}
}

//头插法建立单链表

void createlinklistH(LNode* head)
{
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	LNode* p = NULL;
	int n;
	scnaf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->next = NULL;
		scanf("%d", &(p->data));
		//头插法建立单链表核心代码///
		p->next = head->next;
		head->next = p;
	}
}
