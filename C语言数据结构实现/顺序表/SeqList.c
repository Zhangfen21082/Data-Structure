#include "Seqlist.h"


void Seqlistinit(Seqlist* ps)
{
	ps->arr = (Seqlist*)malloc(sizeof(SLDataType) * 4);
	ps->length = -1;
	ps->size = 4;

}
void Seqlistdestory(Seqlist* ps)
{
	ps->length = 0;
	ps->size = 0;
	free(ps);
	ps = NULL;
}
void Seqlistprint(Seqlist* ps)
{
	for (int i = 0; i <= ps->length; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");

}
void SeqlistisFull(Seqlist* ps)
{
	assert(ps);
	if (ps->length + 1 == ps->size)
	{
		ps->size *= 2;
		ps->arr = realloc(ps->arr, sizeof(SLDataType)*ps->size);
	}


}
void SeqlistpushBack(Seqlist* ps, SLDataType x)
{
	assert(ps);
	SeqlistisFull(ps);
	ps->arr[ps->length + 1] = x;
	ps->length += 1;
}
void SeqlistpopBack(Seqlist* ps)
{
	assert(ps);
	assert(ps->length);
	ps->length -= 1;
}
void SeqlistpushFront(Seqlist* ps, SLDataType x)
{
	assert(ps);
	SeqlistisFull(ps);
	for (int i = ps->length; i >= 0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->length += 1;

}
void SeqlistpopFront(Seqlist*ps)
{
	assert(ps);
	assert(ps->length);
	for (int i = 0; i < ps->length; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->length -= 1;
}
void SeqlistFind(Seqlist* ps, SLDataType x)
{
	assert(ps);
	assert(ps->length);
	int i = 0;
	for (i = 0; i <= ps->length; i++)
	{
		if (ps->arr[i] == x)
		{
			printf("元素%d的下标为%d", ps->arr[i], i);
			break;
		}
	}
	if (i > ps->length)
	{
		printf("未找到");
	}
}
void Seqlistinsert(Seqlist* ps, int pos, SLDataType x)
{
	assert(ps);
	SeqlistisFull(ps);
	for (int i = ps->length; i >= pos-1; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos-1] = x;
	ps->length += 1;
}
void Seqlistdelete(Seqlist* ps, int pos)
{
	assert(ps);
	assert(ps->length);
	for (int i = pos - 1; i < ps->length; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->length -= 1;

}