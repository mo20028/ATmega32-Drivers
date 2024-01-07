/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : Ultrasonic          *************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"


#include "Ultra_config.h"
#include "Ultra_interface.h"
#include "Ultra_private.h"
#include "../../1-mcal/6-TIMER/Timer_interface.h"
#include "../../1-mcal/1-DIO/DIO_interface.h"
#include <util/delay.h>

static u16 Ultra_Reading;
static u16 Ultra_Distance;
static u8 couter=0;
static u16 reading1;
static u16 reading2;

void Ultra_voidInti(void)
{
	Timer1_voidInt();
	Timer_u8SetCallBack(&edge_pro, ICU_capture);
	ICU_inti();

}
void edge_pro(void)
{
	couter++;
	if(couter==1)
	{
		reading1=ICU_u16ReadingTimer();
		ICU_voidsetTirgrededge(ICU_falling_edge);
	}
	else if(couter==2)
	{
		reading2=ICU_u16ReadingTimer();
		Ultra_Reading=reading2-reading1;
		ICU_voidsetTirgrededge(ICU_rissing_edge);
		ICU_voidDisableinterrupt();
		couter=0;
	}

}
void Ultra_Trigger(void)
{
	DIO_u8SetPin(ULTRA_PORT, ULTRA_TRIGGAR, DIO_u8PIN_HIGH);
	_delay_ms(11);
	DIO_u8SetPin(ULTRA_PORT, ULTRA_TRIGGAR, DIO_u8PIN_LOW);
}
u16 Ultra_u16Distance(void)
{
	Ultra_Trigger();
	ICU_voidenableinterrupt();


	Ultra_Distance=(Ultra_Reading/50);

	return (Ultra_Distance);
}
void show_reading(void)
{
	CLCD_voidNumber(reading1);
	CLCD_voidSendString("   ");
	CLCD_voidNumber(reading2);
	CLCD_voidGOTOXY(1, 0);
	CLCD_voidNumber(Ultra_Reading);


}
