#include <stdio.h>
#define maxSize 100
//顺序表归并

typedef struct
{
	int data[maxSize];
	int length;
}Sqlist;
//L1和L2为有序顺序表，按他们的顺序将其归并有序顺序表L
void mergearray(Sqlist L1, Sqlist L2, Sqlist L)
{
	int i = 0;//用来跟随L1的下标
	int j = 0;//用来跟随L2的下标
	int k = 0;//用来跟随L的下标

	while (i < L1.length && j < L2.length)//跟踪时i和j分别指向L2和L2的第一个元素，然后对应比较
	{
		if (L1.data[i] < L2.data[i])//如果L1的元素小于L2的，那么把L1的那个元素放进去
		{
			L.data[k] = L1.data[i];
			k++;
			i++;
		}
		else//如果L2的元素小于L1的，那么把L2的那个元素放进去
		{
			L.data[k] = L2.data[j];
			k++;
			j++;
		}
	}
	while (i < L1.length)//扫描到最后，发现L1没有被扫描完，说明L1短，则把L1剩余元素放到L中去
	{
		L.data[k] =L1.data[i];
		k++;
		i++;
	}
	while (j < L2.length)//扫描到最后，发现L2没有被扫描完，说明L2短，则把L2剩余元素放到L中去
	{
		L.data[k] = L2.data[j];
		k++;
		j++;
	}
	L.length = L1.length + L2.length;//归并后的表长等于两者之和
}


//链表归并
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
//链表归并1:正常归并
void merge(LNode* A, LNode* B, LNode* C)//A,B是待归并链表的头结点，C是新链表的头结点
{
	LNode* p = A->next;
	LNode* q = B->next;//p和q分别指向两个链表的第一个元素
	LNode* r;//r指针始终指向新链表尾节点
	C = A;//直接把A的头结点当作C的头结点
	C->next = NULL;
	free(B);//B不用了，释放
	r = C;//r始终指向尾节点

	while (p != NULL && q != NULL)//p和q同时扫描两个链表，两者都没有扫描至各自末尾时，就一直扫描
	{
		if (p->data <= q->data)//如果p指针所指数据小于q指针所指数据
		{
			r->next = p;//那么新链表后面接上p
			p = p->next;//p就向后移动，看下一个p所指数据和q的大小情况
			r = r->next;//新链表增加了一个元素，r指针后移
		}
		else
		{
			r->next = q;
			q=q->next;
			r = r->next;
		}
	}
	if (p != NULL)//如果p所指不空，说明p所指链表较长，那么就把剩余的一次性归并到新链表后面
		r->next = p;
	if (q != NULL)//如果q所指不空，说明q所指链表较长，那么就把剩余的一次性归并到新链表后面
		r->next = q;
}
//链表归并2：逆序归并
void mergeR(LNode* A, LNode* B, LNode* C)
{
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* s;//这个s节点相当于中转站，比较的过程找到p或q最小，就让s代替他们完成插入操作，因为p和q指针不能丢失
	C = A;
	C->next = NULL;
	free(B);

	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			s = p;//为了不使p结点丢失，先把p结点复制一份给s，让s完成插入操作
			p = p->next;//p后移一位，进行下一轮比较
			s->next = C->next;//属于头插法
			C->next = s;//以上两句将结点插入到了头结点的后面
		}
		else
		{
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}
	while(p != NULL)//由于是逆序，一个一个要插入到头结点后面，所以不像第一种插入那样一次性拿过来
	{
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q!=NULL)
	{
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}

}