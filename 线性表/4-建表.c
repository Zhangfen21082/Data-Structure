#include <stdio.h>
#include <malloc.h>

typedef struct LNnode
{
	int data;
	struct LNonde* next;
}LNode;

//β�巨����������

void createlinklistR(LNode* head)//C���Բ��������ͣ�ʵ��ΪLNode* &head
{
	head = (LNode*)malloc(sizeof(LNode));//Ϊͷ��������ڴ�ռ�
	head->next = NULL;//��ϰ�ߣ�����ý��󣬾ͽ���ָ��NULL
	LNode* p = NULL;//pָ����ѭ�������½ڵ�
	LNode* r = head;//������β�巨��������Ҫһ��ָ���ǳ�ĩβ����λ�ã��²���Ľ�����ĩβ
	int n;//���ڽ���Ҫ���ٸ���
	scanf("%d", &n);//���û��������
	for (int i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));//Ϊÿ���½ڵ�����ռ�
		p->next = NULL;
		scanf("%d", &(p->data));//����������ݷ��ص�ָ���data����
		//β�巨������Ĵ���/////
		p->next = r->next;
		r->next = p;
		r = p;
	}
}

//ͷ�巨����������

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
		//ͷ�巨������������Ĵ���///
		p->next = head->next;
		head->next = p;
	}
}
