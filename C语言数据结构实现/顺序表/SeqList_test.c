#include "SeqList.h"

//测试插入删除元素
void Test1(SeqList* ps)
{
	SeqListInit(ps);//初始化
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 4);
	SeqListPushBack(ps, 5);//尾部插入依次元素
	SeqListPrint(ps);

	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);//尾部依次删除元素
	//SeqListPrint(&s);

	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 8);
	//SeqListPushFront(&s, 7);
	//SeqListPushFront(&s, 6);
	//SeqListPushFront(&s, 5);//头部依次插入元素
	//SeqListPrint(&s);

	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);//头部依次删除元素
	//SeqListPrint(&s);

	//SeqListInsert(&s, 1, 5);
	//SeqListInsert(&s, 1, 6);//向指定位置插入元素
	//SeqListPrint(&s);

	//SeqListErase(&s, 1);
	//SeqListErase(&s, 1);//把指定位置元素删除
	//SeqListPrint(&s);

}
//测试接受用户输入删除指定元素删除
void Test2(SeqList* ps)
{
	printf("请输入要删除的元素\n");
	int res = 0;
	scanf_s("%d", &res);
	int index = SeqListFind(ps, res);
	if (index == -1)
		printf("没有此元素");
	else
	{
		printf("删除后为\n");
		SeqListErase(ps, index);
		SeqListPrint(ps);
	}
	
	

}


int main()
{
	SeqList s;
	Test1(&s);//测试插入删除元素
	Test2(&s);//测试用户指定元素删除
	return 0;
}