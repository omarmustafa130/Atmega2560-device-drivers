/*
 * EXTI_private.h
 *
 * Created: 1/6/2023 7:36:18 PM
 *  Author: Omar Mustafa
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

extern void (*Global_Callback[8])(void);
extern void (*Global_CallbackPCINT[3])(void);

#define EICRA	(*(volatile u8*)0x69)
#define EICRB	(*(volatile u8*)0x6A)
#define EIMSK	(*(volatile u8*)0x3D)
#define EIFR	(*(volatile u8*)0x3C)
#define PCICR	(*(volatile u8*)0x68)
#define PCIFR	(*(volatile u8*)0x3B)
#define PCMSK0	*((volatile u8*)0x6B)
#define PCMSK1	*((volatile u8*)0x6C)
#define PCMSK2	*((volatile u8*)0x6D)



#define EXTI_VEC0 		__vector_1
#define EXTI_VEC1 		__vector_2
#define EXTI_VEC2 		__vector_3
#define EXTI_VEC3 		__vector_4
#define EXTI_VEC4 		__vector_5
#define EXTI_VEC5 		__vector_6
#define EXTI_VEC6 		__vector_7
#define EXTI_VEC7 		__vector_8

void EXTI_VEC0()		__attribute__((signal,used));
void EXTI_VEC1()		__attribute__((signal,used));
void EXTI_VEC2()		__attribute__((signal,used));
void EXTI_VEC3()		__attribute__((signal,used));
void EXTI_VEC4()		__attribute__((signal,used));
void EXTI_VEC5()		__attribute__((signal,used));
void EXTI_VEC6()		__attribute__((signal,used));
void EXTI_VEC7()		__attribute__((signal,used));

#define  EXTI_VEC_PCINT0 		__vector_9
#define  EXTI_VEC_PCINT1 		__vector_10
#define  EXTI_VEC_PCINT2 		__vector_11

void EXTI_VEC_PCINT0()	__attribute__((signal,used));
void EXTI_VEC_PCINT1()	__attribute__((signal,used));
void EXTI_VEC_PCINT2()	__attribute__((signal,used));



#endif /* EXTI_PRIVATE_H_ */