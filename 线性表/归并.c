#include <stdio.h>
#define maxSize 100
//˳���鲢

typedef struct
{
	int data[maxSize];
	int length;
}Sqlist;
//L1��L2Ϊ����˳��������ǵ�˳����鲢����˳���L
void mergearray(Sqlist L1, Sqlist L2, Sqlist L)
{
	int i = 0;//��������L1���±�
	int j = 0;//��������L2���±�
	int k = 0;//��������L���±�

	while (i < L1.length && j < L2.length)//����ʱi��j�ֱ�ָ��L2��L2�ĵ�һ��Ԫ�أ�Ȼ���Ӧ�Ƚ�
	{
		if (L1.data[i] < L2.data[i])//���L1��Ԫ��С��L2�ģ���ô��L1���Ǹ�Ԫ�طŽ�ȥ
		{
			L.data[k] = L1.data[i];
			k++;
			i++;
		}
		else//���L2��Ԫ��С��L1�ģ���ô��L2���Ǹ�Ԫ�طŽ�ȥ
		{
			L.data[k] = L2.data[j];
			k++;
			j++;
		}
	}
	while (i < L1.length)//ɨ�赽��󣬷���L1û�б�ɨ���꣬˵��L1�̣����L1ʣ��Ԫ�طŵ�L��ȥ
	{
		L.data[k] =L1.data[i];
		k++;
		i++;
	}
	while (j < L2.length)//ɨ�赽��󣬷���L2û�б�ɨ���꣬˵��L2�̣����L2ʣ��Ԫ�طŵ�L��ȥ
	{
		L.data[k] = L2.data[j];
		k++;
		j++;
	}
	L.length = L1.length + L2.length;//�鲢��ı���������֮��
}


//����鲢
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
//����鲢1:�����鲢
void merge(LNode* A, LNode* B, LNode* C)//A,B�Ǵ��鲢�����ͷ��㣬C���������ͷ���
{
	LNode* p = A->next;
	LNode* q = B->next;//p��q�ֱ�ָ����������ĵ�һ��Ԫ��
	LNode* r;//rָ��ʼ��ָ��������β�ڵ�
	C = A;//ֱ�Ӱ�A��ͷ��㵱��C��ͷ���
	C->next = NULL;
	free(B);//B�����ˣ��ͷ�
	r = C;//rʼ��ָ��β�ڵ�

	while (p != NULL && q != NULL)//p��qͬʱɨ�������������߶�û��ɨ��������ĩβʱ����һֱɨ��
	{
		if (p->data <= q->data)//���pָ����ָ����С��qָ����ָ����
		{
			r->next = p;//��ô������������p
			p = p->next;//p������ƶ�������һ��p��ָ���ݺ�q�Ĵ�С���
			r = r->next;//������������һ��Ԫ�أ�rָ�����
		}
		else
		{
			r->next = q;
			q=q->next;
			r = r->next;
		}
	}
	if (p != NULL)//���p��ָ���գ�˵��p��ָ����ϳ�����ô�Ͱ�ʣ���һ���Թ鲢�����������
		r->next = p;
	if (q != NULL)//���q��ָ���գ�˵��q��ָ����ϳ�����ô�Ͱ�ʣ���һ���Թ鲢�����������
		r->next = q;
}
//����鲢2������鲢
void mergeR(LNode* A, LNode* B, LNode* C)
{
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* s;//���s�ڵ��൱����תվ���ȽϵĹ����ҵ�p��q��С������s����������ɲ����������Ϊp��qָ�벻�ܶ�ʧ
	C = A;
	C->next = NULL;
	free(B);

	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			s = p;//Ϊ�˲�ʹp��㶪ʧ���Ȱ�p��㸴��һ�ݸ�s����s��ɲ������
			p = p->next;//p����һλ��������һ�ֱȽ�
			s->next = C->next;//����ͷ�巨
			C->next = s;//�������佫�����뵽��ͷ���ĺ���
		}
		else
		{
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}
	while(p != NULL)//����������һ��һ��Ҫ���뵽ͷ�����棬���Բ����һ�ֲ�������һ�����ù���
	{
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q!=NULL)
	{
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}

}