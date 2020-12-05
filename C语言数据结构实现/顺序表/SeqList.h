#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* Array;
	int Size;//有效数据个数
	int Capacity;//容量大小
}SeqList;

void SeqListInit(SeqList* ps);//初始化
void SeqListDestory(SeqList* ps);//销毁

void SeqListPrint(SeqList* ps);//屏幕输出操作
void SeqListCheckCapacity(SeqList* ps);//检查容量是否满了


void SeqListPushBack(SeqList* ps, SLDataType x);//尾插（可以与任意位置插入复用）
void SeqListPopBack(SeqList* ps);//尾删除（可以与任意位置删除复用）
void SeqListPushFront(SeqList* ps, SLDataType x);//头插（可以与任意位置插入复用）
void SeqListPopFront(SeqList* ps);//头删（可以与任意位置删除复用）
void SeqListInsert(SeqList* ps, int pos, SLDataType x);//任意位置插入
void SeqListErase(SeqList* ps, int pos);//任意位置删除

int  SeqListFind(SeqList* ps, SLDataType x);//使用顺序查找法查找某个元素的位置
int  SeqListFindvalue_Bind(SeqList* ps, int pos);//使用二分查找法查找某个元素的位置