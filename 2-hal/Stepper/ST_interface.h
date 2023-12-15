/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : ST_MOTOR         *************************/
/************************************************************************/
/************************************************************************/


#ifndef ST_INTERFACE_H_
#define ST_INTERFACE_H_

#define full_step			0
#define half_step			1

u8 ST_voidclockwise(u8 copy_u8size,u16 copy_u8degree);
u8 ST_voidunclockwise(u8 copy_u8size,u16 copy_u8degree);
void stop();



#endif