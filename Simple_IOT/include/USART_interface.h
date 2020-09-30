/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 19 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART1_voidInit(void);

void MUSART1_voidTransmit(char* word);

u8 MUSART1_u8Receive(void);

#endif
