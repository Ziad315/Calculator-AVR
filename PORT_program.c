/*
 * DIO_program.c
 *
 *  Created on: 8 Dec 2023
 *      Author: Ziad Yakoot
 */

#include "STD_types.h"
#include "bitMath.h"
#include "DIO_Reg.h"
#include "PORT_cfg.h"
#include "PORT_interface.h"



void PORT_init(void)
{
	DDRA =PORTA_DIR;
	DDRB =PORTB_DIR;
	DDRC =PORTC_DIR;
	DDRD =PORTD_DIR;

	PORTA =PORTA_VAL;
	PORTB =PORTB_VAL;
	PORTC =PORTC_VAL;
	PORTD =PORTD_VAL;

}

