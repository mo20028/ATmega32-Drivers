/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : RTOS           *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : RTOS             *************************/
/************************************************************************/
/************************************************************************/

#ifndef RTOS_INTEFACE_H_
#define RTOS_INTEFACE_H_

void RTOS_voidStart(void);

u8 RTOS_u8CreateTask(u8 copy_u8priority, u16 copy_u16periodesity , void(*copy_pvTaskfunc)(void));

void RTOS_voidSuspendTask(u8 copy_u8priority);
void RTOS_voidResumeTask(u8 copy_u8priority);
void RTOS_voidDeleteTask(u8 copy_u8priority);

#endif
