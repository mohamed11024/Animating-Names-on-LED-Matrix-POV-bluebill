#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H



typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;



}EXTI_t;



#define EXTI                     ((volatile EXTI_t *)0x40010400)


#define EXTI0                        0
#define EXTI1                        1
#define EXTI2                        2
#define EXTI3                        3

#define FALLING_EDGE                 0
#define RISING_EDGE                  1
#define ON_CHANGE                    2








#endif
