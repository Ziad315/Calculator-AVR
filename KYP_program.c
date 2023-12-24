/*
 * KYP_program.c
 *
 *  Created on: 15 Dec 2023
 *      Author: Ziad Yakoot
 */
#include "STD_types.h"
#include "bitMath.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "KYP_interface.h"
#include "KYP_cfg.h"

uint8 getPressed(void)
{
	uint8 COL_ARR[COL_NUM]=COL_PINS;
	uint8 ROW_ARR[ROW_NUM]=ROW_PINS;
	uint8 KEYPAD_KEYS[ROW_NUM][COL_NUM]=KEYS_array;
	uint8 pressedKey = 0xff;
	uint8 button = 0xff;


	for(uint8 COL_index = 0;COL_index < COL_NUM ; COL_index++)
	{
		DIO_setPinValue(KYP_PORT,COL_ARR[COL_index],LOW);
		for(uint8 ROW_index = 0 ; ROW_index < ROW_NUM ; ROW_index++)
		{
			DIO_uint8_getPinValue(KYP_PORT,ROW_ARR[ROW_index],&pressedKey);
			if(pressedKey == LOW)
			{
				while(pressedKey == LOW)
				{
					DIO_uint8_getPinValue(KYP_PORT,ROW_ARR[ROW_index],&pressedKey);
				}
				button=KEYPAD_KEYS[ROW_index][COL_index];
				return button;

			}
		}
		DIO_setPinValue(KYP_PORT,COL_ARR[COL_index],HIGH);

	}
	return button;
}
