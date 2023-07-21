/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : EXIT_Private.h    ********************************/
/********Date       : 08/10/2022        ********************************/
/********Version    : V1                ********************************/
/********Desc       : Empty             ********************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Exit_PRIVATE.h"
#define NULL  0

void (*EXIT_CALLBACK_0)(void) = NULL ;
void (*EXIT_CALLBACK_1)(void) = NULL ;
void (*EXIT_CALLBACK_2)(void) = NULL ;


void EXIT0_VidInt(u8 intrrupt)
{


	/*  THE INTERUPT 0 IS SET TO FALLING EDGE   */
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
	/*  THE INTERUPT 0 IS ENABLE TO PIE         */
	SET_BIT(GICR,6);
    /*  GIE = ENABLE                            */
    SET_BIT(SREG,7);
	}



void EXIT1_VidInt()
{
	/*       RISING  EDGE                      */
	MCUCR |= 1 << 3 ;
	MCUCR |= 1 << 2 ;

	/*       INTERRUPT 1 IS ENABLE TO PIE      */
	GICR  |= 1 <<7  ;
	GIFR  |= 1 <<7  ;
	/*       GIE ENABLE                        */
	SREG  |= 1 <<7  ;
}



void EXIT2_VidInt()
{
	/*       RISING  EDGE                      */
	    MCUCSR |= 1<<6 ;
	/*       INTERRUPT 1 IS ENABLE TO PIE      */
		GICR  |= 1 <<5  ;
		GIFR  |= 1 <<5  ;
	/*       GIE ENABLE                        */
	    SREG  |= 1 <<7  ;
}






void Call_back_EXIT0( void (*ptr)(void))
{
	if(ptr != 0)
	{
		EXIT_CALLBACK_0  = ptr;
	}

}


void Call_Back_EXIT1(void(*ptr)(void))
{
	if (ptr!=NULL)
	{
		EXIT_CALLBACK_1 = ptr;
	}
}


void CALL_BACK_EXIT2(void(*ptr)(void))
{
	if (ptr != NULL)
	{
		EXIT_CALLBACK_2 = ptr;
	}
}




void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXIT_CALLBACK_0();

}



void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXIT_CALLBACK_1();

}


void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXIT_CALLBACK_2();

}
