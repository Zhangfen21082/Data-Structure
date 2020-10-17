#include <stdio.h>
#define maxSize 100

typedef struct
{
	char data[maxSize];
	int top;
}Sqstack;

///////////////////括号匹配问题///////////////////
//1:基本描述
/*
  1.1:括号匹配和不匹配
	匹配的情况如：()[]{}，{[()]},([])
	不匹配的情况如：()[]{   )[]{}   [(])
  1.2:括号匹配监测问题
	此过程需要使用到一个栈，从左向右扫描表达式，遇到"("就入栈，遇到")"就出栈。若栈空，则出栈操作不成功
	就判断为不匹配（比如上面不匹配情况的第二种）；如果可以出栈，监测刚出栈的括号和扫描到的括号，如果两者
	匹配则继续扫描，否则判断为不匹配(比如上面不匹配情况的第三种)；如此进行下去，待到整个表达式扫描完毕，
	若栈中还有括号为不匹配（比如不匹配情况的第一种），若栈空，则匹配。
*/
//2：代码实现
int isMatched(char left, char right)//判读括号是否匹配
{
	if (left == '('&&right == ')')
		return 1;
	else if (left == '['&&right == ']')
		return 1;
	else if (left == '{'&&right == '}')
		return 1;
	else
		return 0;
}
int isParenthesesBalanced(char exp[],Sqstack* s1)
{
	s1->top = -1;

	for (int i = 0; exp[i] != '\0'; ++i)//从左向右扫描表达式
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')//如果遇到左括号直接进栈
		{
			s1->top += 1;
			s1->data[s1->top] = exp[i];
		}
		if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')//如果遇到右括号准备出栈
		{
			if (s1->top = -1)//首先如果是栈空，直接判断为不匹配
				return 0;

			char left = s1->data[s1->top];//栈不空，则取栈顶元素
			s1->top -= 1;
			if (isMatched(left, exp[i]) == 0)//拿栈顶元素和扫描到的右括号比较，isMatched函数返回0则表示不匹配，一个不匹配，整个不匹配，结束判断
				return 0;
		}
	}
	if (s1->top > -1)//扫描完之后，如果栈中还有元素，不匹配
		return 0;
	return 1;//能够执行到这儿，说明就是匹配的


}
/////////////计算问题//////////////////
//1:基本描述
/*
	对于A4纸上写出的这个递推式，可以用栈来实现，因为递归的内部其实就是栈
*/