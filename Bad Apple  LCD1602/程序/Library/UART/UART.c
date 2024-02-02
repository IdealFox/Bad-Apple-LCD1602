#include <REGX52.H>
#include <UART.h>

/** @brief	串口初始化
  * @param	无
  * @retval	无
  **/
void Uart_Init(void)		//4800bps@12.000MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA  = 1;		//启动所有中断
	ES  = 1;		//启动串口中断
}


/** @brief	串口发送数据
  * @param	Byte 为要发送的数据，数据长度，1字节
  * @retval	无
  **/
void Uart_SendByte(unsigned char Byte)		
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

