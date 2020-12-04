#include "SeqList.h"

//测试头尾插入删除
void Test1()
{
	SeqList s;
	SeqListInit(&s);//初始化
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);//尾部插入依次元素
	SeqListPrint(&s);

	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);//尾部依次删除元素
	//SeqListPrint(&s);

	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 8);
	//SeqListPushFront(&s, 7);//头部依次插入元素
	//SeqListPrint(&s);

	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);//头部依次删除元素
	//SeqListPrint(&s);

	SeqListInsert(&s, 1, 5);
	SeqListInsert(&s, 1, 6);//向指定位置插入元素
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListErase(&s, 1);//把指定位置元素删除
	SeqListPrint(&s);

	printf("这个元素是存在的它的下表是%d\n", SeqListFindvalue_Bind(&s, 0));//使用二分查找某个元素并输出

}


int main()
{
	Test1();
	return 0;
}