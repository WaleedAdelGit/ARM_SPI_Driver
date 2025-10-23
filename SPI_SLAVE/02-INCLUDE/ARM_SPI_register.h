/**************************************************************************************************/
/* Author  : Waleed Adel                                                                        */
/* Version : V01                                                                                  */
/* Date    : 28 Dec 2024                                                                           */
/**************************************************************************************************/


#ifndef ARM_SPI_REGISTER_H_
#define ARM_SPI_REGISTER_H_


typedef struct
{
	u32  CR1;
	u32  CR2;
	u32  SR;
	u32  DR;
	u32  CRCPR;
	u32  RXCRCR;
	u32  TXCRCR;

}ASPI;


#define ASPI  ((volatile ASPI*)0x40013000)


#define CR1_CPHA 0
#define CR1_CPOL 1
#define CR1_MSTR 2
#define CR1_BR0  3
#define CR1_BR1  4
#define CR1_BR2  5
#define CR1_SPE  6
#define CR1_LSBFIRST 7
#define CR1_SSI  8
#define CR1_SSM  9
#define CR1_RXONLY 10
#define CR1_DFF 11
#define CR1_CRCNEXT 12
#define CR1_CRCEN 13
#define CR1_BIDIOE 14
#define CR1_BIDIMODE 15

#define CR2_SSOE 2

#define SR_RXNE 0
#define SR_TXNE 1


#endif /* ARM_SPI_REGISTER_H_ */
