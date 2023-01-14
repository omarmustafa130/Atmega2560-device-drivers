/*
 * GPIO_interface.h
 *
 * Created: 1/5/2023 11:05:01 PM
 *  Author: Omar Mustafa
 */ 


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
#include "../../Library/STD_TYPES.h"
enum GPIO_PORT_ID_t {GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD, GPIO_PORTE, GPIO_PORTF, GPIO_PORTG, GPIO_PORTH, GPIO_PORTJ, GPIO_PORTK, GPIO_PORTL};
enum GPIO_DIRECTION_t {GPIO_INPUT, GPIO_OUTPUT, GPIO_INPUT_PULLUP};
enum GPIO_VALUE_t {GPIO_LOW, GPIO_HIGH};


/*GPIO functions*/
void MGPIO_VoidSetPortDirection(enum GPIO_PORT_ID_t GPIO_PORT_ID, enum GPIO_DIRECTION_t GPIO_DIRECTION);
void MGPIO_VoidSetPinDirection(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo, enum GPIO_DIRECTION_t GPIO_DIRECTION);

void MGPIO_VoidSetPortValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8Value);
void MGPIO_VoidSetPinValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo, enum GPIO_VALUE_t GPIO_VALUE);

u8 MGPIO_VoidGetPortValue(enum GPIO_PORT_ID_t GPIO_PORT_ID);
u8 MGPIO_VoidGetPinValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo);

void MGPIO_VoidTogglePinValue(enum GPIO_PORT_ID_t GPIO_PORT_ID, u8 Copy_u8PinNo);

#endif /* GPIO_INTERFACE_H_ */