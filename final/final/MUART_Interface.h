/************************************************************************/
/* Name:MUART_interface.h                                                */
/*Author:Sara Mostafa                                                   */
/*version:v1.0                                                          */
/*Description:This file contains interface information for UART module   */
/************************************************************************/


#ifndef INCFILE1_H_
#define INCFILE1_H_
/************************************************************************/
/* interfacing macros                                                  */
/************************************************************************/

/*Baud rates*/
#define MUART_2400BPS    (416)
#define MUART_4800BPS    (207)
#define MUART_9600BPS    (103)
#define MUART_19200BPS   (51)
#define MUART_115200BPS  (8)


/************************************************************************/
/*              Functions prototypes                                    */
/************************************************************************/

/*this function is responsible for initializing uart*/
void muart_init(u16_t baudrate);

/*this function is responsible for sending  the data*/
void muart_sendByte(u8_t data);

/*this function is responsible for receiving the data*/
void muart_reciveByte(u8_t* data);

/*this function is responsible for sending data string*/
void muart_sendStream(u8_t* data_stream, u8_t data_size);



#endif /* INCFILE1_H_ */