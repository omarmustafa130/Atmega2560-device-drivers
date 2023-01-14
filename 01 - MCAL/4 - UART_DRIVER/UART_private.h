/*
 * UART_private.h
 *
 * Created: 1/8/2023 5:26:54 PM
 *  Author: Omar Mustafa
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "../../Library/STD_TYPES.h"


typedef struct
{
	u8 UCSR0A;
	u8 UCSR0B;
	u8 UCSR0C;
	u8 RESERVED;
	u8 UBRR0L;		//USART baud rate register low
	u8 UBRR0H;		//USART baud rate register high
	u8 UDR0;		//USART I/O data register
}USART0_REGs;


typedef struct
{
	u8 UCSR1A;
	u8 UCSR1B;
	u8 UCSR1C;
	u8 RESERVED1;
	u8 UBRR1L;		//USART baud rate register low
	u8 UBRR1H;		//USART baud rate register high
	u8 UDR1;		//USART I/O data register
}USART1_REGs;


typedef struct
{
	u8 UCSR2A;
	u8 UCSR2B;
	u8 UCSR2C;
	u8 RESERVED2;
	u8 UBRR2L;		//USART baud rate register low
	u8 UBRR2H;		//USART baud rate register high
	u8 UDR2;		//USART I/O data register
}USART2_REGs;

typedef struct
{
	u8 UCSR3A;
	u8 UCSR3B;
	u8 UCSR3C;
	u8 RESERVED3;
	u8 UBRR3L;		//USART baud rate register low
	u8 UBRR3H;		//USART baud rate register high
	u8 UDR3;		//USART I/O data register
}USART3_REGs;

#define USART0_REG 		((volatile USART0_REGs*)0xC0)
#define USART1_REG 		((volatile USART1_REGs*)0xC8)
#define USART2_REG 		((volatile USART2_REGs*)0xD0)
#define USART3_REG 		((volatile USART3_REGs*)0x130)

extern void (*UART_Global_Callback[8])(void);


#define USART0_RX		__vector_25
#define USART0_RE		__vector_26
#define USART0_TX		__vector_27

#define USART1_RX		__vector_36
#define USART1_RE		__vector_37
#define USART1_TX		__vector_38

#define USART2_RX		__vector_51
#define USART2_RE		__vector_52
#define USART2_TX		__vector_53

#define USART3_RX		__vector_54
#define USART3_RE		__vector_55
#define USART3_TX		__vector_56

void USART0_RX(void)__attribute__((signal,used));
void USART0_RE(void)__attribute__((signal,used));
void USART0_TX(void)__attribute__((signal,used));

void USART1_RX(void)__attribute__((signal,used));
void USART1_RE(void)__attribute__((signal,used));
void USART1_TX(void)__attribute__((signal,used));

void USART2_RX(void)__attribute__((signal,used));
void USART2_RE(void)__attribute__((signal,used));
void USART2_TX(void)__attribute__((signal,used));

void USART3_RX(void)__attribute__((signal,used));
void USART3_RE(void)__attribute__((signal,used));
void USART3_TX(void)__attribute__((signal,used));


#endif /* UART_PRIVATE_H_ */