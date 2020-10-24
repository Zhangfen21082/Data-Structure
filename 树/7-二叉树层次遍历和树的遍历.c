#include <stdio.h>
#define maxSize 100

typedef struct BTNode
{
	char data;
	struct BTNode* lchirld;
	struct BTNode* rchirld;
}BTNode;




////////////////二叉树层次遍历(广度优先)///////////////////////
//1:实现方法
/*
	以这样一个二叉树为例---第一层1个，第二层2个，第三层4个，分别按照顺序命名为A,B,C,D,E,F,G
	首先A先入队，接着A出队，判断A的左右孩子B和C存在，将B和C入队，再将B出队，判断B的左右孩子D,E存在，
	将其入队，再将C出队，判断C的左右孩子F和G存在，将F和G入队，出队D和E，出队F和G
*/
//2:代码实现
void level(BTNode* bt)
{
	if (bt != NULL)
	{
		int front, rear;//创建一个队列
		BTNode* queue[maxSize];//仍然是一样，这个队列不需要真正入元素，只需保存地址
		front = rear = 0;//队列初始化
		BTNode* p;//创建遍历指针

		rear = (rear + 1) % maxSize;
		queue[rear] = bt;//先入队头结点
		while (front != rear)
		{
			front = (front + 1) % maxSize;//再出队结点(头结点)
			p = queue[front];
			visit(p);
			if (p->lchirld != NULL)//判断这个节点的左右孩子情况，有则入队列
			{
				rear = (rear + 1) % maxSize;
				queue[rear] = p->lchirld;
			}
			if (p->rchirld != NULL)
			{
				rear = (rear + 1) % maxSize;
				queue[rear] = p->rchirld;
			}
		}
	}


}