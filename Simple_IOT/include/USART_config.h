/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 19 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/*Options for word size:
		USART_8_BIT_WORD 
		USART_9_BIT_WORD
						*/
#define USART1_WORD		USART_8_BIT_WORD 

/*Options for parity:
		USART_PARITY_DISABLED	
		USART_PARITY_ENABLED
							*/
#define USART1_PARITY	 	USART_PARITY_DISABLED	

/*Parity:
		USART_EVEN_PARITY	
		USART_ODD_PARITY	
						*/
#define PARITY	USART_EVEN_PARITY

/*Parity error interrupt enable state:
		USART_PE_DISABLED	
        USART_PE_ENABLED	
									*/
#define PARITY_ERROR_INTERRUPT		USART_PE_DISABLED

/*BAUD RATE options:
		BAUD_9600
		BAUD_115200
					*/
#define BAUD_RATE		BAUD_115200
	
#endif
