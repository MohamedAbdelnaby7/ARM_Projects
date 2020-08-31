/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 26 Aug 2020                                                       */
/*********************************************************************************/
#ifndef SysTick_INTERFACE_H
#define SysTick_INTERFACE_H

/* public functions prototypes */

/******************************************************************************
* Description : initializing the SysTick peripheral by configuring the clock
* Parameters  : void
* Return type : void
******************************************************************************/
void MSTK_voidInit(void);

/******************************************************************************
* Description : Synchronous time delay
* Parameters  : ms(the required delay in ms)
* Return type : void
******************************************************************************/
void MSTK_voidSetBusyWait(u32 Copy_u32ms);

/******************************************************************************
* Description : Asynchronous time delay
* Parameters  : ms(the required delay in ms), pointer to function
* Return type : void
******************************************************************************/
void MSTK_voidSetInterval(u32 Copy_u32ms, void (*Copy_ptr) (void));

/******************************************************************************
* Description : disabling the systick module
* Parameters  : void
* Return type : void
******************************************************************************/
void MSTK_voidStopTimer(void);

/******************************************************************************
* Description : getting the elapsed time from the set time
* Parameters  : void
* Return type : u32(the elapsed time)
******************************************************************************/
u32 MSTK_u32GetElapsedTime(void);

/******************************************************************************
* Description : getting the remaining time from the set time
* Parameters  : void
* Return type : u32(the remaining time
******************************************************************************/
u32 MSTK_u32RemainingTime(void);

/******************************************************************************
* Description : SysTick ISR
* Parameters  : void
* Return type : void
******************************************************************************/
void SysTick_Handler(void);


#endif
