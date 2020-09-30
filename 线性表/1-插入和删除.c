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

//**************单链表***************



//**************双链表*****************


//**************顺序表*****************
//插入
//1：可插入下标位置取值范围：0-length；
//2：当length=数组长度时，不可再插入元素
//3：移动元素从后往前进行

int inseretElem(Sqlist L, int p, int e)//p表示插入位置，e表示插入的数据
{
	if (p<0 || p>L.length|| L.length == maxSize)//如果插入位置小于0或大于顺序表长度或顺序表已经满了
		return 0;//返回错误
	for (int i = L.length - 1; i >= p; --i)//否则，元素从最后一个到p位置开始后移，把p位置腾出来
		L.data[i + 1] = L.data[i];
	L.data[p] = e;//p位置放e元素
	++L.length;//同时长度+1
	return 1;

}

//删除
//1：可删除元素下标的p的取值范围为：0-length-1；
//2：当表长length=0的时候，不可再删除元素；
//3：移动元素从前往后进行

int deleteElem(Sqlist L, int p, int e)//p表示删除位置，e用来接受删除的元素(注意引用型)
{
	if (p<0 || p>L.length - 1)//失败中length=0也是不能删除的，但是这种情况已经包含其中了
		return 0;//返回错误
	e = L.data[p];//先把那个元素拿出来
	for (int i = p; i < L.length - 1; ++i)//从这个元素到最后一个元素，全部往前移
		L.data[i] = L.data[i + 1];
	--L.length;//同时长度-1
	return 1;

}
