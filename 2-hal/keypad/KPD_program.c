/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : PORT          *************************/
/************************************************************************/
/************************************************************************/

#include "STD_types.h"

#include  "DIO_interface.h"

#include "KPD_config.h"
#include  "KPD_interface.h"
#include  "KPD_private.h"

u8 KPD_u8GetPressKey(void)
{
	/* the varible you will use */
	u8 Local_u8PressKey=KPD_NOPRESS_KEY;
	u8 Local_u8Column,Local_u8Row,Local_u8Pin_State;

	/* arrs you will used */
	static u8 Local_u8KPDarr[Row_num][Column_num]=KPDarr;
	static u8 Local_u8KPDColumnarr[Column_num]={KPD_column0_pin,KPD_column1_pin,KPD_column2_pin,KPD_column3_pin};
	static u8 Local_u8KPDRowarr[Row_num]={KPD_row0_pin,KPD_row1_pin,KPD_row2_pin,KPD_row3_pin};

	for(Local_u8Column=0;Local_u8Column<Column_num;Local_u8Column++)
	{
		/* active current column */
		setbitvalue(KPD_PORT, Local_u8KPDColumnarr[Local_u8Column]	, DIO_u8PIN_LOW	);

		for(Local_u8Row=0;Local_u8Row<Row_num;Local_u8Row++)
		{
			/* read the current row*/
			getbit(KPD_PORT, Local_u8KPDRowarr[Local_u8Row], &Local_u8Pin_State);

			/*check the swichs pressed */
			if(DIO_u8PIN_LOW==Local_u8Pin_State)
			{
				Local_u8PressKey=Local_u8KPDarr[Local_u8Column][Local_u8Row];
				/* polling (bus waiting) utile the key is relesed */
				while(DIO_u8PIN_LOW==Local_u8Pin_State)
				{
					getbit(KPD_PORT, Local_u8KPDRowarr[Local_u8Row], &Local_u8Pin_State);

				}
				return Local_u8PressKey;
			}

		}
		/* deactive current column */
		setbitvalue(KPD_PORT, Local_u8KPDColumnarr[Local_u8Column]	, DIO_u8PIN_HIGH	);

	}


	return Local_u8PressKey;
}
