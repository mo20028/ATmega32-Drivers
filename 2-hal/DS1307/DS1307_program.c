/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************  layer  : HAL           	*************************/
/*******************  Version: 1.00         	*************************/
/*******************  SWC 	 : DS1307(RTC)     	*************************/
/************************************************************************/
/************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "TWI_interface.h"

#include "DS1307_interface.h"
#include "DS1307_private.h"


static u8 BCD_toDicmal(u8 copy_u8number)
{
	u8 Dicmal=(copy_u8number&0x0f);
	Dicmal+=(copy_u8number>>4)*10;
	return Dicmal;

}
void DS_SetTime(DS1307_t *copy_DSconfig)
{

	TWI_SendStartcon();								// start communication with ds1307
	TWI_SendSlaveAddress_Write(SLAVE_ADDRESS);		// send slave address
	TWI_MasterWriteData(DS1307_START_ADDRESS);		// send start address in ds1307

	TWI_MasterWriteData(copy_DSconfig->second);		// write second
	TWI_MasterWriteData(copy_DSconfig->min);		// write minute
	TWI_MasterWriteData(copy_DSconfig->hour);		// write hour
	TWI_MasterWriteData(copy_DSconfig->week_day);	// write Week day
	TWI_MasterWriteData(copy_DSconfig->day);		// write day
	TWI_MasterWriteData(copy_DSconfig->month);		// write month
	TWI_MasterWriteData(copy_DSconfig->year);		// write year

	TWI_voidSendStopCondition();					// stop communication

}

void DS_ReadTime(DS1307_t *copy_DSconfig)
{
	/***************** receive data form ds1307 ************************/
	TWI_SendStartcon();								// start communication with DS130
	TWI_SendSlaveAddress_Write(SLAVE_ADDRESS);		// send Slave address for ds1307
	TWI_MasterWriteData(DS1307_START_ADDRESS);		// send start address for ds1307
	TWI_SendRestartcon();							// send restart condition
	TWI_SendSlaveAddress_Read(0x68);				// send Slave address for ds1307 againg
	TWI_MasterReadData(&copy_DSconfig->second);     // read second
	TWI_MasterReadData(&copy_DSconfig->min);        // read minute
	TWI_MasterReadData(&copy_DSconfig->hour);       // read hour
	TWI_MasterReadData(&copy_DSconfig->week_day);   // read Week day
	TWI_MasterReadData(&copy_DSconfig->day);        // read day
	TWI_MasterReadData(&copy_DSconfig->month);      // read month
	TWI_MasterReadData_N(&copy_DSconfig->year);     // read year

	TWI_voidSendStopCondition();					// stop communication

	/*************** convert form BCD to dismal *******************/
	copy_DSconfig->second=BCD_toDicmal(copy_DSconfig->second);
	copy_DSconfig->min=BCD_toDicmal(copy_DSconfig->min);
	copy_DSconfig->hour=BCD_toDicmal(copy_DSconfig->hour);
	copy_DSconfig->week_day=BCD_toDicmal(copy_DSconfig->week_day);
	copy_DSconfig->day=BCD_toDicmal(copy_DSconfig->day);
	copy_DSconfig->month=BCD_toDicmal(copy_DSconfig->month);
	copy_DSconfig->year=BCD_toDicmal(copy_DSconfig->year);
	copy_DSconfig->APM=copy_DSconfig->hour/12;

}

