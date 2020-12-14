#include <stdio.h>
#include <math.h>
#define maxSize 100
#define MIN 0.00000001

typedef struct
{
	float data[maxSize];//�������������ջ����������float��
	int top;
}Sqstack1;
typedef struct
{
	char data[maxSize];//�������������ջ���������char��   Z Xȥ
	int top;
}Sqstack2;

int getPriority(char op)//�ж���������ȼ�
{
	if (op == '+' || op == '-')
		return 0;
	else
		return 1;
}
int calSub(float opand1, char op, float opand2, float* result)//������������ֵ,ע���������float�ͣ�C++��Ҫ�������͡�flaot &result
{
	if (op == '+') *result = opand1 + opand2;
	if (op == '-') *result = opand1 - opand2;
	if (op == '*') *result = opand1 * opand2;//�Ӽ���û��ʲô�������
	if (op == '/')//���ڳ�����Ҫ�ж����ĸ����Ϊ0
	{
		if (fabs(opand2 < MIN))//ʹ��fabs�������ľ���ֵ�������жϷ�ĸΪ0�ı�׼д����MINΪԤ�ȶ����һ����С����
			return 0;//��ĸΪ0������ʧ��
		else
			*result = opand1 / opand2;
	}
	return 1;

}
int calSubTopTwo(Sqstack1* s1, Sqstack2* s2)
{
	float opnd1, opnd2, result;//opnd1��opnd2�������ܳ�ջ�Ĳ�������result�������պ����ķ���ֵ
	char op;//op�������ܳ�ջ�������
	int flag;//���ڷ�ĸ���ܻ���0���������flag�жϼ����Ƿ�ɹ�
	
	opnd2 = s1->data[s1->top];//�ȳ�ջ��Ϊ�Ҳ�����
	s1->top -= 1;
	opnd1 = s1->data[s1->top];//���ջ��Ϊ�������
	s1->top -= 1;
	op = s2->data[s2->top];//���������
	s2->top -= 1;
	flag = calSub(opnd1, op, opnd2, &result);//��flag���ܳɹ����
	if (flag == 0)
	{
		printf("ERROR");//���flagΪ0,����
	}


	s1->top += 1;
	s1->data[s1->top] = result;//�����������ѽ���������ջ
	return flag;//����flag
}


////////////��ջ����׺���ʽ///////////
/*
1:����
	׼������ջ��һ���ݴ����������һ���ݴ�������������ң�ɨ����ʽ���������������������ջ������"("
	���������ջ�������������ʱ���������ջ�գ��������ջ��Ԫ��Ϊ"("���������ֱ���������ջ����������ջ
	������ջ��Ԫ�ز���"("����ʱ��ɨ�赽������������ȼ����������ջջ����������ȼ�������ջ������������ջ
	����ִ�г�ջ������ÿ��ջһ���������������ջ�ͳ�ջ����������������������������������������(��һ�γ�ջ��
	�����棬�ڶ��γ�ջ��������)����������������ջ��ֱ��ɨ�赽����������ȼ����������ջ����������ȼ����������
	")"���ͽ������ջ����"("�ŵ�����Ԫ�س�ջ������ÿһ����ջ���������һ���������㡣��󣬵�������׺���ʽ
	ɨ����֮�������ջ��Ȼ��������Ļ����ǾͰ�ÿһ���������ջ������ÿһ����ջ������������������㡣
	���s1ջ����Ϊ���ʽ�����

*/
//2:����
float calInfix(char exp[],Sqstack1* s1,Sqstack2* s2)//expΪ���ʽ,s1Ϊ������ջ��s2λ�����ջ
{
	s1->top = -1;
	s2->top = -1;//��ʼ��ջ
	int i = 0;

	while (exp[i] != '\0')//��������ɨ����׺ʽ��ֱ����ĩβ
	{
		if ('0' <= exp[i] && exp[i] <= '9')//�������������(ע��exp�е����ж����ַ���),�������ջ
		{
			s1->top += 1;
			s1->data[s1->top] = exp[i] - '0';//ע���������ջ��������ջ�����Ǹ����ͣ����뽫�ַ�ת��Ϊ������������ջ
			++i;//�жϱ��ʽ��һ��
		}
		else if (exp[i] == '(')//����"("���������ջ
		{
			s2->top += 1;
			s2->data[s2->top] = '(';
			++i;
		}
		else if (exp[i] == '+' ||exp[i] == '-' ||exp[i] == '*' ||exp[i] == '/')//�����������������������ж�
		{
			if (s2->top == -1 || s2->data[s2->top] == '(' || getPriority(exp[i]) > getPriority(s2->data[s2->top]))//��������ջ�գ�������"("����ɨ�赽����������ȼ����������ջ�����ȼ�����ֱ���������ջ
			{
				s2->top += 1;
				s2->data[s2->top] = exp[i];
				++i;
			}
			else//�����Ҫ��ջ������һ��������������������������
			{
				/*:����ע���������Ҫִ�кܶ�Σ����Է�װΪ������д�����Ƿ������
				float opnd1, opnd2, result;//opnd1��opnd2�������ܳ�ջ�Ĳ�������result�������պ����ķ���ֵ
				char op;//op�������ܳ�ջ�������
				int flag;//���ڷ�ĸ���ܻ���0���������flag�жϼ����Ƿ�ɹ�

				
				opnd2 = s1->data[s1->top];//�ȳ�ջ��Ϊ�Ҳ�����
				s1->top -= 1;
				opnd1 = s1->data[s1->top];//�����ջ��Ϊ�������
				s1->top -= 1;
				op = s2->data[s2->top];//���������
				s2->top -= 1;
				
				flag = calSub(opnd1,op,opnd2,result)
				if (flag == 0)
				{
					printf("ERROR");
					return 0;
				}
				s1->top += 1;
				s1->data[s1->top] = result;//��ȥ�������ִ�����Ϣ�⣬ִ�е���˵��һ����������ô�ѽ���������ջ
				*/

				int flag = calSubTopTwo(&s1, &s2);
				if (flag == 0)
					return 0;//���flagΪ0˵������ĸ��0��ֱ�ӽ�������
				//ע��ѭ��������Ҫ��󣬻�Ҫ����������������͵�ǰɨ��������Ƚϣ�ֱ��ɨ�赽����������������ջ����������ܼ�����ջ
			}
		}
		else if (exp[i] == ')')//�������")"
		{
			while (s2->data[s2->top] != '(')//��")"��"("Ԫ�س�ջ������ϲ�����������������
			{
				int flag = calSubTopTwo(&s1, &s2);
				if (flag == 0)
					return 0;
			}
			s2->top -= 1;//ע���"("�ǳ�ջ�ģ����������������㣬����������1λ���൱��ɾ����"("
			++i;//��ʵ�����������ÿ�ִ������²����б�������
		}

	}

	while (s2->data[s2->top] != -1)//ɨ������ʽ�������ջ���������������ȫ����ջ��ÿ����ջԪ��ִ��ͬ�����������
	{
		int flag = calSubTopTwo(&s1, &s2);
		if (flag == 0)
			return 0;
	}
	return s1->data[s1->top];//���ղ�����ջ��Ԫ�ؼ�Ϊ���ʽ���
}
////////////��ջ��ǰ׺���ʽ//////////
/*
1:����
	׼��һ��ջ����������ɨ����ʽ����������������ջ������������ͳ���������������һ�γ�ջ�Ĳ����������棬�ڶ��ε������棩����������������
	���һ��������������㣬�������Ȼѹջ�У��������ƣ�����ջ��Ԫ�ؼ�Ϊ���

*/
//2������
float calPostFix(char exp[], Sqstack1* s1)
{
	s1->top = -1;

	for (int i = 0; exp[i] != '\0'; ++i)//ʹ��forѭ������Ϊ��׺���ʽҪô������������Ҫô���������
	{
		if ('0' <= exp[i] && exp[i] <= '9')//������������ջ
		{
			s1->top += 1;
			s1->data[s1->top] = exp[i] - '0';
		}
		else//�������������������
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
	return s1->data[s1->top];//ջ��Ԫ���ǽ��
}

///////////////��ջ���׺���ʽ//////////
/*
1:����
	����ǰ׺���ʽ�����ƣ���֮ͬ���������׺ʽ��ʱ���ǴӺ���ǰɨ�裬�����������վʱ�ǵ�һ�γ�ջ�������棬�ڶ��γ�ջ��������
*/
//2:����
float calPrefix(char exp[], Sqstack1* s1, int len)//lenΪ���鳤��
{
	s1->top = -1;

	for (int i = len - 1; i >= 0; --i)//�Ķ�
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

			opnd1 = s1->data[s1->top];//�Ķ�
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