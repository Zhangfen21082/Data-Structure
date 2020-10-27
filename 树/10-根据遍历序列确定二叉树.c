#include <stdio.h>
#include <malloc.h>


typedef struct BTNode
{
	char data;
	struct BTNode *lchirld;
	struct BTNode *rchurld;
}BTNode;
//����������������������ȷ��������
BTNode* CreatBT(char pre[], char in[], int L1, int R1, int L2, int R2)
{
	//����˵����pre��in�ֱ��ʾ����������к�ǰ���������
	//		   L1��R1����ǰ������pre�����Ԫ�����ڵ��±귶ΧΪ��L1��R1
	//		   L2��R2����ǰ������pre�����Ԫ�����ڵ��±귶ΧΪ��L2��R2
	if (L1 > R1)//�ݹ���ڣ����г���Ϊ0
		return NULL;//����Ϊ��
	BTNode* s = (BTNode *)malloc(sizeof(BTNode));//Ϊ����(����)���ڵ�����ռ�,
	s->lchirld = s->rchurld = NULL;
	s->data = pre[L1];//��ʱ���ڵ����pre�����L1

	//s->data=pre[L1]�������ˣ�ÿ�ν���ݹ�����������������ѭ���������ĸ��ڵ㣬��������ڵ������һ�ݹ�s->lchirld��s->rchirld
	int i;
	for (i = L2; i <= R2; ++i)
		if (in[i] == pre[L1])//�����������е�ĳ���ڵ����pre[L1]��ζ�ҵ��˸��ڵ㣨�ڱ����д˸��ڵ�����������ĸ��ڵ㣩
			break;
	s->lchirld = CreatBT(pre, in, L1 + 1, L1 + i - L2, L2, i - 1);//��������ݹ�Ĳ�����Ҫ�ص�˵�������ʼǡ�
	s->rchurld = CreatBT(pre, in, L1 + 1 - L2 + 1, R1, i + 1, R2);//��������ݹ�Ĳ�����Ҫ�ص�˵�������ʼǡ�
	return s;

}
//�ɺ���������������ȷ��������
BTNode *CreatBT2(char post[], char in[], int L1, int R1, int L2, int R2)
{
	if (L1 > R1)
		return NULL;
	BTNode *s = (BTNode *)malloc(sizeof(BTNode));
	s->lchirld = s->rchurld = NULL;
	s->data = post[R1];//�������ʱ�������һ��������Ǹ��ڵ�

	int i;
	for (int i = L2; i <= R2; ++i)
		if (in[i] = post[R1])
			break;
	s->lchirld = CreatBT2(post, in, L1, L1 + i - L2 - 1, L2, i - 1);//������һ��
	s->rchurld = CreatBT2(post, in, L1 + i - L2, R1 - 1, i + 1, R2);
	return s;
}


//�ɲ�α������������ȷ��������
/*
	����������У����������ȷ�����ڵ�󣬸��ڵ�ͽ����н�㻮�����������������������������������������������֣�����
	�ڲ�α����У����������Ƿֿ���
*/

struct S//��������
{
	int n;
	char arr[0];

};

int serach(char arr[], char key, int L, int R)//arr�������������key���ǲ�α������������������ڵ�
{
	int idx;
	for (idx = L; idx <= R; ++idx)//��L��R�ķ�Χ�ڲ��Ҹ��ڵ�
	{
		if (arr[idx] == key)
			return idx;//���ظ��ڵ�����������е��±�
	}
	return -1;

}
void getSubLevel(char subLevel[], char level[], char in[], int n, int L, int R)//subLevel�����½��õ����飬n���䳤�ȣ�in����L��R��ȷ�����������Ҳ����������
{
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (search(in, level[i], L, R) != -1)//�ó���α�����Level����ÿ����㣬�������������(int)�Ƚϣ����ǣ��򽫲�α���(Level)��Ԫ�ط����½��õ�����(sublevel)
			subLevel[k++] = level[i];
	}


}

BTNode* CreateBT3(char level[], char in[], int n, int L, int R)
/*
	1��char level[]������������ڲ�α����л��ֳ��ķ�Χ�����������ཻ�����Ի�����Χ�󣬰������������õ���������
	2��n���ǲ�α�����Ԫ�ظ���
	3��char in[]���������
	4:��L��R���ڿ������������Χ
*/
{
	if (L > R)
		return NULL;

	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->lchirld = s->rchurld = NULL;
	s->data = level[0];


	int i = search(in, level[0], L, R);//������������ҳ����ڵ��λ��
	int LN = i - L;//�õ����ڵ��λ�ú��������L-i��Ȼ���������ķ�Χ����ô���������Ⱦ���LN
	struct S* LeftArrTre = (struct S*)malloc(sizeof(struct S) + LN * sizeof(char));//ʹ����������ķ�ʽ������һ������������
	int RN = R - i;//�õ����ڵ��λ�ú󣬣��������i-L��Ȼ���������ķ�Χ����ô���������Ⱦ���RN
	struct S* RightArrTre = (struct S*)malloc(sizeof(struct S) + RN * sizeof(char));//ʹ����������ķ�ʽ������һ������������

	getSubLevel(LeftArrTre->arr, level, in, n, L, i - 1);//���������������������ΧΪL-i-1�����ⲿ���������ڲ�α�������ɢ��ģ����������������������Ϊ��׼���ڲ�α����������е��������������õ��ո��½��õ�������
	getSubLevel(RightArrTre->arr, level, in, n, i+1, R);////���������������������Χi+1-R�����ⲿ���������ڲ�α�������ɢ��ģ����������������������Ϊ��׼���ڲ�α����������е��������������õ��ո��½��õ�������

	s->lchirld = CreateBT3(LeftArrTre->arr, in, LN, L, i - 1);//���ھͽ���α�������ֿ��ˣ�������������µ������������һ�ν���ѭ�����������ϲ���
	s->lchirld = CreateBT3(RightArrTre->arr, in, LN, i + 1, R);//���ھͽ���α�������ֿ��ˣ�������������µ������������һ�ν���ѭ�����������ϲ���

	return s;
}