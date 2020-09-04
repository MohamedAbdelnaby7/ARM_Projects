/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 15 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "DELAY.h"

/* generating a delay in micro seconds*/
void delay_ms(u32 Copy_u32Time)
{
	u32 i = 0;

	for(i = 0; i < ((SYSTEM_CLOCK/(12000)) * Copy_u32Time); i++)
	{
		__asm ("NOP");
	}
}