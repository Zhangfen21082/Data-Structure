#include "SeqList.h"

//����ͷβ����ɾ��
void Test1()
{
	SeqList s;
	SeqListInit(&s);//��ʼ��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);//β����������Ԫ��
	SeqListPrint(&s);

	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);//β������ɾ��Ԫ��
	//SeqListPrint(&s);

	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 8);
	//SeqListPushFront(&s, 7);//ͷ�����β���Ԫ��
	//SeqListPrint(&s);

	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);//ͷ������ɾ��Ԫ��
	//SeqListPrint(&s);

	SeqListInsert(&s, 1, 5);
	SeqListInsert(&s, 1, 6);//��ָ��λ�ò���Ԫ��
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListErase(&s, 1);//��ָ��λ��Ԫ��ɾ��
	SeqListPrint(&s);

	printf("���Ԫ���Ǵ��ڵ������±���%d\n", SeqListFindvalue_Bind(&s, 0));//ʹ�ö��ֲ���ĳ��Ԫ�ز����

}


int main()
{
	Test1();
	return 0;
}