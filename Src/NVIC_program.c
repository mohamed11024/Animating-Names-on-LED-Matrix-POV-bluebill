/******************************************************/
/*Author    : Mohamed Kamal                           */
/*Date      : 9/2/2024                                */
/*Version   : v01                                     */
/******************************************************/

#include <stdint.h>

#include "BIT_MATH.h"
#include "Error_Type.h"

#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"


void NVIC_voidInterruptEnable(uint8_t Copy_u8InterruptNum)
{

	if(Copy_u8InterruptNum <= 31)
	{
		NVIC_ISER0 = 1 << Copy_u8InterruptNum;
	}

	else if(Copy_u8InterruptNum <= 59)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ISER1 = 1 << Copy_u8InterruptNum;
	}

	else
	{
		//Return Error
	}


}
void NVIC_voidInterruptDisable(uint8_t Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum <= 31)
	{
		NVIC_ICER0 = 1 << Copy_u8InterruptNum;
	}

	else if(Copy_u8InterruptNum <= 59)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ICER1 = 1 << Copy_u8InterruptNum;
	}

	else
	{
		//Return Error
	}



}

void NVIC_voidSetPendingFlag(uint8_t Copy_u8InterruptNum)
{

	if(Copy_u8InterruptNum <= 31)
	{
		NVIC_ISPR0 = 1 << Copy_u8InterruptNum;
	}

	else if(Copy_u8InterruptNum <= 59)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ISPR1 = 1 << Copy_u8InterruptNum;
	}

	else
	{
		//Return Error
	}


}
void NVIC_voidClrearPendingFlag(uint8_t Copy_u8InterruptNum)
{

	if(Copy_u8InterruptNum <= 31)
	{
		NVIC_ICPR0 = ((1) << (Copy_u8InterruptNum));
	}

	else if(Copy_u8InterruptNum <= 59)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ICPR1 = 1 << Copy_u8InterruptNum;
	}

	else
	{
		//Return Error
	}


}

uint8_t NVIC_u8GetActiveFlag(uint8_t Copy_u8InterruptNum)
{

	uint8_t Local_u8Res = OK;

	if(Copy_u8InterruptNum <= 31)
	{
		Local_u8Res = GET_BIT(NVIC_IABR0,Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <= 59)
	{
		Copy_u8InterruptNum -= 32;
		Local_u8Res = GET_BIT(NVIC_IABR1,Copy_u8InterruptNum);

	}
	else
	{
		//Return Error
		Local_u8Res = NOK;
	}
	return Local_u8Res;


}

void NVIC_voidSetPriority(uint8_t Copy_u8IntID,uint8_t Copy_u8GroupPriority,uint8_t Copy_u8SubPriority,uint32_t Copy_u32Group)
{
	 uint8_t Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<((Copy_u32Group - 0x05FA0300)/256));
	 NVIC_IPR[Copy_u8IntID] = Local_u8Priority << 4;

	 SCB_AIRCR = Copy_u32Group;






}


