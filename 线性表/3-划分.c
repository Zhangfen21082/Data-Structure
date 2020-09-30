#include <stdio.h>

//第一种划分：给出一个顺序表，以第一个元素为枢轴，将顺序表划分为左右两个部分，使得左侧元素
//			 小于枢轴，右侧元素大于枢轴，并且枢轴要在左右两部分元素之间
void partition(int arr[], int n)//此过程大致类似于快速排序
{
	int temp;
	int i = 0;
	int j = n - 1;//i和j分别指向这个线性表的首元素和尾元素
	temp = arr[0];//第一个元素作为划分依据，也就是枢纽

	while (i < j)//大循环，当i<j时一直比较
	{
		while (i < j && arr[j] >= temp)//右半部分元素应该是大于枢纽的，所以用while，如果右面的大于枢纽，那就判断下一个，以此类推
			--j;
		if (i < j)//一旦跳出while，说明右面也就是j所指的一个元素它小于了temp，
		{
			arr[i] = arr[j];//那么应该把它放到i的位置去，也就是枢纽左侧
			++i;//同时i+1，准备启动左侧判断
		}
		while (i < j && arr[i] < temp)//左半部分元素应该是小于枢纽的，所以用while，如果左面的小于枢纽，那就判断下一个，以此类推
			++i;
		if (i < j)//一旦跳出while，说明左面也就是i所指的一个元素它大于了temp
		{
			arr[j] = arr[i];//那么应该把它放到j的位置去，也就是枢纽右侧
			--j;//同时j-1，准备起到右侧判断
		}
		
	}
	arr[i] = temp;//大while跳出后，说明i和j同时指向了一个位置，这个位置放的就是枢纽元素

}
//第二种划分（一般情况）：给定一个比价元素comp，comp可以是表内元素也可以是表外元素（当comp
					  //为表内元素且为枢轴元素，就是第一种划分了），将顺序表分为两部分
				      //左半部分小于comp，右半部分大于comp
void partition(int arr[], int n,int comp)//改动
{
	int temp;
	int i = 0;
	int j = n - 1;
	temp = arr[0];
	while (i < j)
	{
		while (i < j&&arr[j] >= comp)//改动
			--i;
		if (i < j)
		{
			arr[i] = arr[j];
			++i;
		}
		while (i < j && arr[i] < comp)//改动
			++i;
		if (i < j)
		{
			arr[j] = arr[i];
			--j;
		}

	}
	arr[i] = temp;//注意最终指向的枢轴元素，comp元素只是起到划分的作用

}
//第三种划分：顺序表中任意一个元素都可以作为枢轴进行划分
void partition(int arr[], int n, int k)//改动:k用来接受用户希望哪一个元素作为枢轴
{
	int temp;
	int i = 0;
	int j = n - 1;

	temp = arr[0];//只需把那个位置交换到第一个位置，仍用之前的代码即可
	arr[k] = arr[0];
	arr[k] = temp;

	temp = arr[0];
	while (i < j)
	{
		while (i < j&&arr[j] >= temp)
			--i;
		if (i < j)
		{
			arr[i] = arr[j];
			++i;
		}
		while (i < j && arr[i] < temp)
			++i;
		if (i < j)
		{
			arr[j] = arr[i];
			--j;
		}

	}
	arr[i] = temp;

}