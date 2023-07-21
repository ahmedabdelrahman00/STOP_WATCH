#include "TIMER_PRIVATE.h"
#include "TIMER_CONFG.h" // Include TIMER_CONFG.h

#include "STD_TYPES.h"
#include "BIT_MATH.h"


void (*Global_PointerToFunction_OVF_T0) (void) = NULL;

void TIMER_VIDINTI()
{
    /* SELECT MODE */
#if MODE == NORMAL
    CLR_BIT(TCCR0, 3);
    CLR_BIT(TCCR0, 6);
    /* PRELOAD VALUE = 133 */
    TCNT0 = 238;
#elif MODE == CTC
    SET_BIT(TCCR0, 3);
    CLR_BIT(TCCR0, 6);

#endif



    /* ENABLE OVERFLOW INTERRUPT */
    SET_BIT(TIMSK, 0);


/*
select mode
preload value
enable overflow interruot
select prescaleer
*/

    /* PRESCALER VALUE = 1024 */
#if  PRESCALLER == STOP_PRESCALLER
      CLR_BIT(TCCR0,0);
      CLR_BIT(TCCR0,1);
      CLR_BIT(TCCR0,2);

#elif PRESCALLER == PRESCALLER_1
      SET_BIT(TCCR0,0);
      CLR_BIT(TCCR0,1);
      CLR_BIT(TCCR0,2);

#elif PRESCALLER == PRESCALLER_8
      CLR_BIT(TCCR0,0);
      SET_BIT(TCCR0,1);
      CLR_BIT(TCCR0,2);

#elif PRESCALLER == PRESCALLER_64
      SET_BIT(TCCR0,0);
      SET_BIT(TCCR0,1);
      CLR_BIT(TCCR0,2);

#elif PRESCALLER == PRESCALLER_256
      CLR_BIT(TCCR0,0);
      CLR_BIT(TCCR0,1);
      SET_BIT(TCCR0,2);

#elif PRESCALLER == FALLING_EDGE
      CLR_BIT(TCCR0,0);
      SET_BIT(TCCR0,1);
      SET_BIT(TCCR0,2);

#elif PRESCALLER == RISING_EDGE
      SET_BIT(TCCR0,0);
      SET_BIT(TCCR0,1);
      SET_BIT(TCCR0,2);


#endif


    /* Enable global interrupt */
    SET_BIT(SREG, 7);
}


void TIMER0_voidSetCallBack_OVF (void (*PTR) (void))
{
	if (PTR != NULL)
		{
			 Global_PointerToFunction_OVF_T0 = PTR ;
		}

}

void TIMER0_STOP()
{
	CLR_BIT(TIMSK, 0);
}


void TIMER0_RESUME()
{
	SET_BIT(TIMSK, 0);
}


void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{


    static u64 counter = 0;
    counter++;
    if (counter == 125)
    {
		Global_PointerToFunction_OVF_T0();

        counter = 0;
        /* PRELOAD VALUE = 133 */
        TCNT0 = 238;
    }
}
