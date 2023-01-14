/*
 * UART_program.c
 *
 * Created: 1/8/2023 5:26:34 PM
 *  Author: Omar Mustafa
 */ 
#include "../../Library/BIT_MATH.h"
#include "UART_private.h"
#include "UART_Interface.h"
void (*UART_Global_Callback[8])(void)={0};


void UART_Init(enum UART_NUM uart_no)
{
	switch(uart_no)
	{
		case UART0:
				/*According to datasheet UBRR must be set to 12 to have a baudrate of 9600*/
				USART0_REG->UBRR0H = 0;
				USART0_REG->UBRR0L = 103;	
				/*This line enables double speed mode*/
				USART0_REG->UCSR0A = (1<<1);	
				/*This line selects the data frame width to be 7 data bits*/
				CLR_BIT(USART0_REG->UCSR0C, 1);
				/*This line enables UART send and receive pins*/
				USART0_REG->UCSR0B = (1<<4) | (1<<3) |(1<<7);
				break;
		case UART1:
			/*According to datasheet UBRR must be set to 12 to have a baudrate of 9600*/
			USART1_REG->UBRR1H = 0;
			USART1_REG->UBRR1L = 103;
			/*This line enables double speed mode*/
			USART1_REG->UCSR1A = (1<<1);
			/*This line selects the data frame width to be 7 data bits*/
			CLR_BIT(USART1_REG->UCSR1C, 1);
			/*This line enables UART send and receive pins*/
			USART1_REG->UCSR1B = (1<<4) | (1<<3);
			break;
		case UART2:
			/*According to datasheet UBRR must be set to 12 to have a baudrate of 9600*/
			USART2_REG->UBRR2H = 0;
			USART2_REG->UBRR2L = 103;
			/*This line enables double speed mode*/
			USART2_REG->UCSR2A = (1<<1);
			/*This line selects the data frame width to be 7 data bits*/
			CLR_BIT(USART2_REG->UCSR2C, 1);
			/*This line enables UART send and receive pins*/
			USART2_REG->UCSR2B = (1<<4) | (1<<3) |(1<<7);
			break;
		case UART3:
			/*According to datasheet UBRR must be set to 12 to have a baudrate of 9600*/
			USART3_REG->UBRR3H = 0;
			USART3_REG->UBRR3L = 103;
			/*This line enables double speed mode*/
			USART3_REG->UCSR3A = (1<<1);
			/*This line selects the data frame width to be 7 data bits*/
			CLR_BIT(USART3_REG->UCSR3C, 1);
			/*This line enables UART send and receive pins*/
			USART3_REG->UCSR3B = (1<<4) | (1<<3);
			break;
		default:
			break;
	}
}
void UART_SendByte(unsigned char Byte, enum UART_NUM uart_no)
{		
		switch(uart_no)
		{
			case UART0:
				/*This line polls UDRE flag to check if Tx register can be written*/
				while ((USART0_REG->UCSR0A & (1<<5)) == 0) { /*Do nothing*/}
				
				/*Assign data to UDR to be sent over UART*/
				USART0_REG->UDR0 = Byte;
				break;
				
			case UART1:
				/*This line polls UDRE flag to check if Tx register can be written*/
				while ((USART1_REG->UCSR1A & (1<<5)) == 0) { /*Do nothing*/}
				
				/*Assign data to UDR to be sent over UART*/
				USART1_REG->UDR1 = Byte;
				break;

			case UART2:
				/*This line polls UDRE flag to check if Tx register can be written*/
				//while ((USART2_REG->UCSR2A & (1<<5)) == 0) { /*Do nothing*/}
				
				/*Assign data to UDR to be sent over UART*/
				USART2_REG->UDR2 = Byte;
				break;
				
			case UART3:
				/*This line polls UDRE flag to check if Tx register can be written*/
				//while ((USART3_REG->UCSR3A & (1<<5)) == 0) { /*Do nothing*/}
				
				/*Assign data to UDR to be sent over UART*/
				USART3_REG->UDR3 = Byte;
				break;
			default:
				break;
		}
}
unsigned char UART_ReceiveByte(enum UART_NUM uart_no)
{		
		switch(uart_no)
		{
			case UART0:
				/*This line polls RXC flag to check if Rx register can be read*/
				//while ((USART0_REG->UCSR0A & (1<<7)) == 0) { /*Do nothing*/}
				//if(USART0_REG->UCSR0A & (1<<5) == 0)
				return USART0_REG->UDR0;

			case UART1:
				/*This line polls RXC flag to check if Rx register can be read*/
				while ((USART1_REG->UCSR1A & (1<<7)) == 0) { /*Do nothing*/}
				return USART1_REG->UDR1;
			case UART2:
				/*This line polls RXC flag to check if Rx register can be read*/
				//while ((USART0_REG->UCSR0A & (1<<7)) == 0) { /*Do nothing*/}
				//if(USART0_REG->UCSR0A & (1<<5) == 0)
				return USART2_REG->UDR2;
			case UART3:
				/*This line polls RXC flag to check if Rx register can be read*/
				while ((USART3_REG->UCSR3A & (1<<7)) == 0) { /*Do nothing*/}
				return USART3_REG->UDR3;
			default:
				break;
		}
	return 0;
}

void MUART_voidSetCallback(enum UART_NUM uart_no,void (*Local_Callback)(void))
{
	UART_Global_Callback[uart_no]= Local_Callback;	
}

void USART2_RX()
{
	if (UART_Global_Callback[UART2] != 0)
		UART_Global_Callback[UART2]();
	else
		return;	
}