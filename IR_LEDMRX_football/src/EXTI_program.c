/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 22 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

static void(* EXTI_CallBack[16])(void);

void MEXTI_voidInit()
{
	SET_BIT(EXTI -> IMR, EXTI_LINE);
	#if EXTI_MODE == RISING
		SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif EXTI_MODE == FALLING 
		SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#elif EXTI_MODE == CHANGING
		SET_BIT(EXTI -> RTSR, EXTI_LINE);
		SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#else
		#error "Wrong Interrupt mode"
	#endif
}


void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR, Copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR, Copy_u8Line);
}

void MEXTI_voidSoftWareTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER, Copy_u8Line);
}

void MEXTI_voidSetSignallatch(u8 Copy_u8Line, u8 Copy_u8SenseMode)
{
	switch(Copy_u8SenseMode)
	{
		case RISING:	SET_BIT(EXTI -> RTSR, Copy_u8Line); break;
		case FALLING:	SET_BIT(EXTI -> FTSR, Copy_u8Line);	break;
		case CHANGING:	SET_BIT(EXTI -> RTSR, Copy_u8Line); 
						SET_BIT(EXTI -> FTSR, Copy_u8Line);	break;
	}
	MEXTI_voidEnableEXTI(Copy_u8Line);
}

void MEXTI_voidSetCallBack(void(*ptr)(void), u8 Copy_u8Line)
{
	switch(Copy_u8Line)
	{
		case LINE0:
			EXTI_CallBack[0] = ptr;
			break;
		case LINE1:
			EXTI_CallBack[1] = ptr;
			break;
		case LINE2:
			EXTI_CallBack[2] = ptr;
			break;
		case LINE3:
			EXTI_CallBack[3] = ptr;
			break;
		case LINE4:
			EXTI_CallBack[4] = ptr;
			break;
		case LINE5:
			EXTI_CallBack[5] = ptr;
			break;
		case LINE6:
			EXTI_CallBack[6] = ptr;
			break;
		case LINE7:
			EXTI_CallBack[7] = ptr;
			break;
		case LINE8:
			EXTI_CallBack[8] = ptr;
			break;
		case LINE9:
			EXTI_CallBack[9] = ptr;
			break;
		case LINE10:
			EXTI_CallBack[10] = ptr;
			break;
		case LINE11:
			EXTI_CallBack[11] = ptr;
			break;
		case LINE12:
			EXTI_CallBack[12] = ptr;
			break;
		case LINE13:
			EXTI_CallBack[13] = ptr;
			break;
		case LINE14:
			EXTI_CallBack[14] = ptr;
			break;
		case LINE15:
			EXTI_CallBack[15] = ptr;
			break;	
	}
}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	SET_BIT(EXTI -> PR, 0);
}
