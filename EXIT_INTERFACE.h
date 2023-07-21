/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : EXIT_Interface.h  ********************************/
/********Date       : 08/10/2022        ********************************/
/********Version    : V1                ********************************/
/********Desc       : Empty             ********************************/

void EXIT0_VidInt();
void EXIT1_VidInt();
void EXIT2_VidInt();



void __vector_1();
void __vector_2();
void __vector_3();



void Call_back_EXIT0( void (*ptr)(void));
void Call_back_EXIT1( void (*ptr)(void));
void Call_back_EXIT2( void (*ptr)(void));



void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

