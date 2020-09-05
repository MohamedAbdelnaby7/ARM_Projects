/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 28 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_INTERFACE.h"
#include "STK_CONFIG.h"
#include "STK_PRIVATE.h"

void (*CallBack) (void);

void MSTK_voidInit(void)
{
	CLR_BIT(STK_CTRL, COUNTER_ENABLE);
	#if(CLK_SOURCE == AHB_NO_DIV)
		SET_BIT(STK_CTRL, 2);
	#elif(CLK_SOURCE == AHB_DIV_8)
		CLR_BIT(STK_CTRL, 2);
	#endif
	SET_BIT(STK_CTRL, COUNTER_ENABLE);
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, COUNTER_ENABLE);
	while((GET_BIT(STK_CTRL, COUNTER_FLAG)) == 0);
	CLR_BIT(STK_CTRL, COUNTER_ENABLE);
	STK_VALUE = 0;
	STK_LOAD = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
	CLR_BIT(STK_CTRL,0);
	STK_VALUE = 0;
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, TICK_INT);
	CallBack = Copy_ptr;
	Is_Periodic = 0;
	SET_BIT(STK_CTRL, COUNTER_ENABLE);
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
	CLR_BIT(STK_CTRL,0);
	STK_VALUE = 0;
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, TICK_INT);
	CallBack = Copy_ptr;
	Is_Periodic = 1;
	SET_BIT(STK_CTRL, COUNTER_ENABLE);
}

void MSTK_voidStopInterval(void) {
	CLR_BIT(STK_CTRL, 1);
	SET_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VALUE = 0;
}

u32 MSTIK_u32GetElapsedTime(void)
{
	return STK_LOAD - STK_VALUE ;
}


u32 MSTIK_u32GetRemainingTime(void)
{
	return STK_VALUE;
}

void SysTick_Handler (void)
{
	u8 Local_u8Temporary;
	if(~Is_Periodic)
	{
		CLR_BIT(STK_CTRL, 1);
		SET_BIT(STK_CTRL, 0);
		STK_LOAD = 0;
		STK_VALUE = 0;
	}
	CallBack();
	Local_u8Temporary = GET_BIT(STK_CTRL,16);
}
