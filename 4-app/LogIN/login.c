/*
 * login.c
 *
 *  Created on: Aug 3, 2023
 *      Author: MS
 */
/*********************************************************************************/
/***************************** Include Section ***********************************/
/*********************************************************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "login.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TWI_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "EEPROM_interface.h"

#include <util/delay.h>
/*********************************************************************************/
/***************************** Variable Section **********************************/
/*********************************************************************************/

u8 password[4];
static u8 iter=0;



void enter_password(void)
{

	CLCD_voidGOTOXY(1, 0);
	CLCD_voidSendCommand(Cursor_on); //command for turn on the cursor

	u8 		Index=0;

	while(1)
	{
		u8 KPD_u8press_key=0xff;
		while(KPD_u8press_key == 0xff)
		{
			KPD_u8press_key=KPD_u8GetPressKey();
		}
		if(KPD_u8press_key== '=')
		{
			break;
		}
		else
		{
			CLCD_voidNumber(KPD_u8press_key);
			CLCD_voidCursorShift(lift);
			_delay_ms(10);
			CLCD_voidSendData('*');
			password[Index]=KPD_u8press_key;
			Index++;
		}

	}
	_delay_ms(10);
	CLCD_voidSendCommand(Cursor_off); //command for turn of the cursor
	CLCD_ClearScreen();

}
void Save_Password(void)
{
	CLCD_voidSendString("wait for saving....");

	for(iter=0;iter<4;iter++)
	{
		EEPROM_voidWrite_Byte(password[iter], iter);
		_delay_ms(100);
	}
	CLCD_ClearScreen();

}
u8   Check_password(void)
{
	u8 return_value=1;
	u8 local_value;

	for( iter=0;iter<4;iter++){

		EEPROM_voidRead_Byte(&local_value, iter);
		_delay_ms(10);
		if(local_value!=password[iter]){
			return_value=0;
		}
		else{
			// do nothing
		}
	}
	return return_value;
}
void First_password(void)
{
	u8 Check_value=0;
	u8 index=3;
	while((!Check_value)&&(index>0)){

		CLCD_ClearScreen();
		CLCD_voidSendString("Enter the password");
		enter_password();
		Save_Password();
		CLCD_ClearScreen();
		CLCD_voidSendString("Confirm the password");
		enter_password();
		Check_value=Check_password();
		index--;
		if((Check_value==0)&&(index>0)){
			CLCD_ClearScreen();
			CLCD_voidSendString("password not match");
			CLCD_voidGOTOXY(1, 0);
			CLCD_voidNumber(index);
			CLCD_voidSendString("trial left");
			_delay_ms(500);
		}
		else if(index==0){
			CLCD_voidSendString("reset the program");
			while(1);
		}

	}
}
void handl_password(void)
{
	u8 Check_value=0;
		u8 index=3;
		while((!Check_value)&&(index>0)){

			CLCD_ClearScreen();
			CLCD_voidSendString("Enter the password");
			enter_password();
			Check_value=Check_password();
			index--;
			if((Check_value==0)&&(index>0)){
				CLCD_ClearScreen();
				CLCD_voidSendString("password Wrong");
				CLCD_voidGOTOXY(1, 0);
				CLCD_voidNumber(index);
				CLCD_voidSendString("trial left");
				_delay_ms(500);
			}
			else if(Check_value==1){
				break;
			}
			else if(index==0){
				CLCD_voidSendString("reset the program");
				while(1);
			}

		}
}
