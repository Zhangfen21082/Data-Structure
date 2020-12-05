#include "SeqList.h"

void SeqListInit(SeqList* ps)//初始化
{
	/*也可以这样申请
	s.Size = 0;
	s.Array = NULL;
	s.Capacity = 0;
	*/
	ps->Array = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->Array == NULL)
	{
		printf("申请失败\n");
		exit(-1);
	}
	ps->Size = 0;
	ps->Capacity = 4;
}
void SeqListDestory(SeqList* ps)//销毁
{
	free(ps->Array);
	ps = NULL;
	ps->Capacity = ps->Size = 0;
}
void SeqListPrint(SeqList* ps)//打印
{
	assert(ps);
	for (int i = 0; i < ps->Size; ++i)
	{
		printf("%d ", ps->Array[i]);
	}
	printf("\n");


}
void SeqListCheckCapacity(SeqList* ps)//检查容量是否满了
{
	if (ps->Size == ps->Capacity)
	{
		ps->Capacity *= 2;
		ps->Array = (SLDataType*)realloc(ps->Array, sizeof(SLDataType)*ps->Capacity);
		if (ps->Array == NULL)//扩容失败
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
	

}

void SeqListPushBack(SeqList* ps, SLDataType x)//尾插
{
	/*尾插就是size位置上的插入
	assert(ps);//警告，指针为空
	SeqListCheckCapacity(ps);//满了就扩容
	ps->Array[ps->Size] = x;//size表示有效个数，但同时是下一个元素的下标
	ps->Size++;//元素加1
	*/
	SeqListInsert(ps,ps->Size, x);
}
void SeqListPopBack(SeqList* ps)//尾删除
{
	assert(ps);
	ps->Size--;

}
void SeqListPushFront(SeqList* ps, SLDataType x)//头插
{
	/*头插是0位置上的插入
	assert(ps);
	SeqListCheckCapacity(ps);//满了就扩容
	for (int i = ps->Size-1; i >= 0; i--)//头插法：从最后一个元素开始，依次向后移，把0的位置空出来
	{
		ps->Array[i+1] = ps->Array[i];
	}
	ps->Array[0] = x;
	ps->Size++;
	*/
	SeqListInsert(ps, 0, x);

}
void SeqListPopFront(SeqList* ps)//头删
{
	/*头删是0位置的删除
	assert(ps);
	for (int i = 0; i < ps->Size; i++)
	{
		ps->Array[i] = ps->Array[i + 1];//删除时直接覆盖即可
	}
	ps->Size--;
	*/
	SeqListErase(ps, 0);
	

}
void SeqListInsert(SeqList* ps, int pos, SLDataType x)//任意位置插入
{
	assert(ps);
	assert(pos <= ps->Size && pos>= 0);//插入位置有误
	SeqListCheckCapacity(ps);
	for (int i = ps->Size - 1; i >= pos; i--)//从插入位置以后依次向后挪动
	{
		ps->Array[i + 1] = ps->Array[i];
	}
	ps->Array[pos] = x;
	ps->Size++;

}
void SeqListErase(SeqList* ps, int pos)//任意位置删除
{
	assert(ps);
	assert(pos < ps->Size && pos >= 0);//删除位置有误
	for (int i = pos; i < ps->Size; i++)
	{
		ps->Array[i] = ps->Array[i + 1];
	}
	ps->Size--;
}

int  SeqListFind(SeqList* ps, SLDataType x)//顺序查找法
{
	assert(ps);
	int i = 0;
	while (i<ps->Size)
	{
		if (ps->Array[i] == x)
			return i;
		++i;
	}
	return -1;


}
int  SeqListFindvalue_Bind(SeqList* ps, int pos)//二分查找法
{
	int low = 0;
	int high = ps->Size - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (pos < ps->Array[mid])
			high = mid - 1;
		else if (pos > ps->Array[mid])
			low = mid + 1;
		else
			return mid;
	}
}