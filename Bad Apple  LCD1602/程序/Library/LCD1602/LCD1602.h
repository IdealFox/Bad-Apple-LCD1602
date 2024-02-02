#ifndef __LCD1602_H__
#define __LCD1602_H__

#include <REGX52.H>

//IO口定义
sbit LCD1602_RS = P2^4;
sbit LCD1602_RW = P2^5;
sbit LCD1602_EN = P2^6;
#define LCD1602_DB P0

//LCD1602指令定义
//显示模式设置指令
#define LCD_MODE_PIN8				0X38		//8位数据口，两行，5*8点阵
#define	LCD_MODE_PIN4				0X28		//4位数据口，两行，5*8点阵

#define	LCD_SCREEN_CLR				0X01		//清屏
#define LCD_CURSOR_RST				0X02		//光标复位

//显示开关控制指令
#define	LCD_DIS_CUR_BLK_ON			0X0F		//显示开，光标开，光标闪烁
#define	LCD_DIS_CUR_ON				0X0E		//显示开，光标开，光标不闪烁
#define	LCD_DIS_ON					0X0C		//显示开，光标关，光标不闪烁
#define	LCD_DIS_OFF					0X08		//显示关，光标关，光标不闪烁

//显示控制模式
#define	LCD_CURSOR_RIGHT			0X06		//光标右移，显示不移动
#define	LCD_CURSOR_LEFT				0X04		//光标左移，显示不移动
#define	LCD_DIS_MODE_LEFT			0X07		//操作后，AC自增，画面平移
#define	LCD_DIS_MODE_RIGHT			0X05		//操作后，AC自减，画面平移

//光标，显示移动指令
#define	LCD_CUR_MOVE_LEFT			0X10		//光标左移
#define	LCD_CUR_MOVE_RIGHT			0X14		//光标右移
#define	LCD_DIS_MOVE_LEFT			0X18		//显示左移
#define	LCD_DIS_MOVE_RIGHT			0X1C		//显示右移


//函数声明
void LCD_Init();																					//LCD1602初始化
void LCD_Clear();																					//清屏
//void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);								//显示单个字符
//void LCD_ShowStr(unsigned char Line,unsigned char Column,unsigned char *Str);						//显示字符串
//void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);	//显示字符

void LCDWriteCGRAM(unsigned char sec,unsigned char time);
void LCD_Custom();



#endif
