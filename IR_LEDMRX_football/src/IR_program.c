/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 03 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "IR_interface.h"
#include "STK_interface.h"
#include "IR_private.h"
#include "IR_config.h"

volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

void(* IR_CallBack)(u8 Copy_u8Key);

void HIR_voidGetFrame(void)
{
	if (u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(100000,HIR_voidExtractKey);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(100000,HIR_voidExtractKey);
		u8EdgeCounter++;
	}
}

void HIR_voidExtractKey(void)
{
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (u8 i=0;i<8;i++)
		{
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		IR_CallBack(u8Data);
	}
	else
	{
		/* Invalid Frame */
	}
	
	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void HIR_voidSetCallBack(void(*ptr)(u8 Copy_u8Key))
{
	IR_CallBack = ptr;
}
