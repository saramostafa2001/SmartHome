/************************************************************************/
/*Name:HLCD_program.c                                                  */
/*Author:Sara Mostafa                                                  */
/*version:v1.1                                                          */
/*Description:This file contains program information for LCD module     */
/************************************************************************/


/************************************************************************/
/*             Includes                                                 */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "MDIO_interface.h"

#include "HLCD_Interface.h"
#include "HLCD_private.h"

#define F_CPU 16000000UL
#include "util/delay.h"


/************************************************************************/
/*                          Functions Definitions                       */
/************************************************************************/
/*This function is responsible for sending 8-bits data for the LCD module*/
static void hlcd_sendData(u8_t Data);

/*This function is responsible for sending 8-bits command for the LCD module*/
static void hlcd_sendCmd(u8_t command);

/*This function is responsible for sending 8-bits data for the LCD module*/
static void hlcd_sendData(u8_t Data)
{
	/*sending display data*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_RS,HIGH);
	
	/*Enable writing operation*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_RW,LOW);
	
	/*sending data High byte*/
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN4,GET_BIT(Data,4));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN5,GET_BIT(Data,5));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN6,GET_BIT(Data,6));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN7,GET_BIT(Data,7));
	
	/*trigger enable pin*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,LOW);
	_delay_us(50);
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,HIGH);
	
	/*sending data low byte*/
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN4,GET_BIT(Data,0));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN5,GET_BIT(Data,1));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN6,GET_BIT(Data,2));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN7,GET_BIT(Data,3));
	
	/*trigger enable pin*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,LOW);
	_delay_us(50);
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,HIGH);
	
	/*return from this function*/
	return;
}


/*This function is responsible for sending 8-bits command for the LCD module*/
static void hlcd_sendCmd(u8_t command) /*0b 1110   -> EN   0100*/
{
	/*send command*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_RS,LOW);
	
	/*Enable writing operation*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_RW,LOW);
	
	/*sending command High byte*/
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN4,GET_BIT(command,4));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN5,GET_BIT(command,5));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN6,GET_BIT(command,6));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN7,GET_BIT(command,7));
	
	/*trigger enable pin*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,LOW);
	_delay_us(20);
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,HIGH);
	
	/*sending command low byte*/
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN4,GET_BIT(command,0));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN5,GET_BIT(command,1));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN6,GET_BIT(command,2));
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN7,GET_BIT(command,3));
	
	/*trigger enable pin*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,LOW);
	_delay_us(20);
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,HIGH);
	
	
	
	
	/*return from this function*/
	return;
}

/*This function is responsible for initializing the LCD module*/
void hlcd_init(void)
{
	/*LCD pins initialization*/
	mdio_pinStatus(HLCD_CONTROL_PORT,HLCD_CONTROL_RS | HLCD_CONTROL_RW |HLCD_CONTROL_EN,OUTPUT);
	mdio_pinStatus(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN4 | HLCD_DATA_PIN5 |HLCD_DATA_PIN6|HLCD_DATA_PIN7,OUTPUT);
	
	/*set enable pin to HIGH*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,HIGH);
	
	/*delay 50ms for powering on*/
	_delay_ms(50);
	
	/*send command*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_RS,LOW);
	
	/*Enable writing operation*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_RW,LOW);
	
	/*sending command High byte*/
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN4,LOW);
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN5,HIGH);
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN6,LOW);
	mdio_setPinValue(HLCD_DATA_PINS_PORT,HLCD_DATA_PIN7,LOW);
	
	/*trigger enable pin*/
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,LOW);
	_delay_us(50);
	mdio_setPinValue(HLCD_CONTROL_PORT,HLCD_CONTROL_EN,HIGH);
	
	/*sending function set*/
	hlcd_sendCmd(0x2C);
	
	/*delay for 1ms*/
	_delay_ms(1);
	
	/*sending display ON/OFF command*/
	hlcd_sendCmd(0x0F);
	
	/*delay for 1ms*/
	_delay_ms(1);
	
	/*sending clear display command*/
	hlcd_sendCmd(0x01);
	
	/*delay for 2ms*/
	_delay_ms(2);
	
	/*send entry mode set command*/
	hlcd_sendCmd(0x06);
	
	/*delay for 1ms*/
	_delay_ms(1);
	
	
	/*return from this function*/
	return;
}


/*This function is used to display char on the LCD*/
void hlcd_displayChar(u8_t char_data)
{
	/*sending character data to the LCD*/
	hlcd_sendData(char_data);
	
	/*return from this function*/
	return;	
}


/*This function is used to display string on the LCD*/
void hlcd_displayString(u8_t* str_data)/*book -> {'B','o','o','k','\0'}*/
{
	/*Looping over given string characters*/
	while(*str_data != '\0')  
	{
		/*sending data character to the LCD*/
		hlcd_sendData(*str_data);
		
		/*incrementing the address of the string to get the next character*/
		str_data++;  
	}
	
	/*return from this function*/
	return;
}

/*This function is used to set the cursor on specific row on specific column*/
void hlcd_goToRowCol(u8_t rowNumber, u8_t colNumber)
{
	/*switching over LCD ROWs*/
	switch(rowNumber)
	{
		/*in case of Row 0*/
		case HLCD_Row0:
			/*Add 1 to bit 7 (0x80) and use 0X00 on DDRAM to set row 0 then add the colNumber*/
			hlcd_sendCmd(0x80 | (0x00+ colNumber));
			break;
		
		/*in case of Row 1*/	
		case HLCD_Row1:
			/*Add 1 to bit 7 (0x80) and use 0X40 on DDRAM to set row 1 then add the colNumber*/
			hlcd_sendCmd(0x80 | (0x40+ colNumber));
			break;
	}
	
	/*return from this function*/
	return;
}