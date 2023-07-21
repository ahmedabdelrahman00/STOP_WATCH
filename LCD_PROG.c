/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : LCD_PROG.c        ********************************/
/********Date       : 24/2/2023         ********************************/
/********Version    : V3                ********************************/
/********Desc       : Empty             ********************************/
/***********************************************************************/
/***********************************************************************/
#include"DIO_INTERFACE.h"
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<util/delay.h>
#include "LCD_CONFG.h" 
static int once =1;

void LCD_VidSendCommand(u8 value)
{
	/*  let rs low  */
	 DIO_VidSetPinvalue(CONTROLPORT,PINRS,0);

	/*  let rw low  */
	 DIO_VidSetPinvalue(CONTROLPORT,PINRW,0);

    /*  SEND COMMAND */
	 DIO_VidSetPortvalue(DATAPORT,value);


	/*  let EN HIGH  */
	 DIO_VidSetPinvalue(CONTROLPORT,PINE,1);

	_delay_ms(1);
	
    /*  let EN LOW  */
	DIO_VidSetPinvalue(CONTROLPORT,PINE,0);

	_delay_ms(1);

}

void LCD_VidIntialize()
{
	/*Set output PORT */
	DIO_VidSetPortDirection(DATAPORT,255);
	
	
	
	/* configre RS RW E */
	
	DIO_VidSetPinDirection(CONTROLPORT,PINRS,1);
	DIO_VidSetPinDirection(CONTROLPORT,PINRW,1);
    DIO_VidSetPinDirection(CONTROLPORT,PINE,1);
	
	
	/*Set of LCD data sheet commands*/
	_delay_ms(40);
	LCD_VidSendCommand(FUNCTION_SET);
	
	_delay_ms(1);
	LCD_VidSendCommand(ON_OFF);

	_delay_ms(1);
	LCD_VidSendCommand(DISPLAY_CLEAR);

	_delay_ms(2);
}




void LCD_VidSendData(u8 value)
{

	if (once > 16 && 16>once)
		{
			LCD_WriteInPosition();
			once = 0;
		}

	/*Set RS */

	DIO_VidSetPinvalue(CONTROLPORT,PINRS,1);

	/*RW*/

	DIO_VidSetPinvalue(CONTROLPORT,PINRW,0);

	/* Send data in ascii */

	DIO_VidSetPortvalue(DATAPORT,value);

	/* enable sequence */

	DIO_VidSetPinvalue(CONTROLPORT,PINE,1);

	_delay_ms(1);

	DIO_VidSetPinvalue(CONTROLPORT,PINE,0);
    once++;
	_delay_ms(1);


}


void LCD_VidSendNum(u16 num)
{
	u8 x = 0;
	u16 rev = 0;

	if(num == 0)
	{
		LCD_VidSendData(48);
		return ;

	}

	while(num)
	{
		rev = (rev *10) + (num %10);

		num/=10;
		x++;

	}
	while(x)
	{
		u8 p = rev%10+48;

		LCD_VidSendData(p);

		rev/=10;

		x--;

	}


}










void LCD_VidGOTOPOS(u8 row,u8 col)
{
	if( 0 == row)
	{
		LCD_VidSendCommand(128 + col);
	}

	if(1 == row)
	{
		LCD_VidSendCommand(128 + 64 + col);
	}
}


void LCD_VidDraw()
{
	LCD_VidSendCommand(64);

	LCD_VidSendData(0b00000001);
	LCD_VidSendData(0b00000001);
	LCD_VidSendData(0b00000001);
	LCD_VidSendData(0b00000001);
	LCD_VidSendData(0b00000001);
	LCD_VidSendData(0b00000001);

	/* got to DDRAM  */
	LCD_VidGOTOPOS(0,0);

	LCD_VidSendData(0);


}


void LCD_VidSendString(u8 *ptr)
{
	u8 i;

	for(i=0 ; ptr[i] != '\0' ;i++)
	{
		LCD_VidSendData(ptr[i]);

	}
}


void LCD_VidDisplayShift()
{
	LCD_VidSendCommand(0b00011100);
}


void LCD_VidClearDisplay()
{
	LCD_VidSendCommand(0b00000001);
}


void LCD_VidReturnHome()
{
	LCD_VidSendCommand(0b00000011);
}

void LCD_WriteInPosition()
{
	u8 Address;

		Address = (1 * 0x40)  ;
		Address = SET_BIT(Address,7); // data sheet pin 7 is high
		LCD_VidSendCommand(Address);

}




