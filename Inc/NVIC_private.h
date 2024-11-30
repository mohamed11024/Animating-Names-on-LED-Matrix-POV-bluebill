
/******************************************************/
/*Author    : Mohamed Kamal                           */
/*Date      : 9/2/2024                                */
/*Version   : v01                                     */
/******************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_ISER0                        *((uint32_t*)0xE000E100)
#define NVIC_ISER1                        *((uint32_t*)0xE000E104)

#define NVIC_ICER0                        *((uint32_t*)0xE000E180)
#define NVIC_ICER1                        *((uint32_t*)0xE000E184)

#define NVIC_ISPR0                        *((uint32_t*)0xE000E200)
#define NVIC_ISPR1                        *((uint32_t*)0xE000E204)

#define NVIC_ICPR0                        *((uint32_t*)0xE000E280)
#define NVIC_ICPR1                        *((uint32_t*)0xE000E284)

#define NVIC_IABR0                        *((volatile uint32_t*)0xE000E200)
#define NVIC_IABR1                        *((volatile uint32_t*)0xE000E204)

#define NVIC_IPR                          ((uint8_t*)(0xE000E400))

#define SCB_AIRCR                         *((volatile uint32_t*)(0xE000ED00+0x0C))






#endif
