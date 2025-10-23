/**************************************************************************************************/
/* Author  : Waleed Adel                                                                        */
/* Version : V01                                                                                  */
/* Date    : 28 Dec 2024                                                                           */
/**************************************************************************************************/

#ifndef ARM_SPI_INTERFACE_H_
#define ARM_SPI_INTERFACE_H_

#define  BAUDRATE_BIT_CLEAR 111

#define  DIVIDE_BY_2      0
#define  DIVIDE_BY_4      1
#define  DIVIDE_BY_8      2
#define  DIVIDE_BY_16     3
#define  DIVIDE_BY_32     4
#define  DIVIDE_BY_64     5
#define  DIVIDE_BY_128    6
#define  DIVIDE_BY_256    7

#define  LOW_LEVEL  0
#define  HIGH_LEVEL 1


#define  READ_THEN_WRITE  0
#define  WRITE_THEN_READ  1


#define DATA_8BIT   0
#define DATA_16BIT  1


#define  MSB_FIRST  0
#define  LSB_FISRT  1

#define  NSS_SOFTWARE   0
#define  NSS_HARDWARE   1

#define  NSS_OUTPUT_ENABLED  0
#define  NSS_OUTPUT_DISABLED 1

#define  MASTER   0
#define  SLAVE    1


#define SPI_SCK  PIN5
#define SPI_MOSI PIN7
#define SPI_MISO PIN6
#define SPI_NSS  PIN4


void ASPI_voidMaster(void);

void ASPI_u16MasterTransfer(u16 Copy_u16Data);

u16 ASPI_u16MasterRecieve(void);

u16 ASPI_u16SlaveRecieve(void);



#endif /* ARM_SPI_INTERFACE_H_ */
