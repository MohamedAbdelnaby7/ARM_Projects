/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 19 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void MUSART1_voidInit(void)
{
	#if BAUD_RATE == BAUD_9600
		USART1 -> BRR = 0x341;
	#elif BAUD_RATE == BAUD_115200
		USART1 -> BRR = 0x45;
	#endif
	
	#if USART1_WORD == USART_8_BIT_WORD
		CLR_BIT(USART1 -> CR[0], M);
	#elif USART1_WORD == USART_9_BIT_WORD
		SET_BIT(USART1 -> CR[0], M);
	#endif
	
	#if USART1_PARITY == USART_PARITY_DISABLED
		CLR_BIT(USART1 -> CR[0], PCE);
	#elif USART1_PARITY == USART_PARITY_ENABLED
		SET_BIT(USART1 -> CR[0], PCE);
		
		#if PARITY == USART_EVEN_PARITY
			CLR_BIT(USART1 -> CR[0], PS);
		#elif PARITY == USART_ODD_PARITY
			SET_BIT(USART1 -> CR[0], PS);
		#endif
		
		#if PARITY_ERROR_INTERRUPT == USART_PE_DISABLED
			CLR_BIT(USART1 -> CR[0], PEIE);
		#elif PARITY_ERROR_INTERRUPT == USART_PE_ENABLED
			SET_BIT(USART1 -> CR[0], PEIE);
		#endif
	#endif
	
	SET_BIT(USART1 -> CR[0], RE);
	SET_BIT(USART1 -> CR[0], TE);
	SET_BIT(USART1 -> CR[0], UE);

	USART1 -> SR = 0;
}	

void MUSART1_voidTransmit(char* word)
{
	u8 Local_u8Currentletter = 0;
	while(word[Local_u8Currentletter] != '\0')
	{
		USART1 -> DR = word[Local_u8Currentletter];
		while( (GET_BIT((USART1 -> SR), TC)) == 0 );
		Local_u8Currentletter++;
	}
}

u8 MUSART1_u8Receive(void)
{
	u32 timeout = 0;
	s8 Local_u8ReceivedData = 0;
	while( (GET_BIT((USART1 -> SR), RXNE) ) == 0)
	{
		timeout++;
		if (timeout == 30000)
		{
			Local_u8ReceivedData = 255;
			break;
		}
	}
	if(Local_u8ReceivedData == 0)
	{
		Local_u8ReceivedData = USART1 -> DR;
	}
	return (Local_u8ReceivedData);
}
