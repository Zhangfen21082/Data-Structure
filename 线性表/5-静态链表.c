#include <stdio.h>
#define maxSize 100

//��̬�ṹ�嶨��
typedef struct
{
	/*
		��̬���������������ϵ�����������˳�����Ϊ���Ĵ洢�ռ���һƬ�����ģ�����
		������Ϊ��Ҳ������ָ�롱����Ԫ������Ƭ�����Ŀռ��ǡ�ɢ�����ģ�����ǰһ��Ԫ�ص�
		����ָ����һ����
	*/
	int data;
	int next;//ע��next����ָ����
}SLNode;
//��������洢��̬����
SLNode SLink[maxSize];

//��̬����Ĳ���
int p = Ad0;//�����Ad0��ĳ��Ԫ�ص��±꣬������һ��p��ָ������
SLink[p].data;//�����Ĳ������ǡ�p->data��
Slink[p].next//����Ĳ������ǡ�p->next��

//��̬�������ڵ�ķ���
SLink[q].next = Slink[p].next;
Slink[p].next = q;//�����ڣ�q->next=p->next,p->next=q