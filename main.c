
#include"TIMER_PRIVATE.h"
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include "EXIT_INTERFACE.h"

static int SEC =0;
static int M = 0;
static int H=0;


	void ISR_TIMER0_OV();
	void ISR_EXIT0(void);
	void ISR_EXIT1(void);
	void ISR_EXIT2(void);

void main(void)
{
	DIO_VidSetPinDirection(0,0,1);
	DIO_VidSetPinvalue(0,0,1);

	DIO_VidSetPinDirection(3,2,0);//int0 input
    DIO_VidSetPinvalue(3,2,1);//int0 pullup

    DIO_VidSetPinDirection(3,3,0);//int1 input
    DIO_VidSetPinvalue(3,3,1);//int1 pullup

    DIO_VidSetPinDirection(1,2,0);//int1 input
    DIO_VidSetPinvalue(1,2,1);//int1 pullup



	EXIT0_VidInt();
	LCD_VidIntialize();
	//TIMER_VIDINTI();
	EXIT1_VidInt();
	EXIT2_VidInt();

    TIMER0_voidSetCallBack_OVF(ISR_TIMER0_OV);
	Call_back_EXIT0(ISR_EXIT0);
Call_Back_EXIT1(ISR_EXIT1);
CALL_BACK_EXIT2(ISR_EXIT2);

	while(1)
	{

	}
}


void ISR_EXIT1()
{
	TIMER_VIDINTI();
}
void ISR_EXIT0()
{
	TIMER0_STOP();
}

void ISR_EXIT2()
{
	TIMER0_STOP();
		SEC = 0;
		M = 0;
		H = 0;
		LCD_VidClearDisplay();
		LCD_VidGOTOPOS(0, 4);
		LCD_VidSendString("H :M : S ");
		LCD_VidGOTOPOS(1, 4);
		LCD_VidSendNum(0);
		LCD_VidSendNum(0);
		LCD_VidSendString(":");
		LCD_VidSendNum(0);
		LCD_VidSendNum(0);
		LCD_VidSendString(":");
		LCD_VidSendNum(0);
		LCD_VidSendNum(0);
}



void ISR_TIMER0_OV()



{

//LCD_VidClearDisplay();
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr=0;


LCD_VidGOTOPOS(0,4);
LCD_VidSendString("H :M : S ");

LCD_VidGOTOPOS(1,4);






if (H<=9)
		{
			LCD_VidSendNum(a[arr]);
		}
		LCD_VidSendNum(H);
		LCD_VidSendString(":");
		// LCD_WriteInAnyPosition(0,5);


		if (M<=9)
		{
					LCD_VidSendNum(a[arr]);
		}
		LCD_VidSendNum(M);
		LCD_VidSendString(":");


		/*      second             */

		if (SEC<=9)
		{
			LCD_VidSendNum(a[arr]);
		}
LCD_VidSendNum(SEC);
SEC++;


if(SEC==60)
		{
			M++;
			SEC = 0 ;

			if(M==60)
			{
				H++;
				M=0;
				SEC=0;
			}

			if (H==24)
			{
				H=0;
				SEC=0;
				M=0;
			}

		}
//LCD_VidClearDisplay();






		}
