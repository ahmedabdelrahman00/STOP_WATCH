

/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : LCD_PROG.c        ********************************/
/********Date       : 24/2/2023         ********************************/
/********Version    : V3                ********************************/
/********Desc       : Empty             ********************************/
/***********************************************************************/
/***********************************************************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H



/*

LCD driver based on DIO driver

RS -> 1 for data 0-> command (PORTD pin 0)
RW -> zero PORTD PIN 1

VO for POT
VSS -> GND
VDD -> POWER
D0-D7 -> PORT
E - > PORTD pin 2
*/



/* this macro define the data port  of lcd
   OPTIONS: 0-> PORTA	1->PORTB	2->PORTC	3->PORTD
*/
#define DATAPORT 2



/* this macro define the control port of lcd  (RS , RW , E)
   OPTIONS: 0-> PORTA	1->PORTB	2->PORTC	3->PORTD
*/
#define CONTROLPORT 3



/*  the macro defines the register select port of lcd
OPTIONS:  range [0-7] ->pins
 */
#define PINRS  5



/*  the macro defines the read write port of lcd
OPTIONS:  range [0-7] ->pins
 */
#define PINRW  6



/*  the macro defines the enable port of lcd
OPTIONS:  range [0-7] ->pins
 */
#define PINE   7



#define FUNCTION_SET    0b00111000
#define ON_OFF          0b00001111
#define DISPLAY_CLEAR   0b00000001
#endif
