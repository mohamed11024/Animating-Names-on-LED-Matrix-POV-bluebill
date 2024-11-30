#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



void EXTI_voidInit(void);
void EXTI_voidSetSignalLatch(uint8_t Copy_u8EXTILine,uint8_t SenseMode);
void EXTI_voidEnable(uint8_t Copy_u8EXTILine);
void EXTI_voidDisable(uint8_t Copy_u8EXTILine);
void EXTI_voidSoftwareTrigger(uint8_t Copy_u8EXTILine);


void EXTI_voidSetCallBack(void *ptr (void));













#endif
