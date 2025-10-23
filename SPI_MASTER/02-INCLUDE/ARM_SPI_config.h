/**************************************************************************************************/
/* Author  : Waleed Adel                                                                        */
/* Version : V01                                                                                  */
/* Date    : 28 Dec 2024                                                                           */
/**************************************************************************************************/

#ifndef ARM_SPI_CONFIG_H_
#define ARM_SPI_CONFIG_H_



#define BAUD_RATE	        DIVIDE_BY_8
#define CLOCK_POLARITY		HIGH_LEVEL
#define CLOCK_PHASE             READ_THEN_WRITE
#define DATA_FORMATE            DATA_16BIT
#define FIRST_TRANSMITTED_BIT   MSB_FIRST
#define NSS_MODE                NSS_HARDWARE
#define NSS_HARDWARE_MODE       NSS_OUTPUT_ENABLED
#define MODE                    MASTER


#endif /* ARM_SPI_CONFIG_H_ */
