#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SlistDataType;

//结点类型定义
typedef struct SlistNode
{
	SlistDataType data;//数据域
	struct SlistNode* next;//指向下一个结点的指针
}SlNode;

void SlistPushBack(SlNode* head,SlNode** tail, SlistDataType x);//尾插

//void SlistPushBack(SlNode** phead, SlistDataType x);//尾插
void SlistPopBack(SlNode* head);//尾删
void SlistPushFront(SlNode* head,SlistDataType x);//头插
void SlistPopFront(SlNode* head);//头删

void SlistPrint(SlNode* head);//打印

