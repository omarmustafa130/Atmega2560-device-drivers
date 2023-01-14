/*
 * EXTI_program.c
 *
 * Created: 1/6/2023 7:36:48 PM
 *  Author: Omar Mustafa
 */ 

#include "../../Library/BIT_MATH.h"
#include "../2 - GIE_DRIVER/GIE_interface.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

void (*Global_Callback[8])(void)={0};
void (*Global_CallbackPCINT[3])(void)={0};
void MEXTI_voidSetCallback(enum EXTI_ID_t EXTI_ID,void (*Local_Callback)(void))
{
	Global_Callback[EXTI_ID]= Local_Callback;
}

void MEXTI_voidEnable(enum EXTI_ID_t EXTI_ID,enum EXTI_Trigger_t EXTI_Trigger)
{
	GIE_voidEnable();
	switch(EXTI_ID)
	{
		case EXTI_INT0:
			EIMSK|= 1<<EXTI_ID;
			EICRA |= EXTI_Trigger;
			break;
		case EXTI_INT1:
			EIMSK|= (1<<EXTI_ID);
			EICRA |= (EXTI_Trigger<<2);
			break;
		case EXTI_INT2:
			EIMSK|= 1<<EXTI_ID;
			EICRA |= EXTI_Trigger<<4;
			break;
		case EXTI_INT3:
			EIMSK|= (1<<EXTI_ID);
			EICRA |= (EXTI_Trigger<<6);
			break;
		case EXTI_INT4:
			EIMSK|= 1<<EXTI_ID;
			EICRB |= EXTI_Trigger;
			break;
		case EXTI_INT5:
			EIMSK|= 1<<EXTI_ID;
			EICRB |= (EXTI_Trigger<<2);
			break;
		case EXTI_INT6:
			EIMSK|= 1<<EXTI_ID;
			EICRB |= EXTI_Trigger<<4;
			break;
		case EXTI_INT7:
			EIMSK|= 1<<EXTI_ID;
			EICRB |= (EXTI_Trigger<<6);
			break;
	}
}


void MEXTI_voidDisable(enum EXTI_ID_t EXTI_ID)
{
	CLR_BIT(EIMSK,EXTI_ID);
}

void MEXTI_voidEnablePCINT(enum GPIO_PORT_ID_t PORT_ID, u8 Copy_u8_PinNumber)
{
	switch(PORT_ID)
	{
		case GPIO_PORTK:
			PCICR = 4;
			PCMSK2 |= (1<<Copy_u8_PinNumber);
			break;
		case GPIO_PORTJ:
			PCICR = 2;
			PCMSK1 |=(1<<Copy_u8_PinNumber);
			break;
		case GPIO_PORTB:
			PCICR = 1;
			PCMSK0 |=(1<<Copy_u8_PinNumber);
			break;
		default:
			break;
		
	}
	GIE_voidEnable();

}

void MEXTI_voidDisablePCINT(u8 Copy_u8_pinnumber)
{
	if(Copy_u8_pinnumber>=0 && Copy_u8_pinnumber<8)
	{
		CLR_BIT(PCMSK0,Copy_u8_pinnumber);
	}
	else if(Copy_u8_pinnumber>7 && Copy_u8_pinnumber<15)
	{
		CLR_BIT(PCMSK1,(Copy_u8_pinnumber-8));
	}
	else if(Copy_u8_pinnumber>15 && Copy_u8_pinnumber<24)
	{
		CLR_BIT(PCMSK2,(Copy_u8_pinnumber-16));
	}
	else
		return;
}

void MEXTI_voidSetCallbackPCINT	(enum EXTI_PCINT_num EXTI_PCINT,void (*Local_Callback)(void))
{
	Global_CallbackPCINT[EXTI_PCINT]= Local_Callback;
}


void EXTI_VEC0()
{
	if (Global_Callback[EXTI_INT0] != 0)
		Global_Callback[EXTI_INT0]();
	else
		return;
}
void EXTI_VEC1()
{
	if (Global_Callback[EXTI_INT1] != 0)
		Global_Callback[EXTI_INT1]();
	else
		return;
}

void EXTI_VEC2()
{
	if (Global_Callback[EXTI_INT2] != 0)
		Global_Callback[EXTI_INT2]();
	else
		return;
}
void EXTI_VEC3()
{
	if (Global_Callback[EXTI_INT3] != 0)
		Global_Callback[EXTI_INT3]();
	else
		return;
}

void EXTI_VEC4()
{
	if (Global_Callback[EXTI_INT4] != 0)
		Global_Callback[EXTI_INT4]();
	else
		return;
}
void EXTI_VEC5()
{
	if (Global_Callback[EXTI_INT5] != 0)
		Global_Callback[EXTI_INT5]();
	else
		return;
}

void EXTI_VEC6()
{
	if (Global_Callback[EXTI_INT6] != 0)
		Global_Callback[EXTI_INT6]();
	else
		return;
}
void EXTI_VEC7()
{
	if (Global_Callback[EXTI_INT7] != 0)
		Global_Callback[EXTI_INT7]();
	else
		return;
}


void EXTI_VEC_PCINT0()
{
	Global_CallbackPCINT[EXTI_PCINT0]();
}
void EXTI_VEC_PCINT1()
{
	Global_CallbackPCINT[EXTI_PCINT1]();
}
void EXTI_VEC_PCINT2()
{
	Global_CallbackPCINT[EXTI_PCINT2]();
}