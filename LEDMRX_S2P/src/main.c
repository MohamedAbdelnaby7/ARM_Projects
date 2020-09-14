#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "S2P_interface.h"

u8 DataArray[8] = {120, 4, 8, 16, 8, 4, 120, 0};

void main (void)
{
	/*Clock initializations*/
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(APB2, IOPA);

	/*PINS direction*/
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);

	u8 Local_Colume = 1;

	while (1)
	{
		for (u8 i = 0; i <=7; i++)
		{
			u16 Local_u16DataToSend = (~Local_Colume << 8) | DataArray[i];
			HSTP_voidSendSynchronous(Local_u16DataToSend, 2);
			MSTK_voidSetBusyWait(1350);
			Local_Colume = Local_Colume << 1;
		}
		Local_Colume = 1;
	}
}
