
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "IR_interface.h"
#include "LEDMRX_interface.h"

u8 DataArray[38] = {120, 4, 8, 16, 8, 4, 120, 0, 56, 68, 68, 56, 0, 124, 16, 112, 0, 120, 20, 20, 120, 0, 124, 8, 120, 8, 120, 0, 124, 84, 92, 0, 112, 80, 124, 0, 0, 0};

void voidDetermineKey(u8 Copy_u8Key)
{
	switch(Copy_u8Key)
	{
		case STOP		:	HLEDMRX_voidPauseAnimating();	break;
		case ON			:	HLEDMRX_voidResumeAnimating();	break;
		case VOL_UP		:	HLEDMRX_voidSpeedUp();		break;
		case VOL_DOWN	:	HLEDMRX_voidSpeedDown();			break;
	}
}
void main (void)
{
	/* RCC Initialize */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(APB2, IOPA); /* GPIOA Enable Clock */
	MRCC_voidEnableClock(APB2, IOPB); /* GPIOB Enable Clock */

	MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING); /* A0 Input Floating        */

	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(HIR_voidGetFrame, LINE0);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */

	/* SysTick Init */
	MSTK_voidInit();

	/*Init LedMatrix pins*/
	HLEDMRX_voidInit();

	HIR_voidSetCallBack(voidDetermineKey);

	/*Start animating the name*/
	HLEDMRX_voidAnimation(DataArray);

}
