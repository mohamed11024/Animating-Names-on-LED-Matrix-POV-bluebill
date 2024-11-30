/******************************************************/
/*Author    : Mohamed Kamal                           */
/*Date      : 9/2/2024                                */
/*Version   : v01                                     */
/******************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


#define GROUP_4_SUB_0                    0x05FA0300 //4bits for group =>IPR
#define GROUP_3_SUB_1                    0x05FA0400 //3bits for group and 1bit for sub
#define GROUP_2_SUB_2                    0x05FA0500 //2bits for group and 2 bits for sub
#define GROUP_1_SUB_3                    0x05FA0600 //1bit for group and 3 bits for sub
#define GROUP_0_SUB_4                    0x05FA0700 //0group and 4bits for sub


#define EXTI0                  6
#define EXTI1                  7


void NVIC_voidInterruptEnable(uint8_t Copy_u8InterruptNum);
void NVIC_voidInterruptDisable(uint8_t Copy_u8InterruptNum);

void NVIC_voidSetPendingFlag(uint8_t Copy_u8InterruptNum);
void NVIC_voidClrearPendingFlag(uint8_t Copy_u8InterruptNum);

uint8_t NVIC_u8GetActiveFlag(uint8_t Copy_u8InterruptNum);

void NVIC_voidSetPriority(uint8_t Copy_u8IntID,uint8_t Copy_u8GroupPriority,uint8_t Copy_u8SubPriority,uint32_t Copy_u32Group);


#endif
