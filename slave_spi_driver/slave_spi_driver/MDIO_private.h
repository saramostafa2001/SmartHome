
/************************************************************************/
/* Name:MDIO_private.h                                                  */
/*Author:Sara Mostafa                                                   */
/*version:v1.1                                                          */
/*Description:This file contains private information for DIO module     */
/************************************************************************/


/*Header file guard*/
#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_

/************************************************************************/
/*                  DIO Registers                                       */
/************************************************************************/

#define MDIO_PORTA (*(volatile u8_t*)(0x3B))
#define MDIO_DDRA  (*(volatile u8_t*)(0x3A))
#define MDIO_PINA  (*(volatile u8_t*)(0x39))

#define MDIO_PORTB (*(volatile u8_t*)(0x38))
#define MDIO_DDRB  (*(volatile u8_t*)(0x37))
#define MDIO_PINB  (*(volatile u8_t*)(0x36))

#define MDIO_PORTC (*(volatile u8_t*)(0x35))
#define MDIO_DDRC  (*(volatile u8_t*)(0x34))
#define MDIO_PINC  (*(volatile u8_t*)(0x33))

#define MDIO_PORTD (*(volatile u8_t*)(0x32))
#define MDIO_DDRD  (*(volatile u8_t*)(0x32))
#define MDIO_PIND  (*(volatile u8_t*)(0x30))


//MDIO_PORTA = 0xFF;

#endif /* MDIO_PRIVATE_H_ */