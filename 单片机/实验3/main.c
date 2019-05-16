#include <reg52.h>
typedef unsigned int u16;
typedef unsigned char u8;
unsigned char buffer[]={'w','w','w','.','n','u','c','.','e','d','u','.','c','n','\n'}; 

unsigned char i = 0,flage=0;

void delay_long() //延时子程序
{
	unsigned char i,j,k,x;
	for(x=10;x>0;x--)
	for(i=20;i>0;i--)
	for(j=20;j>0;j--)
	for(k=248;k>0;k--);
}
void delay(u16 i) //延时子程序
{
	int s = i * 10000;
	while(s --);
}
void main (void)
{
	SCON = 0x50;
	TMOD |= 0x20;
	TH1 = 0xF3;
	TL1 = 0xF3;
	PCON = 0x80;

	//TH1 = 0xFD;
	TR1 = 1;
	EA = 1;
	ES = 1;
	while(1)
	{
		delay_long();
		for(i=0;i<15;i++)
		{	
			if(flage) SBUF=buffer[i];
			delay(1);
			flage=1;
		}
	}
}
void UART_SER (void) interrupt 4
{
	
	if(RI)
	{
		RI=0;
	}
	if(TI)
	{
		TI = 0;
		flage=0;
	}
}