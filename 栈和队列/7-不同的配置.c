#include <stdio.h>

//对于栈和队列，只要设计的结构能满足他们的特性，那就是正确的。在配置问题中，主要考察队列，栈
//的考点较少，而在队列中基本就是考察顺序队，链式队考察基本没有
//再次重复，队列的配置并不唯一，不是说rear=front就是为空，

//1:正常配置---咋们最习以为常的配置
/*
	//队空队满状态判定
	   队空：rear==front
	   队满：front==(rear+1)%maxSize 为真

	//元素个数计算
	   N=(rear-front+maxSize)%maxSize

*/
//2:非正常配置1
/*
	//队列进入队操作
		入队：queue[rear]=x;rear
			  rear=(rear+1)%maxSize//先入队元素，再移动指针
		出队：x=queue[front]
			 front=(front+1)%maxSize//先出队元素，再移动指针
	//队满队空判定
		队空：front==rear
		队满：front==(rear+1)%maxSize 为真

	（正常配置下，rear指向队尾元素，front指向队头元素的前一个；而这种配置rear指向队尾元素的下一个，
	  而front指向了队头元素，相当于都后移了一位）

	  //元素个数计算
		N=（rear-front+maxSize)%maxSize

*/  
//3:非正常配置2
/*
	//入队
		入队：rear=(rear+1)%maxSize
			 queue[rear]=x;//注意这并不唯一，也可以先入队元素，再移动指针
		出队：x=queue[front]
			 front=(front+1)%maxSize

	//队满队空判定
		队空：front==(rear+1）%maxSize 为真
		队满：front==(rear+2)%maxSize  为真（因为这个过程中rear和front始终指向元素）

	//元素个数计算
		N=（rear-front+1+maxSize)%maxSize

*/