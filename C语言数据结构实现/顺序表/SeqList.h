#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* Array;
	int Size;//��Ч���ݸ���
	int Capacity;//������С
}SeqList;

void SeqListInit(SeqList* ps);//��ʼ��
void SeqListPrint(SeqList* ps);//��Ļ�������
void SeqListCheckCapacity(SeqList* ps);//��������Ƿ�����


void SeqListPushBack(SeqList* ps, SLDataType x);//β��
void SeqListPopBack(SeqList* ps);//βɾ��
void SeqListPushFront(SeqList* ps, SLDataType x);//ͷ��
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListInsert(SeqList* ps, int pos, SLDataType x);//����λ�ò���
void SeqListErase(SeqList* ps, int pos);//����λ��ɾ��

int  SeqListFindvalue_Bind(SeqList* ps, int pos);//ʹ�ö��ֲ��ҷ�����ĳ��Ԫ�ص�λ��