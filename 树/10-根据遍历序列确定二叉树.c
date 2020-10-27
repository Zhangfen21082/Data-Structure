#include <stdio.h>
#include <malloc.h>


typedef struct BTNode
{
	char data;
	struct BTNode *lchirld;
	struct BTNode *rchurld;
}BTNode;
//由先序遍历和中序遍历序列确定二叉树
BTNode* CreatBT(char pre[], char in[], int L1, int R1, int L2, int R2)
{
	//参数说明：pre和in分别表示先序遍历序列和前序遍历序列
	//		   L1和R1代表当前操作的pre数组的元素所在的下标范围为从L1到R1
	//		   L2和R2代表当前操作的pre数组的元素所在的下标范围为从L2到R2
	if (L1 > R1)//递归出口，序列长度为0
		return NULL;//此树为空
	BTNode* s = (BTNode *)malloc(sizeof(BTNode));//为此树(子树)根节点申请空间,
	s->lchirld = s->rchurld = NULL;
	s->data = pre[L1];//此时根节点存在pre数组的L1

	//s->data=pre[L1]就链接了，每次进入递归它申请的是这个进入循环的子树的根节点，而这个根节点就是上一递归s->lchirld或s->rchirld
	int i;
	for (i = L2; i <= R2; ++i)
		if (in[i] == pre[L1])//如果中序遍历中的某个节点等于pre[L1]意味找到了根节点（在遍历中此根节点就是其子树的根节点）
			break;
	s->lchirld = CreatBT(pre, in, L1 + 1, L1 + i - L2, L2, i - 1);//关于这个递归的参数需要重点说明，见笔记。
	s->rchurld = CreatBT(pre, in, L1 + 1 - L2 + 1, R1, i + 1, R2);//关于这个递归的参数需要重点说明，见笔记。
	return s;

}
//由后序遍历和中序遍历确定二叉树
BTNode *CreatBT2(char post[], char in[], int L1, int R1, int L2, int R2)
{
	if (L1 > R1)
		return NULL;
	BTNode *s = (BTNode *)malloc(sizeof(BTNode));
	s->lchirld = s->rchurld = NULL;
	s->data = post[R1];//后序遍历时，其最后一个保存的是根节点

	int i;
	for (int i = L2; i <= R2; ++i)
		if (in[i] = post[R1])
			break;
	s->lchirld = CreatBT2(post, in, L1, L1 + i - L2 - 1, L2, i - 1);//和上面一样
	s->rchurld = CreatBT2(post, in, L1 + i - L2, R1 - 1, i + 1, R2);
	return s;
}


//由层次遍历和中序遍历确定二叉树
/*
	在先序遍历中，由中序遍历确定根节点后，根节点就将所有结点划分左右子树，而这个左右子树在先序遍历是连续的两部分，但是
	在层次遍历中，这两部分是分开的
*/

struct S//柔性数组
{
	int n;
	char arr[0];

};

int serach(char arr[], char key, int L, int R)//arr就是中序遍历，key就是层次遍历的树（子树）根节点
{
	int idx;
	for (idx = L; idx <= R; ++idx)//从L到R的范围内查找根节点
	{
		if (arr[idx] == key)
			return idx;//返回根节点在中序遍历中的下标
	}
	return -1;

}
void getSubLevel(char subLevel[], char level[], char in[], int n, int L, int R)//subLevel就是新建好的数组，n是其长度，in是由L和R所确定的中序遍历也即左右子树
{
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (search(in, level[i], L, R) != -1)//拿出层次遍历（Level）的每个结点，依次与中序遍历(int)比较，若是，则将层次遍历(Level)的元素放入新建好的数组(sublevel)
			subLevel[k++] = level[i];
	}


}

BTNode* CreateBT3(char level[], char in[], int n, int L, int R)
/*
	1：char level[]：由中序遍历在层次遍历中划分出的范围，左右子树相交，所以划出范围后，把所有子树放置到该数组里
	2：n：是层次遍历的元素个数
	3：char in[]：中序遍历
	4:：L和R用于控制中序遍历范围
*/
{
	if (L > R)
		return NULL;

	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->lchirld = s->rchurld = NULL;
	s->data = level[0];


	int i = search(in, level[0], L, R);//在中序遍历中找出根节点的位置
	int LN = i - L;//拿到根节点的位置后，中序遍历L-i自然是左子树的范围，那么左子树长度就是LN
	struct S* LeftArrTre = (struct S*)malloc(sizeof(struct S) + LN * sizeof(char));//使用柔性数组的方式，建立一个左子树数组
	int RN = R - i;//拿到根节点的位置后，，中序遍历i-L自然是右子树的范围，那么右子树长度就是RN
	struct S* RightArrTre = (struct S*)malloc(sizeof(struct S) + RN * sizeof(char));//使用柔性数组的方式，建立一个右子树数组

	getSubLevel(LeftArrTre->arr, level, in, n, L, i - 1);//现在左子树在中序遍历范围为L-i-1，而这部分左子树在层次遍历中是散落的，所以以中序遍历的左子树为标准，在层次遍历中找所有的左子树，并放置到刚刚新建好的数组中
	getSubLevel(RightArrTre->arr, level, in, n, i+1, R);////现在右子树在中序遍历范围i+1-R，而这部分右子树在层次遍历中是散落的，所以以中序遍历的右子树为标准，在层次遍历中找所有的右子树，并放置到刚刚新建好的数组中

	s->lchirld = CreateBT3(LeftArrTre->arr, in, LN, L, i - 1);//现在就将层次遍历的左分开了，这个左子树和新的中序遍历将再一次进入循环，进行如上操作
	s->lchirld = CreateBT3(RightArrTre->arr, in, LN, i + 1, R);//现在就将层次遍历的左分开了，这个左子树和新的中序遍历将再一次进入循环，进行如上操作

	return s;
}