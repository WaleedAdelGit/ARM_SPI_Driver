/**************************************************************************************************/
/* Author  : Waleed Adel                                                                        */
/* Version : V01                                                                                  */
/* Date    : 28 DEC 2024                                                                           */
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "ARM_SPI_interface.h"
#include "ARM_SPI_register.h"
#include "ARM_SPI_private.h"
#include "ARM_SPI_config.h"

void ASPI_voidSlave(void)
{

#if  CLOCK_POLARITY==LOW_LEVEL

	//SET CLOCK POLARITY LOW
	CLR_BIT(ASPI->CR1,CR1_CPOL);

#elif CLOCK_POLARITY==HIGH_LEVEL

	//SET CLOCK POLARITY HIGH
	SET_BIT(ASPI->CR1,CR1_CPOL);

#endif

#if    CLOCK_PHASE==READ_THEN_WRITE
	//SET CLOCK PHASE READ THEN WRITE
	CLR_BIT(ASPI->CR1,CR1_CPHA);

#elif  CLOCK_PHASE==WRITE_THEN_READ
	//SET CLOCK PHASE WRITE THEN READ
	SET_BIT(ASPI->CR1,CR1_CPHA);
#endif

#if   DATA_FORMATE==DATA_8BIT
	//SET 8 BIT DATA FORMATE
	CLR_BIT(ASPI->CR1,CR1_DFF);
#elif DATA_FORMATE==DATA_16BIT
	//SET 16 BIT DATA FORMATE
	SET_BIT(ASPI->CR1,CR1_DFF);
#endif
#if   FIRST_TRANSMITTED_BIT==MSB_FIRST
	//MSB
	CLR_BIT(ASPI->CR1,CR1_LSBFIRST);
#elif FIRST_TRANSMITTED_BIT==LSB_FIRST
	//LSB
	SET_BIT(ASPI->CR1,CR1_LSBFIRST);
#endif
	//SLAVE SELECTION
	CLR_BIT(ASPI->CR1,CR1_MSTR);
#if  NSS_MODE==NSS_SOFTWARE
	//SOFTWARE NSS ENABLED FOR SLAVE
	SET_BIT(ASPI->CR1,CR1_SSM);
	CLR_BIT(ASPI->CR1,CR1_SSI);

#endif
	//PERIPHRAL ENABLE
	SET_BIT(ASPI->CR1,CR1_SPE);

}


u16 ASPI_u16SlaveRecieve(void)
{
	u16 Local_u16Data=0;
	//WAIT FOR RX FLAG
	while(GET_BIT(ASPI->SR,SR_RXNE)==0);

	//RECIEVE DATA FROM DATA REGISTER
	Local_u16Data=ASPI->DR;

	return Local_u16Data;
}



