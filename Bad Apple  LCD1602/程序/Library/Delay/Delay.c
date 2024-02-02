#include <REGX52.H>
#include <INTRINS.H>
#include <Delay.h>

void Delay_us(unsigned int us)		//@12.000MHz
{
	while(us)
	{
		_nop_();
		us--;
	}
}

void Delay_ms(unsigned int ms)		//@12.000MHz
{
	while(ms)
	{
		unsigned char i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		}
		while (--i);
		ms--;
	}
}
void Delay_s(unsigned int s)		//@12.000MHz
{
	while(s)
	{
		unsigned char i, j, k;

		_nop_();
		i = 8;
		j = 154;
		k = 122;
		do
		{
			do
			{
				while (--k);
			} 
			while (--j);
		}
		while (--i);
		s--;
	}
}



