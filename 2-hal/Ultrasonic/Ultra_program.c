/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : Ultrasonic          *************************/
/************************************************************************/
/************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"


#include "Ultra_config.h"
#include "Ultra_interface.h"
#include "Ultra_private.h"
#include "Timer_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

static u16 Ultra_Reading;
static u16 Ultra_Distance;
static u8 couter=0;
static u16 reading1;
static u16 reading2;

/************************************************************************
************************ define static functions *************************
*************************************************************************/
static void Ultra_Trigger(u8 copy_port,u8 copy_pin);
static void edge_pro(void);


/************************************************************************
************************ implement functions ****************************
*************************************************************************/

void Ultra_voidInti()
{
	Timer1_voidInt();
	Timer_u8SetCallBack(&edge_pro, ICU_capture);
	ICU_inti();

}

u16 Ultra_u16Distance(Ultra_t *copy_ultra)
{
	Ultra_Trigger(copy_ultra->trg_port,copy_ultra->trg_pin);
	ICU_voidenableinterrupt();


	Ultra_Distance=(Ultra_Reading/58);

	return (Ultra_Distance);
}


/****************************************************************************
************************ implement static functions *************************
*****************************************************************************/
static void edge_pro(void)
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
static void Ultra_Trigger(u8 copy_port,u8 copy_pin)
{
	DIO_u8SetPin(copy_port, copy_pin, DIO_u8PIN_HIGH);
	_delay_ms(11);
	DIO_u8SetPin(copy_port, copy_pin, DIO_u8PIN_LOW);
}
