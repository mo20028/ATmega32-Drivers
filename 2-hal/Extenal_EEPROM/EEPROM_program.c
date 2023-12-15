/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************  layer  : Hal              *************************/
/*******************  Version: 1.00             *************************/
/*******************  SWC 	 : EEPROM           *************************/
/************************************************************************/
/************************************************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"

#include "TWI_interface.h"

TWI_error EEPROM_voidWrite_Byte(u8 copy_u8DATA,u16 copy_u16Address)
{
	TWI_error local_error=NO_error;
	TWI_SendStartcon();
	local_error|=TWI_SendSlaveAddress_Write(0x50 | (((copy_u16Address) & 0x0700) >> 8));
	TWI_MasterWriteData((u8)copy_u16Address);
	TWI_MasterWriteData(copy_u8DATA);
	TWI_voidSendStopCondition();
	return local_error;
}
u8 EEPROM_voidRead_Byte(u8 *copy_u8DATA,u16 copy_u16Address)
{
	u8 local_error=OK;
	local_error=TWI_SendStartcon();
	local_error|=TWI_SendSlaveAddress_Write((0x50)|(copy_u16Address>>8));
	local_error|=TWI_MasterWriteData((u8)copy_u16Address);
	local_error|=TWI_SendRestartcon();
	local_error|=TWI_SendSlaveAddress_Read((0x50)|(copy_u16Address>>8));
	local_error|=TWI_MasterReadData(copy_u8DATA);
	TWI_voidSendStopCondition();

	return local_error;

}
