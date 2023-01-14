/*
 * GPIO_program.c
 *
 * Created: 1/5/2023 11:04:47 PM
 *  Author: Omar Mustafa
 */ 
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

volatile PORT_t* PGPIO_PORT_tPtrGetRegister (enum GPIO_PORT_ID_t PORT_ID)
{
	switch(PORT_ID){
		case GPIO_PORTA:
			return PORTA_REGS;
		case GPIO_PORTB:
			return PORTB_REGS;
		case GPIO_PORTC:
			return PORTC_REGS;
		case GPIO_PORTD:
			return PORTD_REGS;
		case GPIO_PORTE:
			return PORTE_REGS;
		case GPIO_PORTF:
			return PORTF_REGS;
		case GPIO_PORTG:
			return PORTG_REGS;
		case GPIO_PORTH:
			return PORTH_REGS;
		case GPIO_PORTJ:
			return PORTJ_REGS;
		case GPIO_PORTK:
			return PORTK_REGS;
		case GPIO_PORTL:
			return PORTL_REGS;
		default:
			return 0;
	}
}

/*GPIO functions*/
void MGPIO_VoidSetPortDirection(enum GPIO_PORT_ID_t GPIO_PORT_ID, enum GPIO_DIRECTION_t GPIO_DIRECTION)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(GPIO_PORT_ID);
	if (P == 0)
		return;
	switch(GPIO_DIRECTION)
	{
		case GPIO_INPUT:
			P->DDR = 0;
			break;
		case GPIO_OUTPUT:
			P->DDR=255;
			break;
		case GPIO_INPUT_PULLUP:
			P->DDR=0;
			P->PORT=255;
			break;
	}
}

void MGPIO_VoidSetPinDirection(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo, enum GPIO_DIRECTION_t GPIO_DIRECTION)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(GPIO_PORT_ID);
	if (P == 0)
		return;
	switch(GPIO_DIRECTION)
	{
		case GPIO_INPUT:
			CLR_BIT(P->DDR, Copy_u8PinNo);
			break;
		case GPIO_OUTPUT:
			SET_BIT(P->DDR, Copy_u8PinNo);
			break;
		case GPIO_INPUT_PULLUP:
			CLR_BIT(P->DDR, Copy_u8PinNo);
			SET_BIT(P->PORT, Copy_u8PinNo);
			break;
	}
	
}

void MGPIO_VoidSetPortValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8Value)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(GPIO_PORT_ID);
	if (P == 0)
		return;
	P->PORT = Copy_u8Value;
}

void MGPIO_VoidSetPinValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo, enum GPIO_VALUE_t GPIO_VALUE)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(GPIO_PORT_ID);
	if (P == 0)
		return;
	switch(GPIO_VALUE)
	{
		case GPIO_LOW:
			CLR_BIT(P->PORT, Copy_u8PinNo);
			break;
		case GPIO_HIGH:
			SET_BIT(P->PORT, Copy_u8PinNo);
			break;
	}
}

u8 MGPIO_VoidGetPortValue(enum GPIO_PORT_ID_t GPIO_PORT_ID)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(GPIO_PORT_ID);
	if (P == 0)
		return 0;
	return P->PIN;	
}
u8 MGPIO_VoidGetPinValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(GPIO_PORT_ID);
	if (P == 0)
		return 0;
	return (GET_BIT(P->PIN, Copy_u8PinNo));	
}

void MGPIO_VoidTogglePinValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(GPIO_PORT_ID);
	if (P == 0)
		return;
	TOG_BIT(P->PORT, Copy_u8PinNo);	
}