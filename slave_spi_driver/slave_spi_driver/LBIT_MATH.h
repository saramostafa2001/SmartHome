
/************************************************************************/
/* Name:MDIO_interface.h                                                */
/*Author:Sara Mostafa                                                  */
/*version:v1.1                                                          */
/*Description:This file contains interface information for DIO module   */
/************************************************************************/


/*Header file guard*/
#ifndef _LBIT_MATH_H_
#define _LBIT_MATH_H_

/*Setting the required bit to 1*/
#define SET_BIT(REG,BIT)      REG |= (1<<BIT)

/*Setting the required bit to 0*/
#define CLEAR_BIT(REG,BIT)    REG &= ~(1<<BIT)

/*Get the required bit value*/
#define GET_BIT(REG,BIT)      ((REG >> BIT)&1)

/*Toggle the required bit value*/
#define TOGGLE_BIT(REG,BIT)   REG ^= (1<<BIT)

#endif/*_LBIT_MATH_H_*/
