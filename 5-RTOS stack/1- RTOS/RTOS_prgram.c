/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : RTOS           *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : RTOS             *************************/
/************************************************************************/
/************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "Timer_interface.h"
#include "GIE_interface.h"

#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"

Task_t System_Task[TASK_NUM]={{NULL}};

void RTOS_voidStart(void)
{
	Timer0_u8SetCallBack(&scadule);
	GIE_voidEnable();
	Timer0_voidInt();
}

u8 RTOS_u8CreateTask(u8 copy_u8priority, u16 copy_u16periodesity , void(*copy_pvTaskfunc)(void))
{
	u8 local_error_state=OK;
	/* check of the record periority is empty*/
	if(System_Task[copy_u8priority].pv_funTask==NULL){
		System_Task[copy_u8priority].perdiosity=copy_u16periodesity;
		System_Task[copy_u8priority].pv_funTask=copy_pvTaskfunc;
		System_Task[copy_u8priority].Task_state=TASK_RESUME;
	}
	else
	{
		local_error_state=NOK;
	}

	return local_error_state;

}
static void scadule(void)
{
	static u16 Task_counter=0;
	u8      local_u8iter=0;

	Task_counter++;

	for(local_u8iter=0;local_u8iter<TASK_NUM;local_u8iter++)
	{
		if(System_Task[local_u8iter].Task_state==TASK_RESUME){ //check TASK state
			if(Task_counter % System_Task[local_u8iter].perdiosity==0){
				/*invake the task func */
				if(System_Task[local_u8iter].pv_funTask!=NULL){
					System_Task[local_u8iter].pv_funTask();
				}else{
					/* do nothing*/
				}
			}
			else{
				// Task is suspended
				// do nothing
			}
		}
	}
	if(Task_counter==60000)
	{
		Task_counter=0;
	}
}
void RTOS_voidSuspendTask(u8 copy_u8priority)
{
	System_Task[copy_u8priority].Task_state=TASK_SUSPEND;
}
void RTOS_voidResumeTask(u8 copy_u8priority)
{
	System_Task[copy_u8priority].Task_state=TASK_RESUME;
}
void RTOS_voidDeleteTask(u8 copy_u8priority)
{
	System_Task[copy_u8priority].pv_funTask=NULL;
}
