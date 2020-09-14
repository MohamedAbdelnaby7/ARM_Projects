/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 14 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "S2P_interface.h"
#include "S2P_private.h"
#include "S2P_config.h"

void HSTP_voidSendSynchronous(u32 Copy_u8DataToSend, u8 Copy_u8NumberOfRegisters)
{
	s8 Local_u8Counter;
	u8 Local_u8Bit;
	
	Local_u8Counter = Copy_u8NumberOfRegisters * 8 - 1;

	for (; Local_u8Counter >= 0; Local_u8Counter--)
	{
		/*Send bit by bit starting from MSb*/
		Local_u8Bit = GET_BIT(Copy_u8DataToSend, Local_u8Counter);
		
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA, Local_u8Bit);
		
		/*send pulse to shift reg clock*/
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, LOW);
		MSTK_voidSetBusyWait(1);
	}
	/*send pulse to storage clock*/
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, LOW);
	MSTK_voidSetBusyWait(1);
}
