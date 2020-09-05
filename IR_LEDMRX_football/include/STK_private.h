/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 28 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_CTRL 	*((volatile u32*)0xE000E010)
#define STK_LOAD 	*((volatile u32*)0xE000E014)
#define STK_VALUE 	*((volatile u32*)0xE000E018)

#define COUNTER_ENABLE 	0
#define TICK_INT		1
#define CLKSOURCE		2
#define COUNTER_FLAG	16

u8 Is_Periodic = 0;
void (* CallBack)(void);

#endif
