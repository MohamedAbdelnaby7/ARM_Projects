#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "ESP_interface.h"

void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(APB2, IOPA);		/* Enable GPIOA clock*/
	MRCC_voidEnableClock(APB2, USART1);		/* Enable USART1 Clock */

	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	MGPIO_voidSetPinDirection(GPIOA, PIN10, INPUT_FLOATING);

	MUSART1_voidInit();

	HESP_voidInit();

	HESP_voidConnctToRouter("MIDO", "allmaimido1");
	HESP_voidConnectToServer("TCP", "162.253.155.226", "80");
	HESP_voidExecuteRequest("GET http://simpleiot.freevar.com/status.txt");

}
