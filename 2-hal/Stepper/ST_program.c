/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : ST_MOTOR         *************************/
/************************************************************************/
/************************************************************************/


#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include  "ST_config.h"
#include  "ST_interface.h"
#include  "ST_private.h"

#include "../../1-mcal/1-DIO/DIO_interface.h"


#include  "util/delay.h"

u8 ST_voidclockwise(u8 copy_u8size,u16 copy_u8degree)
{
	u8 local_errorstate=OK;
	u8 number_of_steps;
	if(copy_u8size==full_step)
	{
		number_of_steps=copy_u8degree/(0.5*4);
		u8 iteritor;
		for(iteritor=0;iteritor<number_of_steps;iteritor++)
		{
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);

			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3, DIO_u8PIN_HIGH);
			_delay_ms(2);

		}
	}
	else if(copy_u8size==half_step)
	{
		number_of_steps=copy_u8degree/(0.5*4);
		u8 iteritor;
		for(iteritor=0;iteritor<number_of_steps;iteritor++)
		{
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
		}
	}
	else
	{
		local_errorstate=NOK;

	}
	return local_errorstate;
}
u8 ST_voidunclockwise(u8 copy_u8size,u16 copy_u8degree)
{
	u8 local_errorstate=OK;
	u8 number_of_steps;
	if(copy_u8size==full_step)
	{
		number_of_steps=copy_u8degree/(0.5*4);
		u8 iteritor;
		for(iteritor=0;iteritor<number_of_steps;iteritor++)
		{
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
		}
	}
	else if(copy_u8size==half_step)
	{
		number_of_steps=copy_u8degree/(0.5*4);
		u8 iteritor;
		for(iteritor=0;iteritor<number_of_steps;iteritor++)
		{
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_HIGH);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
			DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_HIGH);
			_delay_ms(2);
		}
	}

}
void stop()
{
	DIO_u8SetPin(STEPPER_PORT, STEPPER_pin0, DIO_u8PIN_LOW);
	DIO_u8SetPin(STEPPER_PORT, STEPPER_pin1,  DIO_u8PIN_LOW);
	DIO_u8SetPin(STEPPER_PORT, STEPPER_pin2,  DIO_u8PIN_LOW);
	DIO_u8SetPin(STEPPER_PORT, STEPPER_pin3,  DIO_u8PIN_LOW);

}
