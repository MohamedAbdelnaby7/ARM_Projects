/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 26 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* global variable */
u32 Global_u32Clock;

/* Callback Global Variable */
static void(*MSTK_CallBackFunc)(void);

/* setting the SysTick clock source */
void MSTK_voidInit(void)
{
	/* desabling the SysTick module */
	CLR_BIT(SysTick -> CTRL, ENABLE);

	/* configuring the clock prescaler */
	#if MSTK_CLK_SRC == AHP_CLK
		SET_BIT(SysTick -> CTRL, CLK_SRC);
		Global_u32Clock = 8000000;

	#elif MSTK_CLK_SRC == AHP_CLK_8
		CLR_BIT(SysTick -> CRTL, CLK_SRC);
		Global_u32Clock = 1000000;

	#endif

	/* enabling the SysTick module */
	SET_BIT(SysTick -> CTRL, ENABLE);

}

/* generating a synchronous time delay */
void MSTK_voidSetBusyWait(u32 Copy_u32ms)
{
	u32 Loc_u32Ticks = 0;

	/* getting the ticks required for the corresponding time */
	Loc_u32Ticks = (Copy_u32ms * (Global_u32Clock / 1000));

	/* start the timer and loading ticks to LOAD reg */
	SysTick -> LOAD = Loc_u32Ticks;
	SET_BIT(SysTick -> CTRL, ENABLE);

	/* Wait till flag is set */
	while(!(GET_BIT(SysTick -> CTRL, COUNT_FLAG)));

	/* Stop Timer */
	CLR_BIT(SysTick -> CTRL, ENABLE);

	/* clearing the LOAD and VAL reg*/
	SysTick -> LOAD = 0;
	SysTick -> VAL  = 0;

}

/* generating an asynchronous time delay */
void MSTK_voidSetInterval(u32 Copy_u32ms, void (* Copy_ptr) (void))
{
	u32 Loc_u32Ticks = 0;

	/* getting the ticks required for the corresponding time */
	Loc_u32Ticks = (Copy_u32ms * (Global_u32Clock / 1000));
	SysTick -> LOAD = Loc_u32Ticks;

	/* Start Timer */
	SET_BIT(SysTick -> CTRL, ENABLE);

	/* Enable SysTick Interrupt */
	SET_BIT(SysTick -> CTRL, TICK_IRQ);

	/* Save CallBack */
	MSTK_CallBackFunc = Copy_ptr;
}

/* disabling the systick module */
void MSTK_voidStopTimer(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(SysTick -> CTRL, TICK_IRQ);

	/* stop timer */
	CLR_BIT(SysTick -> CTRL, ENABLE);

	/* clearing registers */
	SysTick -> LOAD = 0;
	SysTick -> VAL  = 0;
}

/* getting the elapsed time from the set time */
u32 MSTK_u32GetElapsedTime(void)
{
	return(((SysTick -> LOAD) - (SysTick -> VAL)) / (Global_u32Clock / 1000));
}

/* getting the remaining time from the set time */
u32 MSTK_u32RemainingTime(void)
{
	return ((SysTick -> VAL) / (Global_u32Clock / 1000));

}

/* SysTick ISR */
void SysTick_Handler(void)
{
	MSTK_CallBackFunc();
}
