/************************************************************************/
/* Name:MUART_program.c                                                  */
/*Author:Sara Mostafa                                                  */
/*version:v1.1                                                          */
/*Description:This file contains program information for UART module     */
/************************************************************************/

/************************************************************************/
/*             Includes                                                 */
/************************************************************************/
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MUART_Interface.h"
#include "MUART_Private.h"

#define F_CPU 16000000UL
#include "util/delay.h"
/************************************************************************/
/*              global variables                              */
/************************************************************************/

u8_t timeout_var =0 ;
/************************************************************************/
/*              Functions implementation                                */
/************************************************************************/

/*this function is responsible for initializing uart*/
void muart_init(u16_t baudrate)
{
	/*Enable TX and Rx*/
	SET_BIT(MUART_UCSRB,4);
	SET_BIT(MUART_UCSRB,3);
	
	/*choosing Asynchronous mode ,disable Parity ,data length 8-bit*/
	MUART_UCSRC =(0x80)| (0x06);
	
	/*casting the baudrate and set the low baud rate*/
	MUART_UBRRL =(u8_t)baudrate;
	
	/*setting the high baud rate*/
	MUART_UBRRH =(u8_t)(baudrate>>8); 
	
	
	
	return;
}

/*this function is responsible for sending  the data*/
void muart_sendByte(u8_t data)
{
	timeout_var=0;
	
	/*checking if UDR Empty or not*/
	if(GET_BIT(MUART_UCSRA , 5) == 1)
	{
		/*Transmitting data*/
		MUART_UDR=data;
		
		/*make sure that the data has been transmitted or timeout have been happened*/
		while((GET_BIT(MUART_UCSRA , 6)==0) && timeout_var <10)/*Pulling system*/
		{
			
			timeout_var++;
			_delay_ms(1);
		}	
		/*clearing Tx flag*/
		SET_BIT(MUART_UCSRA,6);
		
	}
	else
	{
		/*report error*/
	}
	
	
	return;
}

/*this function is responsible for receiving the data*/
void muart_reciveByte(u8_t* data)
{
	/*Checking that there's a new data or not*/
	if(GET_BIT(MUART_UCSRA,7)==1)
	{
		/*Getting the new data*/
		*data = MUART_UDR;
	}
	else
	{
		/*there is no data*/
	}
	
	
	return ;
}

void muart_sendStream(u8_t* data_stream, u8_t data_size)
{
	/*Sending stream of data according to their size*/
	while(data_size--)
	{
		/*Send one byte at a time*/
		muart_sendByte(*data_stream);
		
		/*Increase data pointer*/
		data_stream++;
	}
	
	/*Return from this function*/
	return;
}