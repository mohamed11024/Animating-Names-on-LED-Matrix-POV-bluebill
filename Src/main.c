#include <stdint.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Error_Type.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "LED_MATRIX_interface.h"
#include "STK_interface.h"

volatile u8 u8Flag = 0;
volatile u32 u8Data[50] = {0};
volatile u8 u8EdgeCounter = 0;
volatile u8 Data = 0;

u8 Ball1[8] = {0, 0, 0, 0, 0, 0, 0, 32};
u8 Ball2[8] = {0, 0, 0, 0, 0, 0, 0, 16};
u8 Ball3[8] = {0, 0, 0, 0, 0, 0, 0, 8};
u8 Ball4[8] = {0, 0, 0, 0, 0, 0, 0, 4};
u8 Ball5[8] = {0, 0, 0, 0, 0, 0, 0, 2};
u8 Ball6[8] = {0, 0, 0, 0, 0, 0, 0, 1};

u8 LED_OFF[8] = {0,0,0,0,0,0,0,0};

u8 Hamoksha1[8] = {0, 0, 214, 126, 214, 0, 0, 0};

/*
 u8 Ball2[8] = {0, 0, 0, 0, 0, 0, 16, 0};
 u8 Ball3[8] = {0, 0, 0, 0, 0, 0, 8, 0};
 u8 Ball4[8] = {0, 0, 0, 0, 0, 0, 4, 0};
 u8 Ball5[8] = {0, 0, 0, 0, 0, 0, 2, 0};
 u8 Ball6[8] = {0, 0, 0, 0, 0, 0, 1, 0};
 */

void voidPlay(void)
{
	if(Data == 24)
	{

		for(u8 i =0;i<250;i++)
		{
			LED_MATRIX_voidDisplay(Hamoksha1);
		}
		if(Data == 12)
		{
			LED_MATRIX_voidDisplay(Ball1);
			STK_voidSetBusyWait(100000);
			LED_MATRIX_voidDisplay(LED_OFF);

			LED_MATRIX_voidDisplay(Ball1);
			STK_voidSetBusyWait(100000);
			LED_MATRIX_voidDisplay(LED_OFF);

			LED_MATRIX_voidDisplay(Ball1);
			STK_voidSetBusyWait(100000);
			LED_MATRIX_voidDisplay(LED_OFF);

			LED_MATRIX_voidDisplay(Ball1);
			STK_voidSetBusyWait(100000);
			LED_MATRIX_voidDisplay(LED_OFF);

		}

	}



		/*for(s8 k=4;k>=0;k--){
			for(u8 z =0;z<25;z++)
			{
				LED_MATRIX_voidDisplay(Ball1[k]);
			}
			LED_MATRIX_voidDisplay(LED_OFF);
		}
		 */



	}










void voidTakeAction(void)
{

	u8 i;
	Data = 0;

	if((u8Data[0]>=10000) && (u8Data[0]<=14000))
	{

		for(i=0;i<8;i++)
		{
			if((u8Data[17+i]>=2000)&&(u8Data[17+i]<=2300))
			{
				SET_BIT(Data,i);
			}
			else
			{
				CLR_BIT(Data,i);
			}


		}
		voidPlay();

	}


	u8Data[0] = 0;
	u8EdgeCounter = 0;
	u8Flag = 0;
}


void GetPattern(void)
{


	if(u8Flag == 0)
	{
		STK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8Flag = 1;
	}
	else
	{
		u8Data[u8EdgeCounter] = STK_u32GetElapsedTime();
		STK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;


	}


}
int main()
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(t_APB2 ,GPIOA);
	RCC_voidEnableClock(t_APB2 ,3);




	EXTI_voidSetCallBack(&GetPattern);
	EXTI_voidInit();

	NVIC_voidInterruptEnable(6);
	LED_MATRIX_voidInit();
	STK_voidInit();


	while(1)
	{




	}


}


