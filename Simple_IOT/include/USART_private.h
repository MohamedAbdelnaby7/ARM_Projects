/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 19 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define UE 		13	/*USART enable*/
#define M 		12 	/*WORD length*/
#define PCE 	10 	/*Parity control Enable*/
#define PS 		9	/*Parity selection*/
#define PEIE	8	/*Parity interrupt enable*/
#define TXEIE	7	/*TXE Interrupt enable*/
#define TCIE	6	/*RX Interrupt enable*/
#define RXNEIE  5	/*RCNE interrupt enable*/
#define TE 		3	/*TX enabled*/
#define RE		2	/*RX enabled*/

#define TXE 	7	/*Transmistion data register empty*/
#define TC 		6	/*Transimation complete*/
#define RXNE 	5	/*Read data register not empty*/
#define IDLE	4	/*Idle Line*/

#define USART_8_BIT_WORD			0
#define USART_9_BIT_WORD			1

#define USART_PARITY_DISABLED		0
#define USART_PARITY_ENABLED		1

#define USART_EVEN_PARITY			0
#define USART_ODD_PARITY			1

#define USART_PE_DISABLED			0
#define USART_PE_ENABLED			1

#define BAUD_9600					0
#define BAUD_115200					1

typedef struct
{
	u32 volatile SR;
	u32 volatile DR;
	u32 volatile BRR;
	u32 volatile CR[3];
	u32 volatile GTPR;
} USART_t;

#define USART1 ((volatile USART_t*) 0x40013800)

#endif

