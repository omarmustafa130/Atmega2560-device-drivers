/*
 * GPIO_private.h
 *
 * Created: 1/5/2023 11:05:21 PM
 *  Author: Omar Mustafa
 */ 


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct  
{
	volatile u8 PIN;
	volatile u8 DDR;
	volatile u8 PORT;
}PORT_t;

#define PORTA_REGS	((volatile PORT_t*)(0x20))
#define PORTB_REGS	((volatile PORT_t*)(0x23))
#define PORTC_REGS	((volatile PORT_t*)(0x26))
#define PORTD_REGS	((volatile PORT_t*)(0x29))
#define PORTE_REGS	((volatile PORT_t*)(0x2C))
#define PORTF_REGS	((volatile PORT_t*)(0x2F))
#define PORTG_REGS	((volatile PORT_t*)(0x32))
#define PORTH_REGS	((volatile PORT_t*)(0x100))
#define PORTJ_REGS	((volatile PORT_t*)(0x103))
#define PORTK_REGS	((volatile PORT_t*)(0x106))
#define PORTL_REGS	((volatile PORT_t*)(0x109))



#endif /* GPIO_PRIVATE_H_ */