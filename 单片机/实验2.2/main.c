#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;


u16 led;

void delay(u16 i)
{
	while(i --);
}


void Timer0Init()
{
	TMOD|=0X01;//选择为定时器0模式，工作方式1，仅用TR0打开启动。

	TH0=0XFC;	//给定时器赋初值，定时1ms
	TL0=0X18;	
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR0=1;//打开定时器			
}


void main()
{
	Timer0Init();
	while(1);
}


void Timer0() interrupt 1
{
	static u16 i;
	TH0 = 0xfc;
	TL0 = 0x18;
	i ++;
	if (i == 500)
	{
		i = 0;
		led --;
		P2 = led; 
		if (led == 0) led = 0xff;
	}
	
	
}