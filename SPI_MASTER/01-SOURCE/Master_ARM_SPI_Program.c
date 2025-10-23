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
#include "ARM_SPI_config.h"

void ASPI_voidMaster(void)
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


#if MODE==MASTER
	//MASTER SELECTION
	SET_BIT(ASPI->CR1,CR1_MSTR);

	(ASPI->CR1)&=~(BAUDRATE_BIT_CLEAR<<4);
	(ASPI->CR1)|=(BAUD_RATE<<4);

#if  NSS_MODE==NSS_SOFTWARE
	//SOFTWARE NSS ENABLED FOR MASTER
	SET_BIT(ASPI->CR1,CR1_SSM);
	SET_BIT(ASPI->CR1,CR1_SSI);
#elif NSS_MODE==NSS_HARDWARE
	//HARDWARE NSS MODE (CONFIGURED IN MASTER ONLY)
#if NSS_HARDWARE_MODE==NSS_OUTPUT_ENABLED
	CLR_BIT(ASPI->CR1,CR1_SSM);
	SET_BIT(ASPI->CR2,CR2_SSOE);
#elif NSS_HARDWARE_MODE==NSS_OUTPUT_DISABLED
	CLR_BIT(ASPI->CR1,CR1_SSM);
	CLR_BIT(ASPI->CR2,CR2_SSOE);
#endif
#endif
#elif MODE==SLAVE
	//SLAVE SELECTION
	CLR_BIT(ASPI->CR1,CR1_MSTR);
#if  NSS_MODE==NSS_SOFTWARE
	//SOFTWARE NSS ENABLED FOR SLAVE
	SET_BIT(ASPI->CR1,CR1_SSM);
	CLR_BIT(ASPI->CR1,CR1_SSI);
#endif
#endif
	//PERIPHRAL ENABLE
	SET_BIT(ASPI->CR1,CR1_SPE);
}

void ASPI_u16MasterTransfer(u16 Copy_u16Data)
{
	//WAIT FOR TX FLAG
	while(GET_BIT(ASPI->SR,SR_TXNE)==0);

	//SEND DATA TO THE DATA REGISTER
	ASPI->DR=Copy_u16Data;
}
