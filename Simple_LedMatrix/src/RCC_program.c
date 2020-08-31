/********************************************************************/
/* Author	: MOHAMED ABDELNABY									 	*/
/* Date		: 08 Aug 2020                                           */
/* Version	: V01                                              		*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR =   0x00010000;			//Enable HSE with no bypass
		RCC_CFGR = 0x00000001;			//SW(bit0,1) = 0x01 HSE
		
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000;			//Enable HSE with bypass
		RCC_CFGR = 0x00000001;			//SW(bit0,1) = 0x01 HSE
										 
	#elif RCC_CLOCK_TYPE == RCC_HSI      
		RCC_CR   = 0x00000081;			//Enable HSI
		RCC_CFGR = 0x00000000;			//SW(bit0,1) = 0x00 HSI
		
	#elif RCC_CLOCK_TYPE == RCC_PLL
	
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			/*Enable HSI
			Trim value is default*/
			RCC_CR   = 0x00000081;			
			/*SW(bit0,1) = 0x10 -> Choose Pll as clock system
			PLL SRC (bit16) = 0 -> HSI/2*/
			RCC_CFGR = 0x00000002;
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL
			//Enable HSE with no bypass
			RCC_CR 		= 0x00010000;			
			/*SW(bit0,1) = 0x10 -> Choose Pll as clock system
			  PLL SRC (bit16) = 1 -> HSE
			  */
			RCC_CFGR	= 0x00010002;

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC
			//Enable HSE with bypass
			RCC_CR   = 0x00050000;			
			//PLL SRC (bit16) = 1 -> HSE
			RCC_CFGR	= 0x00010002;
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2
			//Enable HSE with no bypass
			RCC_CR 		= 0x00010000;			
			/*PLL SRC (bit16) = 1 -> HSE,
			  PLLXTPRE = 1 -> HSE/2
			  */
			RCC_CFGR 	= 0x00030002;
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2
			RCC_CR   = 0x00050000;			/*Enable HSE with bypass*/
			/*PLL SRC (bit16) = 1 -> HSE,
			  PLLXTPRE = 1 -> HSE/2*/
			RCC_CFGR 	= 0x00030002;
			
		#else
			#error("You should choose an available clcSystem")
		#endif
		
		//Setting the mul value to PLL
		#if ( CLOCK_FACTOR >= NO_CLOCK_FACTOR ) && ( CLOCK_FACTOR <= PLL_CLOCK_MULTIPLE_BY_16)
			CFGR &= ~( ( 0b1111 )     << 18 ) ;		//clearing the MUl bits
			CFGR |=  ( CLOCK_FACTOR ) << 18   ;		//Set the new value
		#elif ( CLOCK_FACTOR > PLL_CLOCK_MULTIPLE_BY_16 ) || ( CLOCK_FACTOR < NO_CLOCK_FACTOR )
			#warning "Wrong Multiplication Factor"
		#endif
		
		/*PLLON*/
		Set_BIT(RCC_RC, 24);
		
	#else
		#error("You should choose an available clcSystem")
	
	#endif
}

void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* input validation */
	if (Copy_u8PerId <= 31)
	{
		//check on witch bus the peripheral belongs to
		switch (Copy_u8BusId)
		{
			//Enable the peripeheral
			case AHB  : SET_BIT (RCC_AHBENR, Copy_u8PerId); 	break;
			case APB1 : SET_BIT (RCC_APB1ENR, Copy_u8PerId);	break;
			case APB2 :	SET_BIT (RCC_APB2ENR, Copy_u8PerId);	break;
			default		  : /*Return Error*/						break;
		}
	}
	else 
	{
		/*Return Error*/
	}
}

void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* input validation */
	if (Copy_u8PerId <= 31)
	{
		//check on witch bus the peripheral belongs to
		switch (Copy_u8BusId)
		{
			//Disable the peripeheral
			case AHB  : CLR_BIT (RCC_AHBENR, Copy_u8PerId);		break;
			case APB1 : CLR_BIT (RCC_APB1ENR, Copy_u8PerId); 	break;
			case APB2 :	CLR_BIT (RCC_APB2ENR, Copy_u8PerId); 	break;
			default		  : /*Return Error*/						break;
		}
	}
	else 
	{
		/*Return Error*/
	}
}
