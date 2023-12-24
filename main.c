/*
 * main.c
 *
 *  Created on: 15 Dec 2023
 *      Author: Ziad Yakoot
 */


#include "STD_types.h"
#include "bitMath.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "KYP_interface.h"
#include "LCD_interface.h"


int main(void)
{
	uint32 num1=0;
	uint32 num2=0;
	uint32 operation=0;
	uint32 result=0;
	uint32 value=0;
	PORT_init();
	LCD_voidinit();
	while(1)
	{
		do
		{
			value=getPressed();
		}while(value == 0xff);
        if (value =='C')
        {
        	 LCD_sendCommand(0x01);
        	     num1=0;
        		 num2=0;
        		 operation=0;

        }
        else
        {
        	LCD_sendData(value);
        	if(value!='+'&&value !='-'&&value !='*'&&value !='/'&&value!='=')
        	{
        		num1=(value -48)+num1*10;
        	}
        	if(value=='+'||value =='-'||value =='*'||value =='/')
        	{
        		num2=num1;
        		num1=0;
        		operation =value;

        	}
        	if(value =='=')
        	{
        		if(operation=='+')
        		{
        			result=num1+num2;
        		}
        		else if(operation=='-')
				{
					result=num2-num1;
				}
        		else if(operation=='*')
				{
					result=num1*num2;
				}
        		else if(operation=='/')
				{
					result=num2/num1;
				}
        		else
        		{
        			result= 'E';
        		}
        		if(result<10)
        		{
        			LCD_sendData(result+48);
        		}
        		else if(result<100)
        		{
        			LCD_sendData(result/10+48);
        			LCD_sendData(result%10+48);
        		}
        		else if(result<1000)
        		{
        			LCD_sendData(result/100+48);
        			LCD_sendData((result%100)/10+48);
        			LCD_sendData(result%10+48);
        		}
        		else
        		{
        			LCD_voidString("ERROR");
        		}



        	}
        }


	}

}
