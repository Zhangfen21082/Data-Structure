#include <stdio.h>

typedef struct BTNode
{
	char data;
	struct BTNode* lchirld;
	struct BTNode* rchirld;
}BTNode;

/////////二叉树深度优先遍历(递归)///////////
void r(BTNode* p)
{
	if (p != NULL)
	{
		//：访问代码放在这里是先序遍历
		r(p->lchirld);
		//：访问代码放在这里是中序遍历
		r(p->rchirld);
		//：访问代码放在这里是后序遍历
	}

}