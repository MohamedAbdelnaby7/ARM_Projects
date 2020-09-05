/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 28 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#define AHB_DIV_8	0
#define AHB_NO_DIV  1

/*Apply Clock Choice from configurationfile
  Disable SysTick interrupt
  Disable SysTick							*/
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void MSTK_voidStopInterval(void);
u32 MSTIK_u32GetElapsedTime(void);
u32 MSTIK_u32GetRemainingTime(void);

#endif
