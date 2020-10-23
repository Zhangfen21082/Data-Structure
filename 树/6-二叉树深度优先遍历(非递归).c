#include <stdio.h>
#define maxSize 100

typedef struct BTNode
{
	char data;
	struct BTNode* lchirld;
	struct BTNode* rchirld;
}BTNode;

////////////////先序遍历非递归化////////////////////
//1:实现方法
/*
	从根节点开始入栈元素，然后出根节点并访问，接着将根节点的两个孩子都入栈，右孩子先入栈，左孩子后
	入栈，接着再出栈并访问，然后把它的左右孩子按照上述规则入栈，重复之前的操作，需要注意的时，在入栈
	元素前要判断其是否为叶子结点，如果是叶子结点，则不需要入左右孩子即可
*/
//2:代码实现
void preorderNonrecursion(BTNode* bt)//导入二叉树根节点
{
	if (bt != NULL)//首先判断是否为空树
	{
		BTNode* stack[maxSize];//入栈时无需实际把元素压入栈中，只需压入地址。这里创建的是一个指针数组，数组内的所有元素是BTNode*的指针
		int top = -1;
		BTNode* p = NULL;//用于遍历的指针

		stack[++top] = bt;//入根结点，注意这里入的是地址

		while (top != -1)//栈不空则不停
		{
			p = stack[top--];//出来一个元素
			visit(p);
			if (p->rchirld != NULL)//如果不是叶子结点，先入右孩子，再入左孩子
				stack[++top] = p->rchirld;
			if (p->lchirld != NULL)
				stack[++top]=p->lchirld;
		}

	}

}

////////////////后序遍历非递归化////////////////////
//1:实现方法
/*
	对于一颗二叉树，逆后序就是将其后序遍历倒着写，而逆后序和前序的差别就在于：前序是根左右，逆后序是根右左
	所以我们根据前序遍历推导出逆后序，然后再将逆后序压入栈中，出栈就是后序遍历
*/
//2:代码实现
void postorderNonrecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* stack1[maxSize];//用于遍历的栈
		int top1 = -1;
		BTNode* stack2[maxSize];//用于将逆后序转为后序的栈
		int top2 = -2;
		BTNode* p = NULL;

		stack1[++top1] = bt;
		while (top1 != -1)
		{
			p = stack1[top1--];
			stack2[++top2] = p;//从stack1出栈的元素是逆后序，直接入Stack2，出来之后就是后序了

			if (p->lchirld != NULL)//先入左孩子，再入右孩子
				stack1[++top1] = p->lchirld;
			if (p->rchirld != NULL)
				stack1[++top1] = p->rchirld;
		}

		while (top2 != -1)//将逆后序的栈的元素依次出栈访问，就是后序
		{
			p = stack2[top2--];
			visit(p);
		}
	}
}


////////////////中序遍历非递归化////////////////////
//1:实现方法
/*
	从根节点开始，一直往左走，走到不能走为止，途径结点全部入栈
	然后出栈一个结点并访问，然后下一个结点往右走，重复上述过程
*/
//2:代码实现
void inorderNonrecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* stack[maxSize];
		int top = -1;
		BTNode* p = bt;//从根节点开始入栈

		while (top != -1 || p != NULL)
		{
			while (p != NULL)//从根节点开始，往左走，途径全部入栈
			{
				stack[++top] = p;
				p = p->lchirld;
			}
			if (top != -1)//出栈一个元素，拿出一个右孩子，返回循环，继续判断这个右孩子是否有这样的左孩子，有的话一直把所有左孩子入下去
			{
				p = stack[top--];
				visit(p);
				p = p->rchirld;
			}
		}
	}
}