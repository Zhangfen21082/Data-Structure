#include <stdio.h>

//����ջ�Ͷ��У�ֻҪ��ƵĽṹ���������ǵ����ԣ��Ǿ�����ȷ�ġ������������У���Ҫ������У�ջ
//�Ŀ�����٣����ڶ����л������ǿ���˳��ӣ���ʽ�ӿ������û��
//�ٴ��ظ������е����ò���Ψһ������˵rear=front����Ϊ�գ�

//1:��������---զ����ϰ��Ϊ��������
/*
	//�ӿն���״̬�ж�
	   �ӿգ�rear==front
	   ������front==(rear+1)%maxSize Ϊ��

	//Ԫ�ظ�������
	   N=(rear-front+maxSize)%maxSize

*/
//2:����������1
/*
	//���н���Ӳ���
		��ӣ�queue[rear]=x;rear
			  rear=(rear+1)%maxSize//�����Ԫ�أ����ƶ�ָ��
		���ӣ�x=queue[front]
			 front=(front+1)%maxSize//�ȳ���Ԫ�أ����ƶ�ָ��
	//�����ӿ��ж�
		�ӿգ�front==rear
		������front==(rear+1)%maxSize Ϊ��

	�����������£�rearָ���βԪ�أ�frontָ���ͷԪ�ص�ǰһ��������������rearָ���βԪ�ص���һ����
	  ��frontָ���˶�ͷԪ�أ��൱�ڶ�������һλ��

	  //Ԫ�ظ�������
		N=��rear-front+maxSize)%maxSize

*/  
//3:����������2
/*
	//���
		��ӣ�rear=(rear+1)%maxSize
			 queue[rear]=x;//ע���Ⲣ��Ψһ��Ҳ���������Ԫ�أ����ƶ�ָ��
		���ӣ�x=queue[front]
			 front=(front+1)%maxSize

	//�����ӿ��ж�
		�ӿգ�front==(rear+1��%maxSize Ϊ��
		������front==(rear+2)%maxSize  Ϊ�棨��Ϊ���������rear��frontʼ��ָ��Ԫ�أ�

	//Ԫ�ظ�������
		N=��rear-front+1+maxSize)%maxSize

*/