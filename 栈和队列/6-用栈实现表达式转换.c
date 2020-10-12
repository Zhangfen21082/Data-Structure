#include <stdio.h>
#define maxSize 100
typedef struct
{
	char data[maxSize];
	int top;
}Sqstack;
int getPriority(char op)//判断运算符优先级
{
	if (op == '+' || op == '-')
		return 0;
	else
		return 1;
}
/////////////中缀式转后缀式/////////////////
//1:转换规则
/*
	从左向右扫描中缀式，遇到操作数直接写出来，如果遇到运算符就入栈。
	入栈之前，首先拿扫描到的这个运算符与栈顶运算符比较，如果当前扫描到的运算符的优先级小于
	栈顶运算符，那么就将栈顶运算符出栈，并将这个运算符写入表达式中，当然这个过程是多次，如果此次
	栈顶运算符出栈了，那么当前扫描到的运算符还要和下一个栈顶运算符比较，若还是小于等于，那么继续
	出栈，这样一直下去，直到扫描到的运算符优先级大于栈顶元素，则将扫描到的运算符入栈，注意栈空直接入栈；
	如果扫描时遇到了"("，直接入栈，如果扫描到了")"，进行出栈操作，将栈顶到"("的元素全部出栈,并写入表达式中，
	（出栈的括号全部扔掉）。扫描完中缀式后，若栈中还有剩余运算符，将其全部出栈，并写入表达式即可
*/
//2:代码实现
void infixToPostFix(char infix[], Sqstack* s1, Sqstack* s2)//s2是结果栈（就是咋们说的那个遇到到操作数写出来）,s1是辅助栈（就是咋们说要把操作符入栈然后进行优先级比较，再出栈）
{
	s1->top = -1;
	s2->top = -1;//初始化栈
	int i = 0;

	while (infix[i] != '\0')//从左向右扫描表达式，直到结束
	{
		if ('0' <= infix[i] && infix[i] <= '9')//如果扫描到了操作数，直接进入结果栈
		{
			s2->top += 1;//先移动栈顶指针
			s2->data[s2->top] = infix[i];//再入栈
			++i;
		}
		else if (infix[i] == '(')//如果扫描到了'('直接进入辅助栈
		{
			s1->top += 1;
			s1->data[s1->top] == '(';
			++i;
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')//如果遇到了运算符那么就要进行一定判断
		{
			if (s1->top == -1 || s1->data[s1->top] == '(' || getPriority(infix[i]) > getPriority(s1->data[s1->top]))//如果辅助栈空，或者辅助栈栈顶元素是“（”，又或是扫描到的运算符优先级大于栈顶运算符，那么该运算符继续进入辅助栈
			{
				s1->top += 1;
				s1->data[s1->top] = infix[i];
				++i;//这里i要后移一位，这一位入了辅助栈，下一位还要判断呢
			}
			else//否则就把辅助栈的这个运算符出栈，入结果栈（也就是写到表达式里）
			{
				s2->top += 1;
				s2->data[s2->top] = s1->data[s1->top];
				s1->top -= 1;
			}
		}
		else if (infix[i] == ')')//然后就是遇到“)”的情况
		{
			while (s1->data[s1->top] != '(')//遇到")"时，把")"到第一个"("之间的元素，除了"("全部入结果栈
			{
				s2->top += 1;
				s2->data[s2->top] = s1->data[s1->top];
				s1->top -= 1;
			}
			s1->top -= 1;//这里注意不要忘了，上一个循环结束后，辅助栈栈顶指针还指向"("呢，"("不入结果栈，所以要把它“删了”，也就是栈顶指针减1
			++i;
		}
	}
	while (s1->top != -1)//表达式扫描完后，如果辅助栈还有运算符，就把剩余的全部入了结果栈
	{
		s2->top += 1;
		s2->data[s2->top] = s1->data[s1->top];
		s1->top -= 1;
	}

}



/////////////中缀式转前缀式/////////////////////////
//1:转换规则
/*
	几乎和转后缀式是相反的过程
	从右往左扫描，遇到右括号入栈，遇到左括号出栈，写表达式的时候从右往左写，比较时扫描到的运算符如果小于
	栈顶运算符，将栈顶元素出栈。
*/
//2:代码实现
void infixToPostFix(char infix[], Sqstack* s1, Sqstack* s2)//s2是结果栈（就是咋们说的那个遇到到操作数写出来）,s1是辅助栈（就是咋们说要把操作符入栈然后进行优先级比较，再出栈）
{
	s1->top = -1;
	s2->top = -1;
	int i =(sizeof(infix)/sizeof(infix[0]))-1;//从后往前扫描

	while (i>=0)//改动
	{
		if ('0' <= infix[i] && infix[i] <= '9')
		{
			s2->top += 1;
			s2->data[s2->top] = infix[i];
			--i;//改动
		}
		else if (infix[i] == ')')//改动：遇到")"入栈
		{
			s1->top += 1;
			s1->data[s1->top] == ')';//改动
			--i;//改动
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			if (s1->top == -1 || s1->data[s1->top] == '）' || getPriority(infix[i]) >= getPriority(s1->data[s1->top]))//改动
			{
				s1->top += 1;
				s1->data[s1->top] = infix[i];
				--i;//改动
			}
			else
			{
				s2->top += 1;
				s2->data[s2->top] = s1->data[s1->top];
				s1->top -= 1;
			}
		}
		else if (infix[i] == '(')//改动
		{
			while (s1->data[s1->top] != ')')//改动
			{
				s2->top += 1;
				s2->data[s2->top] = s1->data[s1->top];
				s1->top -= 1;
			}
			s1->top -= 1;
			--i;//改动
		}
	}
	while (s1->top != -1)
	{
		s2->top += 1;
		s2->data[s2->top] = s1->data[s1->top];
		s1->top -= 1;
	}

}




////////////后缀式转前缀式/////////////////////////////
//1：转换规则
/*
	这个和咋们上一节说过的手工后缀转前缀的过程其实是一致的
	扫描时，遇到操作数入栈，遇到运算符把前面入栈的两个操作数组合到一起（注意先出来的在右面后出来的在左面）
	，然后重新入栈，以此类推


*/
