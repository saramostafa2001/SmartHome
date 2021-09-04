/************************************************************************/
/*Name:HLCD_interface.h                                                */
/*Author:Sara Mostafa                                                   */
/*version:v1.0                                                          */
/*Description:This file contains interface information for LCD module   */
/************************************************************************/


#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

/************************************************************************/
/*                          interfacing macros                         */
/************************************************************************/

/*LCD Rows*/
#define HLCD_Row0   0
#define HLCD_Row1   1

/*LCD columns*/
#define HLCD_col0   0
#define HLCD_col1   1
#define HLCD_col2   2
#define HLCD_col3   3
#define HLCD_col4   4
#define HLCD_col5   5
#define HLCD_col6   6
#define HLCD_col7   7
#define HLCD_col8   8
#define HLCD_col9   9
#define HLCD_col10  10
#define HLCD_col11  11
#define HLCD_col12  12
#define HLCD_col13  13
#define HLCD_col14  14

/************************************************************************/
/*                          Functions prototypes                        */
/************************************************************************/

/*This function is responsible for initializing the LCD module*/
void hlcd_init(void);

/*This function is used to display char on the LCD*/
void hlcd_displayChar(u8_t char_data);

/*This function is used to display string on the LCD*/
void hlcd_displayString(u8_t* str_data);

/*This function is used to set the cursor on specific row on specific column*/
void hlcd_goToRowCol(u8_t rowNumber, u8_t colNumber);

#endif /* HLCD_INTERFACE_H_ */