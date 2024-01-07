/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : Hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : LED              *************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"


#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"

#include "../../1-mcal/1-DIO/DIO_interface.h"


void LED_voidBlank_one_led(u8 copy_u8PORT, u8 copy_u8PIN,u8 copy_u8status)
{
	DIO_u8SetPin(copy_u8PORT, copy_u8PIN, copy_u8status);
}

void LED_voidBlank_register(u8 copy_u8PORT, u8 copy_u8status)
{
	DIO_u8SetPort(copy_u8PORT,copy_u8status );
}
