#include <stdio.h>

typedef struct BTNode
{
	char data;
	struct BTNode* lchirld;
	struct BTNode* rchirld;
}BTNode;

/////////������������ȱ���(�ݹ�)///////////
void r(BTNode* p)
{
	if (p != NULL)
	{
		//�����ʴ�������������������
		r(p->lchirld);
		//�����ʴ�������������������
		r(p->rchirld);
		//�����ʴ�����������Ǻ������
	}

}