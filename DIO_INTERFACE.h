/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : DIO_Interface.H     ********************************/
/********Date       : 17/9/2022         ********************************/
/********Version    : V1                ********************************/
/********Desc       : Empty             ********************************/
/***********************************************************************/

#ifndef DIO_INTERFACE_h
#define DIO_INTERFACE_h
#include"STD_TYPES.h"

#define OUTPUT 1
#define INPUT  0
#define HIGH   1
#define LOW    0
#define PORT_OUTPUT 255
#define PORT_INPUT  0


void  DIO_VidSetPinDirection(u8 port ,u8 pin ,  u8 dir);
void  DIO_VidSetPortDirection(u8 port , u8 dir);
void  DIO_VidSetPinvalue(u8 port , u8 pin , u8 value);
void  DIO_VidSetPortvalue(u8 port , u8 value); 
u8    DIO_u8GetPinValue(u8 port , u8 pin);
void  DIO_VidTogglePinValue(u8 port , u8 pin);

#endif

