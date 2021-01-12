#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int length;
	int size;
}Seqlist;



void Seqlistinit(Seqlist* ps);//初始化
void Seqlistdestory(Seqlist* ps);//销毁

void Seqlistprint(Seqlist* ps);//打印
void SeqlistisFull(Seqlist* ps);//增容

void SeqlistpushBack(Seqlist* ps, SLDataType x);//尾插
void SeqlistpopBack(Seqlist* ps);//尾删除
void SeqlistpushFront(Seqlist* ps, SLDataType x);//头插
void SeqlistpopFront(Seqlist*ps);//头删除

void SeqlistFind(Seqlist* ps, SLDataType x);//找元素

void Seqlistinsert(Seqlist* ps, int pos, SLDataType x);//任意位置插入
void Seqlistdelete(Seqlist* ps, int pos);//任意位置删除