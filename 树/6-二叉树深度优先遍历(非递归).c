#include <stdio.h>
#define maxSize 100

typedef struct BTNode
{
	char data;
	struct BTNode* lchirld;
	struct BTNode* rchirld;
}BTNode;

////////////////��������ǵݹ黯////////////////////
//1:ʵ�ַ���
/*
	�Ӹ��ڵ㿪ʼ��ջԪ�أ�Ȼ������ڵ㲢���ʣ����Ž����ڵ���������Ӷ���ջ���Һ�������ջ�����Ӻ�
	��ջ�������ٳ�ջ�����ʣ�Ȼ����������Һ��Ӱ�������������ջ���ظ�֮ǰ�Ĳ�������Ҫע���ʱ������ջ
	Ԫ��ǰҪ�ж����Ƿ�ΪҶ�ӽ�㣬�����Ҷ�ӽ�㣬����Ҫ�����Һ��Ӽ���
*/
//2:����ʵ��
void preorderNonrecursion(BTNode* bt)//������������ڵ�
{
	if (bt != NULL)//�����ж��Ƿ�Ϊ����
	{
		BTNode* stack[maxSize];//��ջʱ����ʵ�ʰ�Ԫ��ѹ��ջ�У�ֻ��ѹ���ַ�����ﴴ������һ��ָ�����飬�����ڵ�����Ԫ����BTNode*��ָ��
		int top = -1;
		BTNode* p = NULL;//���ڱ�����ָ��

		stack[++top] = bt;//�����㣬ע����������ǵ�ַ

		while (top != -1)//ջ������ͣ
		{
			p = stack[top--];//����һ��Ԫ��
			visit(p);
			if (p->rchirld != NULL)//�������Ҷ�ӽ�㣬�����Һ��ӣ���������
				stack[++top] = p->rchirld;
			if (p->lchirld != NULL)
				stack[++top]=p->lchirld;
		}

	}

}

////////////////��������ǵݹ黯////////////////////
//1:ʵ�ַ���
/*
	����һ�Ŷ��������������ǽ�������������д����������ǰ��Ĳ������ڣ�ǰ���Ǹ����ң�������Ǹ�����
	�������Ǹ���ǰ������Ƶ��������Ȼ���ٽ������ѹ��ջ�У���ջ���Ǻ������
*/
//2:����ʵ��
void postorderNonrecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* stack1[maxSize];//���ڱ�����ջ
		int top1 = -1;
		BTNode* stack2[maxSize];//���ڽ������תΪ�����ջ
		int top2 = -2;
		BTNode* p = NULL;

		stack1[++top1] = bt;
		while (top1 != -1)
		{
			p = stack1[top1--];
			stack2[++top2] = p;//��stack1��ջ��Ԫ���������ֱ����Stack2������֮����Ǻ�����

			if (p->lchirld != NULL)//�������ӣ������Һ���
				stack1[++top1] = p->lchirld;
			if (p->rchirld != NULL)
				stack1[++top1] = p->rchirld;
		}

		while (top2 != -1)//��������ջ��Ԫ�����γ�ջ���ʣ����Ǻ���
		{
			p = stack2[top2--];
			visit(p);
		}
	}
}


////////////////��������ǵݹ黯////////////////////
//1:ʵ�ַ���
/*
	�Ӹ��ڵ㿪ʼ��һֱ�����ߣ��ߵ�������Ϊֹ��;�����ȫ����ջ
	Ȼ���ջһ����㲢���ʣ�Ȼ����һ����������ߣ��ظ���������
*/
//2:����ʵ��
void inorderNonrecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* stack[maxSize];
		int top = -1;
		BTNode* p = bt;//�Ӹ��ڵ㿪ʼ��ջ

		while (top != -1 || p != NULL)
		{
			while (p != NULL)//�Ӹ��ڵ㿪ʼ�������ߣ�;��ȫ����ջ
			{
				stack[++top] = p;
				p = p->lchirld;
			}
			if (top != -1)//��ջһ��Ԫ�أ��ó�һ���Һ��ӣ�����ѭ���������ж�����Һ����Ƿ������������ӣ��еĻ�һֱ��������������ȥ
			{
				p = stack[top--];
				visit(p);
				p = p->rchirld;
			}
		}
	}
}