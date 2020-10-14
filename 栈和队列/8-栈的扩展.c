#include <stdio.h>
#define maxSize 100


////////////共享栈///////////////////
//:基本描述
/*
	两个栈共享一片存储空间，此存储空间不单独属于任何一个栈，各个栈对空间按需索取
	两个栈顶指针分别在两端，入栈时栈顶指针相向而行
*/
//定义
void bulidstack()
{
	int stack[maxSize];
	int top1 = -1;
	int top2 = maxSize;
}

//栈空与栈满
//top[0]==-1时s1空，top[1]==maxSize时s2空
//top[0]+1==top[1]时栈满

//入栈
void enstack()
{
	//stack[++top[0]] = x;  s1入栈
	//srack[--top[1]] = x;  s2入栈
}
///////////////用栈模拟队列////////////
//1:基本描述
/*
	队列的特点是先进先出，要用栈来模拟队列，就需要准备两个栈s1，s2
*/
//入"队"规则
/*
	若s1没有满，则元素直接入s1
	若1满了，s2空着，则将s1中元素全部出栈入s2，腾出位置后，再入s1
*/
//出"队"规则
/*
	若s2不空，则从s2直接出栈
	若s2空，则将s1中元素全部出栈入s2，然后从s2中出栈
*/
//队满:s1满且s2不空，则不能继续入队，视为队满状态
//队空:s1空且s2空，视为队空状态