/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : EXIT_Private.h    ********************************/
/********Date       : 08/10/2022        ********************************/
/********Version    : V1                ********************************/
/********Desc       : Empty             ********************************/

#ifndef EXIT_PRIVATE_h
#define EXIT_PRIVATE_h

#define MCUCR  *((u8*)0x55)

#define MCUCSR *((u8*)0x54)

#define SREG  *((u8*)0x5F)

#define GIFR  *((u8*)0x5A)

#define GICR  *((u8*)0x5B)

/*  to prevent compiler from optomize         */
void __vector_1(void) __attribute__((signal));


#endif

