/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : USART            *************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"


#include "Spi_config.h"
#include "Spi_interface.h"
#include "Spi_private.h"
#include  "Spi_register.h"


void SPI_voidintiMast(void)
{
	/*MAST INTI*/
	SET_BIT(SPCR,SPCR_MSTR);
	/*SET PARASCAL*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
	/*spi enable*/
	SET_BIT(SPCR,SPCR_SPE);
}
void SPI_voidintislave(void)
{
	/*MAST INTI*/
	CLR_BIT(SPCR,SPCR_MSTR);
	/*spi enable*/
	SET_BIT(SPCR,SPCR_SPE);
}
u8   SPI_u8trancive(u8 copy_u8data)
{
	/*SEND DATA*/
	SPDR=copy_u8data;
	/*wait until transfer is complete*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	/* get exchange value*/
	return SPDR;

}


