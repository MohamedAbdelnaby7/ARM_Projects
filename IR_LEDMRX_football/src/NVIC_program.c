/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 19 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR		*((volatile u32*)0xE000ED0C)
	SCB_AIRCR = MVIC_GROUP_SUB_DISTRIBUSTION;
}
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if ( Copy_u8IntNumber <= 31 )
	{
		Local_u8Result = GET_BIT (NVIC_IABR0, Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT (NVIC_IABR0, Copy_u8IntNumber);
	}
	else
	{
		
	}
	return Local_u8Result;
}

void MNVIC_voidSetPriority(s8 copy_s8PerIdx, u8 copy_u8Priority)
{
	/*core peripheral*/
	
	/*external peripheral*/
	if(copy_s8PerIdx >= 0 && copy_s8PerIdx < 60)
	{
		NVIC_IPR[copy_s8PerIdx] = copy_u8Priority;
	}
	else
	{
		/*Report error*/
	}
}
