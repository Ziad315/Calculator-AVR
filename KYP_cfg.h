/*
 * KYP_cfg.h
 *
 *  Created on: 15 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef KYP_CFG_H_
#define KYP_CFG_H_

#define KYP_PORT           DIO_PORTD

#define ROW_NUM               4
#define COL_NUM               4

#define ROW_PINS            {PIN0,PIN1,PIN2,PIN3}
#define COL_PINS            {PIN4,PIN5,PIN6,PIN7}


#define KEYS_array         {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}}


uint8 keyPad[ROW_NUM][ROW_NUM]=KEYS_array;

#endif /* KYP_CFG_H_ */
