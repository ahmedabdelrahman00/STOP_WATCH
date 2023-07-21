/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : TIMER_Private.h   ********************************/
/********Date       : 19/07/2023        ********************************/
/********Version    : V2                ********************************/
/********Desc       : Empty             ********************************/


#ifndef TIMER_PRIVATE_h
#define TIMER_PRIVATE_h


#define TCCR0  *((u8*)0x53)
#define TCNT0  *((u8*)0x52)
#define TIMSK  *((u8*)0x59)
#define TIFR  *((u8*)0x58)
#define SFIOR  *((u8*)0x50)
#define OCR0  *((u8*)0x5C)

#define SREG  *((u8*)0x5F)


void __vector_11(void) __attribute__((signal));



#endif
