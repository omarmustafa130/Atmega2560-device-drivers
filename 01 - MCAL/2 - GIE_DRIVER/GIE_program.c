/*
 * GIE_program.c
 *
 * Created: 1/8/2023 12:59:19 PM
 *  Author: Omar Mustafa
 */ 
#include "../../Library/BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG, 7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG, 7);
}