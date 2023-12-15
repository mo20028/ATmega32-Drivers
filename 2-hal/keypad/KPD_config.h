/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : KPD           *************************/
/************************************************************************/
/************************************************************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define KPD_PORT   			DIO_u8PORTD

#define KPD_column0_pin		DIO_u8PIN0
#define KPD_column1_pin		DIO_u8PIN1
#define KPD_column2_pin		DIO_u8PIN2
#define KPD_column3_pin		DIO_u8PIN3

#define KPD_row0_pin		DIO_u8PIN4
#define KPD_row1_pin		DIO_u8PIN5
#define KPD_row2_pin		DIO_u8PIN6
#define KPD_row3_pin		DIO_u8PIN7


#define KPD_NOPRESS_KEY		0xff;

#define KPDarr    			{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}


#endif
