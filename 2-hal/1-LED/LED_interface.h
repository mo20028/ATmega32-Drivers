/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : Hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : LED              *************************/
/************************************************************************/
/************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* PORT choose :
 * 					1:portA 2: portB  3:portC  4:portD
 *
 * 	status choose :
 * 					1:turn on led
 * 					2:turn off led
 * 									*/
void LED_voidBlank_one_led(u8 copy_u8PORT, u8 copy_u8PIN,u8 copy_u8status);

void LED_voidBlank_register(u8 copy_u8PORT, u8 copy_u8status);



#endif
