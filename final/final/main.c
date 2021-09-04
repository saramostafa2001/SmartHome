#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MUART_Interface.h"
#include "HLCD_Interface.h"
#include "MSPI_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	/*variables*/
	u8_t recive_var=0;
	
	/*the status of the UART PINs*/
	mdio_pinStatus(PORTD,PIN1,OUTPUT);
	mdio_pinStatus(PORTD,PIN0,INPUT_FLOAT);
	
	/*the status of the SPI module*/
	mdio_pinStatus(PORTB,PIN4,OUTPUT);
	mdio_pinStatus(PORTB,PIN5,OUTPUT);
	mdio_pinStatus(PORTB,PIN6,INPUT_FLOAT);
	mdio_pinStatus(PORTB,PIN7,OUTPUT);
	
	/*the status of the led*/
	mdio_pinStatus(PORTD,PIN2,OUTPUT);
	
	/*Initializing the modules*/
	muart_init(MUART_9600BPS);
	hlcd_init();
	mspi_init(MSPI_SAMPLE_R_SETUP_F,MSPI_PRE_32);
	
	/*for the LCD the first line*/
	hlcd_goToRowCol(HLCD_Row0,HLCD_col0);
	hlcd_displayString("hello");
	
	/*for SPI */
	u8_t x=10;
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		muart_reciveByte(&recive_var);
		hlcd_goToRowCol(HLCD_Row1,HLCD_col0);
		hlcd_displayChar(recive_var);
		mspi_sendRecvByte(recive_var);
		
		
		if (recive_var == 'a')
		{
			mdio_setPinValue(PORTD,PIN2,HIGH);
			
			//hlcd_goToRowCol(HLCD_Row1,HLCD_col0);
			//hlcd_displayChar(recive_var);
			
		}
		else
		{
			mdio_setPinValue(PORTD,PIN2,LOW);
			//hlcd_goToRowCol(HLCD_Row1,HLCD_col0);
			//hlcd_displayChar(recive_var);
		}
	
    }
	return 0;
}

