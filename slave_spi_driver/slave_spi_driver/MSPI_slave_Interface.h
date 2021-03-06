/************************************************************************/
/* Name:    MSPI_interface.h                                              */
/* Author:  Sara Mostafa                                                */
/* Version: v1.0                                                        */
/* Description: This file contains interface information for SPI module   */
/************************************************************************/



#ifndef MSPI_SLAVE_INTERFACE_H_
#define MSPI_SLAVE_INTERFACE_H_


/************************************************************************/
/*                            Interfacing macros                        */
/************************************************************************/

/*SPI Data mode*/
#define MSPI_SAMPLE_R_SETUP_F  (0)
#define MSPI_SETUP_R_SAMPLE_F  (1)
#define MSPI_SAMPLE_F_SETUP_R  (2)
#define MSPI_SETUP_F_SAMPLE_R  (3)

/*SPI Clock prescaler*/
#define MSPI_PRE_2             (0)
#define MSPI_PRE_4             (1)
#define MSPI_PRE_8             (2)
#define MSPI_PRE_16            (3)
#define MSPI_PRE_32            (4)
#define MSPI_PRE_64            (5)
#define MSPI_PRE_128           (7)

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/


/*this function is responsible for initializing spi module*/
void mspi_init(u8_t data_mode, u8_t clk_prescaler);

/*this function is responsible for resv Character*/
char mspi_recvChar(void);



#endif /* MSPI_SLAVE_INTERFACE_H_ */