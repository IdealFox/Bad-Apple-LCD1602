#include <REGX52.H>
#include <Delay.h>
#include <LCD1602.h>
unsigned char dat;					//定义全局变量dat,用来接收串口发送的数据
unsigned char time;					//定义全局变量time,原来接收串口发送的次数

void main()
{
	P2_5=0;										//P25脚置低电平，使LCD1602一直处于写入状态
	Delay_ms(100);						//由于取消了LCD1602的忙检测，单片机上电后先延时，再初始化LCD
	LCD_Init();								//LCD1602初始化
	Uart_Init();							//串口初始化
	while(1)
	{
		LCD_Custom();								//循环展示LCD1602的CGRAM内的字符
//		LCD_ShowNum(1,8,time,2);	//显示数据接收状态，用于调试
		Delay_ms(100);							//延时，留影

	}
}

/** @brief	中断接收数据
  * @param	无
  * @retval	无
  **/
void UART_Routine() interrupt 4			//串口中断
{
	if(RI==1)													//检测串口是否接收到数据
	{
		sec=SBUF;												//读取SBUF，也就是串口发来的数据
		LCDWriteCGRAM(dat,time);				//写入接收的数据置LCD1602的CGRAM
		time++;													//接收次数
		RI=0;														//RI置0，完成数据接收
		if(time>=64)										//1帧图片接收完成
		{time=0;	}											//time归零，等待下一组数据
	}
}



