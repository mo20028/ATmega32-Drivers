/*
 * Smart_home.c
 *
 *  Created on: Jul 27, 2023
 *      Author: MS
 */
#include "STD_types.h"
#include "BIT_math.h"
#include "map.h"

#include "Smart_home.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "Timer_interface.h"
#include "Uasrt_inteface.h"
#include "Srevo_inteface.h"


#include "util/delay.h"

/*************************** some static function deceleration ********************************/

/***************************  		Variable Decaleration	   ********************************/
static u8 Order_Num;
static u16 LDR_Reading;
static u8  Light_insity;
static u16 LM_Reading;
static u8  Fan_speed;

void Welcome_mes(void)
{
	u8 it;
	UART_voidSendString("Welcome to your Home\r");
	UART_voidSendString("Please wait");
	for(it =0;it<15;it++)
	{
		UART_voidTX('.');
		_delay_ms(100);
	}
	UART_voidTX('\r');
}
void Menu(void)
{
	UART_voidSendString("	Choose Menu\r");
	UART_voidSendString(" 1:open the door \r");
	UART_voidSendString(" 2:close the door \r");
	UART_voidSendString(" 3:open the light \r");
	UART_voidSendString(" 4:close the light \r");
	UART_voidSendString(" 5:Adjust the brightness \r");
	UART_voidSendString(" 6:open the fan \r");
	UART_voidSendString(" 7:close the fan \r");
	UART_voidSendString(" 8:Adjust fan speed \r");
	UART_voidSendString(" 9:Play music \r");
	UART_voidSendString("10:close the system\r");
}
u8   Get_Number(u8 *copy_u8Number)
{
	u8 local_error=OK;

	UART_voidSendString("please enter your choose\r");
	*copy_u8Number=Uart_u8recive();
	return local_error;
}
u8 Doors(u8 copy_u8door_State)
{
	u8 local_error=OK;
	if(copy_u8door_State==Open_door)
	{
		Servo_u8Angle(90);
	}
	else if(copy_u8door_State==close_door)
	{
		Servo_u8Angle(20);
	}
	else
	{
		local_error=NOK;
	}
	return local_error;
}
u8   LED_control(u8 copy_u8Led_State)
{
	u8 local_error=OK;
	if(copy_u8Led_State==Open_Led){
		setbitvalue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_HIGH);
	}
	else if(copy_u8Led_State==Close_Led){
		setbitvalue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_LOW);
	}
	else if(copy_u8Led_State==Adjust_Led){

		ADC_u8startconversionsync(ADC0, &LDR_Reading);
		Light_insity=map(0, 159, 0,255, LDR_Reading);
		Timer_config item={Timer0,fast_PWM,Light_insity,divid_8};
		Timer_Inti(&item);

	}
	else{
		local_error=NOK;
	}

	return local_error;
}
u8   FAN_control(u8 copy_u8Fan_State)
{
	u8 local_error=OK;
	if(copy_u8Fan_State==Open_Fan){
		setbitvalue(DIO_u8PORTD, DIO_u8PIN7, DIO_u8PIN_HIGH);
	}
	else if(copy_u8Fan_State==Close_Fan){
		setbitvalue(DIO_u8PORTD, DIO_u8PIN7, DIO_u8PIN_LOW);
	}
	else if(copy_u8Fan_State==Adjust_Fan){
		ADC_u8startconversionsync(ADC1, &LM_Reading);
		Fan_speed=map(10, 20, 0,255, LM_Reading);
		Timer_config item={Timer2,fast_PWM,Fan_speed,t2_divid_8};
		Timer_Inti(&item);
	}
	else{
		local_error=NOK;
	}

	return local_error;
}
u8   Stop_System(u8 *copy_u8Choose)
{
	UART_voidSendString("	Choose Menu\r");
	UART_voidSendString("0: EXIT from the System\r");
	UART_voidSendString("1: Return to Main Menu \r");
	Get_Number(copy_u8Choose);

}
u8	  Smart(u8 copy_u8choose)
{
	u8 local_error=OK;
	switch(copy_u8choose)
	{
	case '1':Doors(Open_door);
	break;
	case '2':Doors(close_door);
	break;
	case '3':LED_control(Open_Led);
	break;
	case '4':LED_control(Close_Led);
	break;
	case '5':LED_control(Adjust_Led);
	break;
	case '6':FAN_control(Open_Fan);
		break;
	case '7':FAN_control(Close_Fan);
		break;
	case '8':FAN_control(Adjust_Fan);
		break;


	}

	return local_error;
}
