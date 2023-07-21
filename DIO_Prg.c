
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"






void DIO_VidSetPinDirection(u8 port ,u8 pin ,  u8 dir)
{
	if (0 == dir )
	{
		switch (port)
		{
			case 0 : CLR_BIT (DDRA , pin ); break; 
			case 1 : CLR_BIT (DDRB , pin ); break; 
			case 2 : CLR_BIT (DDRC , pin ); break; 
			case 3 : CLR_BIT (DDRD , pin ); break; 
		}
	}
	
	
	else if (1 == dir)
	{
		switch (port)
		{
			case 0 : SET_BIT (DDRA , pin ); break;
			case 1 : SET_BIT (DDRB , pin ); break; 
			case 2 : SET_BIT (DDRC , pin ); break; 
			case 3 : SET_BIT (DDRD , pin ); break; 
		}
	}
	
	
	else 
	{
		//do no thing 
	}
}





void DIO_VidSetPortDirection(u8 port , u8 dir)
{
	
	switch(port)
	{
		case 0:  DDRA = dir;  break;
		case 1:  DDRB = dir;  break;
		case 2:  DDRC = dir;  break;
		case 3:  DDRD = dir;  break;
		default : break;
	}
	
	
	
	
}




void DIO_VidSetPinvalue(u8 port , u8 pin , u8 value)
{
	
	if (0 == value )
	{


		switch (port)
		{
			case 0 :  CLR_BIT (PORTA , pin); break;			case 1 :  CLR_BIT (PORTB , pin) ; break;
			case 2 :  CLR_BIT (PORTC , pin) ; break;
			case 3 :  CLR_BIT (PORTD , pin); break;
			
		}

	}
	
	else if (1 == value )
	{
		switch (port)
		{
			case 0 :  SET_BIT(PORTA , pin); break;
			case 1 :  SET_BIT (PORTB , pin); break;
			case 2 :  SET_BIT (PORTC , pin); break;
			case 3 :  SET_BIT (PORTD , pin); break;
			
		}
	}
	
	else {
		//do no thing 
	}
	
		
}




void DIO_VidSetPortvalue(u8 port , u8 value)
{
	switch(port)
	{
		case 0:  PORTA = value;  break;
		case 1:  PORTB = value;  break;
		case 2:  PORTC = value;  break;
		case 3:  PORTD = value;  break;
		default : break;
	}
	
}


 u8 DIO_u8GetPinValue(u8 port , u8 pin)
{
	u8 x = 0 ;
	switch(port)
	{
		case 0 : x = GET_BIT (PINA , pin ); break;
		case 1 : x = GET_BIT (PINB , pin ); break;
		case 2 : x = GET_BIT (PINC , pin ); break;
		case 3 : x = GET_BIT (PIND , pin ); break;
		default : break;  //do no thing
	}
   return x ;     
	
}


void  DIO_VidTogglePinValue(u8 port , u8 pin)
{
	u8 x = 0 ;
		switch(port)
		{
			case 0 : x = TOGGLE_BIT (PORTA , pin ); break;
			case 1 : x = TOGGLE_BIT (PORTB , pin ); break;
			case 2 : x = TOGGLE_BIT (PORTC , pin ); break;
			case 3 : x = TOGGLE_BIT (PORTD , pin ); break;
			default : break;  //do no thing
		}

	
}
