#include <stdio.h>
#include <math.h>
#define maxSize 100
#define MIN 0.00000001

typedef struct
{
	float data[maxSize];//用来定义操作数栈，操作数用float型
	int top;
}Sqstack1;
typedef struct
{
	char data[maxSize];//用来定义运算符栈，运算符用char型   Z X去
	int top;
}Sqstack2;

int getPriority(char op)//判断运算符优先级
{
	if (op == '+' || op == '-')
		return 0;
	else
		return 1;
}
int calSub(float opand1, char op, float opand2, float* result)//两个操作数求值,注意操作数是float型，C++中要用引用型。flaot &result
{
	if (op == '+') *result = opand1 + opand2;
	if (op == '-') *result = opand1 - opand2;
	if (op == '*') *result = opand1 * opand2;//加减乘没有什么大的问题
	if (op == '/')//对于除法，要判断其分母不能为0
	{
		if (fabs(opand2 < MIN))//使用fabs求两数的绝对值，这是判断分母为0的标准写法，MIN为预先定义的一个很小的数
			return 0;//分母为0，返回失败
		else
			*result = opand1 / opand2;
	}
	return 1;

}
int calSubTopTwo(Sqstack1* s1, Sqstack2* s2)
{
	float opnd1, opnd2, result;//opnd1和opnd2用来接受出栈的操作数，result用来接收函数的返回值
	char op;//op用来接受出栈的运算符
	int flag;//由于分母可能会有0的情况，用flag判断计算是否成功
	
	opnd2 = s1->data[s1->top];//先出栈的为右操作数
	s1->top -= 1;
	opnd1 = s1->data[s1->top];//后出栈的为左操作数
	s1->top -= 1;
	op = s2->data[s2->top];//弹出运算符
	s2->top -= 1;
	flag = calSub(opnd1, op, opnd2, &result);//用flag接受成功情况
	if (flag == 0)
	{
		printf("ERROR");//如果flag为0,错误
	}


	s1->top += 1;
	s1->data[s1->top] = result;//如果正常，则把结果入操作数栈
	return flag;//返回flag
}


////////////用栈求中缀表达式///////////
/*
1:规则
	准备两个栈，一个暂存操作数，另一个暂存运算符。从左到右，扫描表达式，遇到操作数就入操作数栈，遇到"("
	就入运算符栈。当遇到运算符时，若运算符栈空，或运算符栈顶元素为"("，则运算符直接入运算符栈，如果运算符栈
	不空且栈顶元素不是"("，此时若扫描到的运算符的优先级大于运算符栈栈顶运算符优先级，则入栈，否则对运算符栈
	不断执行出栈操作，每出栈一个运算符，操作数栈就出栈两个操作数，这两个操作数与该运算符进行运算(第一次出栈的
	在右面，第二次出栈的在左面)，并将结果入操作数栈，直到扫描到的运算符优先级大于运算符栈顶运算符优先级；如果遇到
	")"，就将运算符栈顶到"("号的所有元素出栈，并对每一个出栈的运算符做一次上述运算。最后，当整个中缀表达式
	扫描完之后，运算符栈依然有运算符的话，那就把每一个运算符出栈，并对每一个出栈的运算符进行上述运算。
	最后s1栈顶即为表达式结果。

*/
//2:代码
float calInfix(char exp[],Sqstack1* s1,Sqstack2* s2)//exp为表达式,s1为操作数栈，s2位运算符栈
{
	s1->top = -1;
	s2->top = -1;//初始化栈
	int i = 0;

	while (exp[i] != '\0')//从左向有扫描中缀式，直到到末尾
	{
		if ('0' <= exp[i] && exp[i] <= '9')//如果遇到操作数(注意exp中的所有都是字符型),入操作数栈
		{
			s1->top += 1;
			s1->data[s1->top] = exp[i] - '0';//注意入操作数栈，操作数栈数组是浮点型，必须将字符转换为浮点数才能入栈
			++i;//判断表达式下一个
		}
		else if (exp[i] == '(')//遇到"("，入运算符栈
		{
			s2->top += 1;
			s2->data[s2->top] = '(';
			++i;
		}
		else if (exp[i] == '+' ||exp[i] == '-' ||exp[i] == '*' ||exp[i] == '/')//遇到运算符进行两种情况的判断
		{
			if (s2->top == -1 || s2->data[s2->top] == '(' || getPriority(exp[i]) > getPriority(s2->data[s2->top]))//如果运算符栈空，或遇到"("，或扫描到的运算符优先级大于运算符栈顶优先级，则直接入运算符栈
			{
				s2->top += 1;
				s2->data[s2->top] = exp[i];
				++i;
			}
			else//否则就要出栈，进行一个运算符结合两个操作数的运算
			{
				/*:下面注释运算后面要执行很多次，所以封装为函数，写到这是方便理解
				float opnd1, opnd2, result;//opnd1和opnd2用来接受出栈的操作数，result用来接收函数的返回值
				char op;//op用来接受出栈的运算符
				int flag;//由于分母可能会有0的情况，用flag判断计算是否成功

				
				opnd2 = s1->data[s1->top];//先出栈的为右操作数
				s1->top -= 1;
				opnd1 = s1->data[s1->top];//虎后出栈的为左操作数
				s1->top -= 1;
				op = s2->data[s2->top];//弹出运算符
				s2->top -= 1;
				
				flag = calSub(opnd1,op,opnd2,result)
				if (flag == 0)
				{
					printf("ERROR");
					return 0;
				}
				s1->top += 1;
				s1->data[s1->top] = result;//除去上述那种错误信息外，执行到这说明一切正常，那么把结果入操作数栈
				*/

				int flag = calSubTopTwo(&s1, &s2);
				if (flag == 0)
					return 0;//如果flag为0说明，分母是0，直接结束运算
				//注意循环变量不要向后，还要拿新上来的运算符和当前扫描运算符比较，直到扫描到的运算符大于运算符栈顶运算符才能继续入栈
			}
		}
		else if (exp[i] == ')')//如果遇到")"
		{
			while (s2->data[s2->top] != '(')//将")"到"("元素出栈，并结合操作数进行上述运算
			{
				int flag = calSubTopTwo(&s1, &s2);
				if (flag == 0)
					return 0;
			}
			s2->top -= 1;//注意和"("是出栈的，但是它不参与运算，所以向下移1位，相当于删除了"("
			++i;//其实这四种情况，每种大的情况下才能有变量后移
		}

	}

	while (s2->data[s2->top] != -1)//扫描完表达式后，运算符栈若还有运算符，则全部出栈，每个出栈元素执行同样的运算操作
	{
		int flag = calSubTopTwo(&s1, &s2);
		if (flag == 0)
			return 0;
	}
	return s1->data[s1->top];//最终操作数栈顶元素即为表达式结果
}
////////////用栈求前缀表达式//////////
/*
1:规则
	准备一个栈，从左向右扫描表达式，遇到操作数就入栈，遇到运算符就出两个操作数（第一次出栈的操作数在右面，第二次的在左面），用这两个操作数
	结合一个运算符进行运算，将结果仍然压栈中，依次类推，最终栈顶元素即为结果

*/
//2：代码
float calPostFix(char exp[], Sqstack1* s1)
{
	s1->top = -1;

	for (int i = 0; exp[i] != '\0'; ++i)//使用for循环，因为后缀表达式要么碰到操作数，要么碰到运算符
	{
		if ('0' <= exp[i] && exp[i] <= '9')//碰到操作数入栈
		{
			s1->top += 1;
			s1->data[s1->top] = exp[i] - '0';
		}
		else//碰到运算符进行与运算
		{
			float opnd1, opnd2, result;
			char op;
			int flag;

			opnd2 = s1->data[s1->top];
			s1->top -= 1;
			opnd1 = s1->data[s1->top];
			s1->top -= 1;
			op = exp[i];
			flag = calSub(opnd1, op, opnd2, &result);

			if (flag == 0)
			{
				printf("ERROE");
				break;
			}
			s1->top += 1;
			s1->data[s1->top] = result;
		}
	}
	return s1->data[s1->top];//栈顶元素是结果
}

///////////////用栈求后缀表达式//////////
/*
1:规则
	和求前缀表达式很相似，不同之处就是求后缀式的时候是从后往前扫描，遇到运算符出站时是第一次出栈的在左面，第二次出栈的在右面
*/
//2:代码
float calPrefix(char exp[], Sqstack1* s1, int len)//len为数组长度
{
	s1->top = -1;

	for (int i = len - 1; i >= 0; --i)//改动
	{
		if ('0' <= exp[i] && exp[i] >= '9')
		{
			s1->top += 1;
			s1->data[s1->top] = exp[i] - '0';
		}
		else
		{
			float opnd1, opnd2, result;
			char op;
			int flag;

			opnd1 = s1->data[s1->top];//改动
			s1->top -= 1;
			opnd2 = s1->data[s1->top];
			s1->top -= 1;
			op = exp[i];

			flag = calSub(opnd1, op, opnd2, &result);
			if (flag == 0)
			{
				printf("error");
				return 0;
			}
			s1->top += 1;
			s1->data[s1->top] = result;
		}
	}
	return s1->data[s1->top];
}