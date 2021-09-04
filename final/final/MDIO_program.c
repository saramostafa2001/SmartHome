
/************************************************************************/
/* Name:MDIO_program.c                                                  */
/*Author:Sara Mostafa                                                  */
/*version:v1.1                                                          */
/*Description:This file contains program information for DIO module     */
/************************************************************************/

/************************************************************************/
/*             Includes                                                 */
/************************************************************************/
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/************************************************************************/
/*              Functions implementation                                */
/************************************************************************/
/*this function is responsible for setting the status a pin or pins for a dedicated port*/
/*
@function parameters port, pin(bit), pin status (input, output, pull up)
@input DDRx=0 , output DDRx=1 ,pull up DDRx=0 portx=1
@to set a specified bit |=  to clear specified bit &= ~
*/
void mdio_pinStatus(u8_t port,u8_t pin,u8_t pin_status)
{
	/*Switching over DIO PORTs*/
	switch(port)
	{
		case PORTA:
			/*switching over DIO pin status*/
			switch(pin_status)
			{
				case OUTPUT:
					MDIO_DDRA |= pin;
					break;
				
				case INPUT_FLOAT:
					MDIO_DDRA &= ~pin;
					break;
					
				case INPUT_PULLUP:
					MDIO_DDRA &= ~pin;
					MDIO_PORTA |= pin;
					break;
			}
		    break;	
		
		case PORTB:
			switch(pin_status)
			{
				case OUTPUT:
					MDIO_DDRB |= pin;
					break;
				
				case INPUT_FLOAT:
					MDIO_DDRB &= ~pin;
					break;
					
				case INPUT_PULLUP:
					MDIO_DDRB &= ~pin;
					MDIO_PORTB |= pin;
					break;
			}
		    break;	
			
		case PORTC:
			switch(pin_status)
			{
				case OUTPUT:
					MDIO_DDRC |= pin;
					break;
				
				case INPUT_FLOAT:
					MDIO_DDRA &= ~pin;
					break;
					
				case INPUT_PULLUP:
					MDIO_DDRC &= ~pin;
					MDIO_PORTC |= pin;
					break;
			}
		    break;
		
		case PORTD:
			switch(pin_status)
			{
				case OUTPUT:
					MDIO_DDRD |= pin;
					break;
				
				case INPUT_FLOAT:
					MDIO_DDRD &= ~pin;
					break;
					
				case INPUT_PULLUP:
					MDIO_DDRD &= ~pin;
					MDIO_PORTD |= pin;
					break;
			}
		    break;		
		
	}
	return;
}

/*this function is responsible for setting pin or pins for a dedicated value */
void mdio_setPinValue(u8_t port,u8_t pin,u8_t pin_value)//output
{
	/*Switching over DIO PORTs*/
	switch(port)
	{
		case PORTA:
		/*switching over DIO pin status*/
			switch(pin_value)
			{
				case HIGH:
					MDIO_PORTA |= pin;
					break;
			
				case LOW:
					MDIO_PORTA &= ~pin;
					break;
			
			}
			break;
		
		case PORTB:
		/*switching over DIO pin status*/
			switch(pin_value)
			{
				case HIGH:
					MDIO_PORTB |= pin;
					break;
			
				case LOW:
					MDIO_PORTB &= ~pin;
					break;
			
			}
			break;
		
		case PORTC:
		/*switching over DIO pin status*/
			switch(pin_value)
			{
				case HIGH:
					MDIO_PORTC |= pin;
					break;
			
				case LOW:
					MDIO_PORTC &= ~pin;
					break;
			
			}
			break;
		
		case PORTD:
		/*switching over DIO pin status*/
			switch(pin_value)
			{
				case HIGH:
					MDIO_PORTD |= pin;
					break;
			
				case LOW:
					MDIO_PORTD &= ~pin;
					break;
			
			}
			break;
	}
	return;
}

void mdio_togglePinValue(u8_t port,u8_t pin)
{
	/*Switching over DIO PORTs*/
	switch(port)
	{
		case PORTA:
			MDIO_PORTA ^= pin;
			break;
		
		case PORTB:
			MDIO_PORTB ^= pin;
			break;
		
		case PORTC:
			MDIO_PORTC ^= pin;
			break;
		
		case PORTD:
			MDIO_PORTD ^= pin;
			break;
	}
	return;
}

/*this function is responsible for getting pin for a dedicated value */
u8_t mdio_getPinValue(u8_t port,u8_t pin)//input
{
	u8_t pinValue;
	/*Switching over DIO PORTs*/
	switch(port)
	{
		case PORTA:
		/*switching over DIO pin status*/
			if(MDIO_PINA & pin)
			{
				pinValue=HIGH;		
			}
			else
			{
				pinValue=LOW;
			}
			break;
		
		case PORTB:
			/*switching over DIO pin status*/
			if(MDIO_PINB & pin)
			{
				pinValue=HIGH;
			}
			else
			{
				pinValue=LOW;
			}
			break;
			
		
		case PORTC:
		/*switching over DIO pin status*/
			if(MDIO_PINC & pin)
			{
				pinValue=HIGH;
			}
			else
			{
				pinValue=LOW;
			}
			break;
		
		case PORTD:
			/*switching over DIO pin status*/
			if(MDIO_PIND & pin)
			{
				pinValue=HIGH;
			}
			else
			{
				pinValue=LOW;
			}
			break;
			
	}
	
	return pinValue;
}
