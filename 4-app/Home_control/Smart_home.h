/*
 * Smart_home.h
 *
 *  Created on: Jul 27, 2023
 *      Author: MS
 */

#ifndef SMART_HOME_H_
#define SMART_HOME_H_
/************************************ Definition for variable  ****************************/
#define Open_door		1
#define close_door		2

#define Open_Led		3
#define Close_Led		4
#define Adjust_Led		5

#define Open_Fan		6
#define Close_Fan		7
#define Adjust_Fan		8
/*********************************** Declaration for function *****************************/
 void Welcome_mes(void);
 void Menu(void);
 u8   Get_Number(u8 *copy_u8Number);
 u8   Doors(u8 copy_u8door_State);
 u8   LED_control(u8 copy_u8Led_State);
 u8   FAN_control(u8 copy_u8Fan_State);
 u8   Stop_System(u8 *copy_u8Choose);
 u8	  Smart(u8 copy_u8choose);



#endif /* SMART_HOME_H_ */
