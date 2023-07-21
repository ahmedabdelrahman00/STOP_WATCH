/***********************************************************************/
/***********************************************************************/
/********Author     : Ahmed abdelrahman ********************************/
/********File Name  : LCD_PROG.c        ********************************/
/********Date       : 24/2/2023         ********************************/
/********Version    : V3                ********************************/
/********Desc       : Empty             ********************************/
/***********************************************************************/
/***********************************************************************/

#ifndef LCDINTERFACE_H
#define LCDINTERFACE_H

#include"STD_TYPES.h"
void LCD_VidIntialize();
void LCD_VidSendCommand(u8 value);
void LCD_VidSendData(u8 value);
void LCD_VidSendString(u8 *ptr);
void LCD_VidSendNum(u16 num);
void LCD_VidGOTOPOS(u8 row,u8 col);
void LCD_VidDraw();
void LCD_VidDisplayShift();
void LCD_VidClearDisplay();
void LCD_VidReturnHome();
void LCD_WriteInPosition();

#endif

