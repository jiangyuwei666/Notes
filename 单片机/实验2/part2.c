#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;
sbit led0 = P2^0;

sbit k1 = P3^0;


void delay(u16 i)
{
	while(i --);
}


void main()
{
	while(1)
	{
		if(k1 == 0)
		{
			delay(1000);
			if (k1 == 0)
			{
				led0 =~ led0;
			}
			while(!k1);
		} 
	}	
}