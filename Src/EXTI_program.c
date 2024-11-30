
#include <stdint.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Error_Type.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void(*EXTI0_CallBack)(void) = NULL;


void EXTI_voidInit(void)
{
#if EXTI_LINE == EXTI0
	SET_BIT(EXTI->IMR,EXTI0);

#elif EXTI_LINE == EXTI1
	SET_BIT(EXTI->IMR,EXTI0);


#elif EXTI_LINE == EXTI2
	SET_BIT(EXTI->IMR,EXTI0);


#elif EXTI_LINE == EXTI3
	SET_BIT(EXTI->IMR,EXTI0);


#else
#error("Wrong External Interrupt Line !")
#endif

#if   EXTI_SENSE_MODE == FALLING_EDGE
	SET_BIT(EXTI->FTSR,EXTI0);
#elif EXTI_SENSE_MODE == RISING_EDGE
	SET_BIT(EXTI->RTSR,EXTI0);
#elif EXTI_SENSE_MODE == ON_CHANGE_EDGE
	SET_BIT(EXTI->FTSR,EXTI0);
	SET_BIT(EXTI->RTSR,EXTI0);

#else
#error("Wrong External Interrupt Line !")
#endif




}
void EXTI_voidSetSignalLatch(uint8_t Copy_u8EXTILine,uint8_t SenseMode)
{
	switch(SenseMode)
	{
	case FALLING_EDGE : SET_BIT(EXTI->FTSR,EXTI0);break;
	case RISING_EDGE : SET_BIT(EXTI->RTSR,EXTI0);break;
	case ON_CHANGE : SET_BIT(EXTI->FTSR,EXTI0);SET_BIT(EXTI->RTSR,EXTI0);break;


	}
	SET_BIT(EXTI->IMR,Copy_u8EXTILine);




}




void EXTI_voidSetCallBack(void *ptr (void))
{

	EXTI0_CallBack = ptr;

}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	SET_BIT(EXTI->PR,0);
}
