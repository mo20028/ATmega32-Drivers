/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : RTOS           *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : Timer0           *************************/
/************************************************************************/
/************************************************************************/

#include "STD_types.h"
#include  "BIT_math.h"

#include  "Timer_config.h"
#include  "Timer_interface.h"
#include  "Timer_private.h"
#include  "Timer_register.h"

static void(*Timer0_pvCallBackfun)(void)=NULL;


void Timer0_voidInt(void)
{

	/*choose the CTC mode	*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);


	/*compare match interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
	

	 copmare match value
	OCR0=125;

	/* choose prescale div 8*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

}
void Timer0_voidSetCompareMatch(u8 copy_u8value)
{
	OCR0=copy_u8value;

}


u8 Timer0_u8SetCallBack(void (*copy_pvCallBackfun)(void))
{
	u8 local_errorstate=OK;
	if(copy_pvCallBackfun!= NULL)
	{
		Timer0_pvCallBackfun=copy_pvCallBackfun;
	}
	else
	{
		local_errorstate=NULL_POINTER;
	}



	return local_errorstate;

}



void __vector_10 (void)		__attribute__ ((signal));
void __vector_10 (void)
{
	if(Timer0_pvCallBackfun!= NULL)
	{
		Timer0_pvCallBackfun();
	}
}
