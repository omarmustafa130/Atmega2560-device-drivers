/*
 * UART_interface.h
 *
 * Created: 1/8/2023 5:26:22 PM
 *  Author: Omar Mustafa
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../../Library/STD_TYPES.h"

#define UART_BAUDRATE 9600

enum UART_NUM {UART0, UART1, UART2, UART3};
void UART_Init(enum UART_NUM uart_no);
void UART_SendByte(u8 Byte, enum UART_NUM uart_no);
u8 UART_ReceiveByte(enum UART_NUM uart_no);

void MUART_voidSetCallback(enum UART_NUM uart_no,void (*Local_Callback)(void));



#endif /* UART_INTERFACE_H_ */