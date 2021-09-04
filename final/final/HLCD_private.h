
/************************************************************************/
/*Name:HLCD_private.h                                                  */
/*Author:Sara Mostafa                                                   */
/*version:v1.1                                                          */
/*Description:This file contains private information for LCD module     */
/************************************************************************/


#ifndef HLCD_PRIVATE_H_
#define HLCD_PRIVATE_H_


/************************************************************************/
/*                  LED Ports and Pins                                  */
/************************************************************************/

/*LCD Control ports and pins*/
#define HLCD_CONTROL_PORT  PORTB
#define HLCD_CONTROL_RS    PIN1
#define HLCD_CONTROL_RW    PIN2
#define HLCD_CONTROL_EN    PIN3 


/*LCD DATA ports and pins*/
#define HLCD_DATA_PINS_PORT PORTA
#define HLCD_DATA_PIN4      PIN4
#define HLCD_DATA_PIN5      PIN5
#define HLCD_DATA_PIN6      PIN6
#define HLCD_DATA_PIN7      PIN7





#endif /* HLCD_PRIVATE_H_ */