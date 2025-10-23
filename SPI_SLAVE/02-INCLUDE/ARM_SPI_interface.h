/**************************************************************************************************/
/* Author  : Waleed Adel                                                                        */
/* Version : V01                                                                                  */
/* Date    : 28 Dec 2024                                                                           */
/**************************************************************************************************/

#ifndef ARM_SPI_INTERFACE_H_
#define ARM_SPI_INTERFACE_H_


#define  DIVIDE_BY_2      000
#define  DIVIDE_BY_4      001
#define  DIVIDE_BY_8      010
#define  DIVIDE_BY_16     011
#define  DIVIDE_BY_32     100
#define  DIVIDE_BY_64     101
#define  DIVIDE_BY_128    110
#define  DIVIDE_BY_256    111

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



void ASPI_voidSlave(void);

void ASPI_u16MasterTransfer(u16 Copy_u16Data);
void ASPI_u8MasterTransfer(u8 Copy_u16Data);

u16 ASPI_u16MasterRecieve(void);

u16 ASPI_u16SlaveRecieve(void);
u8 ASPI_u8SlaveRecieve(void);



#endif /* ARM_SPI_INTERFACE_H_ */
