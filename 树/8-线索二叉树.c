#include <stdio.h>

////////////////线索二叉树系统总描述/////////////
/*
	二叉树在遍历之后就有了确定的序列，可以看做是它变成了一种线性结构，但是二叉树在实际遍历的
	过程中我们发现，有些步骤其实是重复繁琐的，就是在其空指针的位置处。所以如果能够很好的利用
	好的空指针，让其空指针直接指向它的前驱或者是后继，岂不是能有很大的效率？所以我们把确定二叉树的
	前后关系的过程叫做二叉树的线索化
	线索化后，二叉树的每个结点就有了明确的前后件关系，它就不是一种树形结构了，而是线性的了
*/
///////////////线索二叉树存储结构////////////////
/*
	之前二叉树的存储结构显然是不能描述线索二叉树的逻辑结构，因为线索二叉树它的指针有时指向的是
	其孩子，有时指向的是其前驱或后继，这样的话就极易造成混乱
	所以在其基础上，我们增加两个标签，如果标签为0表示指向孩子，如果标签为1表示指向前驱或后继

*/
typedef struct TBTNode
{
	int data;
	int lTag;
	int rTag;
	TBTNode* lChirld;
	TBTNode* rChirld;
}TBTNode;
//////////////中序线索二叉树////////////////////////
//1:如何线索化
/*
	【我们知道】：中序遍历是遍历指针第二次指向某结点时再访问的操作。
	【具体来说】：在第二次访问到某个结点B时，其前面的结点A如果被访问过并且右指针为空，表示A是B的前驱，
	将A的右指针连到B即可。依次类推，若发现某节点是其前驱，则将左结点拉过去
	【总之】：每当访问一个结点的时候，如果当前结点左指针为空，就把其左指针规定为线索，指向其前驱结点；
	如果其前驱结点的右指针为空，就把其规定为线索，指向当前访问的结点
*/
//2:代码实现
/*
	此过程是递归实现，由于比较抽象，所以不好描述。这里只能大概说出一种想法，具体还需要仔细体会
	首先整体是中序遍历的递归，中间部分以前是访问操作，现在只是被换成了连接线索操作。pre一直跟在
	p的后面，
*/
void inThread(TBTNode* p, TBTNode* pre)
{
	if (p != NULL)
	{
		inThread(p->lChirld, pre);
		if (p->lChirld == NULL)
		{
			p->lChirld == pre;
			p->lTag = 1;
		}
		if (pre != NULL && pre->rChirld == NULL)
		{
			pre->rChirld = p;
			pre->rTag = 1;
		}
		pre = p;
		inThread(p->rChirld, pre);
	}

}



//////////////////////前序线索二叉树///////////////////////////////////
//1:代码实现
void preThread(TBTNode*p, TBTNode* pre)
{
	if (p != NULL)
	{
		if (p->lChirld == NULL)
		{
			p->lChirld = pre;
			p->lTag = 1;
		}
		if (pre != NULL & pre->rChirld == NULL)
		{
			pre->rChirld = p;
			pre->rTag = 1;
		}
		pre = p;
		if (p->lTag == 0)//这里的两个判断是保证，进入递归的不是线索，而是它的孩子，不然它就成了死循环了
			preThread(p->lChirld, pre);
		if (p->lChirld == 0)
			preThread(p->rChirld, pre);
	}

}
//2:如何在前序线索二叉树上执行前序遍历
/*
	对于前序遍历，第一个节点就是根节点；如果一个结点的左指针不空且不是线索，那左指针就指向后继，如果是线索就指向其前驱
	如果一个结点左指针空但右指针不空，那么不管右指针是什么，它指向的都是后继
*/
void preOrder(TBTNode* tbt)//传入根节点
{
	if (tbt != NULL)
	{
		TBTNode* p = tbt;//创建扫描指针
		while (p != NULL)
		{
			while (p->lTag == 0)//当扫描的结点左指针不是线索时，就是其左孩子，那么访问该节点后移动到左孩子
			{
				visit(p);
				p = p->lChirld;
			}
			visit(p);//如果跳出循环，表明其指针是线索，此指针指向的是其前驱，故访问该节点后跳过左指针，直接访问右指针，右指针不管是孩子还是结点反正都是其后继
			p = p->rChirld;
		}
	}

}


/////////////////////////后序线索二叉树//////////////////////////////////
//1:代码实现
void postThread(TBTNode*p, TBTNode* pre)
{
	if (p != NULL)
	{
		postThread(p->lChirld, pre);
		postThread(p->rChirld, pre);
		if (p->lChirld == NULL)
		{
			p->lChirld = pre;
			p->lTag = 1;
		}
		if (pre != NULL && pre->rChirld == NULL)
		{
			pre->rChirld = p;
			pre->rTag = 1;
		}
		pre = p;
	}
}
