#include <REGX52.H>
#include <LCD1602.h>
#include <Delay.h>
	
	
//void LCDReadBF()											//检测LCD1602是否空闲		//忙检测
//{
//	unsigned char state;
//	unsigned char i;
//	LCD1602_DB = 0XFF; 									//IO口置1
//	LCD1602_RS = 0;											//指令模式
//	LCD1602_RW = 1; 										//读
//	do{
//	LCD1602_EN = 1;											//EN口置1，读取指令 
//	state =	LCD1602_DB;									//读取IO口数据
//	LCD1602_EN = 0;											//EN口置0，退出
//	i++;
//	if(i>50)
//	{break;}} 
//	while(state & 0x80);								//判断state是否为80，若是表示LCD1602空闲，退出循环
//}

void LCDWriteCmd(unsigned char cmd)		//写命令
{
//	LCDReadBF();												//忙检测
	Delay_us(3);												//用Delay代替忙检测，提高运行速度
	LCD1602_RS = 0;											//指令模式
	LCD1602_RW = 0; 										//写
	LCD1602_DB = cmd;										//写指令
	LCD1602_EN = 1;											//EN口置1，写入指令
	LCD1602_EN = 0;											//EN口置0，退出
}

void LCDWriteData(unsigned char dat)		//写数据
{
//	LCDReadBF();												//忙检测
	Delay_us(3);												//用Delay代替忙检测，提高运行速度
	LCD1602_RS = 1;											//数据模式
	LCD1602_RW = 0; 										//写
	LCD1602_DB = dat;										//写数据
	LCD1602_EN = 1;											//EN口置1，写入指令
	LCD1602_EN = 0;											//EN口置0，退出
}

///**
//  * @brief  返回值=X的Y次方
//  */
int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

/**
  * @brief  LCD1602设置光标位置
  * @param  Line 行位置，范围：1~2
  * @param  Column 列位置，范围：1~16
  * @retval 无
  */
void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCDWriteCmd(0x80|(Column-1));
	}
	if(Line==2)
	{
		LCDWriteCmd(0x80|(Column-1+0x40));
	}
}

/** @brief	LCD1602初始化
  * @param	无
  * @retval	无
  **/
void LCD_Init()										//LCD1602初始化函数
{
	LCDWriteCmd(LCD_MODE_PIN8);					//显示模式设置，8位数据口，两行，5*8点阵
	LCDWriteCmd(LCD_DIS_ON);						//显示开，光标关，光标不闪烁
	LCDWriteCmd(LCD_CURSOR_RIGHT);			//光标右移，显示不移动
	LCDWriteCmd(LCD_SCREEN_CLR);				//清屏
}

/** @brief	清屏
  * @param	无
  * @retval	无
  **/
void LCD_Clear()
{
	LCDWriteCmd(LCD_SCREEN_CLR);
}
///**
//  * @brief  在LCD1602指定位置上显示一个字符
//  * @param  Line 行位置，范围：1~2
//  * @param  Column 列位置，范围：1~16
//  * @param  Char 要显示的字符
//  * @retval 无
//  */
//void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char)
//{
//	LCD_SetCursor(Line,Column);
//	LCDWriteData(Char);
//}

///** @brief	LCD1602显示字符串
//  * @param  Line 行位置，范围：1~2
//  * @param  Column 列位置，范围：1~16
//  * @param	Str			
//  * @retval	无
//  **/
//void LCD_ShowStr(unsigned char Line,unsigned char Column,unsigned char *Str)
//{
//	LCD_SetCursor(Line,Column);
//	while(*Str !='\0'){
//	LCDWriteData(*Str++);
//	}
//}

///**
//  * @brief  在LCD1602指定位置开始显示所给数字
//  * @param  Line 起始行位置，范围：1~2
//  * @param  Column 起始列位置，范围：1~16
//  * @param  Number 要显示的数字，范围：0~65535
//  * @param  Length 要显示数字的长度，范围：1~5
//  * @retval 无
//  */
//void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
//{
//	unsigned char i;
//	LCD_SetCursor(Line,Column);
//	for(i=Length;i>0;i--)
//	{
//		LCDWriteData(Number/LCD_Pow(10,i-1)%10+'0');
//	}
//}

/** @brief	写入数据至CGRAM
  * @param	dat 写入的数据	time	写入的次数
  * @retval	无
  **/
void LCDWriteCGRAM(unsigned char dat,unsigned char time)
	{
		switch(time)															//检测数据写入次数，每写满8位进1
	{ case 0:LCDWriteCmd(0x40);break;
		case 8:LCDWriteCmd(0x48);break;
		case 16:LCDWriteCmd(0x50);break;
		case 24:LCDWriteCmd(0x58);break;
		case 32:LCDWriteCmd(0x60);break;
		case 40:LCDWriteCmd(0x68);break;
		case 48:LCDWriteCmd(0x70);break;
		case 56:LCDWriteCmd(0x78);break;
		default :break;
	}
	LCDWriteData(sec);													//写入数据
}


/** @brief	LCD1602展示自定义字符
  * @param	无
  * @retval	无
  **/
void LCD_Custom()
{
	LCD_Clear();
	Delay_ms(5);
	LCDWriteCmd(0x80);
	LCDWriteData(0X00);
	LCDWriteCmd(0x81);
	LCDWriteData(0X01);
	LCDWriteCmd(0x82);
	LCDWriteData(0X02);
	LCDWriteCmd(0x83);
	LCDWriteData(0X03);
	LCDWriteCmd(0xC0);
	LCDWriteData(0X04);
	LCDWriteCmd(0xC1);
	LCDWriteData(0X05);
	LCDWriteCmd(0xC2);
	LCDWriteData(0X06);
	LCDWriteCmd(0xC3);
	LCDWriteData(0X07);
}

