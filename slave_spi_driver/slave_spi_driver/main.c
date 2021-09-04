#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_slave_Interface.h"
#include "MDIO_interface.h"
#include "HLCD_Interface.h"

int main(void)
{
	
	mdio_setPinValue(PORTB, PIN4,INPUT_FLOAT);
	mdio_setPinValue(PORTB, PIN5,INPUT_FLOAT);
	mdio_setPinValue(PORTB, PIN6,OUTPUT);
	mdio_setPinValue(PORTB, PIN7,INPUT_FLOAT);
	
	mspi_init(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_64);
	hlcd_init();
	hlcd_goToRowCol(HLCD_Row0,HLCD_col0);
	
	hlcd_displayString("hello");
	
	/*the status of the led*/
	mdio_pinStatus(PORTD,PIN3,OUTPUT);
	mdio_pinStatus(PORTC,PIN2,OUTPUT);
	
	
	mdio_setPinValue(PORTD,PIN3,LOW);
	
	u8_t data=0;
	
	//data=mspi_recvChar();
	//hlcd_displayChar(data);
	
    /* Replace with your application code */
    while (1) 
    {
		hlcd_goToRowCol(HLCD_Row1,HLCD_col0);
		data=mspi_recvChar();
		hlcd_displayChar(data);
		
		
		
		
		if (data == 0x61)
		{
			mdio_setPinValue(PORTD,PIN3,HIGH);
			mdio_setPinValue(PORTC,PIN2,LOW);
			
			//hlcd_goToRowCol(HLCD_Row1,HLCD_col0);
			//hlcd_displayChar(recive_var);
			
		}
		else if(data == 0x62)
		{
			mdio_setPinValue(PORTD,PIN3,LOW);
			mdio_setPinValue(PORTC,PIN2,HIGH);
			//hlcd_goToRowCol(HLCD_Row1,HLCD_col0);
			//hlcd_displayChar(recive_var);
		}
		else
		{
				mdio_setPinValue(PORTD,PIN3,LOW);
				mdio_setPinValue(PORTC,PIN2,LOW);
		}
    }
}

