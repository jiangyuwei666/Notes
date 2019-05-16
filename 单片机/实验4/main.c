/**************************************************************************************
*		              LCD1602液晶显示实验												  *
实现现象：下载程序后插上LCD1602液晶在开发板上，即可显示
注意事项：如果不想让点阵模块显示，可以将74HC595模块上的JP595短接片拔掉。																				  
***************************************************************************************/

#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "lcd.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

u8 count, k1Num;
char hour, min, second;
u8 date[]="  2019-5-16";
// u8 time[]="   23:59:50";
u8 time[]="   00:00:00";

void write_time(u8 add, u8 date)
{
	u8 m, n;
	m = date / 10;  //取出date的十位和个位
	n = date % 10;
	LcdWriteCom(add + 0x80 + 0x40);
	LcdWriteData(0x30 + m);
	LcdWriteData(0x30 + n);

}



void delay(uint z)
{
	u16 x, y;
	for (x = z; x > 0; x --)
		for (y = 110; y > 0; y --);
}



void keyScan()
{
	rd = 0;
	if (k1 == 0)
	{
		delay(5);
		if (k1 == 0)
		{
			k1Num ++;
			while(!k1);  //等待松手
			if (k1Num == 1)
			{
				TR0 = 0; 	//计时停止
				LcdWriteCom(0x80 + 0x40 + 10); //设置光标位置在 秒
				LcdWriteCom(0x0f);	  // 光标闪烁
			}
			if (k1Num == 2)
			{
				TR0 = 0; 	//计时停止
				LcdWriteCom(0x80 + 0x40 + 7); //设置光标位置在 分 
				LcdWriteCom(0x0f);	  // 光标闪烁
			}
			if (k1Num == 3)
			{
				TR0 = 0; 	//计时停止
				LcdWriteCom(0x80 + 0x40 + 4); //设置光标位置在 时
				LcdWriteCom(0x0f);	  // 光标闪烁
			}
			if (k1Num == 4)
			{
				LcdWriteCom(0x0c);	  // 光标不闪烁
				k1Num = 0;
				TR0 = 1; 	//计时停止
			}
			
		}
	}
	
	if (k1Num != 0)	 // 表示重置键已经按下(光标闪烁)
	{
		if (k2 == 0)
		{
			delay(5);
			if (k2 == 0)
			{
				while(!k2);     //等待松手
				if (k1Num == 1) //说明光标在秒的位置
				{
					second ++;
					if (second == 60) second = 0;
					write_time(9, second);			  // 刷新时间
					LcdWriteCom(0x80 + 0x40 + 10);	 //重置光标的位置
				}
				if (k1Num == 2) //说明光标在分的位置
				{
					min ++;
					if (min == 60) min = 0;
					write_time(6, min);
					LcdWriteCom(0x80 + 0x40 + 7);
				}
				if (k1Num == 3) //说明光标在时的位置
				{
					hour ++;
					if (hour == 24) hour = 0;
					write_time(3, hour);
					LcdWriteCom(0x80 + 0x40 + 4);
				}
			}
		}
		if (k3 == 0)
		{
			delay(5);
			if (k3 == 0)
			{
				while(!k3);     //等待松手
				if (k1Num == 1) //说明光标在秒的位置
				{
					second --;
					if (second < 0) second = 59;
					write_time(9, second);			  // 刷新时间
					LcdWriteCom(0x80 + 0x40 + 10);	  //重置光标的位置
						 
				}
				if (k1Num == 2) //说明光标在分的位置
				{
					min --;
					if (min < 0) min = 59;
					write_time(6, min);
					LcdWriteCom(0x80 + 0x40 + 7);
				}
				if (k1Num == 3) //说明光标在时的位置
				{
					hour --;
					if (hour < 0) hour = 23;
					write_time(3, hour);
					LcdWriteCom(0x80 + 0x40 + 4);
				}
			}
		}
	}
}






void main(void)
{
	u16 i;
	LcdInit();
	for(i = 0; i < 11; i ++)
	{
		LcdWriteData(date[i]);	
	}
	LcdWriteCom(0x40+0x80);
	for (i = 0; i < 11; i ++)
	{
		LcdWriteData(time[i]);
	}
	TMOD = 0x01;
	TH0 = (65526 - 50000) / 256;
	TL0 = (65526 - 50000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;

	//hour = 23;
	//min = 59;
	//second = 50;
	
	while(1)
	{
		keyScan();
		
	}				
}



void timer0() interrupt 1
{
	TH0 = (65526 - 50000) / 256;
	TL0 = (65526 - 50000) % 256;
	count ++;
	if (count == 20)
		{
		 count = 0;
		 second ++;
		 if (second == 60)
		 {
		 	second = 0;
			min ++;
			if (min == 60)
			{
				min = 0;
				hour ++;
				if (hour == 24)
				{
					hour = 0;
				}
				write_time(3, hour);
			}
			write_time(6, min);
		 }
		 write_time(9, second);
		 
		}
}