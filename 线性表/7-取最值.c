#include <stdio.h>
#define maxSize 100


//˳���ȡ��ֵ
typedef struct
{
	int data[maxSize];
	int length;
}Sqlist;
Sqlist L;
//ȡ���ֵ
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
//ȡ��Сֵ
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



//����ȡ��ֵ
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
//���ֵ
int main(void)
{
	LNode* head;
	LNode* p;
	LNode* q;

	int max = head->next->data;//������Ϊ��һ��Ԫ��������
	q = p = head->next;//��q��p��ָ����
	while (p != NULL)//��pȥɨ������
	{
		if (max < p->data)//ĳһʱ��p��ָ���Ҫ����max
		{
			max = p->data;//��ô�Ͱ�����ڵ㶨��Ϊmax
			q = p;//q����ʵʱ����������λ��
		}
		p = p->next;//һֱɨ��ֱ������
	}
}
//��Сֵ
int main(void)
{
	LNode* head;
	LNode* p;
	LNode* q;

	int min = head->next->data;//�仯
	q = p = head->next;
	while (p != NULL)
	{
		if (min > p->data)//�仯
		{
			min = p->data;//�仯
			q = p;
		}
		p = p->next;
	}
}
