#include <stdio.h>
#define maxSize 100


typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
typedef struct
{
	int data[maxSize];
	int length;
}Sqlist;

//**************������***************



//**************˫����*****************


//**************˳���*****************
//����
//1���ɲ����±�λ��ȡֵ��Χ��0-length��
//2����length=���鳤��ʱ�������ٲ���Ԫ��
//3���ƶ�Ԫ�شӺ���ǰ����

int inseretElem(Sqlist L, int p, int e)//p��ʾ����λ�ã�e��ʾ���������
{
	if (p<0 || p>L.length|| L.length == maxSize)//�������λ��С��0�����˳����Ȼ�˳����Ѿ�����
		return 0;//���ش���
	for (int i = L.length - 1; i >= p; --i)//����Ԫ�ش����һ����pλ�ÿ�ʼ���ƣ���pλ���ڳ���
		L.data[i + 1] = L.data[i];
	L.data[p] = e;//pλ�÷�eԪ��
	++L.length;//ͬʱ����+1
	return 1;

}

//ɾ��
//1����ɾ��Ԫ���±��p��ȡֵ��ΧΪ��0-length-1��
//2������length=0��ʱ�򣬲�����ɾ��Ԫ�أ�
//3���ƶ�Ԫ�ش�ǰ�������

int deleteElem(Sqlist L, int p, int e)//p��ʾɾ��λ�ã�e��������ɾ����Ԫ��(ע��������)
{
	if (p<0 || p>L.length - 1)//ʧ����length=0Ҳ�ǲ���ɾ���ģ�������������Ѿ�����������
		return 0;//���ش���
	e = L.data[p];//�Ȱ��Ǹ�Ԫ���ó���
	for (int i = p; i < L.length - 1; ++i)//�����Ԫ�ص����һ��Ԫ�أ�ȫ����ǰ��
		L.data[i] = L.data[i + 1];
	--L.length;//ͬʱ����-1
	return 1;

}
