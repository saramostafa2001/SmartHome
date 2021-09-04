/************************************************************************/
/* Name:    MSPI_Program.c                                              */
/* Author:  Sara Mostafa                                                */
/* Version: v1.0                                                        */
/* Description: This file contains program information for SPI module   */
/************************************************************************/


/************************************************************************/
/*             Includes                                                 */
/************************************************************************/
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_slave_Interface.h"
#include "MDIO_interface.h"
#include "MSPI_Private.h"



#define  F_CPU   16000000UL
#include "util/delay.h"
/************************************************************************/
/*              Functions implementation                                */
/************************************************************************/


/*this function is responsible for initializing spi module*/
void mspi_init(u8_t data_mode, u8_t clk_prescaler)
{
	/*Enable SPI*/
	SET_BIT(MSPI_SPCR,6);
	
	MSPI_SPCR = (0x40) | (data_mode << 2);
	
	/*Check if the prescaler value is divisable by two or not*/
	if( (clk_prescaler % 2) == 0)
	{
		/*Enable SPI double speed*/
		SET_BIT(MSPI_SPSR, 0);
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Set SPI clock*/
	MSPI_SPCR |= (clk_prescaler / 2);
	
	
	
	return;
}

/*this function is responsible for receive Character*/
char mspi_recvChar(void)
{
	
	/*Variable used in timing out operations*/
	u16_t timeout_var = 0;
	
	/*Enable SPI peripheral*/
	SET_BIT(MSPI_SPCR, 6);
	
	/*Send master data*/
	//MSPI_SPDR = data;
	
	/*Wait until data is transmitted or timeout in 10ms*/
	while (GET_BIT(MSPI_SPSR, 7) == 0);//&& timeout_var < 10000)
	
		/*Increase timeout variable*/
		//timeout_var++;
		
		/*Delay for 1us*/
		//_delay_us(1);
	
	
	/*Disable SPI peripheral*/
	CLEAR_BIT(MSPI_SPCR, 6);
	
	/*Return SPI slave data*/
	return MSPI_SPDR;
}