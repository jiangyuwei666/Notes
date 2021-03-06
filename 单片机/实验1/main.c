#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include<intrins.h>
typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

#define ledd P2

u16 flag = 1,ii;

sbit led = P2^0;		 //将单片机的P2.0端口定义为led
sbit k3 = P3^2;  		//定义按键K3
sbit k4 = P3^3;  		//定义按键K4
sbit k2 = P3^0;
sbit led1 = P2^5;

void delay(u16 i)
{
	while(i --);	
}

void Int0Init()
{
	//设置INT0
	IT0 = 1;//跳变沿出发方式（下降沿）
	EX0 = 1;//打开INT0的中断允许。	
	EA = 1;//打开总中断	
}


void Int1Init()
{
	//设置INT1
	IT1 = 1;//跳变沿出发方式（下降沿）
	EX1 = 1;//打开INT1的中断允许。	
	EA = 1;//打开总中断	
}

//胜利oid keypros()
//{
//	if(k2==0)		  //检测按键K1是否按下
//	{	
//		for(ii=0;ii<4;ii++)
//		delay(1000);   //消除抖动 一般大约10ms
//		if(k2==0)	 //再次判断按键是否按下
//		{
//		 //led1 =~ led1;	
//		 	if (flag==1) flag=0;
//			if (flag==0) flag=1;
//		}
//		while(!k2);	 //检测按键是否松开
//	}		
//}

void main()
{
	Int0Init();  //	设置外部中断0
	Int1Init();  //	设置外部中断1
	while(1)
		led = 0;
//	
//	{
//		keypros();
//	}		
}


void Int0() interrupt 0		//外部中断0的中断函数
{
	delay(1000);	 //延时消抖
	if(k3 == 0)
	{
		while(k4!=0)
		{
			led=~led;
			delay(50000); //大约延时450ms
//			led=1;
//			delay(50000); //大约延时450ms
		}
			
	}
	
}

void Int1()	interrupt 2		//外部中断1的中断函数
{
	delay(1000);	 //延时消抖
	if(k4 == 0)
	{
		u8 i;
		ledd=0xfe;
		delay(50000); //大约延时450ms	
		while(k3!=0)
		{			
			for(i=0;i<7;i++)	 //将led左移一位
			{
				ledd=_crol_(ledd,1);
				delay(50000); //大约延时450ms	
				if(k3==0){P2=0XFF;break;}
			}
			for(i=0;i<7;i++)	//将led右移一位
			{
				ledd=_cror_(ledd,1);
				delay(50000); //大约延时450ms	
				if(k3==0){P2=0XFF;break;}
			}
				
		} 
	}
}
