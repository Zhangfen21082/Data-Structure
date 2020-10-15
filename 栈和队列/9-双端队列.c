#include <stdio.h>


/*
	1:双端队列的种类
		两端毫无限制：两端可以进行插入和删除的队列
		输入受限的双端队列：插入只能在一端，输出可以在两端
		输出受限的双端队列：输出只能在一端，输入可以在两端
	2:双端队列经典题型
————设有一个双端队列，元素进入该队列的顺序是1-2-3-4，分别求出满足下列条件的输出序列
	①：不可能通过输入受限的双端序列输出的序列是：
	解：将一个输入受限的双端队列的对应一个输出端“堵住”，现在他就变成了一个栈，根据卡特兰数计算
		规则，由栈输出的种类为14种，而1-2-3-4所能存的全部序列为，4的全排列，那么栈形态下不可能的
		序列数就是4!-14=10。
		所以我们利用穷举法列出4的全排列，然后列出栈能导出的14种形态，从中剔除掉，剩余的就是栈
		不可能导出的10种形态，如下
				1,4,2,3
				2,4,1,3
				3,4,1,2
				3,1,4,2
				3,1,2,4
				4,3,1,2
				4,1,3,2
				4,2,1,3
				4,2,3,1
				4,1,2,3
		将上述10种情况按照1-2-3-4进输入受限的双端队列尝试导出，无法导出，或矛盾的就是不满足的
		可以发现4,2,1,3和4,2,3,1无法导出
	②：不可能通过输出受限的双端队列输出的序列时
		分析方法同上，4,1,3,2和,4,2,3,1无法导出








*/