# include "reg52.h"			 


typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit k1 = P1^7;
sbit led = P2^0;
sbit k2 = P3^0;

void delay(u16 i)
{
	while(i --);
}

void main(void)
{
	
	while(1)
	
	{
		if(k1==0)		  //检测按键K1是否按下
		{	
			delay(1000);   //消除抖动 一般大约10ms
			if(k1==0)	 //再次判断按键是否按下
			{
				led=~led;	  //led状态取反
			}
			while(!k1);	 //检测按键是否松开
		}
		if(k2==0)		  //检测按键K1是否按下
		{	
			delay(1000);   //消除抖动 一般大约10ms
			if(k2==0)	 //再次判断按键是否按下
			{
				led=~led;	  //led状态取反
			}
			while(!k2);	 //检测按键是否松开
		}	
	}				
}